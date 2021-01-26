#include "project1.h"

void choose_setting3();
void hangman_game(int day_file);

int day_file; //파일명(일차)

// 사용자로부터 원하는 파일명을 받아 행맨 게임에 넘겨주는 기능
void choose_setting3() {
	printf("파일명(일차) : ");
	scanf("%d\n%", &day_file);

	hangman_game(day_file);
	system("clear");
}

//행맨 게임 기능
void hangman_game(int day_file) {
	printf(">> 영어 단어 암기 프로그램 : 행맨 <<\n");

}
