#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(char *message) {
  fprintf(stdout, "%s\n", message);
  exit(1);
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

  int byte_read;
  while ((byte_read = fgetc(fp)) != EOF) {
    printf("%d ", byte_read);
  }
}
