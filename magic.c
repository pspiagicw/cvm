#include "vm.h"
#include <string.h>

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
