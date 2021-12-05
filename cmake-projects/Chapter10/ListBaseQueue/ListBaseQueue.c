/**
 * ListBaseQueue.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"


void QueueInit(Queue* pq) {
  // front와 rear가 가리킬 대상이 없으니 NULL로 초기화
  pq->front = NULL;
  pq->rear = NULL;
}


int QIsEmpty(Queue* pq) {
  // 연결리스트 기반의 큐가 비었다면 front는 NULL이다.
  if (pq->front == NULL) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}


void Enqueue(Queue* pq, Data data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->data = data;

  if (QIsEmpty(pq)) { // 첫번째 노드의 추가라면...
    pq->front = newNode;    // front와 rear 모두 newNode를 가리키게한다.
    pq->rear = newNode;
  }
  else { // 두번째 이후의 노드 추가라면...
    pq->rear->next = newNode;   // 마지막 노드의 다음을 newNode를 가리키게하고.
    pq->rear = newNode;         // rear를 newNode를 가리키게한다.
  }
}


Data Dequeue(Queue* pq) {
  if (QIsEmpty(pq)) {
    printf("큐가 비어있습니다. 꺼낼 것이 없습니다.");
    exit(-1);
  }

  Node* delNode = pq->front;  // 삭제할 노드의 주소 값 저장
  Data data = delNode->data;  // 삭제할 노드가 지닌 값 저장
  pq->front = delNode->next;  // 삭제할 노드의 다음노드를 front가 가리킴

  free(delNode);
  return data;
}


Data QPeek(Queue* pq) {
  if (QIsEmpty(pq)) {
    printf("큐가 비어있습니다. 조회할 것이 없습니다.");
    exit(-1);
  }
  return pq->front->data;
}
