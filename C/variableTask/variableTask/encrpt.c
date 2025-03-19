#include<stdio.h>

void main() {
	//문자와 정수의 연산의 결과는 정수이다(아스키코드
	char pw[12] = "KoeunSung32";
	char en_pw[12] = "";
	const int KEY = 3;//상수

	char de_pw[12] = "";

	for (int i = 0;i < sizeof(pw); i++) {
		en_pw[i] += (char)(pw[i] + KEY);
	}

	printf("기본 : ");
	for (int i = 0; i < sizeof(pw);i++) {
		printf("%c", pw[i]);
	}

	printf("\n암호화 : ");
	for (int i = 0; i < sizeof(pw);i++) {
		printf("%c", en_pw[i]);
	}

	for (int i = 0;i < sizeof(en_pw); i++) {
		de_pw[i] += (char)(en_pw[i] -KEY);
	}

	printf("\n복호화 : ");
	for (int i = 0; i < sizeof(de_pw);i++) {
		printf("%c", de_pw[i]);
	}


}

/*
단방향 암호화 : 둘다 암호화를 한 다음에 암호화 한거끼리 비교한다
양방향 암호화 : 암호화 + 복호화를 둘다 진행한다.
*/