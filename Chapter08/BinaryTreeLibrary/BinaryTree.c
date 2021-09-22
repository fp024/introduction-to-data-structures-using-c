/**
 * BinaryTree.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"


 /**
  * 노드의 생성
  *
  * @return 생성된 노드 주소
  */
BTreeNode* MakeBTreeNode(void) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * 노드에 저장된 데이터를 반환
 *
 * @param bt    노드 주소
 * @return  노드의 데이터
 */
BTData GetData(BTreeNode* bt) {
    return bt->data;
}

/**
 * 노드에 데이터 저장
 *
 * @param bt    노드 주소
 * @param data  저장할 데이터
 */
void SetData(BTreeNode* bt, BTData data) {
    bt->data = data;
}


/**
 * 왼쪽 서브 트리 주소 값 반환
 *
 * @param bt    노드 주소
 * @return 왼쪽 서브트리 주소
 */
BTreeNode* GetLeftSubTree(BTreeNode* bt) {
    return bt->left;
}

/**
 * 오른쪽 서브 트리 주소 값 반환
 *
 * @param bt    노드 주소
 * @return 오른쪽 서브트리 주소
 */
BTreeNode* GetRightSubTree(BTreeNode* bt) {
    return bt->right;
}


/**
 * 특정 노드 왼쪽에 서브트리 노드 연결
 *
 * @parm main   서브트리를 연결할 특정노드
 * @parm sub    서브트리
 */
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
    // 이부분은 바로 생각 못했다. 순회를 해서 줄줄이 free를 해야하는데, 저자님이 이후 내용에서 하신다고 한다.
    if (main->left != NULL) {
        free(main->left);
    }

    main->left = sub;
}


/**
 * 특정 노드의 오른쪽에 서브트리 노드 연결
 *
 * @parm main   서브트리를 연결할 특정노드
 * @parm sub    서브트리
 */
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
    if (main->right != NULL) {
        free(main->right);
    }

    main->right = sub;
}