#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
  int data;
  struct NODE* next;
}Node;

typedef struct {
  Node* head;
}headNode;

headNode* createHeadNode(){
  headNode* head = (headNode*)malloc(sizeof(headNode));
  if(head != NULL){
    return head;
  }
}

// 새로운 노드가 맨 앞으로
void pre_addNode(headNode* pnode, int _data){
  Node* tnode = (Node*)malloc(sizeof(Node));
  if(tnode != NULL){
    tnode->data = _data;
    tnode->next = pnode->head;

    pnode->head = tnode;
  }
}

// 새로운 노드가 맨 뒤로
void rear_addNode(headNode* pnode, int _data){
  Node* tnode1 = (Node*)malloc(sizeof(Node));
  if(tnode1 != NULL){
    tnode1->data = _data;
    tnode1->next = NULL;
    if(pnode->head == NULL) pnode->head = tnode1;
    else{
      Node* tnode2 = pnode->head;
      while(tnode2->next != NULL){
        tnode2 = tnode2->next;
      }
      tnode2->next = tnode1;
    }
  }
}

// 노드 출력
void showNode(headNode* pnode){
  Node* tnode = pnode->head;
  while(tnode != NULL){
    printf("데이터 : %d\n", tnode->data);
    tnode = tnode->next;
  }
}

void freeNode(headNode* pnode){
  Node* tnode = (Node*)malloc(sizeof(Node));
  tnode = pnode->head;
  while(tnode != NULL){
    printf("소멸 데이터 : %d\n", tnode->data);
    pnode->head = tnode->next;
    free(tnode);
    tnode = pnode->head;
  }
}

void searchNode(headNode* pnode, int _data){
  Node* tnode = pnode->head;
  while(tnode != NULL){
    if(tnode->data == _data){
      printf("검색된 데이터: %d\n", tnode->data);
    }
    tnode = tnode->next;
  }
}

void main(){
  headNode* newhead = createHeadNode();

  /*Node* tr = (Node*)malloc(sizeof(Node));
  tr = newhead->head;
  tr->data = 10;      // 안됨
  printf("%d\n", tr->data);*/

  pre_addNode(newhead, 10);
  pre_addNode(newhead, 20);
  pre_addNode(newhead, 30);
  pre_addNode(newhead, 40);

  rear_addNode(newhead, 9);
  rear_addNode(newhead, 8);
  rear_addNode(newhead, 7);

  searchNode(newhead, 30);

  showNode(newhead);
  freeNode(newhead);

  free(newhead);
}