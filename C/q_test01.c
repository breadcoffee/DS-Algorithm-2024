#include <stdio.h>

void main(){
  int ary[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int queue[20];
  int front = 0, rear = 0;
  int size = sizeof(ary)/sizeof(int);

  for (rear; rear<size; rear++){
    queue[rear] = ary[rear];
  }

  for (front; front<rear; front++){
    printf("%d\n", queue[front]);
  }
}
