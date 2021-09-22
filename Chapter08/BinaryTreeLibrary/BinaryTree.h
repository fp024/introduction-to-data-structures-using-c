/**
 * BinaryTree.h
 */
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

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


#endif // !__BINARY_TREE_H__
