#include <stdio.h>
#include <stdlib.h>
#include <binpro.h>

int main(int argc, char* argv[], char* envp[]) {
  instrumentProg(argc-1, argv+1, envp);	
  return 0;
}

