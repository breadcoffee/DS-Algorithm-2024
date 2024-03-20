/* 연결리스트를 이용한 큐 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
  int data;
  struct NODE* next;
}Node;

typedef struct {
  Node* rear;
  Node* front;
}linkQ;

linkQ* createLinkQ();
void enqueue(linkQ*, int);
void dequeue(linkQ*);
void printfQ(linkQ*);
void freeAllQ(linkQ*);

void main(){
  linkQ* lq = createLinkQ();

  enqueue(lq, 10);
  enqueue(lq, 20);
  enqueue(lq, 30);
  enqueue(lq, 40);
  enqueue(lq, 50);

  printfQ(lq);

  dequeue(lq);
  dequeue(lq);

  freeAllQ(lq);
}

linkQ* createLinkQ(){
  linkQ* lq = (linkQ*)malloc(sizeof(linkQ));
  if(lq != NULL){
    lq->front = NULL;
    lq->rear = NULL;
    return lq;
  }
}

void enqueue(linkQ* lq, int data){
  Node* tq = (Node*)malloc(sizeof(Node));

  if(lq->front == NULL){
    tq->data = data;
    tq->next = NULL;
    lq->front = tq;
  }
  else{
    tq->data = data;
    tq->next = NULL;
    lq->rear = tq;
    tq = lq->front;
    while(tq->next != NULL){
      tq = tq->next;
    }
    tq->next = lq->rear;
  }
}

void printfQ(linkQ* lq){
  Node* tq = lq->front;
  while(tq != NULL){
    printf("데이터: %d\n", tq->data);
    tq = tq->next;
  }
}

void dequeue(linkQ* lq){
  Node* tq = lq->front;
  printf("삭제된 데이터: %d\n", tq->data);

  lq->front = tq->next;
  free(tq);
}

void freeAllQ(linkQ* lq){
Node* tq;
  while(lq->front != NULL){
    tq = lq->front;
    printf("남은 데이터 삭제: %d\n", tq->data);
    lq->front = tq->next;
    free(tq);
  }
}