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
