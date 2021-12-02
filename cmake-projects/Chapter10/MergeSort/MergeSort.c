#include <stdio.h>
#include <stdlib.h>
#include "CommonUtils.h"
//
// 병합 정렬
// 도식도만 보고 만들 수 있어야 할 것 같은데... 아직은 힘들다.
//

// 병합 정렬 함수
typedef void MergeSortFunc(int arr[], int left, int right);

/**
 * 좌우 영역 병합
 *
 * @param arr       병합 대상 배열
 * @param left      왼쪽 인덱스
 * @param mid       중간 인덱스
 * @param right     오른쪽 인덱스
 */
void MergeTwoArea(int arr[], int left, int mid, int right) {
  // 병합할 두 영역의 첫번째 위치정보 fIdx, rIdx
  int fIdx = left;
  int rIdx = mid + 1;
  int i;

  // 병합 한 결과를 담을 sortArr의 동적 할당.
  int *sortArr = (int *) malloc(sizeof(int) * right + 1);
  // 정렬된 배열에 사용할 인덱스
  int sIdx = left;

  while (fIdx <= mid && rIdx <= right) {
    if (arr[fIdx] <= arr[rIdx]) {
      sortArr[sIdx] = arr[fIdx++];
    } else {
      sortArr[sIdx] = arr[rIdx++];
    }
    sIdx++;
  }

  if (fIdx > mid) { // 우측 영역에 남은 내용 정렬된 배열 뒷부분에 그대로 채워넣기
    for (i = rIdx; i <= right; i++, sIdx++) {
      sortArr[sIdx] = arr[i];
    }
  } else {    // 좌측 영역에 남은 내용 정렬된 배열 뒷부분에 그대로 채워넣기
    for (i = fIdx; i <= mid; i++, sIdx++) {
      sortArr[sIdx] = arr[i];
    }
  }

  // 현재 병합에서 완성된 정렬된 배열을 원래 배열로 복사
  for (i = left; i <= right; i++) {
    arr[i] = sortArr[i];
  }

  free(sortArr);
}


/**
 * 병합 정렬
 *
 * Clang-Tidy에서 재귀가 있으면 무조건 경고를 노출하는 것 같다.
 * Clang-Tidy: Function 'MergeSort' is within a recursive call chain
 *
 *
 * @param arr   정렬 대상 배열
 * @param left  정렬 대상의 왼쪽 범위
 * @param right 정렬 대상의 오른쪽 범위
 */
void MergeSort(int arr[], int left, int right) {
  int mid;

  if (left < right) {
    // 중간 지점 계산
    mid = (left + right) / 2;

    // 둘로 나눠서 각각을 정렬
    MergeSort(arr, left, mid);        // left ~ mid에 위치한 데이터 정렬
    MergeSort(arr, mid + 1, right);    // mid + 1 ~ right에 위치한 데이터 정렬

    // 정렬된 두 배열을 병합
    MergeTwoArea(arr, left, mid, right);
  }
}


void testSort(MergeSortFunc sortFunc) {
  int arr[] = {3, 2, 4, 1, 7, 6, 5};
  int length = sizeof(arr) / sizeof(int);

  printf("정렬 전=> ");
  printArraySimple(arr, length);

  // 배열 arr의 전체 영역 정렬
  sortFunc(arr, 0, length - 1);

  printf("정렬 후=> ");
  printArraySimple(arr, length);
}


int main(void) {
  testSort(MergeSort);
  return 0;
}
