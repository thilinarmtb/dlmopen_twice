#define _GNU_SOURCE

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  dlerror();

  void *self1 = dlmopen(LM_ID_NEWLM, "./libfoo.so", RTLD_NOW | RTLD_LOCAL);
  if (!self1) fprintf(stderr, "%s\n", dlerror());
  if (self1) dlclose(self1);

  void *self2 = dlmopen(LM_ID_NEWLM, "./libfoo.so", RTLD_NOW | RTLD_LOCAL);
  if (!self2) fprintf(stderr, "%s\n", dlerror());
  if (self2) dlclose(self2);

  return 0;
}
