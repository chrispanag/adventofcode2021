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

  // Count Sizes
  i = 0;
  char* beginOfFile = file_data;
  while (*file_data != '\n') {
    file_data++;
    i++;
  }

  int numberOfBits = i;
  int numberOfLines = (fsize + 1) / (numberOfBits + 1);

  // Parse data
  file_data = beginOfFile;
  int num[numberOfLines];
  for (i = 0; i < numberOfLines; i++) {
    num[i] = (int)strtol(file_data + i * (numberOfBits + 1), NULL, 2);
  }

  // Compute result
  int o2flag[numberOfLines], co2flag[numberOfLines];
  for (i = 0; i < numberOfLines; i++) {
    o2flag[i] = 1;
    co2flag[i] = 1;
  }

  int o2remaining = numberOfLines, co2remaining = numberOfLines;
  int j;

  for (i = 0; i < numberOfBits; i++) {
    int sumO2 = 0, sumCO2 = 0;
    for (j = 0; j < numberOfLines; j++) {
      if (o2flag[j] == 0) {
        continue;
      }

      int digit = num[j] >> (numberOfBits - i - 1) & 1;
      if (digit == 1) {
        sumO2++;
      } else {
        sumO2--;
      }
    }

    for (j = 0; j < numberOfLines; j++) {
      if (co2flag[j] == 0) {
        continue;
      }

      int digit = num[j] >> (numberOfBits - i - 1) & 1;
      if (digit == 1) {
        sumCO2++;
      } else {
        sumCO2--;
      }
    }

    for (j = 0; j < numberOfLines; j++) {
      if (o2remaining == 1) {
        break;
      }
      if (o2flag[j] == 0) {
        continue;
      }
      int digit = num[j] >> (numberOfBits - i - 1) & 1;
      if (sumO2 >= 0 && digit == 0) {
        o2flag[j] = 0;
        o2remaining--;
      } else if (sumO2 < 0 && digit == 1) {
        o2flag[j] = 0;
        o2remaining--;
      }
    }

    for (j = 0; j < numberOfLines; j++) {
      if (co2remaining == 1) {
        break;
      }
      if (co2flag[j] == 0) {
        continue;
      }
      int digit = num[j] >> (numberOfBits - i - 1) & 1;
      if (sumCO2 >= 0 && digit == 1) {
        co2flag[j] = 0;
        co2remaining--;
      } else if (sumCO2 < 0 && digit == 0) {
        co2flag[j] = 0;
        co2remaining--;
      }
    }
  }

  int x, y;
  for (j = 0; j < numberOfLines; j++) {
    if (o2flag[j] == 1) {
      x = num[j];
      printf("o2: %d\n", num[j]);
    }
    if (co2flag[j] == 1) {
      y = num[j];
      printf("co2: %d\n", num[j]);
    }
  }
  printf("End: %d\n", x * y);
  return 0;
}
