/**
 * Deque.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq) {
    pdeq->head = NULL;
    pdeq->tail = NULL;
}


int DQIsEmpty(Deque* pdeq) {
    return (pdeq->head == NULL) ? TRUE : FALSE;
}


/**
 * 노드에 데이터를 넣어 생성한다.
 * @param 데이터
 * @return 노드 포인터
 */
Node* createNode(Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void DQAddFirst(Deque* pdeq, Data data) {
    Node* newNode = createNode(data);
    if (DQIsEmpty(pdeq)) {
        pdeq->tail = newNode;
    }
    else {
        pdeq->head->prev = newNode;
        newNode->next = pdeq->head;
    }
    pdeq->head = newNode;
}



void DQAddLast(Deque* pdeq, Data data) {
    Node* newNode = createNode(data);

    if (DQIsEmpty(pdeq)) {
        pdeq->head = newNode;
    }
    else {
        newNode->prev = pdeq->tail;
        pdeq->tail->next = newNode;
    }
    pdeq->tail = newNode;
}


Data DQRemoveFirst(Deque* pdeq) {
    if (DQIsEmpty(pdeq)) {
        printf("Deque가 비어있습니다. 삭제할 것이 없습니다.\n");
        exit(-1);
    }

    Node* delNode = pdeq->head;
    Data data = delNode->data;

    pdeq->head = delNode->next;

    free(delNode);

    if (pdeq->head == NULL) {
        pdeq->tail = NULL;
    }
    else {
        pdeq->head->prev = NULL;
    }
    return data;
}



Data DQRemoveLast(Deque* pdeq) {
    if (DQIsEmpty(pdeq)) {
        printf("Deque가 비어있습니다. 삭제할 것이 없습니다.\n");
        exit(-1);
    }

    Node* delNode = pdeq->tail;
    Data data = delNode->data;

    pdeq->tail = delNode->prev;
    free(delNode);

    if (pdeq->tail == NULL) {
        pdeq->head = NULL;
    }
    else {
        pdeq->tail->next = NULL;
    }

    return data;
}



Data DQGetFirst(Deque* pdeq) {
    if (DQIsEmpty(pdeq)) {
        printf("Deque가 비어있습니다. 조회할 것이 없습니다.\n");
        exit(-1);
    }

    return pdeq->head->data;
}



Data DQGetLast(Deque* pdeq) {
    if (DQIsEmpty(pdeq)) {
        printf("Deque가 비어있습니다. 조회할 것이 없습니다.\n");
        exit(-1);
    }

    return pdeq->tail->data;
}