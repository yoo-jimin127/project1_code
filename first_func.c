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
					printf("%s ", engWord[quizCnt].meaning[i]; //뜻 출력하고
					break; //for 반복문 탈출
				}

				printf("%s ", engWord[quizCnt].meaning[i]); //뜻 출력
			}

			printf("-> ");

			scanf("&s", wordAns); //사용자가 화면에 나와있는 뜻을 보고 영단어 입력
			if (strcmp (wordAns, ".quit") == 0) {정
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
					printf("%s ", engWord[randemSet].meaning[i]); // 뜻 출력하고
					break; // 반복문 탈출
				}

				printf("%s ", engWord[randomSet].meaningCnt[i]); //뜻 출력
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
		if ((c = getchar()) == '\n') {
			break;
		}
}
