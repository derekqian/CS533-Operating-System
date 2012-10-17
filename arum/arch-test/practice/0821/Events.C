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
   //events.lookupEventByName("instructions_completed");
   //events.lookupEventByName("instructions_on_vacation");
   //events.lookupEventByName("global_power_events");
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
   this->walkArchList(archie);
   printf ("There are %d archie nodes\n", archie.getCount());

   printf ("Resetting archie iterator...\n");
   archie.resetIterator();
   while (archie.getItNesting() == 0) {
      this->addNode(archie);
   }
   
}

void
Events::walkArchList(const Arch & a)
{
  a.printNodes();
}

////////////////////// old ///////////////////////////////////////////////////
//bool 
//Events::addNode(const char *data)
//{
//    bool rv;
//
//    EventNode * add = new EventNode;
//    if (add == NULL) { // no memory
//        rv = false;
//    } else {
//        add->name = new char[strlen(data+1)];
//        strcpy(add->name, data);
//        //add->registers = NULL;
//        add->registers[PMC].name = "Bob";
//        //add->registers = new RegNode[MAX_REG_TYPES];
//        add->next = NULL;
//        this->count++;
//        if (this->head == NULL) {
//            this->head = add;
//        } else {
//            this->tail->next = add;
//        }
//        this->tail = add;
//        rv = true;
//    }
//    return rv;
//}
///////////////////////////////////////////////////////////////////////////////


//This version of addNode adds event nodes based on
//the architecture specification
bool 
Events::addNode (Arch & a)
{
   bool rv;
   int currNest, nextNest;
   char tempName[MAX_REG_NAME_LEN];
   int regType = -1, regNumber = -1;
   unsigned long regAddr = 0;
   
   if (a.getItNesting() != 0) {  //nesting level of current arch node 
                                 //is not at the Event name level
      return false;
   }

   currNest = 0;
   EventNode * add = new EventNode;
   if (add == NULL) { //no memory
      rv = false;
   } else {
      add->name = new char[30];
      memset(add->name, '\0', 30);
      a.getItName(add->name);
      //printf ("addNode: Event name: %s\n", add->name);
      add->next = NULL;
      this->count++;
      if (this->head == NULL) {
         this->head = add;
      } else {
         this->tail->next = add;
      }
      this->tail = add;

      //set up registers
      RegNode * dummy = new RegNode; 
      if (!dummy) {
         rv = false;
      } else {
         rv = this->fillRegNode(a, dummy, currNest);
      }      
   }
   //printf ("addNode returning\n");
   return rv;

}

bool 
Events::fillRegNode (Arch & a, struct RegNode * r, int currLevel)
{
   bool rv;
   char tempName[MAX_REG_NAME_LEN];
   int regType = -1, regNumber = -1;
   unsigned long regAddr = 0;
   int nextLevel = -1;

   //printf("!!!!!!! fillRegNode  currLevel = %d  !!!!!!!!!!\n",currLevel);

   //IF at top of an event node
   if (currLevel == 0) { 
      printf("Current Event Node: %s\n", this->tail->name);
      if( (nextLevel = a.getNextItNesting()) < 0) {     //peek ahead 
         return false;
      }

      //IF next is an associate (from event node top)
      if (nextLevel == currLevel + 1) {
         rv = a.incrementIterator();            //increment Arch iterator
         if (rv != OK) {
            return rv;
         }
         currLevel ++;                          //increment level       

         memset(tempName, '\0', MAX_REG_NAME_LEN);
         a.getItName(tempName);
         a.getItType(regType);
         if (!a.getItNumber(regNumber)) {
            printf ("getItNumber failed\n");
            return false;
         }
         a.getItAddr(regAddr);
         //printf ("   type:%d  name:%s  number:%d  addr:0x%8.8lx\n",
         //        regType, tempName, regNumber, regAddr);
         this->tail->entryReg = regType;

         //fill in entry point register
         this->tail->registers[regType].rType = regType; 
         this->tail->registers[regType].number = regNumber;
         this->tail->registers[regType].name = new char[strlen(tempName) + 1];
         memset(this->tail->registers[regType].name, 
                '\0', strlen(tempName) + 1);
         strcpy(this->tail->registers[regType].name, tempName);
         this->tail->registers[regType].addr = regAddr;
         this->tail->registers[regType].associates = NULL;
         this->tail->registers[regType].previous = NULL;
         this->tail->registers[regType].next = NULL;

         //peek ahead - if associate, increment iterator and currLev, call self
         if( (nextLevel = a.getNextItNesting()) < 0) {
            return false;
         }
         if (nextLevel == currLevel + 1) {   //next is an associate
            rv = a.incrementIterator();
            if (rv != OK){
               return rv;
            }
            currLevel++;
            RegNode * assocA = new RegNode;

            //point to previous  
            assocA->previous = &(this->tail->registers[regType]); 
            assocA->associates = NULL;                //set associates to null
            //set previous' associates 
            this->tail->registers[regType].associates = assocA;
            //printf ("   Begin recursive call to fillRegNode assoc: ");
            //printf ("nextLevel:%d == currLevel:%d\n", nextLevel, currLevel);
            //call self with new associate and level
            this->fillRegNode(a, assocA, currLevel);

         //ELSE IF a previous register's next
         } else if ((nextLevel < currLevel) && (nextLevel != 0)){ 
            printf ("previous register's next: top level not complete!\n");
            return false;

         //ELSE IF this register's next
         } else if ((nextLevel == currLevel) && (nextLevel != 0)) { 
            printf ("this register's next: top level not complete!\n");
            return false;

         //ELSE IF reached the end of an event
         } else if (nextLevel == 0) {
            printf("\tnextLevel:%d == event node level\n\n\n",
                   nextLevel, currLevel);
            rv = a.incrementIterator();
            if (rv != OK ){
               return rv;
            }

         //ELSE - empty else
         } else {}

         //rv = true;

      // The next node (from event top) is not an associate
      // Could be a next register type or end of list
      } else {
         //TODO: code this 
         printf ("next node from event top is not an associate!\n");
         return false;
         //rv = true;
      }

      rv = true;              //if didn't return early, then success

   // ELSE currLevel > 0 -- within a register list
   // the previous link is already set, so fill out the easy stuff
   // then look to see if there are associates
   } else {                           
      //printf("\tcurrLevel:%d > 0 previous node is %s\n",
      //       currLevel,r->previous->name);
      //printf("\t   with type:%d number:%d addr:0x%8.8lx\n", 
      //       r->previous->rType, r->previous->number, r->previous->addr);

      memset(tempName, '\0', MAX_REG_NAME_LEN);
      a.getItName(tempName);
      a.getItType(regType);
      if (!a.getItNumber(regNumber)) {
         printf ("getItNumber failed\n");
      }
      a.getItAddr(regAddr);
      //printf ("\t   type:%d  name:%s  number:%d  addr:0x%8.8lx\n",
      //        regType, tempName, regNumber, regAddr);
      //printf ("\t contents of r before assign: ");
      //printf ("type:%d number:%d addr:0x%8.8lx\n",
      //        r->rType, r->number, r->addr);
     
      r->rType = regType;                        //fill in register
      r->number = regNumber;
      r->name = new char[strlen(tempName) + 1];
      memset(r->name, '\0', strlen(tempName) + 1);
      strcpy(r->name, tempName);
      r->addr = regAddr;
      r->associates == NULL;
      r->next = NULL;
      
#ifdef DEBUG_EVENT
      //printf ("\tCurrent node:  type:%d name:%s number:%d addr:0x%8.8lx\n",
      //        r->rType, r->name, r->number, r->addr);
      //if (r->previous == NULL){
      //   printf ("\tPrevious node is null\n");
      //} else { 
      //   printf ("\tPrevious node: type:%d name:%s number:%d addr:0x%8.8lx\n",
      //            r->previous->rType, r->previous->name, 
      //            r->previous->number, r->previous->addr);
      //} 
#endif      
      //peek ahead - if associate, increment iterator and currLev, call self
      if( (nextLevel = a.getNextItNesting()) < 0) { 
         return false;
      }

      //IF next is an associate
      if (nextLevel == currLevel + 1) { 
         rv = a.incrementIterator();
         if (rv != OK) {
            return rv;
         }
         currLevel++;
         RegNode * assocB = new RegNode;  //create new associate
         assocB->previous = r;            //point to previous
         assocB->associates = NULL;       //set new's associates to NULL
         r->associates = assocB;          //set previous' associates

         //printf ("\tBegin recursive call to fillRegNode assoc: ");
         //printf ("nextLevel:%d == currLevel:%d\n", nextLevel, currLevel);

         //call self with new associate and level
         this->fillRegNode(a, assocB, currLevel);

      //ELSE IF next is a previous register's next 
      } else if ((nextLevel < currLevel) && (nextLevel != 0)){ 
         //printf("\tnextLevel:%d < currLevel:%d\n", nextLevel, currLevel);
         //walk up the list; while currLevel > next level decrement currLevel 
         //at each step; when currLevel == nextLevel, check if that node's next
         //is null -- keep walking back through list until a previous with a 
         //null next is found. The found node is the node whose next pointer 
         //should point to the new node.
         rv = a.incrementIterator();           //increment arch iterator
         if (rv != OK) {
            return rv;
         }
         RegNode * nextB = new RegNode;
         nextB->next = NULL;
         nextB->previous = NULL;
         nextB->associates = NULL;
         RegNode * rTemp = r;             //set up iterator
         while (currLevel != nextLevel) {
            rTemp = rTemp->previous;      //move iterator backwards
            currLevel--;                  //decrement currLevel
         }
         while (rTemp->next != NULL) {
            rTemp = rTemp->previous;
         }
         //printf("\tname of node whose next to fill: %s\n", rTemp->name);
         rTemp->next = nextB;             //iterator's next points to nextB
         nextB->previous = rTemp;         //set nextB's previous
         //printf("\tname of new node's previous: %s\n", nextB->previous->name);
         //printf("\tBegin recursive call to fillRegNode next: ");
         //printf("nextLevel:%d == currLevel:%d\n", nextLevel, currLevel);
         //call self with new next and level
         this->fillRegNode(a, nextB, currLevel);

      //ELSE IF this register's next
      } else if ((nextLevel == currLevel) && (nextLevel != 0)) {
         printf("\tnextLevel:%d == currLevel:%d\n", nextLevel, currLevel);
         return false;
      //ELSE IF end of an event (next is start of new event)
      } else if (nextLevel == 0) { 
          //printf("\tnextLevel:%d == event node level\n\n\n", 
          //      nextLevel, currLevel);
          rv = a.incrementIterator();
          if (rv != OK ){
             return rv;
          }

      //ELSE - empty
      } else {
         printf("empty else!\n");
         return false;
      }

      rv = true;                        //if didn't return early with false,
                                        //then must be success
   }
   return rv;                           //return success
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
    printf ("Events:\n");
    if (!this->isEmpty()) {
        EventNode * iterator = this->head;
        while (iterator != NULL) {
            printf ("%s has registers:\n", iterator->name);
            RegNode * rit = new RegNode;
            printEventRegisterList(iterator,rit,0);
            iterator = iterator->next;
        }       
    } else {
        printf ("Event List is empty\n");
    }
    
}

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
