#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LEN 12
#define INPUT "input.txt"

int main() {
  int i, res[MAX_BINARY_LEN], o2[MAX_BINARY_LEN], co2[MAX_BINARY_LEN];
  for (i = 0; i < MAX_BINARY_LEN; i++) {
    res[i] = 0;
    o2[i] = 0;
    co2[i] = 0;
  }

  FILE* fp = fopen(INPUT, "r");

  // Compute file size to allocate buffer
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  // Read data
  char* file_data = malloc(fsize + 1);
  fread(file_data, 1, fsize, fp);
  fclose(fp);

  i = 0;
  while (*file_data != '\0') {
    if (*file_data == '\n') {
      i = 0;
      file_data++;
      continue;
    }
    if (*file_data == '0') {
      res[i] += -1;
    } else {
      res[i] += 1;
    }

    file_data++;
    i++;
  }
  int sizeOfBinary = i;

  unsigned int gamma = 0, mask = 0;
  for (i = 0; i < sizeOfBinary; i++) {
    if (res[i] > 0) {
      gamma += (1 << (sizeOfBinary - i - 1));
    }
  }

  for (i = 0; i < sizeOfBinary; i++) {
    mask += (1 << i);
  }

  unsigned int epsilon = (~gamma) & mask;
  unsigned int consumption = gamma * epsilon;

  printf("gamma: %u, epsilon: %u: %u\n", gamma, epsilon, consumption);
  return 0;
}
