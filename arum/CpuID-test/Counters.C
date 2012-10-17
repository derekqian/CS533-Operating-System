#include "Counters.h"
#include "CpuId.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

baseCpuid base;                 // to hold basic cpuid info

Counters::Counters ()
{
   memset (&base, '\0', sizeof(struct baseCpuid));
   bzero (this->eventListStr, this->MaxEventsListLen);
   this->eventListStr[this->MaxEventsListLen] = '\0';
   bzero (this->eventReport, this->MaxReportLen);
   this->eventReport[this->MaxReportLen] = '\0';
   this->dbug = false;
   this->mplex = false;
   this->aid.architecture = 0;
   this->aid.family = 0;
   this->aid.model = 0;
   this->aid.stepping = 0;
}

Counters::Counters (const char * events, bool debug, bool mplex) 
{
   int len;
   bool archCheck;
   len = strlen (events);
   if (debug) {
      this->dbug = true;
   } 

   if (mplex) {
      this->mplex = true;
   }

   if (len <= MaxEventsListLen) {
      
      //parse events

      //get cpuid info
      CpuId cpu;                      // runs the cpuid instruction
      cpu.getBasicReport (&base);     // get basic cpuid info
#ifdef DEBUG_COUNT
      if (base.cpuid_enabled) {
         printf ("*************** CPUID Report ***************\n");
         printf ("Vendor: %s\n", base.vendor);
         if (base.brand_string) {
            printf ("Brand String: %s\n", base.brand_string);
         }
         printf ("LSFN        Family      Model       Stepping\n");
         printf ("0x%8.8lx  0x%8.8lx  0x%8.8lx  0x%8.8lx\n\n",
                 base.lsfn, base.family, base.model, base.stepping);
         printf ("Brand Id    Clflush Sz  NB node ID  CPU No.\n");
         printf ("0x%8.8lx  0x%8.8lx  0x%8.8lx  0x%8.8lx\n\n",
                 base.brand_id, base.clflush_size, base.nb_node_id,
                 base.cpu_number);
      } else {
         printf ("no cpuid support!\n");
      }
#endif
      //Fill out the architecture id structure 
      this->aid.architecture = this->getVendorId(&base);
      this->aid.family = base.family;
      this->aid.model = base.model;
      this->aid.stepping = base.stepping;

      //Based on architecture id, build searchable data structure
      //an event list is returned

      //check if events are compatible with architecture     
      archCheck = true;
      if (archCheck) {
         strcpy(this->eventListStr, events);
         this->eventListStr[len] = '\0';
      }


   } else {
      error ("constructor: event list exceeds max length.");
   }
}


bool 
Counters::isCompatible() const
{
   bool rv = true;
   if (!this->eventListStr) {
      rv = false;
   }
   return rv;
}


Counters::~Counters()
{

}


// Counters::openDevice
// Purpose: open hardware counter device file
// Description: Calls the hardware counter module's open to open the Arum
//              device.  Opens for Read and Write. On success, 1 is returned;
//              on failure, -1 is returned. The Counter class does not force 
//              an exit as a result of this error. 
int
Counters::openDevice()
{
   int rv;
   if ((this->fd = open ("/dev/Arum", O_RDWR)) == -1){
      rv = -1;
      this->error("open device failed.");
   } else {
      rv = 1;
   }
     
   return rv;
}


// Counters::closeDevice
// Purpose: close hardware counter device file
// Description: Calls the hardware counter module's close to close the Arum
//              device.  If the close fails, an error is reported. The Counter
//              class does not force an exit as result of this error.
int
Counters::closeDevice()
{
   int rv;
   if ((rv = close (this->fd)) == -1) {
      this->error("close device failed.\n");
   }
   return rv;
}

// Counters::writeCounters()
// Purpose: Send the hardware counter module the list of performance events
//          to monitor
// Description: Notifies the hardware counter module of the performance events
//          that are to be monitored (this list is stored in class object). 
//          TODO: move this check to the constructor: This list is checked to 
//          ensure that the events listed can be monitored.  
//
//          Calls the hardware module's write() and writes the list to the 
//          device. If multiplexing, then notifies module of this tool. 
//          On success returns the number of events written.  On error returns 
//          -1. 
//
int
Counters::writeCounters()
{
   int rv;
   printf ("Counters: string to write = %s, len=%d\n", 
            this->eventListStr, strlen(this->eventListStr));
   rv = write (this->fd, this->eventListStr, strlen(this->eventListStr)); 
   if (rv == 0){
      this->debug("writeCounters wrote 0 bytes.");
   } else if (rv == -1) {
      this->error("writeCounters failed.");
   } else {
      printf ("Counters: writeCounters: count written = %d\n", rv);
   }
   return rv;
}


// Counters::readCounters()
// Purpose: Receive results from the monitored events. 
// Description: Uses the hardware module's read() to get the results from
//          monitoring the selected events. The results are stored in this
//          object and can subsequently by printed via printReport
//          On success, returns the number of events read.  On, error returns 
//          -1.
//
int
Counters::readCounters()
{
   int rv;
   rv = read(this->fd, this->eventReport, this->MaxReportLen);
   if (rv < 0) {
      this->error("readCounters failed.");
   } else if (rv == 0) {
      this->debug("readCounters reached end of file.");
   } else {
      printf ("Counters: readCounters: count read = %d\n", rv);
   }
   return rv;
}

// Counters::printReport()
// Purpose: Display hardware performance counter results
// Description: Incomplete
//
void
Counters::printReport()
{
   printf ("Performance Counter Monitoring Results\n");
   printf ("    %s\n", this->eventReport);
}

// Counters::getVendorId
// Purpose: return and id number for a vendor string
//
int 
Counters::getVendorId(const struct baseCpuid * base)
{
   int vendorId;
   if (strcmp(base->vendor, "GenuineIntel") == 0 ) {
      vendorId = INTEL_VENDOR;
   } else if (strcmp(base->vendor, "AuthenticAMD") == 0 ) {
      vendorId = AMD_VENDOR;
   } else {
      vendorId = NONSUPPORT_VENDOR;  //unsupported vendor
   }
   return vendorId;
}

// Counters::printStats()
// Purpose: helper method to print out what is known about what hardware events 
//          will be monitored
// Description:
//
void
Counters::printStats()
{
   printf ("Events: %s\n", eventListStr);
}

// Counters::error()
// Purpose: Report an error description when Counters detects an error.
//
void
Counters::error(const char * errorStr)
{
   printf ("Counters: %s\n", errorStr);
}

// Counters::debug()
// Purpose: Print a debug statement if Counters instance has been
//          initialized with debug set to true.
void 
Counters::debug(const char * debugStr)
{
   if (this->dbug) {
      printf("DEBUG: Counters: %s\n");
   }
}

#ifdef TEST_COUNT
/*
 * main program
 */
int
main(int ac, char*av[])
{
    printf ("Test Counters Class and CPUId instruction.\n");
    //CpuId x;
    Counters cntrs;
    cntrs = Counters (theEventStr, true, false);
    if (cntrs.isCompatible()) {

       printf("The specified events can be counted\n"); 
    } else {
       printf 
         ("The specified event list is incompatible with the architecture\n");
    }
    printf ("\nEnd of Test.\n");
}
#endif
