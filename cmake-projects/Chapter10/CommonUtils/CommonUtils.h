//
// 사용자 정의 단순 공통 구현 함수 라이브러리 프로젝트
//
// 타입에 대해서 제네릭처럼 가능하게 작성하면 좋을 수 있는데,
// 일단은 int 기준으로 만들고, 우선 책 내용에 집중하자!
//

#ifndef CHAPTER10_COMMON_UTILS_H
#define CHAPTER10_COMMON_UTILS_H

/**
 * 배열 내용 출력
 * @param array     배열
 * @param length    배열의 길이
 */
void printArray(int array[], int length);

/**
 * 배열 내용 단순하게 한줄 출력
 * @param array     배열
 * @param length    배열의 길이
 */
void printArraySimple(int array[], int length);

/**
 * 배열의 특정 인덱스 값을 서로 스왑
 * @param array     배열
 * @param aIndex    a 인덱스
 * @param bIndex    b 인덱스
 */
void swap(int array[], int aIndex, int bIndex);


#endif //CHAPTER10_COMMON_UTILS_H
