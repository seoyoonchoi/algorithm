#include<stdio.h>

void main() {
	//���ڿ� ������ ������ ����� �����̴�(�ƽ�Ű�ڵ�
	char pw[12] = "KoeunSung32";
	char en_pw[12] = "";
	const int KEY = 3;//���

	char de_pw[12] = "";

	for (int i = 0;i < sizeof(pw); i++) {
		en_pw[i] += (char)(pw[i] + KEY);
	}

	printf("�⺻ : ");
	for (int i = 0; i < sizeof(pw);i++) {
		printf("%c", pw[i]);
	}

	printf("\n��ȣȭ : ");
	for (int i = 0; i < sizeof(pw);i++) {
		printf("%c", en_pw[i]);
	}

	for (int i = 0;i < sizeof(en_pw); i++) {
		de_pw[i] += (char)(en_pw[i] -KEY);
	}

	printf("\n��ȣȭ : ");
	for (int i = 0; i < sizeof(de_pw);i++) {
		printf("%c", de_pw[i]);
	}


}

/*
�ܹ��� ��ȣȭ : �Ѵ� ��ȣȭ�� �� ������ ��ȣȭ �Ѱų��� ���Ѵ�
����� ��ȣȭ : ��ȣȭ + ��ȣȭ�� �Ѵ� �����Ѵ�.
*/