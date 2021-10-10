/**
 * PriorityQueue.h
 */
#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "EnhancedHeap.h"

typedef Heap PQueue;
typedef HData PQData;

/**
 * 우선순위 큐 초기화
 *
 * @param ph 큐 주소
 * @param pc 사용자 정의 우선순위 비교 함수
 */
void PQueueInit(PQueue* ppq, PriorityComp pc);


/**
 * 우선순위 큐가 비었는지 확인
 *
 * @param ph 큐 주소
 * @return 비었을 경우 TRUE(1), 그렇지 않을 경우 FALSE(0)
 */
int PQIsEmpty(PQueue* ppq);


/**
 * 우선순위 큐에 데이터 삽입
 *
 * @param ph    큐 주소
 * @param data  데이터
 */
void PEnqueue(PQueue* ppq, PQData data);


/**
 * 우선순위가 가장 높은 데이터 삭제
 * 
 *  (참고) 큐가 비었을 때의 예외 처리가 안되어있다.
 *
 * @param ph 큐 주소
 * @return 삭제된 우선순위가 가장 높은 데이터
 */
PQData PDequeue(PQueue* ppq);

#endif