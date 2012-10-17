
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
#include "Events.h"
#include "Arch.h"
using namespace std; 


int main(int argc, char * argv[])
{

   //char * name;
   //char temp[25];
   struct ArchId aid = {"GenuineIntel", 15, 6};

   //printf ("Hello World!\n");
   //cout << "Enter name...\n";
   //cin >> temp;
   //name = new char[strlen(temp) + 1];
   //strcpy (name, temp);
   //printf ("Hello %s!\n", name);
   Events events(&aid);
   events.printEvents();
   events.lookupEventByName("instructions_completed");
   events.lookupEventByName("instructions_on_vacation");
   events.lookupEventByName("global_power_events");
   return 0;
}

Events::Events(const struct ArchId * thatAid)
{
   memset(this->archStr, '\0', MAX_ARCH_FILE_LEN);
   this->head = this->tail = NULL;
   this->count = 0;
   strcpy(this->aid.vendor, thatAid->vendor);
   this->aid.model = thatAid->model;
   this->aid.family = thatAid->family;
   this->createArchStr(this->archStr); 
 
#ifdef DEBUG_EVENT     
   printf ("Events Instantiation of vendor %s family %d model %d!\n", 
           thatAid->vendor, thatAid->family, thatAid->model);
   printf ("Architecture String: %s\n", this->archStr);
#endif

   Arch archie(this->archStr); 
   //read file
   if (archie.readFile()){
       printf ("file read!\n");
   }
   //archie.printNodes();
   this->walkArchList(archie);
   printf ("There are %d archie nodes\n", archie.getCount());

   this->addNode("global_power_events");
   this->addNode("instructions_retired");
   this->addNode("instructions_completed");
   printf ("Resetting archie iterator...\n");
   archie.resetIterator();
   archie.printIterator();
   this->superAddNode(archie);
   printf ("Incrementing archie iterator...\n");
   archie.incrementIterator();
   archie.printIterator();
   //this->superAddNode(archie);
}

void
Events::walkArchList(const Arch & a)
{
  a.printNodes();
}

bool 
Events::addNode(const char *data)
{
    bool rv;

    EventNode * add = new EventNode;
    if (add == NULL) { // no memory
        rv = false;
    } else {
        add->name = new char[strlen(data+1)];
        strcpy(add->name, data);
        //add->registers = NULL;
        add->registers[PMC].name = "Bob";
        //add->registers = new RegNode[MAX_REG_TYPES];
        add->next = NULL;
        this->count++;
        if (this->head == NULL) {
            this->head = add;
        } else {
            this->tail->next = add;
        }
        this->tail = add;
        rv = true;
    }
    return rv;
}

//This version of addNode adds event nodes based on
//the architecture specification
bool 
Events::superAddNode (Arch & a)
{
   bool rv;
   if (a.getItNesting() != 0) {  //nesting level of current arch node 
                                 //is not at the Event name level
      return false;
 
   }
   EventNode * add = new EventNode;
   if (add == NULL) { //no memory
      rv = false;
   } else {
      if (a.incrementIterator()) { 
         printf ("Entry Reg = %d and Nesting = %d\n", 
                  a.getItEntryReg(), a.getItNesting());
         printf ("Next Entry Reg = %d and Next Nesting = %d\n",
                  a.getNextItEntryReg(), a.getNextItNesting());
      }
   }

}

void
Events::createArchStr(char * archStr)
{
   int n;
   memset (archStr, '\0', MAX_ARCH_FILE_LEN);
   if (strcmp(this->aid.vendor,  INTEL_VENDOR_STR ) == 0) {
      n = sprintf (archStr, "Intel-%d-%d", this->aid.family, 
                   this->aid.model);
   } else if (strcmp(this->aid.vendor, AMD_VENDOR_STR) == 0) {
      n = sprintf (archStr, "AMD-%d-%d", this->aid.family, 
                   this->aid.model);
   } else {

   }
}


bool
Events::removeNode()
{
    bool rv;

    if (this->head == NULL) {
        rv = false;
    } else {
        EventNode * temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->count--;
        if (this->count == 0) {
            this->tail = NULL;
        }
        rv = true;
    }
    return rv;
}

Events::~Events()
{
}

bool
Events::isEmpty() const
{
   bool rv;

   if (this->count > 0) {
      rv = false;
   } else {
      rv = true;
   }
   return rv;
}



int
Events::getCount() const
{
   return this->count;
}


bool 
Events::lookupEventByName(const char * name)
{
   bool found = false;

   EventNode * iterator = this->head;
   while (iterator != NULL) {
      if (strcmp(name,iterator->name) == 0) {
         found = true;
         break;
      }
      iterator = iterator->next;
   }
   printf ("Event %s found status: %d\n", name, (int)found);
   return found;
}

void 
Events::printEvents()
{
    if (!this->isEmpty()) {
        EventNode * iterator = this->head;
        while (iterator != NULL) {
            printf ("\t%s\t%s\n", iterator->name, iterator->registers[PMC].name);  
            iterator = iterator->next;
        }       
    } else {
        printf ("Event List is empty\n");
    }
    
}

