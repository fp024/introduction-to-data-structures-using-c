#include <stdio.h>
#include "ListBaseQueue.h"
#include "CommonUtils.h"
//
// 기수 정렬
//

// 기수 정렬 함수
typedef void RadixSortFunc(int arr[], int arrayLength, int maxElementLength);

#define BUCKET_SIZE 10

/**
 * 기수 정렬
 * @param arr                   정렬할 배열
 * @param arrayLength           정렬할 배열의 길이
 * @param maxElementLength      배열의 요소중 가장 긴 요소의 자릿수
 */
void RadixSort(int arr[], int arrayLength, int maxElementLength) {

  // 버킷 배열
  Queue buckets[BUCKET_SIZE];

  // 버킷 초기화
  for (int bi = 0; bi < BUCKET_SIZE; bi++) {
    Queue q;
    QueueInit(&q);
    buckets[bi] = q;
  }

  // 자릿수 마다 반복
  for (int di = 0, radix = 1; di < maxElementLength; di++, radix *= 10) {

    printf("=== 버킷에 값 넣기 ===\n");
    // 버킷에 값 넣기
    for (int i = 0; i < arrayLength; i++) {
      int bi = (arr[i] / radix) % 10;
      printf("bi: %d, arr[%d]:%d\n", bi, i, arr[i]);
      Enqueue(&buckets[bi], arr[i]);
    }

    printf("=== 버킷에 값 빼기 ===\n");
    // 버킷에서 다시 순서대로 빼서 배열에 다시 넣기
    for (int bi = 0, i = 0; bi < BUCKET_SIZE; bi++) {

      // 여기 왜 while로 해야할까? 여기 if로 하고 있어서 틀리고 있었는데... => 인덱스가 같은 곳에 들어간 경우가 있어서 그렇다.
      // 같은 인덱스로 처리되더라도 큐에 먼저 들어같 것이 우선순위가 높게 처리하는게 자연스럽게 된다.
      // 예를 들어 1의 자리수의 큐에 먼저 들어간 순서대로 다시 꺼내므로...
      while (!QIsEmpty(&buckets[bi])) {
        arr[i] = Dequeue(&buckets[bi]);
        printf("arr[%d]:%d\n", i, arr[i]);
        i++;
      }

    }
  }
}


// 정렬 테스트 수행
void runSort(RadixSortFunc sortFunc, int arr[], int arrayLength, int maxElementLength) {
  printf("정렬 전=> ");
  printArraySimple(arr, arrayLength);

  // 배열 arr의 전체 영역 정렬
  sortFunc(arr, arrayLength, maxElementLength);

  printf("정렬 후=> ");
  printArraySimple(arr, arrayLength);
}

// 정렬 테스트
void testSort(RadixSortFunc sortFunc) {
  int arr0[] = {13, 212, 14, 7141, 10987, 6, 15};
  int length = sizeof(arr0) / sizeof(int);
  runSort(sortFunc, arr0, length, 5);
}


int main(void) {
  testSort(RadixSort);
  return 0;
}
