#if !defined(CpuId_h)
#define CpuId_h

#include <sys/resource.h>
#include <unistd.h>


class CpuId {
public:
    CpuId();
    ~CpuId();

private:
    int cpuid_enabled;		// is CPUID enabled on this machine

				// function 0 values
    char vendor[16];		// processor vendor
    int lsfn;			// largest standard function number

				// function 1 values
    int stepping;		// processor stepping
    int model;			// effective model number
    int family;			// effective family number
    int brand_id;		// brand ID
    int clflush_size;		// cache line flush size (brand ID must be non-zero)
    int nb_node_id;		// northbridge node ID
    int cpu_number;		// CPU number (within the server)
};

#endif

