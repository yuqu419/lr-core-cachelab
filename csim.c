#include "cachelab.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  uint64_t tag;
  uint8_t set_index;
  uint8_t valid_bit;
} cache_unit;

int main(int argc, char *argv[]) {
  int set_bit = atoi(argv[2]);
  int associativity = atoi(argv[4]);
  int block_bit = atoi(argv[6]);
  cache_unit caches[1 << set_bit][associativity];
  for (int i = 0; i < (1 << set_bit); i++) {
    for (int j = 0; j < associativity; j++) {
      caches[i][j] = (cache_unit){.valid_bit = 0};
    }
  }

  FILE *file = fopen(argv[8], "r");
  char buf[4096];
  fgets(buf, 4096, file);
  printSummary(0, 0, 0);
  return 0;
}
