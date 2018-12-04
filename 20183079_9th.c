#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int n;
	struct Node *next;
};


int printNodes(struct Node* p);
void freeNodes(struct Node* p);
void ShowMiddleNodes(struct Node* p,int n);
struct Node *Reversed(struct Node* p);


void main() {
	// 메인함수에서 사용할 기본 변수 선언 
	int flag = 1;
	int input;

	struct Node *head;
	struct Node *last;
	struct Node *node;

	head = NULL;
	last = NULL;

	printf("저장할 정수를 입력하시오(종료:Ctrl+Z(세번정도 입력해야하고 빨리하려면 -1) : ");

	while ((scanf("%d", &input)) != EOF){

		printf("저장할 정수를 입력하시오(종료:Ctrl+Z) : ");
		

		
		node = (struct Node*)malloc(sizeof(struct Node));

		
		node->n = input;
		node->next = NULL;

		
		if (head == NULL) {//연결리스트가 비어있을 경우(첫번째 리스트)
			head = node;
		}
		else { 
			last->next = node;
		}

		//연결 리스트에 추가된 node의 주소를 last에 저장
		last = node;

	}//값을 입력받고 사용자의 입력이 Ctrl+Z가 아니면 노드를 할당하여 연결리스트에 추가

	
	printf("<입력받은 대로 출력>\n");


	int size = printNodes(head); //연결리스트를 출력하면서 갯수를 계산

	printf("\n");

	printf("<자료의 갯수:%d개>\n", size); //자료의 갯수 출력
	printf("\n");

	printf("<자료의 중간값 출력>\n");
	ShowMiddleNodes(head,size); //중간값 출력
	printf("\n");

	printf("<자료의 역순으로 출력>\n");

	head = Reversed(head);//역순으로 저장
	printNodes(head);//역순으로 저장된 연결리스트를 출력

	head = Reversed(head);//다시 입력받은 순서대로 정렬

	printf("\n");

	printf("<홀수번째 자료 제거 후 출력>\n");


	//홀수번째 자료 제거하기

		struct Node *temp;
		struct Node *p;
		
		//printf("%d", head); printf("%d", head->n);

		int n = 1;

		p = head;
		temp=p;
		head=p->next;
		p=p->next;
		free(temp); 
		n++;
		//head,p가 두번째 node가 됨

	

		while(n+1<=size)
		{
			if (n + 1 == size)
			{
				temp = p->next;
				p->next = NULL;
				last = p->next;
				free(temp);
				n++;
			}
			
			else {

				temp = p->next;
				p->next = temp->next;
				free(temp);
				p = p->next;
				n = n + 2;
			}

		}
		

	printNodes(head); //연결리스트 출력하기
	freeNodes(head); //연결리스트 할당해제하기
}




int printNodes(struct Node* p) {
	int n = 0;
	//p가 NULL 아닌 경우 = 마지막 노드가 아닌 경우
	while (p != NULL) {
		//노드에 저장된 값을 출력하고, 다음 노드로 이동
		printf("%d\n", p->n);
		p = p->next;
		n++;
	}

	return n;
}

void freeNodes(struct Node* p) {
	struct Node *temp;//다음 노드의 주소를 임시 저장할 temp 변수
	while (p != NULL) {//연결 리스트의 끝 까지 반복
		temp = p;//지울 노드를 임시변수에 저장
		p = p->next;//다음 노드로 이동
		free(temp);//임시변수에 저장된 이전 노드를 해제
	}
}

void ShowMiddleNodes(struct Node* p, int n) {

	int i = 1;
	while (i < n)
	{
		if (i == n / 2 && n % 2 == 0) printf("%d, ", p->n);
		else if (i == n / 2 + 1) printf("%d\n", p->n);
		i++;
		p = p->next;
	}


}

struct Node *Reversed(struct Node* p)
{
	struct Node *target;
	struct Node *Rhead;
	struct Node *count;

	Rhead = NULL;
	count = p;
	target = NULL;

	
	while (count != NULL)
	{
		target = Rhead;
		Rhead = count;
		count = count->next;
		Rhead->next = target;
	}

	return (Rhead);

}

		

