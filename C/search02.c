/* 이진탐색 */
#include <stdio.h>

int binarySearch(int* ary, int size, int target){
   int first=0, last=size, middle=0;

   while(first <= last){
     middle = (first + last) / 2;
     if(target == ary[middle]){
       printf("검색 값 : %d\n", ary[middle]);
       return 0;
     }
     else {  // middle 값은 +1, -1 해주는 것은 m>
       if(target > ary[middle]) first = middle+1;
       else last = middle-1;
     }
   }
}

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


void main(){
  int ary[] = {3, 5, 2, 4, 9, 8, 1};
  int size = (sizeof(ary)/sizeof(int));

  printf("정렬되기 전:");
  for(int i=0; i<size; i++){
    printf(" %d", ary[i]);
  }
  printf("\n");

  swap(ary, size);
  printf("정렬된 후 :");
  for(int i=0; i<size; i++){
     printf(" %d", ary[i]);
  }
  printf("\n");

  binarySearch(ary, size, 9);
}
