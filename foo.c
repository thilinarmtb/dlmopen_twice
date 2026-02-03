#include <stdio.h>

void __attribute__((constructor))
foo(void) {
  printf("hello from foo!\n");
}
