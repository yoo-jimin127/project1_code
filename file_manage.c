//*******************************************************
//project1.h 영어 단어 암기 프로그램 헤더파일
//*******************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //system("clear"); rand() 사용 등
#include <time.h> // 랜덤함수 사용 시 중복 제거
#include <unistd.h>  //sleep 함수(일정 시간 동안 실행 정지), read 함수(파일 읽어오기)
#include <dirent.h>

//영단어와 뜻 저장 구조체 선언
typedef struct engWord {
	char word[16]; //영단어(max 15)
	char meaning[3][31]; //영단어에 대응되는 한글 뜻 (최대 3개의 뜻, 한글 뜻 max 30자)
	int meaningCnt; //영단어에 대응되는 한글 뜻의 count
}EngWord;

//파일 이름 저장해 연결 위한 노드 구조체
typedef struct node {
	struct node *next; //다음 단어 저장 포인터
	struct node *prev; //이전 단어 저장 포인터
	char fileName[100]; //파일 이름 저장할 멤버변수 (1.dic ~ n.dic 문자열)  
}Node;

//파일 목록들 저장해놓는 연결리스트
typedef struct linkedList {
	Node *head; //이중 연결리스트의 head 노드
	Node *tail; //이중 연결리스트의 tail 노드
	int fileCnt; //연결리스트에 저장되어있는 파일 개수 count
}LinkedList;

//---------함수 선언----------

// 연결리스트 관련 함수 선언부
Node *makeNode (char *fileName);
void addNode (LinkedList *linkedList, Node *node);
void initList (LinkedList *linkedList);
Node *findFile (LinkedList *linkedList, int day_file);
int calcWordCount (char *fileName);
void addFileToList (Node *node);
void splitWordByToken (EngWord *engWord, char *wordArr);
int calcFileCount();

//1번 기능
void choose_setting1(int *day_file, int *output_way);
void word_quiz(LinkedList *linkedList);

//2번 기능
void choose_setting2(int *speed, int *day_file, int *output_way);
void flash_card(LinkedList *linkedList);

//3번 기능

//4번 기능


//*******************************************************************************
//연결리스트 관련 함수 구현부
//********************************************************************************

// 노드 생성 함수 (파일이름 노드에 저장)
Node *makeNode (char *fileName) {
	Node *newNode;
//	Node *currNode;

	newNode = (Node *)malloc(sizeof(Node)); //메모리 동적 할당
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
	}

	//리스트가 비어있지 않은 경우
	else {
		linkedList -> tail -> prev -> next = node; //node : 추가, tail->prev : 기존
		node -> next = linkedList -> tail; //추가노드 -> next = tail

		node -> prev = linkedList -> tail -> prev; // 추가노드->prev = 기존노드
		linkedList -> tail -> prev = node; //tail->prev = 추가노드
	}

	linkedList -> fileCnt++; //연결리스트에 저장된 노드 개수 ++
}


//리스트 초기화 함수
void initList (LinkedList *linkedList) {
	FILE *fptr; //파일 포인터
	int fileCnt; //리스트에 저장되어있는 파일 개수 저장 변수

	fptr = fopen("dic.list", "w+"); //파일 포인터에 dic.list 파일 오픈
	fileCnt = calcFileCount(); // fileCnt에 calcFileCount 리턴 값 저장

	linkedList -> head = (Node*)malloc(sizeof(Node));
	linkedList -> tail = (Node*)malloc(sizeof(Node)); //링크드리스트의 head, tail의 메모리 동적할당

	linkedList -> head -> next = linkedList -> tail;
	linkedList -> tail -> prev = linkedList -> head; //head와 tail 연결

	linkedList -> tail -> next = NULL;
	linkedList -> head -> prev = NULL; //tail->next와 head->prev 초기화

	linkedList -> fileCnt = 0; //파일 목록 개수 0으로 초기화

	calcFileCount(linkedList); //파일의 개수 세고 makeNode, addNode 하는 작업 수행
	
	fclose(fptr); //dic.list 파일 닫기

}


//사용자로부터 입력받은 단어장파일을 연결리스트에서 찾는 함수
Node *findFile (LinkedList *linkedList, int day_file) {
	
	char selectedFile[100] = ""; //사용자가 int형으로 입력한 파일명을 %d.dic 형태로 저장해둘 문자열배열
	int same = 999; //찾는 파일명과 순회중인 파일명이 일치한지의 결과값을 저장하는 변수
	Node *curr; // 리스트를 순회하며 찾는 노드와 같은 노드 반환

	sprintf(selectedFile, "%d.dic", day_file); // selectedFile 배열에 문자열로 day_file.dic이 저장됨
	curr = linkedList -> head -> next; // curr 노드를 연결리스트의 head의 next 위치로
	
	while(curr -> next != NULL) { // curr의 next가 연결리스트의 tail까지 순회
		if (strcmp(selectedFile, curr -> fileName) == 0) {
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
	int ch; //개행문자를 만났을 때 이를 비교하기 위한 변수
	FILE *fptr; //파일포인터
	
	fptr = fopen(fileName, "r");
	
	wordCnt = 0; //wordCnt 초기화
	while ((ch = fgetc(fptr)) != EOF) { //end of file까지 반복
		if (ch == '\n') wordCnt++;
	}

	return wordCnt;
}


//~.dic 파일명을 dic.list에 추가하는 함수
void addFileToList (Node *node) {
	FILE *fptr; // fopen 리턴 값 저장 위한 파일포인터

	fptr = fopen("dic.list", "a"); //dic.list 파일 오픈, a모드: 파일의 끝 위치에 append하게 포인터 이동
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
		return;
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
	return;
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


//디렉터리에 저장되어 있는 단어장 파일의 개수를 계산하는 함수
int calcFileCount(LinkedList *linkedList) {
	int cnt = 0; //파일 개수 세는 변수
	DIR *dirptr; //디렉터리형 포인터
	char buf[300] = ""; //작업 디렉토리의 이름을 저장하기 위한 배열 (getcwd함수 리턴 : char), NULL 초기화

	struct dirent *dir; // dirent 구조체
	//struct dirent {
	//	long d_ino; //inode 번호
	//	off_t d_off; //offset
	//	unsigned shord d_reclen; //d_name 길이
	//	char d_name[NAME_MAX+1]; //파일 이름
	//};
	Node *node; //추가할 노드
	
	getcwd(buf, 300); //현재 작업 디렉터리의 이름을 size만큼 buf 에 복사 
	
	if((dirptr = opendir(buf)) == NULL) { //디렉터리 열기 (DIR* 리턴받음)
		fprintf(stderr, "direntory 정보를 읽을 수 없습니다.\n");
		return -1;
	}

	while ((dir = readdir(dirptr)) != NULL) { //디렉터리 처음부터 파일 or 디렉터리 명 읽어옴
		if (strcmp(dir -> d_name, ".") == 0) {
			continue;
		} // 현재 디렉터리일 경우 순회 계속

		if (strcmp (dir -> d_name, "..") == 0) {
			continue;
		} //이전 디렉터리일 경우 순회 계속

		for (int i = 0; i < strlen(dir -> d_name); i++) {
			if(strncmp(dir -> d_name+i, ".dic", 4) == 0) { //시작 위치를 바꿔가며 파일명을 순회하였을 때
				cnt++; //.dic이 있으면 cnt++
				node = makeNode(dir -> d_name); //dir 구조체의 d_name의 이름을 가진 노드를 생성
				addNode(linkedList, node); //만들어진 파일명의 노드를 연결리스트에 추가
				break;
			}
		}
	}


	return cnt;
}


//void putDicIntoList (int cnt) {
//	DIR *dirptr; // 디렉터리 포인터 (opendir, readdir 통해 파일이름 넣어야하므로)
//	char buf[300] = ""; //현재 디렉토리의 이름을 저장하기 위한 배열
//	struct dirent *dir; //dirent 구조체
//
//	getcwd(buf, 300); // 현재 작업 디렉터리의 이름을 size 만큼 buf에 복사
//}


//**********************************************
// 프로그램 실행 시 가장 처음 등장하는 메뉴 화면
//**********************************************

void first_func(LinkedList *linkedList); //영어 단어 맞추기
void second_func(LinkedList *linkedList); //플래쉬 카드
void third_func(LinkedList *linkedList); //행맨
void fourth_func(LinkedList *linkedList); //단어장 관리

int main (void) {
	int user; // 사용자가 선택한 단어장 기능
	LinkedList linkedList; //파일목록 담긴 연결리스트

	initList(&linkedList); //프로그램 시작마다 연결리스트를 초기화시켜주는 작업

	printf(">> 영어 단어 암기 프로그램 <<");

	printf("1. 영어 단어 맞추기 \t 2. 플래쉬 카드\n");
	printf("3. 행맨(hangman) \t 4. 단어장 관리\n");
	printf("5. 프로그램 종료\n\n");

	printf("번호를 선택하세요: ");
	scanf("%d", &user);

	switch (user) {
		
		case 1 : 
			//영어 단어 맞추기 기능
			first_func(&linkedList);
			break;

		case 2 :
			//플래쉬 카드 기능
			second_func(&linkedList);
			break;

		case 3 : 
			//행맨 기능
	//		third_func(&linkedList);
			break;

		case 4 :
			//단어장 관리 기능
	//		fourth_func(&linkedList);
			break;

		case 5 :
			system("clear");
			return 0;

	}
}

void first_func (LinkedList *linkedList) {
	word_quiz(linkedList);
}

void second_func (LinkedList *linkedList) {
	flash_card(linkedList);
}

void third_func (LinkedList *linkedList) {
//	hangman_game(linkedList);
}

void fourth_func (LinkedList *linkedList) {
//	manage_voca(linkedList);
}


//*********************************
// 1번 기능 : 영어 단어 맞추기
//*********************************

// 1번 메뉴 선택 시 파일명과 출력 방식 물어보는 기능
void choose_setting1(int *day_file, int *output_way) {
    printf("파일명(일차) : ");
    scanf("%d\n", day_file);

    printf("출력 방식(알파벳 순서대로 : 1, 무작위 : 2) : ");
    scanf("%d\n", output_way);

    //화면 비우기
    system("clear");

}

//choose_setting에서의 입력값을 바탕으로 영어 단어 맞추기 퀴즈를 내는 기능
void word_quiz(LinkedList *linkedList){

    int day_file; //파일명(일차)
    int output_way; //출력 방식 (알파벳 순서대로 : 1, 무작위 : 2)

    int engWordCnt = 0; //파일에 저장되어있는 단어 개수 저장 변수
    int quizCnt = 0; //카운트를 늘려가며 engWordCnt만큼의 게임 진행
    int corCnt = 0; //정답횟수 카운트
    int incorCnt = 0; //오답횟수 카운트
    char wordArr[300]; //단어 저장을 위한 배열
    char wordAns[31]; //최대 30개의 단어가 들어있는 파일 문제에 대한 사용자의 답이 저장되는 배열
    int randomSet; //무작위 생성 시 단어개수만큼의 랜덤설
    int enter; //엔터 누르면 메인으로 돌아가도

    EngWord *engWord;//노드 순회하며 읽어올 단어 구조체
    Node *chooseFile; //사용자가 선택한, 단어 맞추기를 진행할 파일명
    FILE *fptr = NULL; //파일 포인터

    // 파일명과 출력방식 입력받아 day_file, output_way에 저장하고 화면 clear
    choose_setting1(&day_file, &output_way);

    chooseFile = findFile(linkedList, day_file); //사용자가 입력한 파일명 가진 노드 찾아 chooseFile저장

    engWordCnt = calcWordCount(chooseFile -> fileName); //chooseFile의 단어 개수 저장
    engWord = (EngWord *)malloc(sizeof(EngWord)*engWordCnt); //단어 개수만큼 동적메모리 할당

    fptr = fopen(chooseFile -> fileName, "r+"); //읽기 모드로 fileName이름의 파일 오픈, 파일포인터 저장

	//입력한 파일명이 존재하지 않을 경우
    if (fptr == NULL) {
        printf("입력한 파일명이 존재하지 않습니다.\n");
        exit(1); //exit(1) : 에러일 경우 종료 - 배치파일에서 처리 O, exit(0) : 정상적인 종료
    }   

    for (quizCnt = 0; quizCnt < engWordCnt; quizCnt++) {
        memset(wordArr, 0, 300); //단어 저장 배열 모두 0으로 초기화
        fgets(wordArr, sizeof(wordArr), fptr); //파일포인터에 wordArr만큼의 문자열 읽어들임
        splitWordByToken(&engWord[quizCnt], wordArr); //wordArr 배열을 구조체에 구분하여 넣는 작업
        quizCnt++; //다음 단어도 구조체로
    }   

    printf(">> 영어 단어 암기 프로그램 : 영어 단어 맞추기 <<\n");
    quizCnt = 0; // 문제 출력을 위해 다시 quizCnt 변수를 0으로 초기화

    //------출력방식대로 문제내는 작업------
    if (output_way == 1) {
        while(quizCnt != engWordCnt) { //파일에 저장되어있는 단어 개수만큼 반복하여 문제 출제
            memset(wordAns, 0, 31); //답 저장 배열 모두 0으로 초기화
    

            for (int i = 0; i < engWord[quizCnt].meaningCnt; i++) {

                //뜻 출력 과정 중에 마지막으로 저장된  뜻을 출력할 때
                if (engWord[quizCnt].meaningCnt - 1 == i) {
                    printf("%s ", engWord[quizCnt].meaning[i]); //뜻 출력하고
                    break; //for 반복문 탈출
                }

                printf("%s ", engWord[quizCnt].meaning[i]); //뜻 출력
            }

            printf("-> ");

            scanf("&s", wordAns); //사용자가 화면에 나와있는 뜻을 보고 영단어 입력
            if (strcmp(wordAns, ".quit") == 0) {
                break;//사용자로부터 입력받은 wordAns 값이 .quit인 경우 입력 종료
            }


			// 정답 & 오답 확인 과정
            if (strcmp(engWord[quizCnt].word, wordAns) == 0) {
                printf("correct!\n");
                corCnt++; //정답인 경우 correct! 출력, 정답 카운트 corCnt++;
            }

            else {
                printf("incorrect!\n");
                incorCnt++;
            }

            quizCnt++; //퀴즈 출력 수++;
        }

        printf("당신의 점수는 %.2f 점 입니다.\n", (((double)corCnt/(double)quizCnt)) * 100.0);
    }   

    // ------무작위 방식으로 문제내는 작업------
    else if (output_way == 2) {

        srand(time(NULL));//여러번 실행 했을 때 같은 난수 나오지 않도록 시행마다 다르게

        while(quizCnt != engWordCnt) { //파일에 저장되어있는 단어 개수만큼 반복하여 문제 출제
            memset(wordAns, 0, 31); //답 저장 배열 모두 0으로 초기화

            randomSet = rand() % engWordCnt; //단어개수만큼의 랜덤 세팅
            for (int i = 0; i < engWord[randomSet].meaningCnt; i++) {

                //뜻 출력 과정 중 마지막으로 저장된 뜻 출력할 때
                if (engWord[randomSet].meaningCnt -1 == i) {
                    printf("%s ", engWord[randomSet].meaning[i]); // 뜻 출력하고
                    break; // 반복문 탈출
                }

                printf("%s ", engWord[randomSet].meaning[i]); //뜻 출력
            }

            printf("-> ");

            scanf("&s", wordAns); //사용자가 화면에 나와있는 뜻을 보고 영단어 입력
	if (strcmp (wordAns, ".quit") == 0) {
				break;//사용자로부터 입력받은 wordAns 값이 .quit인 경우 입력 종료
			}
			
			// 정답 & 오답 확인 과정
			if (strcmp(engWord[quizCnt].word, wordAns) == 0) {
				printf("correct!\n");
				corCnt++; //정답인 경우 correct! 출력, 정답 카운트 corCnt++;
			}

			else {
				printf("incorrect!\n");
				incorCnt++;
			}

			quizCnt++; //퀴즈 출력 수++;
		}

		printf("당신의 점수는 %.2f 점 입니다.\n", (((double)corCnt/(double)quizCnt)) * 100.0);
	}

	// ------무작위 방식으로 문제내는 작업------
	else if (output_way == 2) {

		srand(time(NULL));//여러번 실행 했을 때 같은 난수 나오지 않도록 시행마다 다르게

		while(quizCnt != engWordCnt) { //파일에 저장되어있는 단어 개수만큼 반복하여 문제 출제
			memset(wordAns, 0, 31); //답 저장 배열 모두 0으로 초기화
	
			randomSet = rand() % engWordCnt; //단어개수만큼의 랜덤 세팅
			for (int i = 0; i < engWord[randomSet].meaningCnt; i++) {

				//뜻 출력 과정 중 마지막으로 저장된 뜻 출력할 때
				if (engWord[randomSet].meaningCnt -1 == i) {
					printf("%s ", engWord[randomSet].meaning[i]); // 뜻 출력하고
					break; // 반복문 탈출
				}

				printf("%s ", engWord[randomSet].meaning[i]); //뜻 출력
			}

			printf("-> ");
	
			scanf("&s", wordAns); //사용자가 화면에 나와있는 뜻을 보고 영단어 입력
			if (strcmp (wordAns, ".quit") == 0) {
				break; //사용자로부터 입력받은 wordAns의 값이 .quit인 경우 입력 종료
			}

			// 정답 & 오답 확인 과정
			if (strcmp(engWord[randomSet].word, wordAns) == 0) {
				printf("correct!\n");
				corCnt++; //정답인 경우 correct! 출력, 정답 카운트 corCnt++;
			}

			else {
				printf("incorrect!\n");
				incorCnt++;
			}

			quizCnt++; //퀴즈 출력 수++;
		}

		printf("당신의 점수는 %.2f 점 입니다.\n", (((double)corCnt/(double)quizCnt)) * 100.0);
	}

	//명세 : 엔터 누르면 초기 메뉴로 이동
	getchar(); // 엔터 읽어들임, 리턴값 : int
	
	while(1) {
		if ((enter = getchar()) == '\n') {
			break;
		}
	}
}

//******************************************************************
// 2번 기능 : 플래시 카드
//******************************************************************

//기능 2. 속도, 파일명, 출력방식 입력받기
void choose_setting2(int *speed, int *day_file, int *output_way) {
	printf("속도(초) : ");
	scanf("%d\n", speed);

	printf("파일명(일차) : ");
	scanf("%d\n", day_file);

	printf("출력 방식(알파벳 순서대로 : 1, 무작위 : 2) : ");
	scanf("%d\n", output_way);

	//화면 비우기
	system("clear");

}

// 플래시카드 단어 내용 출력
void flash_card(LinkedList *linkedList) {
	int speed; //속도
	int day_file; //파일명 (일차)
	int output_way; //출력 방식 (알파벳 순서대로 : 1, 무작위 : 2)
	int engWordCnt = 0; //파일에 저장되어있는 단어 개수 저장 변수
	int quizCnt = 0; //카운트를 늘려가며 engWordCnt만큼의 게임 진행
	char wordArr[300]; //단어 저장을 위한 배열
	int randomSet = 0; //무작위 생성 시 랜덤 설

	EngWord *engWord; //노드 순회하며 읽어올 단어 구조체
	Node *chooseFile; //사용자가 선택한, 플래시카드를 진행할 파일명 노드
	FILE *fptr; //파일 포인터

	//속도, 파일명, 출력방식 입력받아 speed, day_file, output_way에 저장하고 화면 clear
	choose_setting2(&speed, &day_file, &output_way);

	chooseFile = findFile(linkedList, day_file); //사용자가 입력한 파일명 가진 노드 찾아 chooseFile에 저장

	engWordCnt = calcWordCount(chooseFile -> fileName); //chooseFile의 단어 개수 저장
	engWord = (EngWord *)malloc(sizeof(EngWord)*engWordCnt); //단어 개수만큼 동적 메모리 할당

	fptr = fopen(chooseFile -> fileName, "r"); //읽기 모드로 fileName 이름의 파일 오픈, 파일포인터에 저장

	//입력한 파일명이 존재하지 않을 경우
	if (fptr == NULL) {
		printf("입력한 파일명이 존재하지 않습니다.\n");
		exit(1);
	}

	for (quizCnt = 0; quizCnt < engWordCnt; quizCnt++) {
		memset(wordArr, 0, 300);//단어 저장 배열 모두 0으로 초기화
		

		fgets(wordArr, sizeof(wordArr), fptr); //파일 포인터에 wordArr 만큼의 문자열 읽어들임
		splitWordByToken(&engWord[quizCnt], wordArr); //wordArr 배열을 구조체에 토큰으로 넣는 작업
		quizCnt++; //다음 단어도 구조체로
	}

	printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n");
	
	//------출력 방식대로 플래쉬카드 기능 수행------
	if (output_way == 1) { // 알파벳 순서대로 출력
		while (quizCnt != engWordCnt) { //파일에 저장되어있는 단어 개수만큼 반복하여 문제 출제
			printf("\n\n\n");
			printf("\t\t\t%s\n", engWord[quizCnt].word); //화면의 중앙 부분에 플래쉬카드 출력
			sleep(speed); //사용자가 입력한 시간만큼 지연시키는 작업

			system("clear"); //화면 지우고

			printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n");
			printf("\n\n\n");
			printf("\t\t\t"); // 단어의 뜻 출력을 위해 위의 설정과 동일하게 화면의 중앙 부분에 str 출력

			for (int i = 0; i < engWord[quizCnt].meaningCnt; i++) {

				//뜻 출력 과정 중에 마지막으로 저장된 뜻을 출력할 때
				if (engWord[quizCnt].meaningCnt -1 == i) { //뜻: 최대 3개, 3-1 == (i = 2)
					printf("%s ", engWord[quizCnt].meaning[i]); //뜻 출력하고
					break; //for 반복문 탈출
				}

				printf("%s ", engWord[quizCnt].meaning[i]); //뜻 출력
			}

			sleep(speed); //사용자가 입력한 시간만큼 출력 시간 지연
			quizCnt++;
		}
	}

	else if (output_way == 2) { //무작위 출력
		srand(time(NULL)); // 여러번 실행 했을 때 같은 난수 나오지 않도록 시행마다 다른 값 출력

		while (quizCnt != engWordCnt) {
			randomSet = rand() % engWordCnt; // 단어 개수 만큼의 랜덤 세팅
			
			printf("\n\n\n");
			printf("\t\t\t%s\n", engWord[randomSet].word); //random으로 세팅된 번호로 구조체의 영단어 가져옴
			sleep(speed); //사용자가 입력한 시간만큼 지연시키는 작업

			system("clear"); //화면 지움

			printf(">> 영어 단어 암기 프로그램 : 플래쉬카드 <<\n");
			printf("\n\n\n");
			printf("\t\t\t");

			for (int i = 0; i < engWord[randomSet].meaningCnt; i++) {
				if (engWord[randomSet].meaningCnt - 1 == i) {
					printf("%s ", engWord[randomSet].meaning[i]);
					break;
				}

				printf("%s ", engWord[randomSet].meaning[i]);
			}

			sleep(speed);
			quizCnt++;
		}
	}

	//모든 단어의 출력이 끝나면 메인 메뉴 화면으로 돌아가도록 설정


}
