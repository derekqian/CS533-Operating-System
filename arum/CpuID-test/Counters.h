#if !defined( Counters_h )
#define Counters_h

#include <stdio.h>
#define DEBUG_COUNT
#define TEST_COUNT

#define NONSUPPORT_VENDOR	-1;
#define INTEL_VENDOR 		1;
#define AMD_VENDOR		2;
//const int NONSUPPORT_VENDOR = -1;

const char * theEventStr = "c1 c2 c3";
struct archIdentity {
   int architecture;
   int family;
   int model;
   int stepping;
};

class Counters {
public:
    static const long MaxEventsListLen   = 1024; 
    static const long MaxReportLen       = 8191;

    Counters (const char * events, bool debug, bool mplex);
    Counters();
    ~Counters();
    int openDevice();
    int closeDevice ();
    int writeCounters();
    int readCounters();
    void printReport();
    void printStats();
    bool isCompatible() const;
private:
   char eventListStr[MaxEventsListLen + 1];  
   FILE * fstream;
   int fd;
   bool dbug;
   bool mplex;
   char eventReport[MaxReportLen + 1];
   struct archIdentity aid;
   int getVendorId(const struct baseCpuid * base);
   void error (const char * errorStr);
   void debug (const char * debugStr);
   
};

#endif
