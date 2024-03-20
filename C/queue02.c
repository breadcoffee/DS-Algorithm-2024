/* 연결리스트를 이용한 큐 자료구조 */
#include <stdio.h>
#include <stdlib.h>
#define QSIZE 10

typedef struct {
  int front;
  int rear;
  char queue[QSIZE];
}queue;

// 동적할당
queue* create(){
  queue* tqueue = (queue*)malloc(sizeof(queue));
  if(tqueue != NULL){
    tqueue->front = -1;
    tqueue->rear = -1;
    return tqueue;
  }
}

int isEmpty(queue* pq){
  if(pq->front == pq->rear)
    return 1;
  return 0;
}

int isFull(queue* pq){
  if(pq->rear == QSIZE - 1)
    return 1;
  return 0;
}

void enqueue(queue* pqueue, char word){
  if(isFull(pqueue)){
    printf("QUEUE Overflow!!\n");
    return;
  }
  pqueue->queue[++pqueue->rear] = word;
}

char dequeue(queue* pqueue){
  if(isEmpty(pqueue)){
    printf("QUEUE Underflow\n");
    return -1;
  }
  return pqueue->queue[++pqueue->front];
}

void printfQueue(queue* pq){
  int curr = pq->front;
  while(curr != pq->rear){
    printf("%c\n", pq->queue[++curr]);
  }
}
void main(){
  queue* newqueue = create();
  enqueue(newqueue, 'A');
  enqueue(newqueue, 'B');
  enqueue(newqueue, 'C');
  printf("dequeue: %c\n", dequeue(newqueue));
  dequeue(newqueue);
  printfQueue(newqueue);
}