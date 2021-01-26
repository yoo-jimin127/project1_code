// main_menu.c : 프로그램 실행 시 가장 처음에 등장하는 메뉴화면

#include <stdio.h>
#include <stdlib.h> //system("clear"); rand() 사용 등
#include <unistd.h>  //sleep 함수(일정 시간 동안 실행 정지), read 함수(파일 읽어오기)


int main (void) {
	int user; // 사용자가 선택한 영어 단어 암기 프로그램 기능
	int day_file; // 단어장(일차)
	int output_way; // 출력 방식

	printf(">> 영어 단어 암기 프로그램 <<\n");

	printf("1. 영어 단어 맞추기 \t 2. 플래쉬카드 \n");
	printf("3. 행맨(hangman) \t 4. 단어장 관리 \n");
	printf("5. 프로그램 종료\n\n");

	printf("번호를 선택하세요: ");
	scanf("%d\n", &user);

	switch (user) {
		case 1 : 
			printf("파일명(일차) : ");
			scanf("
