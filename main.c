#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
  int r = open("/dev/urandom", 0_RDONLY);
  int arr[10];
  read(r, arr, sizeof(int) * 10);

  int i;
  printf("Generating random numbers:\n");
  for(i = 0; i < 10; i++) {
    printf("random %d: %d\n", i, arr[i]);
  }

  int r2 = open("numbers.txt", 0_WRONLY | 0_CREAT, 0644);
  write(r2, arr, sizeof(int) * 10);

  int arr2[10];

  r2 = open("numbers.txt", 0_RDONLY, 0644);

  read(r2, arr2, sizeof(int) * 10);

  printf("Verificatioon that written values werre the same:\n");
  for(i = 0; i < 10; i++) {
    printf("random %d: %d\n", i, arr2[i]);
  }

  return 0;
}
