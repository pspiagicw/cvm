#include "vm.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    error("ERROR: Expected 1 argument");
  }

  char *argument = argv[1];

  if (strlen(argument) == 0) {
    error("ERROR: Argument is empty!");
  }

  FILE *fp = fopen(argument, "r");
  if (fp == NULL) {
    error("ERROR: Can't open file for reading.");
  }

  confirmMagicBytes(fp);
  confirmVersion(fp);
  Constant *constants = readConstants(fp);
  uint8_t *bytecode = readBytecode(fp);
  run(constants, bytecode);
}
