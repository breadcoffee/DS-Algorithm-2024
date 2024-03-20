/* 연결리스트로 구현 */
#include <stdio.h>

#define STACK_SIZE 10

typedef struct STACK{
  int buf[STACK_SIZE];
  int top;
}stack;

int isFull(stack*);
int isEmpty(stack*);
void push(stack*, int);
int pop(stack*);

void main(){
  stack sk;
  sk.top = -1;

  push(&sk, 10);
  push(&sk, 20);
  push(&sk, 30);

  printf("%d\n", pop(&sk));
  printf("%d\n", pop(&sk));
  printf("%d\n", sk.buf[2]);
}

int isFull(stack* pst){
  if(pst->top == STACK_SIZE-1)
    return 1;
  return 0;
}

int isEmpty(stack* pst){
  if(pst->top <= -1)
    return 1;
  return 0;
}

void push(stack* pst, int _data){
  if(isFull(pst)){
    printf("stack overflow!!\n");
    return;
  }
  pst->buf[++pst->top] = _data;
}

int pop(stack* pst){
  if(isEmpty(pst)){
    printf("stack underflow\n");
    return 0;
  }
  return pst->buf[pst->top--];
}
