//3번 기능 : 행맨 게임

#include "project1.h"


// 사용자로부터 원하는 파일명을 받아 행맨 게임에 넘겨주는 기능
void choose_setting3(int *day_file) {
	printf("파일명(일차) : ");
	scanf("%d\n%", day_file);

	system("clear");
}

//행맨 게임 기능
void hangman_game(LinkedList *linkedList) {
	int day_file; //파일명(일차)
	
	choose_setting3(&day_file); //행맨 게임 진행할 파일명 읽어옴

	printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");


}

//힌트 보여주는 함수 (ex) (힌트) 코끼리)

