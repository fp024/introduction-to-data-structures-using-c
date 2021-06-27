/**
 * DBLinkedList2.c
 *
 * 문제 05-2 ADT 구현
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DBLinkedList2.h"


void ListInit(List* plist) {
    Node* headDummyNode = (Node*)malloc(sizeof(Node));
    Node* tailDummyNode = (Node*)malloc(sizeof(Node));

    if (headDummyNode == NULL || tailDummyNode == NULL) {
        assert(FALSE);
        return;
    }

    plist->head = headDummyNode;
    plist->tail = tailDummyNode;
    plist->cur = NULL;

    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->prev = plist->head;
    plist->tail->next = NULL;

    plist->numOfData = 0;
}


void LInsert(List* plist, Data data) {
    // 데이터 형이 기본은 int인데, remove시 실패시 반환값을 설정해주기 애매해서
    // 리스트의 조건을 양수 이상 입력받는 것으로 해둔다.
    if (data < 0) {
        assert(FALSE);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        assert(FALSE);
        return;
    }
    newNode->data = data;
    newNode->prev = plist->tail->prev;
    newNode->next = plist->tail;

    plist->tail->prev->next = newNode;
    plist->tail->prev = newNode;

    plist->cur = newNode;

    (plist->numOfData)++;
}


int LFirst(List* plist, Data* pdata) {
    if (plist->head->next == plist->tail) {
        return FALSE;
    }

    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List* plist, Data* pdata) {
    if (plist->cur->next == plist->tail) {
        return FALSE;
    }

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}


int LPrevious(List* plist, Data* pdata) {
    if (plist->cur->prev == plist->head) {
        return FALSE;
    }

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;

}



Data LRemove(List* plist) {
    if (plist->cur == NULL) {
        return -1;
    }

    Data removedData = plist->cur->data;

    Node* next = plist->cur->next;
    Node* prev = plist->cur->prev;

    prev->next = next;
    next->prev = prev;

    free(plist->cur);
    (plist->numOfData)--;
    
    if (next == plist->tail) {
        plist->cur = NULL;
    } else {
        plist->cur = next;
    }
    
    return removedData;
}


int LCount(List* plist) {
    return plist->numOfData;
}