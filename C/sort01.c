#include <stdio.h>

extern void printfAll(int*, int);
extern void swap(int*, int);

void main(){
  int ary[] = {9, 4, 8, 15, 3, 7, 2, 1};
  int size = (sizeof(ary)/sizeof(int));

  swap(ary, size);
  printfAll(ary, size);
}
