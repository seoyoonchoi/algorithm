#include<stdio.h>
void main() {
	int i = 10;
	long l = 10L;
	char c = 'a';
	float f = 3.9F;
	char* str = "ABC";
	//sizeof(�ڷ���) : �Ұ�ȣ �ȿ� �ۼ��� ���� ���� �ڷ����� ũ�⸦ �˷��ִ� �Լ��̴�.
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(str));
}