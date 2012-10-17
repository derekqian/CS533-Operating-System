// events.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"     //very important this is the first include (vis studio)
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
//#include "events-2.h"
//#include "arch-2.h"
#include "Events.h"
#include "Arch.h"

using namespace std; 


int main(int argc, char * argv[])
{

   struct ArchId aid = {"GenuineIntel", 15, 6};

   Events events(&aid);
   events.printEvents();

   //events.lookupEventByName("instructions_completed");
   //events.lookupEventByName("instructions_on_vacation");
   //events.lookupEventByName("global_power_events");
   return 0;
}

Events::Events(const struct ArchId * thatAid)
{
   int rv;

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
   this->walkArchList(archie);
   printf ("There are %d archie nodes\n", archie.getCount());

   //printf ("Resetting archie iterator...\n");
   archie.resetIterator();
   rv = true;
   while (rv == true) {   //events successfully added
      rv = this->addNode(archie);
   }
   
}

void
Events::walkArchList(const Arch & a)
{
  a.printNodes();
}

//
// returns true if parseEvent successfully completed an event and if the
// new node could be created; otherwise returns false
//
bool
Events::addNode(Arch & a)
{
    bool rv;

    EventNode * add = new EventNode;
    if (add == NULL) { // no memory
        rv = false;
    } else {
        add->setCount = 0;
        rv = a.parseEvent(add);
        if (rv != true) {
           printf ("EVENTS:addNode: call to parseEvent returned false!!\n");
           delete add;
        }
        if (rv == true) {
           add->next = NULL;
           this->count++;
           if (this->head == NULL) {
               this->head = add;
           } else {
               this->tail->next = add;
           }
           this->tail = add;
        }
    }
    return rv;
}

/***********************************************************************
//This version of addNode adds event nodes based on
//the architecture specification
bool 
Events::addNode (Arch & a)
{
   return true;

}
************************************************************************/

/***********************************************************************
bool 
Events::fillRegNode (Arch & a, struct RegNode * r, int currLevel)
{
   return true;                           //return success
}
************************************************************************/

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
    int i;
    printf ("Events:\n");
    if (!this->isEmpty()) {
        EventNode * iterator = this->head;
        while (iterator != NULL) {
            printf ("%s has %d register sets:\n", iterator->name, 
                    iterator->setCount);
            for (i= 0; i < iterator->setCount; i++){
               printf("Set%d:\ttype:%d name:%s number:%d addr:0x%8.8lx\n", 
                  i, iterator->registerSets[i].rType, 
                  iterator->registerSets[i].name, 
                  iterator->registerSets[i].number,
                  iterator->registerSets[i].addr);
               RegNode * regIt = iterator->registerSets[i].next;
               while (regIt != NULL) {
                  printf("\ttype:%d name:%s number:%d addr:0x%8.8lx\n", 
                     regIt->rType, regIt->name, regIt->number, regIt->addr);
                  regIt = regIt->next;
               }
               printf("\n");
            }
            iterator = iterator->next;
        }       
    } else {
        printf ("Event List is empty\n");
    }
    
}
/**************************************************************************
void 
Events::printEventRegisterList(EventNode * e, RegNode * r, int currLevel)
{
   int i = 0;
   int saveLevel;

   //at top of an event node
   if (currLevel == 0) {
      if (!e) {                       //e is null
         return; 
      } 
      //print the entry point register
      printf ("   cl:%d Name:%s  Type:%d  Number:%d  Addr:0x%8.8lx\n",
            currLevel,
            e->registers[e->entryReg].name, e->registers[e->entryReg].rType,
            e->registers[e->entryReg].number, e->registers[e->entryReg].addr);

      //If it has associates do this path first
      if (e->registers[e->entryReg].associates != NULL) {
         r = e->registers[e->entryReg].associates;
         currLevel ++;
         this->printEventRegisterList(e, r, currLevel); 

      //If it does not have associates, but has a next do this
      //path first
      } else if (e->registers[e->entryReg].next != NULL) {


      //
      //end of event reached
      } else {
         return;
      }

   //inside a register list
   } else {
      i = 0;
      while (i != currLevel) {
         printf("\t");
         i++;
      }
      printf ("cl:%d Name:%s  Type:%d  Number:%d  Addr:0x%8.8lx\n",
              currLevel, r->name, r->rType, r->number, r->addr);
      if (r->associates != NULL) {
         r = r->associates;
         currLevel ++;
         this->printEventRegisterList(e, r, currLevel);

      //associates is null, so check the next; if next is not null proceed
      //down that path; if it is null proceed back through list
      } else {
         if (currLevel > 0) {
            if (r->next != NULL) {
               r = r->next;
               this->printEventRegisterList(e, r, currLevel);

            //next is null, so proceed back through list looking for
            // a non-null next
            } else {
               //printf ("current's (%s) next is null\n", r->name);
               if (r->previous) {
                  //printf ("previous (%s)\n", r->name);
                  //while (true) { 
                     if (r->previous->next != NULL) {
                        if (r->previous->next->addr != r->addr) {
                           r = r->previous->next;
                           currLevel--;
                           this->printEventRegisterList(e, r, currLevel);
                           //break;
                        } else { //previous->next is current
                           r = r->previous;
                           printf ("previous->next is current\n");
                           printf ("cl:%d cn:%s\n", currLevel, r->name);
                        }
                     } else {  //previous->next is null and can't be current
                        while(r->previous != NULL) {
                           r = r->previous; 
                           currLevel--;
                           printf ("previous->next is null and not current\n");
                           printf ("cl:%d cn:%s\n", currLevel, r->name);
                        }
                        if (r->next != NULL) {
                           currLevel = 0;
                           r = r->next;
                           printf ("cn:%s\n", r->name);
                           //this->printEventRegisterList(e, r, currLevel);
                        }
                     }  
                  //} //end while 
                  //this->printEventRegisterList(e, r, currLevel);

               //should be at entry register level
               } else {

               }   

            }
         } else {
            printf ("?!?!currlevel = %d\n", currLevel);
         }
      }
   }


   //if(currLevel == 0) {             //at top of an event node
   //   if (e->registers[e->entryReg].associates != NULL){
   //      printf ("   Name:%s  Type:%d  Number:%d  Addr:0x%8.8lx\n",
   //         e->registers[e->entryReg].name, e->registers[e->entryReg].rType,
   //         e->registers[e->entryReg].number, e->registers[e->entryReg].addr);

   //       //print associates
   //       r = e->registers[e->entryReg].associates;
   //       saveLevel = currLevel;
   //       currLevel ++;
   //       while (i != currLevel) {
   //          printf("\t");
   //          i++;
   //       } 
   //       printf("Name:%s  Type:%d  Number:%d  Addr:0x%8.8lx\n",
   //              r->name, r->rType, r->number, r->addr);
   //       if (r->associates != NULL) {
   //          this->printEventRegisterList(e, r, currLevel);
   //       } else {
   //          printf ("from assoc -- associates null\n");
   //       }
   //   } else {
   //      printf("top-lev: associates null\n");
   //   }
   //   currLevel = saveLevel;
   //   if (e->registers[e->entryReg].next != NULL) {
   //      printf ("   Name:%s  Type:%d  Number:%d  Addr:0x%8.8lx\n",
   //        e->registers[e->entryReg].name, e->registers[e->entryReg].rType,
   //        e->registers[e->entryReg].number, e->registers[e->entryReg].addr);
   //      //print next
   //      r = e->registers[e->entryReg].next;
   //      saveLevel = currLevel;
   //      currLevel ++;
   //      while (i != currLevel) {
   //         printf("\t");
   //         i++;
   //     }
   //      printf("Name:%s  Type:%d  Number:%d  Addr:0x%8.8lx\n",
   //             r->name, r->rType, r->number, r->addr);
   //      if (r->associates != NULL) {
   //         this->printEventRegisterList(e, r, currLevel);
   //      } else {
   //         printf ("from next -- associates null\n");
   //     }
   //   } else {
   //      printf ("top-lev: next null\n");
   //   }
   //} else if (currLevel > 0) {       //within registers of an event node
   //   if (r->associates != NULL) {
   //      r = r->associates;
   //      currLevel ++; 
   //      i = 0;
   //      while (i != currLevel) {
   //        printf("\t");
   //         i++;
   //      } 
   //      printf ("Name:%s  Type:%d  Number:%d  Addr:0x%8.8lx\n",
   //             r->name, r->rType, r->number, r->addr);
   //      if (r->associates != NULL){
   //         this->printEventRegisterList(e, r, currLevel);
   //      } else {
   //         currLevel ++;
   //         i = 0;
   //         while (i != currLevel) {
   //            printf("\t");
   //            i++;
   //         }
   //         printf ("associates null\n");
   //      }
   //   }
   //   if (r->next != NULL) {
   //      printf("a next is not null\n");
   //   }
   //} else {
   //}
}
*******************************************************************************/

