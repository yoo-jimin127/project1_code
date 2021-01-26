//2번째 기능 : 플래쉬카드

#include "project1.h"

void choose_setting2(int *speed, int *day_file, int *output_way);
void flash_card(LinkedList *linkedList);

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
	engWord = (EngWord *)malloc(sizeof(engWordCnt)); //단어 개수만큼 동적 메모리 할당

	fptr = fopen(chooseFile -> fileName, "r"); //읽기 모드로 fileName 이름의 파일 오픈, 파일포인터에 저장

	//입력한 파일명이 존재하지 않을 경우
	if (fptr == NULL) {
		printf("입력한 파일명이 존재하지 않습니다.\n");
		exit(1);
	}

	for (quizCnt = 0; quizCnt < engWordCnt; quizCnt++) {
		for (int i = 0; i < 300; i++) {
			wordArr[i] = ""; //단어 저장 배열 모두 0으로 초기화
		}

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
정
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
			printf("\t\t\t%s\n", engWordCnt[randomSet].word); //random으로 세팅된 번호로 구조체의 영단어 가져옴
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
