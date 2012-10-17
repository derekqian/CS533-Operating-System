#if !defined( Arch_h )
#define Arch_h

#define MAX_LINE_LEN 100

#define MAX_REG_TYPES 3
#define NONSUPPORT_VENDOR      -1
#define INTEL_VENDOR            1
#define AMD_VENDOR              2
#define INTEL_VENDOR_STR	"GenuineIntel"
#define AMD_VENDOR_STR		"AuthenticAMD"

#define MAX_ARCH_FILE_LEN	16
#define MAX_REG_NAME_LEN    20

//Vendor, family, model combinations
#define NONSUPPORT_ID		-1

#define INTEL_15_6_STR		"Intel-15-6"
#define INTEL_15_6_ID		1

#define AMD_15_65_STR		"AMD-15-65"
#define AMD_15_65_ID		2


#define OK			1
#define E_END_OF_LIST		-1
#define E_EMPTY_LIST		-2
#define E_NULL_NODE		-3
#define E_FORMAT		-4

struct ArchId {
   char vendor[16];
   int family;
   int model;
};

class Arch{
   struct charNode {
      char line [MAX_LINE_LEN];
      int nestingLevel;
      struct charNode * next;
   };

   public:
      //Arch();
      Arch(const char * archStr);
      //Arch(const Arch &);
      ~Arch();
      //bool addLine(const char * data);
      bool readFile();
      bool isEmpty() const;
      int getCount() const;
      void resetIterator();
      int incrementIterator();
      int printIterator() const;
      int getItNesting() const;      
      int getNextItNesting() const;
      int getItEntryReg() const;
      int getNextItEntryReg() const;
      bool getItName(char * name) const;
      bool getItType(int & t) const;
      bool getItNumber(int & n) const;
      bool getItAddr(unsigned long & addr) const;
      void printNodes() const;
      
   private:
      Arch(const Arch & a){} 
      Arch & operator=(const Arch & a) {return * this;}
      charNode * head;
      charNode * tail;
      charNode * iterator;
      int count;
      int archId;
      char archStr[MAX_ARCH_FILE_LEN];
      int determineArchitecture(const char * archStr);
      bool addNode (const char * data, int level);
      //bool readFile ();
      bool addLine(const char * data);
};

#endif //Arch_h
