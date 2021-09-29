/**
 * BinaryTree2.h
 *
 * BinaryTree.h에서 순회 후, 노드 데이터를 어떤식으로 처리할지를
 * action함수로 정의한 부분만 추가되었다.
 */
#ifndef __BINARY_TREE2_H__
#define __BINARY_TREE2_H__

typedef int BTData;

/**
 * 이진 트리의 노드
 *
 * 노드의 표현결과 뿐만 아니라, 이진트리 자체를 표현하는 것도 된다.
 */
typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode* left;
    struct _bTreeNode* right;
} BTreeNode;

/**
 * 노드의 생성
 *
 * @return 생성된 노드 주소
 */
BTreeNode* MakeBTreeNode(void);

/**
 * 노드에 저장된 데이터를 반환
 *
 * @param bt    노드 주소
 * @return  노드의 데이터
 */
BTData GetData(BTreeNode* bt);

/**
 * 노드에 데이터 저장
 *
 * @param bt    노드 주소
 * @param data  저장할 데이터
 */
void SetData(BTreeNode* bt, BTData data);


/**
 * 왼쪽 서브 트리 주소 값 반환
 *
 * @param bt    노드 주소
 * @return 왼쪽 서브트리 주소
 */
BTreeNode* GetLeftSubTree(BTreeNode* bt);

/**
 * 오른쪽 서브 트리 주소 값 반환
 *
 * @param bt    노드 주소
 * @return 오른쪽 서브트리 주소
 */
BTreeNode* GetRightSubTree(BTreeNode* bt);


/**
 * 특정 노드 왼쪽에 서브트리 노드 연결
 *
 * @parm main   서브트리를 연결할 특정노드
 * @parm sub    서브트리
 */
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);


/**
 * 특정 노드의 오른쪽에 서브트리 노드 연결
 *
 * @parm main   서브트리를 연결할 특정노드
 * @parm sub    서브트리
 */
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);



/**
 * 트리 순회 방법에 대해 함수 포인터 정의
 */
typedef void (*VisitFuncPtr)(BTData data);


/**
 * 전위 순회   Center -> Left ->  Right
 */
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);

/**
 * 중위 순회   L -> C -> R
 */
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);;

/**
 * 후위 순회   L -> R -> C
 */
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);



/**
 * 문제 08-1 [이진 트리의 소멸]
 * 특정 노드 부터 시작하는 이진 트리의 소멸
 * 
 * @param bt  삭제할 트리 노드의 주소
 *   
 *   시험삼아 하는데, 호출처의 bt를 DeleteTree()함수 내에서 free한후 NULL로 바꾸기 위해 2차원 포인터로 바꿔본다.
 */
void DeleteTree(BTreeNode** bt);



#endif // !__BINARY_TREE2_H__
