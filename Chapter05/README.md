## Chapter 05 연결 리스트 (Linked List) 3

### [05-1] 원형 연결 리스트 (Circular Linked List)
* 단순 연결리스트! 안보고 구현할 수 있는지?
  * Java로는 구현할 수 있겠는데, C로는 아직 코드를 봐야할 것 같다.

* 원형 연결 리스트의 장점 중 하나
  * 단순 연결 리스트 처럼 머리와 꼬리를 가리키는 포인터 변수를 각각 두지 않아도, 하나의 포인터변수만 있어도 머리또는 꼬리에 노드를 간단히 추가할 수 있다.


### [05-2] 양방향 연결리스트



## 기타
* CLinkedListLibrary를 DLL로 빌드 후에 그것을 메인 프로그램에서 사용하는 방법을 잘 모르겠음.
  * 정적라이브러리 LIB으로 빌드에서 사용 프로젝트인 CLinkedListMain 에서 사용하면 잘되는데.. ㅠㅠ
    ```
    CLinkedListLibrary.dll : fatal error LNK1107: 파일이 잘못되었거나 손상되었습니다. 0x390에서 읽을 수 없습니다.
    ```    
    * 책의 내용에 집중해야하니 이부분은 나중에 하자.
      

### 프로젝트 빌드 참고 사항
* ex05-1 프로젝트
  * CLinkedListLibrary 라이브러리 프로젝트의 전처리기 옵션에 `_USE_EMPLOYEE_DATATYPE` 를 설정해야함.
* CLinkedListMain 프로젝트
  * CLinkedListLibrary 라이브러리 프로젝트의 전처리기 옵션에 `_USE_EMPLOYEE_DATATYPE` 를 설정을 제거해야함. 