/**
 * SimpleHeap.c
 */
#include "SimpleHeap.h"

void HeapInit(Heap* ph) {
    ph->numOfData = 0;
}


int HIsEmpty(Heap* ph) {
    if (ph->numOfData == 0) {
        return TRUE;
    }
    else {
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
int GetHiPriChildIDX(Heap* ph, int idx) {
    // Heap의 마지막 노드 인덱스 번호보다 계산된 자식 노드의 인덱스 번호가 크다면, 
    // 현재 검사하는 부모노드는 자식이 없는 경우이다.
    if (GetLChildIDX(idx) > ph->numOfData) {
        return 0;
    }
    else if (GetLChildIDX(idx) == ph->numOfData) { // 부모노드가 왼쪽 자식노드만 가지고 있는 경우
        return GetLChildIDX(idx);
    }
    else { // 부모노드가 왼쪽, 오른쪽 노드 둘다 가지고 있는 경우
        // 우선순위가 1과 2가 있을 때... 1이 더 우선순위가 높다고 생각한다. (최소 힙)
        if (ph->heapArr[GetLChildIDX(idx)].pr < ph->heapArr[GetRChildIDX(idx)].pr) {
            return GetLChildIDX(idx);
        }
        else {
            return GetRChildIDX(idx);
        }
    }

}



void HInsert(Heap* ph, HData data, Priority pr) {
    int idx = ph->numOfData + 1;
    // 구조체의 배열이고, 구조체의 포인터를 저장하지 않으므로 malloc()으로 생성하지 않은 것 같다.
    HeapElem nelem = { pr, data };

    while (idx != 1) {
        if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else {
            break;
        }
    }
    // 여기까지... 신규 노드가 들어갈 위치를 찾은 상태가 되었고, 옮겨야될 노드들은 전부 아래로 밀어내기가 된 상태이다.
   /*
       - 제시된 트리 (2를 추가한다면, 데이터2,우선순위2)
                    1
                  /   \
                 3     7
                / \   / \
               4  9  12  13
              / 
             15  

        - while 실행 이후
                    1
                  /   \
                 3(*)  7
                / \   / \
               3  9  12  13
              / \
             15  4

        - 이후 *로 마킹한 부분에 신규노드를 할당함.
    */
    // 신규 노드를 제 위치에 할당
    ph->heapArr[idx] = nelem;
    ph->numOfData += 1;
}


HData HDelete(Heap* ph) {
    HData retData = (ph->heapArr[1]).data;  // 반환을 위한 삭제할 데이터 저장 
    HeapElem lastElem = ph->heapArr[ph->numOfData]; // 힙의 마지막 노드 저장

    // 최종적으로 마지막 노드를 저장해야할 위치정보가 담김
    int parentIdx = 1; // 루트 노드부터 시작
    int childIdx;

    // 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
    while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
        if (lastElem.pr <= ph->heapArr[childIdx].pr) { // 마지막 노드와 우선순위 비교 (비교이 대상이 삭제 예정인 루트가 아니라 마지막 노드와 비교한다.)
            break;  // 마지막 노드의 우선 순위가 높으면 탈출
        }

        // 마지막 노드보다 우선순위가 높으니, 비교대상 노드의 위치를 한레벨 올림 (실제로 올림)
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];

        parentIdx = childIdx;  // 마지막 노드가 저장될 위치정보를 한 레벨 내림 (실제로 내리지 않고 위치 정보만 갱신)
    }

    // 트리가 아래와 같은 상태에서 위의 반복문이 끝났다면...  (노드의 데이터를 우선 순위라고 간단하게 생각하자.)
    /*
       - 제시된 트리
                    1
                  /   \
                 3     7
                / \   / \
               4  9  12  13
              / \
             15  8

       - while 반복 이후 트리 변화
                   3[1]
                /       \
             4[2]       7[3]
            /    \       /   \
          4[4]  9[5]   12[6] 13[7]
          /  \
      15[8]  8[9]

         - parentIdx = 4, 마지막 노드가 들어갈 인덱스
         - 탈출 조건에서 마지막 요소가 현재 검사중인 자식요소와 우선순위가 같거나 작으면 반복을 탈출함
           마지막은 교환이 안일어 났음.
    */

    ph->heapArr[parentIdx] = lastElem;  // 마지막 노드 최종 저장
    ph->numOfData -= 1;

    return retData;
}
