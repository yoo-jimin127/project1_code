# README - Yoo Ji Min 

## 2021.01.21 (목) 학습 내용
### 마크다운 사용 방법 익히기
1. 제목 및 부제목 작성 방법 : 제목 ===, 부제목 ---

1. 글머리 작성 방법 : #를 사용하여 #의 개수가 많아질수록 글머리 크기가 작아짐

1. 인용 방법 :
> 인용1
>> 인용2
>>> 인용3

4. 목록 :
    1. 순서가 없는 목록 : * or - 붙여 사용
    2. 순서가 있는 목록 : '숫자.' 붙여 사용, 숫자와 상관 X
   
5. 구분선 : 
    * '***'
    * '**********'
    * '---'
    * '---------'
 
6. 코드 블럭 : 
    - 한줄 : ```(악센트 기호) 사이에 넣기
    
    ex) 
    ```
    #include <stdio.h>
    
    int main (void) {
        printf("hello, world");
        return 0;
    }
    ```

7. 강조 방법 : 
    * 텍스트 굵게 :
        * *중요*한 텍스트
        * **중요**한 텍스트
    * 취소선 :
        ~~취소~~한 텍스트

8. 이미지 첨부 : ![파일명.확장자]  (이미지경로/파일명.확장자)

9. 링크 첨부 : [텍스트] (URL "URL 제목") URL 제목 생략 가능


----------

### vi 명령어 & gcc 컴파일 명령어 (주요 사용)

#### vi 편집기에서 주로 사용할 명령어 학습
* [vi 편집기 명령어] (https://iamfreeman.tistory.com/entry/vi-vim-%ED%8E%B8%EC%A7%91%EA%B8%B0-%EB%AA%85%EB%A0%B9%EC%96%B4-%EC%A0%95%EB%A6%AC-%EB%8B%A8%EC%B6%95%ED%82%A4-%EB%AA%A8%EC%9D%8C-%EB%AA%A9%EB%A1%9D)

#### gcc 컴파일 명령어 학습
* [gcc 컴파일 명령어] (https://ra2kstar.tistory.com/176)
* [gcc 컴파일 명령어 추가 설명 링크] (https://ibabo.tistory.com/87)
---------

### 프로젝트 1 영어사전 사용 함수 및 새롭게 알게 된 기능
* 영어사전 function 2 플래쉬카드 기능 
    [1초에 한번씩 데이터 출력 함수] (https://kkikkodev.tistory.com/66)
    ```
    #include <stdio.h>
    #include <windows.h>
    
    #define ONE_SECOND 1000 //1000 밀리 초 = 1초
    
    int main (int argc, char* argv[]) {
    while(1) {
        printf("1초에 한번씩 출력하기\n");
        Sleep(ONE_SECOND);
        }
    return 0;
   }
   ```
   
   * function 2 플래쉬카드 기능 
   [일정 간격마다 화면에 단어 나오고 사라지도록 하는 함수] (https://kldp.org/node/19333)
   [**function 2 중요 함수**] (https://m.blog.naver.com/PostView.nhn?blogId=cybelion&logNo=80015332914&proxyReferer=https:%2F%2Fwww.google.com%2F)
    ```
    sleep(2);
    system("clear"); //화면 지움
    system("ls"); // 현재 디렉토리 내에 있는 파일과 디렉토리 목록 출력
    system("find ./ -name 'word.txt' "); // word.txt 파일 찾고 ./word.txt 출력
    sleep(2);
    printf("sssssss\n");
    printf("AAAAA\n);
    return 0;
    ```
    
    * function 5 프로그램 종료 기능 및 조건에 따른 차등종료
    (https://m.blog.naver.com/PostView.nhn?blogId=liccorob&logNo=10151840291&proxyReferer=https:%2F%2Fwww.google.com%2F)
*******

## 2021.01.22 (금) 프로젝트 진행 내용 보고 및 학습내용

* 헤더파일 전처리 과정 중 **표준 심볼 상수 및 자료형** 에 대한 함수 사용을 위해 **<unistd.h>** 헤더파일 include
    - [<unistd.h> 헤더파일 정의 함수 및 자료형] (http://neosrtos.com/docs/posix_api/unistd.html)

* [vi 명령어(수정, 복사, 삭제 등)] (https://araikuma.tistory.com/135) : 스크롤으로 하다가 큰 일이 날 수 있음...

#### 파일 입출력 관련 명령어 및 함수
* (https://reakwon.tistory.com/39)

* [텍스트 파일을 리눅스 환경에서 읽어오기] (http://mwultong.blogspot.com/2006/11/linux-unix-txt-view-text-file.html)
    - cat, less, vi, vim text_file.txt로 읽어올 수 있음 (일차별 단어장 읽을 때 사용하기)

* **중요 내용**
[fcntl.h 헤더파일에 정의되어있는 파일 제어] (https://www.joinc.co.kr/w/Site/system_programing/File/Fcntl)

* vi 편집기 환경에서 **여러줄 주석처리** 하는 방법 :
    (https://ljs93kr.tistory.com/34)
    1. command 상태에서 v 눌러 비주얼 상태로 전환
    2. : 누른 뒤 norm i<<원하는 문자>>
    <br> ex) : norm i// -> 블록처리 된 부분 여러 줄 주석처리 
   
* 마크다운 문법에서도 html의 태그 사용이 가능함
    - 일정 부분에 색상을 지정하고 싶어 span태그에서 style="color:~"를 해주었는데 적용되지 않음..
    <br> 줄바꿈은 br 태그
-----------
### 2021.01.22 (금) 코딩 중 헷갈리거나 어려웠던 내용
- 단어가 담긴 1.dic, 2.dic, 3.dic ... 의 txt 파일이 없어 우선 해당 텍스트 파일이 있다고 가정하고 기능 구현함
    - 해당 텍스트 파일을 가지고 퀴즈를 내고, 플래쉬카드에 활용하려면 단어들을 배열에 옮겨와야 하는데, 텍스트파일을 vi 편집기 상에서 어떻게 다뤄야하는지 공부가 더 필요함
   (위의 cat이나 vi를 이용해서 text_file.txt를 읽어오는 것과 별개로 다른 함수가 필요할 것 같다)
   <br>
- 구조체와 연결리스트를 활용해서 파일 안의 단어들을 다루고, 파일 목록을 다루는 방법에 대해 빠르게 익혀야할 것 같다. 파일입출력과 특히 4번 단어장 관리 기능에서 txt 파일을 추가하고, 원래 있던 파일에 항목을 추가하는 방법 등 파일을 가지고 작업하는 부분에 대해 매우 무지함 ...
  <br>
- 깃허브 리드미 작성에서 가독성이 많이 떨어지는 것 같다 가독성 있게 시간 절약하면서 헷갈리는 내용이나 배운 내용들 정리해서 모아두는 연습 하기.

<br><br><br>
--------
## 2021.01.23. (토) 프로젝트 진행 내용 보고 및 학습내용
* 리눅스에서 텍스트 파일 생성 : touch 파일명
* [텍스트 파일 생성 관련 https://aiden1004.tistory.com/entry/%EB%A6%AC%EB%88%85%EC%8A%A4-%EA%B8%B0%EC%B4%88-%EB%AA%85%EB%A0%B9%EC%96%B4-8-txt-c-%EB%A7%8C%EB%93%A4%EA%B8%B0)
* 파일 내용 출력하기 : cat 파일명, more 파일명
    - cat 명령어 : 텍스트 파일의 내용을 화면에 연속적으로 출력함. 
        파일 내용 길다면 **화면 단위로 내용 출력**하는 more 명령어 사용
            - cat 파일명 -n : 라인 번호 붙여 출력
            - more + 시작할 행 번호 : 출력 시작할 행번호 지정
            
* [파일 관련 명령어 정리 내용] (https://coding-factory.tistory.com/501)
<br><br>
* [텍스트 파일에서 내용 읽어와 구조체에 담기 (여러 행)] (https://itng.tistory.com/145)
    - <stdio.h>에서 파일오픈(fopen) 다 해줌
```
#include <stdio.h>

struct mem {
    char name[10];
    int age;
    char sex[3];
    char city[10];
    };
    
 int main() {
    struct mem m[3];
    int i;
    FILE *f;
    f = fopen("a.txt", "r");
    
    for (i = 0; i < 3; i++)
        fscanf(f, "%s %d %s %s", &m[i].name, &m[i].age, &m[i].sex, &m[i].city);
    fclose(f);
    
    for (i = 0; i < 3; i++)
        printf("%s %d %s %s\n", m[i].name, m[i].age, m[i].sex, m[i].city);
        
    return 0;
}
```
텍스트파일의 내용 구조체에 담고, 제대로 담겼는지 확인하는 내용 예제 코드 ↑

* fopen 함수 (<stdio.h>에 fopen, fclose 모두 포함되어 있음) :
    - fopen 함수 원형 : FILE* fopen (const char* fileName, const char* fimeMode)
        - 첫번째 인자 : 파일 이름 ex) 본 프로젝트에서는 "1.dic"
        - 두번째 인자 : 파일 오픈 방식 ("r" : read mode, "w" : write mode, "a" : append mode, ...)
            [fopen/fclose] (https://blockdmask.tistory.com/392)

### 연결 리스트 관련 개념
* 연결리스트 구조체 생성 https://dojang.io/mod/page/view.php?id=645
* 노드 추가, 연결, 삭제 작업
    -  https://edps5091.tistory.com/entry/%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8%EC%82%AD%EC%A0%9C%EC%B6%94%EA%B0%80
    - https://zitto15.tistory.com/66
    - 코딩도장 : 노드 추가 함수 만들기 https://dojang.io/mod/page/view.php?id=646

* 더블링크드리스트 사용?! -> 리스트에 담아와서 알파벳 순으로 저장해서 파일 관리해야하므로 https://ndb796.tistory.com/75


* 노드 삽입 함수 구현 참고 자료 https://ndb796.tistory.com/74?category=1004654

* fgets함수 사용해 텍스트 파일 읽어오기 https://jeckl.tistory.com/entry/C%EC%96%B8%EC%96%B4-21%EA%B0%95-%ED%8C%8C%EC%9D%BC-%EC%9E%85%EC%B6%9C%EB%A0%A5-%EC%9D%BD%EA%B8%B0-fopen-fgets-fseek-feof-fclose
        -> 해당 함수 없을 때 메시지 띄우고 다시 입력받으러 가는 방법 https://jhnyang.tistory.com/199
        
* 연결리스트 노드 생성, 리스트 연결 관련 구현 참고 https://m.blog.naver.com/PostView.nhn?blogId=fldrh224728&logNo=220261949525&proxyReferer=https:%2F%2Fwww.google.com%2F

##### 01.23. 진행 내용
- 영단어 사전 내용 담을 구조체 선언, 연결리스트로 노드간 연결하는 작업 진행 중
- 단어장 1, 2, 3, 4번 기능에서 파일을 열어 구조체에 저장하는 등의 작업을 하기 위한 방법 공부
    - vi 편집기에서 텍스트파일 저장하는 방법
    - c언어에서 파일 열고, 읽어오는 함수 등
- rand함수로 무작위로 문제 나올 수 있도록 하는 방법

<br><br>
---------
### 2021.01.24 (일) 프로젝트 진행 내용 보고 및 학습내용
- 기능별로 사용할 단어장 파일(1.dic, 2.dic, 3.dic ...)을 사용자로부터 입력받을 때, 
사용자가 선택한 파일명(int형 변수 day_file)에 .dic을 붙여 해당 파일이름을 가진 단어장을 여는 방법에 대해 고민하였음
    - 01.23까지 구현 방향 :
        ```
        FILE *fptr = NULL;
        fptr = fopen ("day_file.dic", "r");
        ```
        위의 fopen에서 사용자가 입력한 day_file 변수값에 .dic 형식자를 붙이는 방법에 대해 계속 막혀있었음.
        
    - 01.24 새로운 방향 시도 :
        - [fscanf() : 숫자, 문자 등으로 구성된 데이터를 읽을 때 유용한 함수] (https://blog.naver.com/josep0302/222178670899)
        ```
        fscanf(FILE 포인터, "입력 형식 지정자", &변수명); 의 문법을 사용
        -> 내 코드에 적용하자면 
            fscanf(fptr, ".dic", &day_file); 으로 다시 해봐야겠음.
            -> 수정해야 할 사항들 :
                int형으로 지정해둔 day_file 변수를 포인터 변수로 전환
                기존에 구현해둔 함수에서 인자로 받는 day_file의 형식 수정
        ```
       -> 이 방법 아님... sprintf으로 서식 지정해서 
        - sprintf() 이용해 int형 day_file 변수로 숫자 입력받음. fopen의 리턴 값을 설정할 것.
        -> https://dojang.io/mod/page/view.php?id=352 
        - **주의** 모드 별 파일 존재할 때 열 수 O/X 있음 -> 확인하기!
        
- 파일명 노드에 저장할 때, 문자열 copy & paste 함수 **strcpy()**
    strcpy(붙여넣기 할 곳, 복사할 것)

- 단어가 담긴 구조체(EngWord), 파일명 저장 노드 구조체(Node), 파일 목록 연결리스트 구조체(LinkedList)로 연결하기 위해 
    * makeNode : 노드 생성 함수
    * addNode : 노드 추가 함수
    * initList : 연결리스트 초기화 함수
    * moveTextFile : 텍스트파일 구조체에 옮겨서 관리하는 함수 (알파벳 순으로 정렬하며 담아오기)
    * findFile : 사용자로부터 입력받은 단어장 파일을 연결리스트에서 찾는 함수
        

- 리스트의 노드를 순회하면서 찾는 파일명과 파일명이 일치한지 비교하기 위해 문자열비교함수 **strcmp()** 사용 (https://dojang.io/mod/page/view.php?id=346)


#### 01.24. (일) 프로그램 진행 내용 정리 및 문제점
    - 단어장 리스트 관리하는 자료구조 함수 정의
        - makeNode
        - addNode
        - findFile
    - 첫 화면의 switch문에서 각 case에 따라 기능별 choose_setting()함수 정의가 덜 되어서 제대로 컴파일되지 않음. choose_setting()함수에서 입력값을 넘겨주며 본 기능을 구현해야해서 함수 정의를 어서 해두고, project1.h 헤더파일에 기능 1~4까지에서 정의된 함수명들을 선언해주어야 함.
    - 파일을 가져와서 자료구조로 처리하는 함수들은 계속 구현을 하고있는 상태, 어떤 것부터 구현을 해나가야할지 정리되지 않은 상태로 계속 여기저기 조금씩 수정하다보니 속도가 나지 않음. 명세 분석했던 내용을 구체화해서 함수 간의 관계 파악 중
    - sprintf()를 이용해 파일 이름을 서식을 포함한 문자열배열에 저장하는 방법 학습, 예제코드 만들어서 fopen()해서 제대로 파일 내용 출력되는지 확인
![image](https://user-images.githubusercontent.com/66112716/105632897-f72ea000-5e98-11eb-935f-203105263311.png)


----
### 2021.01.25 (월) 프로젝트 진행 내용 보고 및 학습내용
##### 01.25 진행 계획 및 진행 
* ~~기능별 세분화~~ (연결리스트 구현 후 1..4번 기능이 가능하므로 연결리스트 관련 기능 세분화한 상태, 세분화해놓은 연결리스트 함수들 구현 마무리한 뒤 1..4번 기능 세분화 할 예정)
* 연결리스트 관련 함수 구현 마무리
    - 리스트 초기화 함수 **(01.25 진행 중)** : initList()
    - ~~노드 생성 함수~~(01.24 구현 완료) : makeNode()
    - ~~리스트에 파일명 추가 함수~~(01.24 구현 완료) : addNode()
    - ~~입력받은 파일명 리스트에서 찾는 함수~~(01.24 구현 완료) : findFile()
    - 구조체 EngWord에 텍스트파일에 저장되어있는 단어들 단어|뜻으로 구별해 저장할 함수 **(01.25 진행 중)**
    - 구조체 EngWord에 저장된 단어들 알파벳 순으로 정렬하는 함수 **(01.25 진행 중)**
    - day_file.dic의 파일명 저장된 노드들 dic.list에 저장하는 함수 **(01.25 진행 중)** : addFileToList()
    - 리스트 LinkedList에 저장된 파일명 1.dic, 2.dic ~ n.dic으로 정렬하는 함수
    
* project1.h에 구현 완료한 연결리스트 관련 함수 선언
* 1번 기능 구현

#### 01.25 학습 내용
- fgets()로 받아온 문자열을 strtok 함수를 이용해 영단어|뜻으로 분리하여 구조체에 저장하는 방법
[strtok] (https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-split)
![image](https://user-images.githubusercontent.com/66112716/105697202-9f02a700-5f47-11eb-8f16-6dcb5fe4249c.png)

- 파일 오픈(fopen())과정 중 존재하지 않는 파일 생길 때, 버퍼에 값 쓰는 fprintf()함수
    fprintf 프로토타입 : int fprintf(FILE *stream, const char *format, ...);
    리턴 값 : 파일에 성공적으로 write한 문자의 개수
[sprintf()와 fprintf() 함수 차이점, 버퍼 비우는 함수 fflush()] https://jhnyang.tistory.com/314
    ![image](https://user-images.githubusercontent.com/66112716/105698710-9612d500-5f49-11eb-9550-41ee8b1a743b.png)
    
- ~.dic 파일명을 파일목록 리스트(dic.list)에 추가하는 함수에서 스트림 위치 지정자의 위치 조절
[fseek()함수] (https://modoocode.com/72)
![image](https://user-images.githubusercontent.com/66112716/105702211-d163d280-5f4e-11eb-978b-fd4d96662b66.png)
<-> 파일명을 리스트에 추가할 때, 추가하는 위치(포인터)를 끝쪽으로 옮기기 위해 매크로상수 SEEK_END를 마지막 매개인자로 넣어줌 (기존에 저장되어있던 목록 마지막에 fprintf하여 파일명 추가)
