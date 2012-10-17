#if !defined( Events_h )
#define Events_h
#include "Arch.h"

#define DEBUG_EVENT 

enum regType {PMC, ESCR, CCCR};

class Events {
   struct RegNode {
      char * name;
      int number;
      unsigned addr;
      struct RegNode ** associates;  //an array of register lists
      struct RegNode * next;
   };

   struct EventNode {
      char * name;
      //struct RegNode ** registers;  //an array of register lists
      struct RegNode registers[MAX_REG_TYPES];
      struct EventNode * next;
   };

   public:
 
      Events(const struct ArchId * aid);
      ~Events();
      bool isEmpty() const;
      int getCount() const;
      bool lookupEventByName(const char * name);
      void printEvents();

   private:
      EventNode * head;
      EventNode * tail;
      char archStr[MAX_ARCH_FILE_LEN];
      struct ArchId aid;
      int count;
      void createArchStr(char * archStr);
      bool addNode (const char * data);
      bool superAddNode (Arch & a);
      bool removeNode ();
      void walkArchList(const Arch & a);
      
};
#endif //Events

