# README - Yoo Ji Min 

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

<span style="color:red"> 중요 내용 </span>
