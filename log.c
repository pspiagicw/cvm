#include "vm.h"
#include <stdio.h>
#include <stdlib.h>

void error(char *message) {
  fprintf(stderr, "%s\n", message);
  exit(1);
}

void info(char *message) { fprintf(stderr, "%s\n", message); }
