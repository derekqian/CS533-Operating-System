/*
 * Header file for EventsList class
 */

#if !defined( Events_h )
#define Events_h

#include "arch.h"

   struct EvtNode {
      char * evtName;               //event name
      struct RegNode ** r;          //registers - pointer to array of pointers
      struct EvtNode * next;
   }

   struct RegNode {
      char * regName;               //register name
      int number;                   //register number
      unsigned long addr;           //address
      struct RegNode ** associates; //pointer to array of register pointers
                                    //used in programming a specific event
      struct RegNode * next;
   }

class EventsList {

public:
   EventsList (struct archIdentity * aid, struct evtNode * evtHead);
   ~EventsList();
   getEventByName (char * evtName); 
   int getCount ();

private
   int events;                      //number of events in list
   EvtNode * head;
   EvtNode * tail;
   bool insert (const struct EvtNode &);
   bool remove (struct EvtNode &);
   isEmpty()
   
};

#endif //Events_h
