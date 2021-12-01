/**
 * EnhancedHeap.c
 */
#include "EnhancedHeap.h"

void HeapInit(Heap *ph, PriorityComp pc) {
  ph->numOfData = 0;
  ph->comp = pc;
}


int HIsEmpty(Heap *ph) {
  if (ph->numOfData == 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}


/**
 * 부모 노드의 인덱스 값 반환
 *
 * @param idx 노드 인덱스
 * @return 전달 받은 노드의 부모 노드 인덱스
 */
int GetParentIDX(int idx) {
  return idx / 2;
}


/**
 * 왼쪽 자식 노드의 인덱스 값 반환
 *
 * @param idx 노드 인덱스
 * @return 전달 받은 노드의 왼쪽 자식 인덱스
 */
int GetLChildIDX(int idx) {
  return idx * 2;
}


/**
 * 오른쪽 자식 노드의 인덱스 값 반환
 *
 * @param idx 노드 인덱스
 * @return 전달 받은 노드의 오른쪽 자식 인덱스
 */
int GetRChildIDX(int idx) {
  return GetLChildIDX(idx) + 1;
}


/**
 * 두 개의 자식 노드 중 높은 우선 순위의 자식 노드 인덱스 값 반환
 *
 * @param ph    힙 주소
 * @param idx   부모 인덱스 번호
 * @return 높은 우선 선위의 자식 인덱스 값, 0일경우 자식이 없는 노드를 검사한 경우가 됨.
 */
int GetHiPriChildIDX(Heap *ph, int idx) {
  // Heap의 마지막 노드 인덱스 번호보다 계산된 자식 노드의 인덱스 번호가 크다면,
  // 현재 검사하는 부모노드는 자식이 없는 경우이다.
  if (GetLChildIDX(idx) > ph->numOfData) {
    return 0;
  } else if (GetLChildIDX(idx) == ph->numOfData) { // 부모노드가 왼쪽 자식노드만 가지고 있는 경우
    return GetLChildIDX(idx);
  } else { // 부모노드가 왼쪽, 오른쪽 노드 둘다 가지고 있는 경우
    if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) > 0) {
      return GetLChildIDX(idx);
    } else {
      return GetRChildIDX(idx);
    }
  }
}


void HInsert(Heap *ph, HData data) {
  int idx = ph->numOfData + 1;

  while (idx != 1) {
    if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {
      ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
      idx = GetParentIDX(idx);
    } else {
      break;
    }
  }

  ph->heapArr[idx] = data;
  ph->numOfData += 1;
}


HData HDelete(Heap *ph) {
  HData retData = (ph->heapArr[1]);
  HData lastElem = ph->heapArr[ph->numOfData];

  int parentIdx = 1;
  int childIdx;

  while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
    if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) { // 마지막 노드와 우선순위 비교 (비교이 대상이 삭제 예정인 루트가 아니라 마지막 노드와 비교한다.)
      break;
    }

    ph->heapArr[parentIdx] = ph->heapArr[childIdx];

    parentIdx = childIdx;
  }

  ph->heapArr[parentIdx] = lastElem;
  ph->numOfData -= 1;

  return retData;
}