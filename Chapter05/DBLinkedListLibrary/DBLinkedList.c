#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DBLinkedList.h"


void ListInit(List* plist) {
    plist->head = NULL;
    plist->cur = NULL;
    plist->numOfData = 0;
}



void LInsert(List* plist, Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));    // 새 노드 생성

    if (newNode == NULL) {
        assert(FALSE);
        return;
    }

    newNode->data = data;

    // 아래 문자에서 plist->head는 NULL이다!
    newNode->next = plist->head;    // 새 노드의 next를 NULL로 초기화

    if (plist->head != NULL) {
        plist->head->prev = newNode;
    }

    newNode->prev = NULL;           // 새 노드의 prev를 NULL로 초기화
    plist->head = newNode;          // 포인터 변수 head가 새노드를 가리키게 함.


    (plist->numOfData)++;
}




void LInsertTail(List* plist, Data data) {
    Node* newNode = (Node*)malloc(sizeof(Node));    // 새 노드 생성

    if (newNode == NULL) {
        assert(FALSE);
        return;
    }

    newNode->data = data;   // 새 노드에 데이터 저장
    newNode->next = NULL;
    newNode->prev = NULL;

    if (plist->head == NULL) {
        plist->head = newNode;
        plist->cur = newNode;
    }
    else {
        while (plist->cur->next != NULL) {
            plist->cur = plist->cur->next;
        }

        plist->cur->next = newNode;
        newNode->prev = plist->cur;

        plist->cur = newNode;
    }

    (plist->numOfData)++;
}



int LFirst(List* plist, Data* pdata) {
    if (plist->head == NULL) {
        return FALSE;
    }

    plist->cur = plist->head;

    *pdata = plist->cur->data;
    return TRUE;
}



int LNext(List* plist, Data* pdata) {
    if (plist->head == NULL || plist->cur->next == NULL) {
        return FALSE;
    }

    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;

    return TRUE;
}


int LPrevious(List* plist, Data* pdata) {
    if (plist->head == NULL || plist->cur->prev == NULL) {
        return FALSE;
    }

    plist->cur = plist->cur->prev;

    *pdata = plist->cur->data;

    return TRUE;
}


Data LRemove(List* plist) {
    // 1. 데이터가 없을 때.
    if (plist->head == NULL) {
        return -1;
    }

    Node* toRemoveNode = plist->cur;
    Data toRemoveData = toRemoveNode->data;

    // 2. 첫번째 노드를 지울 때..
    if (plist->head == toRemoveNode) {
        plist->head = toRemoveNode->next;

        if (plist->head != NULL && plist->head->next != NULL) {
            plist->head->next->prev = plist->head;
        }
        plist->cur = plist->head;
    }
    else {
        // 3. 중간 또는 마지막 요소를 지울 경우...     
        if (toRemoveNode->next != NULL) { // 마지막 요소를 지울 경우...
            toRemoveNode->next->prev = toRemoveNode->prev;
        }

        toRemoveNode->prev->next = toRemoveNode->next;
        plist->cur = toRemoveNode->prev;
    }

    free(toRemoveNode);

    (plist->numOfData)--;
    return toRemoveData;
}


int LCount(List* plist) {
    return plist->numOfData;
}
