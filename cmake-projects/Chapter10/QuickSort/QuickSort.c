#include <stdio.h>
#include <assert.h>
#include "CommonUtils.h"
//
// 퀵 정렬
//

// 퀵 정렬 함수
typedef void QuickSortFunc(int arr[], int left, int right);

// 파티션 함수
typedef int PartitionFunc(int arr[], int left, int right);

/**
 * 파티션 함수
 *
 * @param arr       파티션 대상 배열
 * @param left      파티션 할 범위의 왼쪽 인덱스
 * @param right     파티션 할 범위의 오른쪽 인덱스
 * @return  제 자리를 찾은 pivot 의 인덱스
 */
int partition(int arr[], const int left, const int right) {
  // 범위의 중간값을 구해서 left와 중간값 인덱스의 값을 교환해둔다. 문제 10-1에 해당
  swap(arr, left, getMedianIndex(arr, left, right));
  int pivotValue = arr[left];
  int low = left + 1;
  int high = right;

  while (low <= high) {
    while (low <= right && pivotValue >= arr[low]) {
      low++;
    }

    while (high > left && pivotValue <= arr[high]) { // high >= left + 1 이 결국은 high > left와 동일해보여 변경했다.
      high--;
    }

    if (low < high) {
      swap(arr, low, high);
    }
  }
  swap(arr, left, high);
  return high;
}


void QuickSort(int arr[], int left, int right) {
  if (left < right) {
    int pivotIndex = partition(arr, left, right);

    QuickSort(arr, left, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, right);
  }
}

// 파티션 함수 동작 테스트 수행
void runPartition(PartitionFunc partitionFunc, int arr[], int length) {
  printf("파티션 전=> ");
  printArraySimple(arr, length);

  // 파티션 및 피못 값 찾기
  printf("pivot 값=> %d\n", partitionFunc(arr, 0, length - 1));

  printf("파티션 후=> ");
  printArraySimple(arr, length);
}

// 파티션 함수 동작 테스트
void testPartition() {
  int arr0[] = {5, 1, 3, 7, 9, 2, 4, 6, 8};
  runPartition(partition, arr0, sizeof(arr0) / sizeof(int));

  // 2개 짜리 배열 정렬하는 부분이 결국 partition while 문내의 조건들을 결정하는데 가장 중요했다.
  int arr2[] = {4, 3};
  runPartition(partition, arr2, sizeof(arr2) / sizeof(int));

}

// 정렬 테스트 수행
void runSort(QuickSortFunc sortFunc, int arr[], int length) {
  printf("정렬 전=> ");
  printArraySimple(arr, length);

  // 배열 arr의 전체 영역 정렬
  sortFunc(arr, 0, length - 1);

  printf("정렬 후=> ");
  printArraySimple(arr, length);
}

// 정렬 테스트
void testSort(QuickSortFunc sortFunc) {
  int arr0[] = {5, 1, 3, 7, 9, 2, 4, 6, 8};
  int length = sizeof(arr0) / sizeof(int);
  runSort(sortFunc, arr0, length);

  int arr1[] = {3, 3, 3};
  length = sizeof(arr1) / sizeof(int);
  runSort(sortFunc, arr1, length);

}


// 중간 값을 구하는 함수 동작 테스트
void testMedian() {
  int arr0[] = {5, 1, 3, 7, 9, 2, 4, 6, 8};
  int lastIndex = sizeof(arr0) / sizeof(int) - 1;
  assert(8 == getMedianIndex(arr0, 0, lastIndex));

  int arr1[] = {5, 1, 3};
  lastIndex = sizeof(arr1) / sizeof(int) - 1;
  assert(2 == getMedianIndex(arr1, 0, lastIndex));

  int arr2[] = {5, 1};
  lastIndex = sizeof(arr2) / sizeof(int) - 1;
  assert(0 == getMedianIndex(arr2, 0, lastIndex));
}


int main(void) {
  testPartition();
  testMedian();
  testSort(QuickSort);
  return 0;
}
