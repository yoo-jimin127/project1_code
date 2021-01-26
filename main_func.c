// 프로그램 실행 시 가장 처음 등장하는 메뉴 화면

#include "project1.h"

void first_func(LinkedList *list); //영어 단어 맞추기
void second_func(LinkedList *list); //플래쉬 카드
void third_func(LinkedList *list); //행맨
void fourth_func(LinkedList *list); //단어장 관리

int main (void) {
	int user; // 사용자가 선택한 단어장 기능
	LinkedList list; //파일목록 담긴 연결리스트

	printf(">> 영어 단어 암기 프로그램 <<");

	printf("1. 영어 단어 맞추기 \t 2. 플래쉬 카드\n");
	printf("3. 행맨(hangman) \t 4. 단어장 관리\n");
	printf("5. 프로그램 종료\n\n");

	printf("번호를 선택하세요: ");
	scanf("%d", &user);

	switch (user) {
		
		case 1 : 
			//영어 단어 맞추기 기능
			first_func(&list);
			break;

		case 2 :
			//플래쉬 카드 기능
			second_func(&list);
			break;

		case 3 : 
			//행맨 기능
			third_func(&list);
			break;

		case 4 :
			//단어장 관리 기능
			fourth_func(&list);
			break;

		case 5 :
			system("clear");
			return 0;

	}

	return 0;
}

void first_func (LinkedList *linkedList) {
	word_quiz(linkedList);
}

void second_func (LinkedList *linkedList) {
	flash_card(linkedList);
}

void third_func (LinkedList *linkedList) {
	hangman_game(linkedList);
}

void fourth_func (LinkedList *linkedList) {
	manage_voca(linkedList);
}
