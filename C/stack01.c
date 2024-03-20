/* 배열로 구현 */
#include <stdio.h>

#define STACK_SIZE 10

int stack[STACK_SIZE];
int top = -1;

void push(int data);
int pop();
int isFull();
int isEmpty();

void push(int data){
  if(isFull()){
    printf("stack overflow!!\n");
    return;
  }
  stack[++top] = data;
}

int pop(){
  if(isEmpty()){
    printf("stack underflow\n");
    return -1;
  }
  return stack[top--];
}

int isFull(){
  if (top == STACK_SIZE-1)
    return 1;
  return 0;
}

int isEmpty(){
  if (top <= -1)
    return 1;
  return 0;
}

void main(){
  push(3);
  push(5);
  push(10);

  printf("pop: %d\n", pop());
}
