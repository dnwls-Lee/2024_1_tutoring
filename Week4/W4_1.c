//1번 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	while (1) { //정수를 계속 입력받기 위한 while문 선언
		char *input; //문자열을 입력받기 위한 변수
		int n; //문자열의 길이를 입력받는 변수
		printf("길이를 입력하세요 : ");
		scanf("%d", &n);

		input = (char*)malloc(sizeof(char) * n); // 길이 n 만큼 동적할당
		printf("정수 하나를 입력하세요 : ");
		scanf("%s", input);

		if (input[0] == '0') // '0' 입력받으면 while문 탈출
			break;
		else {
			printf("입력한 정수는 : ");
			for (int i = 0; i < n; i++) { //아스키코드가 '0' ~ '9' 사이이면 출력
				if (input[i] <= '9' && input[i] >= '0')
					printf("%d", input[i] - 48);
			}
			printf("\n");
		}
	}

	return 0;
}