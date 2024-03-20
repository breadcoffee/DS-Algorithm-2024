#include <stdio.h>

void swap(int* ary, int size){
  int temp = 0;
   for(int i=0; i<size; i++){
      for(int j=0; j<size; j++){
        if(ary[i]<ary[j]){
          temp = ary[i];
          ary[i] = ary[j];
          ary[j] = temp;
        }
      }
    }
}