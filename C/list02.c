#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
  int data;
  struct NODE* next;
}Node;

void main(){
  Node* head = (Node*)malloc(sizeof(Node));
  head->next = NULL;

  Node* node1 = (Node*)malloc(sizeof(Node));
  node1->data = 10;
  node1->next = NULL;

  head->next = node1;

  Node* node2 = (Node*)malloc(sizeof(Node));
  node2->data = 20;
  node2->next = NULL;

  node1->next = node2;

  Node* node3 = (Node*)malloc(sizeof(Node));
  node3->data = 30;
  node3->next = NULL;

  node2->next = node3;

  Node* curr = head->next;    // 첫번째 노드를 가리킴
  while(curr != NULL){
    printf("노드 data : %d\n", curr->data);
    curr = curr->next;
  }

  printf("head->next->data : %d\n", head->next->data);
  printf("node1->data : %d\n:", node1->data);

  free(head);
  free(node1);
  free(node2);
  free(node3);
}
