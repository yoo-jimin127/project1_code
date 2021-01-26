//project1.h 영어 단어 암기 프로그램 헤더파일

#include <stdio.h>
//기성 멘토님 코멘트 : 파일 제어 함수들 stdio.h에 기본적인 것 다 있음.
#include <string.h>
#include <stdlib.h> //system("clear"); rand() 사용 등
#include <time.h> // 랜덤함수 사용 시 중복 제거
#include <unistd.h>  //sleep 함수(일정 시간 동안 실행 정지), read 함수(파일 읽어오기)
// #include <fcntl.h> //파일 제어함수


//영단어와 뜻 저장 구조체 선언
typedef struct engWord {
	char word[16]; //영단어(max 15)
	char meaning[3][31]; //영단어에 대응되는 한글 뜻 (최대 3개의 뜻, 한글 뜻 max 30자)
	int meaningCnt; //영단어에 대응되는 한글 뜻의 count
	int wordCnt; //파일에 저장되는 영단어 개수 count
	struct engWord *next;
}EngWord;

//파일 이름 저장해 연결 위한 노드 구조체
typedef struct node {
	struct node *next; //다음 단어 저장 포인터
	struct node *prev; //이전 단어 저장 포인터
	char fileName[100]; //파일 이름 저장할 멤버변수 (1.dic ~ n.dic 문자열)  
}Node;

//파일 목록들 저장해놓는 연결리스트
typedef struct linkedLIst {
	Node *head; //이중 연결리스트의 head 노드
	Node *tail; //이중 연결리스트의 tail 노드
	int fileCnt; //연결리스트에 저장되어있는 파일 개수 count
}LinkedList;

//---------함수 선언----------

// 연결리스트 관련 함수 선언부
void *makeNode (char *fileName);
void addNode (LinkedList *linkedList, Node *node);
void initList (LinkedList *linkedList);
Node *findFile (LinkedList *linkedList, int day_file);
int calcWordCount (char *fileName);
void addFileToList (Node *node);
void splitWordByToken (EngWord *engWord, char *wordArr);

//1번 기능
void choose_setting1(int *day_file, int *output_way);
void word_quiz(LinkedList *linkedList);

//2번 기능
void choose_setting2(int *speed, int *day_file, int *output_way);
void flash_card(LinkedList *linkedList);

//3번 기능

//4번 기능
