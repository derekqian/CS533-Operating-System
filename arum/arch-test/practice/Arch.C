#include "Arch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cctype>
#include <iostream>
#include <fstream>
using namespace std;

/***
Arch::Arch()
{
   this->head = this->tail = NULL;
   this->count = 0;
   this->archId = -1;
}
***/

Arch::Arch(const char * archStr)
{
   this->head = this->tail = this->iterator = NULL;
   this->count = 0;
   this->archId = determineArchitecture(archStr);
   printf ("str: %s id: %d\n", archStr, this->archId);
}


Arch::~Arch()
{
}

bool
Arch::readFile()
{
   bool rv;
   char filename[MAX_ARCH_FILE_LEN];
   char line [MAX_LINE_LEN];
   ifstream fin;

   memset (filename, '\0', MAX_ARCH_FILE_LEN);
  
   if (this->archId == INTEL_15_6_ID) {
      strcpy(filename, INTEL_15_6_STR);
   } else if (this->archId == AMD_15_65_ID) {
      strcpy (filename, AMD_15_65_STR);
   } else {
      return false;
   }

   fin.open (filename, ios_base::in);
   if (!fin.is_open()){
      printf("Arch::readFile: open failed %s\n", filename);
      rv = false;
   } else {
      while (fin.getline(line, MAX_LINE_LEN, '\n')){
         if ((line[0] == '#') || (iscntrl(line[0]) && (line[0] != '\t'))) {
            continue;                    //ignore comments and blank lines
         }else {
            this->addLine(line);
            //printf ("%s\n", line);
         }
      }
      fin.close();
      rv = true;
   }
   return rv;
}


int 
Arch::getItNesting() const
{
   int rv;
   if (this->iterator == NULL) {
      rv = E_NULL_NODE;
   } else {
      rv = this->iterator->nestingLevel;
   }
   return rv;
}

int
Arch::getNextItNesting() const
{
   int rv;
   if (this->iterator == NULL) {
      rv = E_NULL_NODE;
   } else if (this->iterator->next == NULL) {
      rv = E_NULL_NODE; 
   } else {
      rv = this->iterator->next->nestingLevel;
   }
   return rv;
}

//returns the index of the entry register of the current charNode iterator
int 
Arch::getItEntryReg() const
{
   int rv;
   char reg[2];
   if (this->iterator != NULL) {
      if ( (this->iterator->line[0] != 'r') &&
           (!isdigit(this->iterator->line[1])) ) {
         rv = E_FORMAT;
         printf ("Format for entry %s in Events file %s is not supported\n",
                 this->iterator->line, this->archStr);
      } else {
         reg[0] = this->iterator->line[1];
         reg[1] = '\0';
         rv = atoi(reg);
         if ((rv < 0) || (rv >= MAX_REG_TYPES)) {
            printf ("Format for entry %s in Events file %s is not supported\n",
                    this->iterator->line, this->archStr);
            rv = E_FORMAT;
         }
      }
   } else {
      rv = E_NULL_NODE;
   }
   return rv; 
}

int 
Arch::getNextItEntryReg() const
{
   int rv;
   char reg[2];
   if (this->iterator != NULL) {
      if ( (this->iterator->next->line[0] != 'r') && 
           (!isdigit(this->iterator->next->line[1])) ) {
         rv = E_FORMAT;
         printf ("Format for entry %s in Events file %s is not supported\n",
                 this->iterator->next->line, this->archStr);
      } else {
         reg[0] = this->iterator->next->line[1];
         reg[1] = '\0';
         rv = atoi(reg);
         if ((rv < 0) || (rv >= MAX_REG_TYPES)) {
            printf ("Format for entry %s in Events file %s is not supported\n",
                    this->iterator->next->line, this->archStr);
            rv = E_FORMAT;
         }
      }
   } else {
      rv = E_NULL_NODE;
   }
   return rv;

}


void 
Arch::resetIterator()
{
   this->iterator = this->head;
}

int 
Arch::incrementIterator()
{
   int rv;
   if (!this->isEmpty()) {
      if (this->iterator == NULL) {
         rv = E_NULL_NODE; 
      }else if (this->iterator->next == NULL) {
         //this->iterator = this->head;   //circles it back to head;
         //don't circle it back to the head; let user decide this
         // with reset option
         rv = E_END_OF_LIST;
      } else {
         this->iterator = this->iterator->next;
         rv = OK;
      }
   } else {
      printf ("Event List is empty\n");
      rv = E_EMPTY_LIST;
   } 
}

int 
Arch::printIterator() const
{
   int rv;
   if (!this->isEmpty()) {
      if (this->iterator != NULL) {
         printf("\t%d\t%s\n", this->iterator->nestingLevel, this->iterator->line);
         rv = OK;
      } else {
         //printf("current iterator is null - try resetting it\n");
         rv = E_NULL_NODE;
      }
   } else {
      //printf ("Event List is empty\n");
      rv = E_EMPTY_LIST;
   }
   return rv;
}

void 
Arch::printNodes() const
{
    if (!this->isEmpty()) {
        charNode * walker = this->head;
        while (walker != NULL) {
            printf ("\t%d\t%s\n", walker->nestingLevel, walker->line);
            walker = walker->next;
        }
    } else {
        printf ("Event List is empty\n");
    }
}

int
Arch::getCount() const
{
   return this->count;
}


bool
Arch::isEmpty() const
{
   bool rv;

   if (this->count > 0) {
      rv = false;
   } else {
      rv = true;
   }
   return rv;
}

bool
Arch::addLine(const char * data)
{
   int level;
   char * parseStr;
   char * p;   //to walk along data, so that we know where to start copying at 
   bool rv;

   p = (char *) data;
   parseStr = new char[strlen(data)+ 1];
   memset (parseStr, '\0', strlen(data) + 1);

   if (isprint(data[0])) {
      level = 0;
      rv = this->addNode(data, level);
   } else if (data[0] == '\t') {
      level = 1;
      p++;
      while (true) {
         if (data[level] == '\t') {
            level ++; 
            p++;
         } else {
            break;
         } 
      }
      strcpy (parseStr, p);
      rv = this->addNode(parseStr, level);
   } else {
      rv = false;
   }
   return rv;
}

bool 
Arch::addNode (const char * data, int level)
{
   bool rv;
   //printf ("str: %s level: %d\n", data, level);
   charNode * add = new charNode;
   if (add == NULL) { // no memory
      rv = false;
   } else {
      strcpy(add->line, data);
      add->nestingLevel = level;
      add->next = NULL;
      this->count++;
      if (this->head == NULL) {
          this->head = add;
      } else {
          this->tail->next = add;
      }
      this->tail = add;
      //printf ("str: %s level: %d\n", this->tail->line, this->tail->nestingLevel);
      rv = true;
   }
   return rv;
}

int
Arch::determineArchitecture(const char * archStr)
{
   int aid;
   if (strcmp(archStr, INTEL_15_6_STR) == 0  ) {
      aid = INTEL_15_6_ID;
      strcpy (this->archStr, archStr);
   } else if (strcmp (archStr, AMD_15_65_STR) == 0 ) {
      aid = AMD_15_65_ID;
      strcpy (this->archStr, archStr);
   } else {
     aid = NONSUPPORT_ID;
   } 
   return aid;
}

/**********************************
int main (int argc, char * argv[]) {
   char filename[MAX_ARCH_FILE_LEN];
   memset (filename, '\0', MAX_ARCH_FILE_LEN);
   strcpy(filename, "go beavers");
   Architecture arch (filename);
   return 0;
}
********************************/
