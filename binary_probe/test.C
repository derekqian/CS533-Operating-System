#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <binpro.h>

int main(int argc, char* argv[], char* envp[]) {
  instrumentProg(argc-1, argv+1, envp);
  struct ProfInfo profInfo;
  profInfo.invokenum = 0;
  profInfo.invoke = NULL;
  getProfInfo(&profInfo);
  assert(profInfo.invokenum != 0);
  profInfo.invoke = new struct InvokeInfo[profInfo.invokenum];
  assert(profInfo.invoke);
  getProfInfo(&profInfo);
  for(int i=0; i<profInfo.invokenum; i++) {
    printf("<Arum> %s %f %f %f %f %f %f\n", profInfo.invoke[i].funcname, profInfo.invoke[i].ustart, profInfo.invoke[i].uend,
	   profInfo.invoke[i].sstart, profInfo.invoke[i].send, profInfo.invoke[i].start, profInfo.invoke[i].end);
  }
  delete profInfo.invoke;
  return 0;
}

