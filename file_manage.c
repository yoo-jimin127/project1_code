#include "project1.h"


Node *makeNode (char *fileName); // 노드 생성 함수 
void addNode (LinkedList *linkedList, Node *node); //파일 목록에 파일 추가하는 함

// 노드 생성 함수 (파일이름 노드에 저장)
Node *makeNode (char *fileName) {
	Node *newNode;수
//	Node *currNode;

	newNode = (Node *)malloc(sizeof(Node));
	strcpy(newNode -> fileName, fileName); //strcpy(붙여넣기 할 곳, 복사할 내용) 

	newNode -> next = NULL;
	newNode -> prev = NULL; //newNode의 next, prev 초기화

	return newNode;
}

//파일목록에 파일 추가하는 함수
void addNode (LinkedList *linkedList, Node *node) {
	//리스트가 비어있는 경우
	if (linkedList -> head -> next == linkedList -> tail) { //헤드-> <-테일
		linkedList -> head -> next = node; // head --> node
		node -> next = linkedList -> tail; // 노드 next = tail

		linkedList -> tail -> prev = node;
		node -> prev = linkedList -> head; // 노드 prev = head
	}수

	//리스트가 비어있지 않은 경우
	else {
		linkedList -> tail -> prev -> next = node; //node : 추가, tail->prev : 기존
		node -> next = linkedList -> tail; //추가노드 -> next = tail

		node -> prev = linkedList -> tail -> prev; // 추가노드->prev = 기존노드
		linkedList -> tail -> prev = node; //tail->prev = 추가노드

	}

	linkedList -> fileCnt++;

//	struct EngWord *prevptr;
//	struct EngWord *addptr;
//	struct EngWord *element;
//
//	element -> word = word;
//	element -> meaning = meaning;
//	element -> next = NULL;
//
//	//리스트가 비어있는 경우
//	if ((*head) == NULL) {
//		(*head) = element;
//		return;
//	}
//
//	//리스트가 비어있지 않은 경우
//	prevptr = NULL;
//	addptr = (*head);
//
//	while (addptr != NULL) {
//		//들어갈 위치 찾지 못했을 때
//		if (addptr->word < word) {
//			prevptr = addptr;
//			addptr = addptr -> next;
//		}
//
//		//들어갈 위치 찾았을 때
//		else {
//			//첫번째 원소로 추가할 때
//			if (prevptr == NULL) (*head) = element;
//
//			//첫번째 원소로 추가X 경우
//			else {
//				prevptr -> next = element;
//				el수ement -> next = addptr;
//				return;
//			}
//
//		}
//
//		//마지막 원소로 추가할 때
//		addptr -> next = element;
//	}

}


//리스트 초기화 함
void initList (LinkedList *linkedList) {
	FILE *fptr;

	fptr = fopen("dic.list", "w+");

	linkedList -> head = (Node*)malloc(sizeof(Node));
	linkedList -> tail = (Node*)malloc(sizeof(Node)); //링크드리스트의 head, tail의 메모리 동적할당

	linkedList -> head -> next = linkedList -> tail;
	linkedList -> tail -> prev = linkedList -> head; //head와 tail 연결

	linkedList -> tail -> next = NULL;
	linkedList -> head -> prev = NULL; //tail->next와 head->prev 초기화

	linkedList -> fileCnt = 0; //파일 목록 개수 0으로 초기화

}


//사용자로부터 입력받은 단어장파일을 연결리스트에서 찾는 함수
Node *findFile (LinkedList *linkedList, int day_file) {
	
	char selectedFile[100]; //사용자가 int형으로 입력한 파일명을 %d.dic 형태로 저장해둘 문자열배열
	int same = 999; //찾는 파일명과 순회중인 파일명이 일치한지의 결과값을 저장하는 변수
	sprintf(selectedFile, "%d.dic", day_file); // selectedFile 배열에 문자열로 day_file.dic이 저장됨
	

	Node *curr; // 리스트를 순회하며 찾는 노드와 같은 노드 반환
	curr = linkedList -> head; // curr 노드를 연결리스트의 head 위치로 초기 설정
	
	
	while(curr -> next != linkedList -> tail -> next) {
		same = strcmp(selectedFile, curr->fileName); // 같으면 0

		if (same == 0) {
			return curr; // same 값이 0일 경우 찾는 파일 curr 리턴하고 종료
		}	
		
		curr = curr -> next; //다르면 다음 노드 순회
	}

	return NULL; //찾는 파일명과 일치하는 파일명 노드에 없으면 NULL
}


// 단어장 파일에 저장되어 있는 단어의 개수를 계산하는 함수
int calcWordCount (char *fileName) {
	// 파일 끝까지 읽어서 \n 만나면 단어의 개수 ++;
	int wordCnt; //단어의 개수 저장하기 위한 변수
	char ch;
	FILE *fptr; //파일포인터
	
	fptr = fopen(fileName, "r");
	
	wordCnt = 0; //wordCnt 초기화
	while ((ch = fgetc(fp)) != EOF) { //end of file까지 반복
		if (ch == '\n') wordCnt++;
	}

	return wordCnt;
}


//~.dic 파일명을 dic.list에 추가하는 함수
void addFileToList (Node *node) {
	FILE *fptr;

	fptr = fopen("dic.list", "a+"); //dic.list 파일 오픈

	fseek(fptr, 0, SEEK_END); //파일 포인터 파일 끝으로 이동시킴
	fprintf(fptr, "%s", node -> fileName); //파일의 끝에 인자로 전달받은 노드의 파일명 작성
	
	fclose(fptr); //dic.list 파일 닫기
}


// 구조체 EngWord에 텍스트파일에 저장되어있는 문장 word|meaning으로 구별해 저장하는 함수
void splitWordByToken (EngWord *engWord, char *wordArr) {
	char *token; //공백 구분자 만나면 토큰 분리해 구조체에 저장
	
	for (int i = 0; i < strlen(wordArr); i++) {
		if (wordArr[i] == '\n') wordArr[i] = 0;
		} //문자열처리를 위해 단어 저장 배열의 개행문자를 만나면 삭제
		
	token = strtok(wordArr, " "); // 공백 구분자 ex) apple 사과 에서 토큰 분리
	strcpy(engWord -> word, token); // 분리된 토큰을 구조체의 word 멤버에 저장

	if (strcmp(engWord -> word, ".add") == 0) { //읽어들인 토큰이 .add일 경우 추가종료(기능 4-1, 4-2)
		return -1;
	}
	
	token = strtok(NULL, " "); //다음 토큰을 가져오기 위한 작업
	int cnt = 0; //뜻 저장 개수 세기 위한 변수

	while(token != NULL) {
		if (cnt >= 3) {
			printf("영단어의 뜻은 3개를 초과하여 저장할 수 없습니다.\n");
			break;
			}

		strcpy(engWord -> meaning[cnt], token); //영단어 구조체의 meaning[cnt]에 읽어들인 토큰을 저장
		cnt++; //뜻 저장 완료 후 뜻 개수 ++
		token = strtok(NULL, " "); //다음 토큰을 가져오기 위한 작업
	}
	engWord -> meaningCnt = cnt; //영단어 구조체에 읽어들임을 완료한 뜻의 개수 저장 
	return 0;
}


// EngWord 구조체에 저장된 멤버 word를 알파벳 순으로 정렬하는 함수
void engWordSort(EngWord *engWord, int engWordCnt) {
	EngWord tmp; //버블정렬 시 두 영단어의 위치교환에 사용될 임시 구조체 저장 변수

	for (int i = engWordCnt-1; i > 0; i--) { // 0 ~ engWordCnt -1 까지 반복
		for (int j = 0; j < i; j++) { //j번째와 j+1 번째의 요소가 알파벳순 아니면 교환
			if (strcmp(engWord[j].word, engWord[j+1].word) > 0) {
				tmp = engWord[j];
				engWord[j] = engWord[j+1];
				engWord[j+1] = tmp;
			}
		}
	}

}


