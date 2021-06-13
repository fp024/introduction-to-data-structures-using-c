## Chapter 04 연결 리스트 (Linked List) 2

### 04-1 연결리스트의 개념적인 이해
* 배열은 메모리의 특성이 정적이여서, 메모리의 길이를 변경하는 것이 불가능함


### 04-2 단순 연결 리스트의 ADT와 구현
* 지금 상태에서는 리스트의 타입을 선택적으로 변경하기가 힘들어보인다.
  * ex04-3을 빌드하기 위해서는 DLinkedListLibrary 프로젝트에 _USE_CUSTOM_DATATYPE 메크로를 주고 빌드해야함.
    * 구성속성 -> C/C++ -> 전처리기 항목에 _USE_CUSTOM_DATATYPE 메크로를 추가하고 정적 라이브러리 빌드
  * DLinkedListMain 프로젝트를 빌드할 때는 위의 메크로를 빼고 정적 라이브러리를 빌드

* `Point*`으로 사용하는 사용처 프로젝트 빌드시에도 메크로를 선언해야한다.

리스트의 요소를 간편하게 변경할 수 있어야할 것 같은데...
3장 진행할 때 전처리기 옵션을 지정해서 빌드할 때는 MinGW 환경에서는  
실행시 오류가나지 않았으나 부정확한 부분이 있을 수 있을 것 같다.

공유라이브러리()는 이미 LData가 int 타입으로 빌드되었는데,
* https://github.com/fp024/introduction-to-data-structures-using-c-by-yoon/tree/master/chapter03/arraylist

라이브러리 사용처에서는 `Point*` 으로 썼음.


### 04-3 연결 리스트의 정렬 삽입의 구현
* ex04-4 프로젝트 빌드시 DLinkedListLibrary 가 먼저 _USE_CUSTOM_DATATYPE 메크로를 적용해서 빌드가 먼저되야함.
  * 문제 4번 동일 경우를 깜빡해서 틀렸다. 동일 경우 조건을 명시적으로 주지않아 오작동함. ㅠㅠ
