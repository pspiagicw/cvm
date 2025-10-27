#include "vm.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(char *message) {
  fprintf(stderr, "%s\n", message);
  exit(1);
}

void info(char *message) { fprintf(stderr, "%s\n", message); }

void confirmMagicBytes(FILE *fp) {
  char magic[5];
  size_t bytes_read;
  bytes_read = fread(magic, 1, 5, fp);
  if (bytes_read != 5) {
    error("ERROR: Can't read magic bytes.");
  }

  printf("Magic Bytes: %s\n", magic);

  if (strncmp(magic, "FENCY", 5) == 0) {
    info("Magic Bytes confirmed!");
  } else {
    error("Magic bytes not matching");
  }
}

void confirmVersion(FILE *fp) {
  char version[1];
  size_t bytes_read;
  bytes_read = fread(version, 1, 1, fp);
  if (bytes_read != 1) {
    error("ERROR: Can't confirm version.");
  }
  printf("Version: %s\n", version);
}

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
