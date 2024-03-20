#include <stdio.h>

void main(){
  int num;
  printf("원하는 피라미드 단 수 입력 : ");
  scanf("%d", &num);

  for(int i=0; i<num; i++){
    for(int j=(num-2); j>=i; j--){
      printf(" ");
    }
    for(int k=0; k<=(i*2); k++){
      printf("*");
    }
    printf("\n");
  }
  printf("\n");
}