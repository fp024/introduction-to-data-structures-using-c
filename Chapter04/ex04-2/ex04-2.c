/**
 * 문제 04-2 [더미노드 적용했을 때의 코드 변화 확인하기]
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;


int main(void) {
	Node* head = NULL;
	Node* cur = NULL;
	Node* tail = NULL;
	Node* dummy = (Node*)malloc(sizeof(Node));

	if (dummy == NULL) {
		return -1;
	}

	dummy->data = -1;
	dummy->next = NULL;

	tail = head = dummy;


	Node* newNode = NULL;
	int readData;


	// 데이터를 입력 받는 과정
	while (1) {
		printf("자연수 입력: ");
		scanf_s("%d", &readData);
		if (readData < 1) {
			break;
		}

		// 노드의 추가 과정
		newNode = (Node*)malloc(sizeof(Node));

		// malloc이 실패했을 경우 newNode가 NULL일수 있다.
		// 분기처리를 하지 않으면 경고로그가 출력된다.
		if (newNode == NULL) {
			return -1;
		}
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;
		tail = newNode;
	}

	// 입력받은 데이터의 출력 과정
	printf("입력 받은 데이터의 전체 출력! \n");
	if (head->next == NULL) {
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else {
		cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
		printf("\n\n");

		// 메모리의 해제과정
		if (head->next == NULL) {
			return 0;
		}
		else {
			Node* delNode = head; // head는 더미를 가리키고 있음.
			Node* delNextNode = head->next;
			while (delNextNode != NULL) { // 더미 다음의 두 번째 이후 노드 삭제
				delNode = delNextNode;
				delNextNode = delNextNode->next;

				printf("%d을(를) 삭제합니다. \n", delNode->data);
				free(delNode);
			}
		}
	}
	return 0;
}
