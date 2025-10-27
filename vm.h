#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef enum {
  INT,
  FLOAT,
  STRING,
  BOOL,
  FUNCTION,
  CLOSURE,
  ARRAY,
  HASH
} ConstantType;

typedef struct {
  ConstantType Type;
  union {
    bool boolean;
    int integer;
    double number;
    char *string;
  } Value;
} Constant;

void confirmMagicBytes(FILE *fp);
void confirmVersion(FILE *fp);
Constant *readConstants(FILE *fp);
uint8_t *readBytecode(FILE *fp);
int run(Constant *constants, uint8_t *bytecode);

void error(char *message);
void info(char *message);
