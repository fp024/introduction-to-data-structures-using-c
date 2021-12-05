# Chapter 10 정렬(Sorting)

## 10-1 단순한 정렬 알고리즘

### 버블 정렬(Bubble Sort): 이해와 구현

* 정렬 순위가 가장 낮은, 제일 큰 값을 맨 뒤로 보내기

### 버블 정렬(Bubble Sort): 성능 평가

* 비교 횟수가 등차수열로 나타남
  * ( n - 1) + ( n - 2 ) + ... + 2 + 1
  * n ( n - 1 ) / 2 = ( n<sup>2</sup> - n ) / 2 => O( n<sup>2</sup> )

### 선택 정렬(Selection Sort): 이해와 구현

* 정렬 순서상 가장 앞서는 것을 선택해서 가장 왼쪽으로 이동
* 원래 그 자리에 있던 데이터는 빈자리에 둠.

### 선택 정렬(Selection Sort): 성능 평가

* 비교 횟수 기준으로 보면 버블정렬과 같다. => ( n - 1) + ( n - 2 ) + ... + 2 + 1 => O( n<sup>2</sup> )

* 대입연산을 바깥쪽 for문에 둬서 대입 횟수를 줄일 수도 있지만, 버블정렬은 최선의 경우(정렬된 경우)라면 대입연산이 한번도 일어나지 않는다.

* 버블이나 선택이나 우열을 가리는 것에는 의미가 없음.

  

### 삽입 정렬(Insertion Sort): 이해와 구현

* 삽입할 위치를 발견하고 데이터를 한칸씩 뒤로 밀기
* 데이터를 한칸씩 뒤로 밀면서 삽입위치 찾기

### 삽입 정렬(Insertion Sort): 성능 평가

* 정렬 대상 대부분이 이미 정렬되어있는 경우 매우 빠르게 동작

* 최악의 경우라면 내부루프에서 항상 대입연산이 일어나므로 O(n<sup>2</sup>) 이다.

  


## 10-2 복잡하지만 효율적인 정렬 알고리즘

### 힙 정렬(Heap Sort): 이해와 구현

* 힙의 특성
  * 힙의 루트 노드에 저장된 값이 가장 우선순위가 크다.
  * 힙의 루트 노드에 저장됨 값이 정렬 순서상 가장 앞선다.

### 힙 정렬(Heap Sort): 성능 평가

* 삽입 삭제에 대한 시간 복잡도 => O(2log<sub>2</sub>n) => O(log<sub>2</sub>n)
  * 힙 데이터 저장 시간 복잡도
    * O(log<sub>2</sub>n)
  * 힙 데이터 삭제 시간 복잡도
    * O(log<sub>2</sub>n)
* n개를 정렬하는 과정과 함깨 생각할 때.
  * O(nlog<sub>2</sub>n)



### 병합 정렬(Merge Sort): 이해와 구현

* 분할 정복 기법 3단계
  1. 분할 (Divide) : 해결이 용이한 단계까지 문제를 분할해 나감
  2. 정복 (Conquer): 해결이 용이한 단계까지 문제를 해결
  3. 결합 (Combine): 분할해서 해결한 결과를 결합해서 마무리 한다.

* 분할을 어디까지 할까?  

  데이터가 2개가 아닌 1개가 남을 때까지 진행

* 분할의 과정에서 하나씩 구분이 될 때까지 둘로 나누는 과정을 반복하는 이유?  

  재귀적 처리를 위해



### 병합 정렬(Merge Sort): 성능 평가

* 비교 연산 관점
  * 정렬의 대상이 데이터 수가 n개 일 때, 각 병합으 ㅣ단계마다 최대 n번의 비교연산이 진행됨
    * O(nlog<sub>2</sub>n)

* 데이터 이동 관점
  * 비교연산 횟수의 두배에 해당하는 이동연산 발생
    * 임시배열에서 데이터를 병합하는 과정에서 한번
    * 임시배열에서 저장된 데이터를 전부 원위치로 옮기는 과정에서 한번
  * O(2nlog<sub>2</sub>n) -> O(nlog<sub>2</sub>n)

* 배열 정렬시 임시 메모리가 필요하다는 단점이 있으나 연결리스트일 경우 단점이 되지 않음.



### 퀵 정렬(Quick Sort): 이해와 구현

* 사용 변수 의미
  * left: 정렬 대상의 가장 왼쪽 지점을 가리킴
  * right: 정렬 대상의 가장 오른쪽 지점을 가리킴
  * pivot: 정렬을 진행 하는데 필요한 기준점
  * low: 피벗을 제외한 가장 왼쪽에 위치한 지점을 가리킴
  * high: 피벗을 제외한 가장 오른쪽에 위치한 지점을 가리킴

* low와 high의 이동
  * low의 오른쪽 이동: 피벗보다 정렬의 우선순위가 낮은(큰 값) 데이터를 만날때까지.
  * high의 왼쪽 이동: 피벗보다 우선순위가 높은(작은 값) 데이터를 만날때까지.
  
* low와 high의 이동은 완전히 별개임.

  

### 퀵 정렬(Quick Sort): 성능 평가

* 피벗이 제 자리를 찾아가는 과정에서 비교연산의 횟수는 데이터의 수에 해당하는 n
  * 피벗으로 인해서 하나가 빠지는 것은 무시할만한 수준.
* 피벗이 항상 중간에 가까운 값을 가질 때, 나뉘는 횟수 k 일 때, 데이터 수 n과의 관계는 다음과 같음
  * k = log<sub>2</sub>n
* 최종적인 비교 연산횟수는 O(nlog<sub>2</sub>n) 가 됨

* 피벗이 끝단에 치우쳐져있을 때.
  * k = n이 되어, O(n<sup>2</sup>) 가 되어버림
* 중간 값 보정을 위해 별도 처리를 해줄 수도 있음.
  * 문제 10의 media of three 처럼 정렬할 배열의 처음, 중간, 끝 인덱스 중에서 그것에 담긴 값의 중간 인덱스를 찾아 pivot 값으로 정하는 것.



### 기수 정렬(Radix Sort): 이해1

* 기수 정렬은 정렬 순서상 앞서고 뒤섬의 판단을 위한 비교연산을 하지 않음
* 일반적으로 데이터의 길이가 같은 데이터는 정렬이 가능



### 기수 정렬(Radix Sort): 이해2

* LSD (Least Significant Digit) : 작은 자릿수부터 시작해서 가장 큰 자릿수까지 비교

  * 작은 자릿수에서 큰 자리수까지 모두 비교를해야하는 점이 단점처럼 보일 수 있지만, 프로그래밍화할 때 장점이 될 수 있다.

    

### 기수 정렬(Radix Sort): LSD vs MSD

* MSD (Most Significant Digit) : 큰 자리 수부터 정렬 진행
* MSD의 단점:
  * 모든 데이터에 일괄 적인 과정을 거치게 할 수 없음
  * 중간 중간에 데이터를 점검해야함



### 기수 정렬(Radix Sort): LSD 기준 구현

* 책 한번 보고 Java 코드로 바꾼후 다시 안 보고 다시 C코드로 해봤는데, 막히고 있던 부분이... 버킷에서 꺼낼 때, while문을 통해 큐에 담긴 것을 모두 꺼내지 않아서 시간이 걸렸다.



### 기수 정렬(Radix Sort): 성능평가

* 삽입과 추출의 빈도 수로 결정
* 복잡도
  * 자릿수(l) X 정렬대상의 수(n)
  * O(ln) => O(n)
  * 적용가능한 대상이 제한 적이지만 성능은 확실히 좋다.



---

## 기타

### 나의 오타로 인한 HEAP CORRUPTION DETECTED 오류

![heap-corruption-detected](doc-resources/heap-corruption-detected.png)

Ubuntu환경 GCC 나, Cygwin 등에서는 실제로 문제가 있는 코드가 있었지만 오류 메시지가 나타나지 않았었는데, Visual Studio 환경으로 선택시 위와 같은 오류가 발생했다.

```c
/* MergeSort.c 코드 일부 */
// 문제를 발생 시키는 부분
int *sortArr = (int *) malloc(sizeof(int) * right + 1);
(...)
// 오류 발생 부분
free(sortArr);


// 수정 코드
int *sortArr = (int *) malloc(sizeof(int) * (right + 1));

```

힙 버퍼의 끝 이후에 메모리 쓰기가 감지 되었다는 메시지 관련해서...

**최초에 malloc으로 int 크기만큼 배수로 생성해야하는데,  괄호를 제대로 안붙여서, 마지막 요소가 1바이트만큼만 붙여진 상태에서 만들어졌다.** 그런데 디버깅을 진행하면서 볼 때, 직접 쓰는 시점에서는 오류가 바로 발생하지 않고, 메모리 해제(free)시에 발생이 된 것 같다.  





## Java 코드로 먼저 만들어보자!

Java 코드를 만들어 먼저 수행 해보는것이 테스트 하기 편하고 이해가 쉬워서, 병합/ 퀵/ 기수 정렬은 [java-study](https://github.com/fp024/java-study/) 레파지토리의 [etc-project](https://github.com/fp024/java-study/tree/master/etc-project)에다 먼저 만들어서 동작을 확인한 후에 C 코드로 옮기자!

* 병합 정렬
  * [MergeSort 클래스](https://github.com/fp024/java-study/blob/master/etc-project/src/main/java/org/fp024/java/study/sort/MergeSort.java)
* 퀵 정렬
  * [QuickSort 클래스](https://github.com/fp024/java-study/blob/master/etc-project/src/main/java/org/fp024/java/study/sort/QuickSort.java)
* 기수 정렬
  * [RadixSort 클래스](https://github.com/fp024/java-study/blob/master/etc-project/src/main/java/org/fp024/java/study/sort/RadixSort.java)
