// 4번째 기능 : 단어장 관리

#include "project1.h"

int user_4func;

void choose_setting4();
void addNewFile();
void addNewWord();
void watchVoca();
void watchFileList();
void manageExit();


void choose_setting4() {
	printf(">> 영어 단어 암기 프로그램 : 단어장 관리 <<");
	printf("1. 새 파일 추가하기 \t 2. 새 단어 추가하기 \n");
	printf("3. 단어장 보기 \t 4. 단어 파일 목록보기 \n");
	printf("5. 단어장 관리 종료\n\n");

	printf("번호를 입력하세요 : ");
	scanf("%d\n)", &user_4func);

	switch (user_4func) {
		
		case 1 : 
			addNewFile();
			system("clear");
			break;

		case 2 :
			addNewWord();
			system("clear");
			break;

		case 3 :
			watchVoca();
			system("clear");
			break;

		case 4 :
			watchFileList();
			system("clear");
			break;

		case 5 :
			//main_menu.c로 이동
		//	main_menu
			return 0;
	}

}

// 4-1. 새 파일 추가하기
void addNewFile () {

}


// 4-2. 새 단어 추가하기
void addNewWord () {

}


// 4-3. 단어장 보기
void watchVoca () {

}


// 4-4. 단어 파일 목록 보기
void watchFileList () {

}


