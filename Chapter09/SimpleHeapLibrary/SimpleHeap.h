/**
 * SimpleHeap.h
 */
#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE    1
#define FALSE   0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;


typedef struct _heapElem {
    Priority pr;    // 이 값이 작을 수록 높은 우선순위
    HData data;
} HeapElem;

typedef struct _heap {
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

/**
 * 힙 초기화
 *
 * @param ph 힙 주소
 */
void HeapInit(Heap* ph);


/**
 * 힙이 비었는지 확인
 *
 * @param ph 힙 주소
 * @return 비었을 경우 TRUE(1), 그렇지 않을 경우 FALSE(0)
 */
int HIsEmpty(Heap* ph);


/**
 * 힙에 데이터 삽입
 *
 * @param ph    힙 주소
 * @param data  데이터
 * @param pr    우선 순위
 */
void HInsert(Heap* ph, HData data, Priority pr);


/**
 * 힙의 데이터 삭제 (우선순위가 가장 높은 루트 노드 삭제)
 *
 * @param ph 힙 주소
 * @return 삭제된 루트노드 데이터
 */
HData HDelete(Heap* ph);


#endif // !__SIMPLE_HEAP_H__
