//5번 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int num[4]; // 각 자리수를 저장하기 위한 배열
	int n, l = 0, cnt = 1; // 로마숫자로 표현하기 위한 입력값 n, 동적할당을 시키기 위한 cnt, 동적할당하고 l번째 자리에 배열 집어넣도록 하는 변수 l
	scanf("%d", &n);
	printf("%d = ", n);
	for (int i = 3; i >= 0; i--) { // 각 자리 수를 저장하기 위한 for문
		num[i] = n % 10;
		n /= 10;
	}
	char* arr = { 0 }; // 로마숫자를 저장하기 위한 char형 문자열 arr 선언
	arr = (char*)malloc(sizeof(char) * cnt); // cnt만큼 동적할당

	printf("%d + %d + %d = ", (num[1] + num[0] * 10) * 100, num[2] * 10, num[3]);

	for (int i = 0; i < 4; i++) { // 각 자리 수를 로마 숫자로 표현하기 위해 4번 for문 돌림
		if (i == 0 && num[i] != 0) { // 천의 자리 수 != 0 일 때
			cnt++;
			arr = (char*)realloc(arr, sizeof(char) * cnt);
			arr[l] = 'M'; // 1칸만큼 재할당 해주고 1000을 표현하는 로마숫자인 M을 arr에 넣기
		}
		if (i == 1 && num[i] != 0) { // 백의 자리 수 ! = 0 일 때
			if (num[i] % 5 == 4) { // 백의 자리 수가 9 이거나 4일 때
				cnt += 2;
				arr = (char*)realloc(arr, sizeof(char) * cnt);
				arr[l] = 'C'; l++;
				if (num[i] == 9) { arr[l] = 'M'; l++; }
				else { arr[l] = 'D'; l++; } // 2칸 할당하고 9일 땐 CM, 4일 땐 CD가 되도록 arr에 넣기
			}
			else {
				if (num[i] >= 5) { // 백의 자리 수 5 이상 일 때
					cnt++;
					arr = (char*)realloc(arr, sizeof(char) * cnt);
					arr[l] = 'D'; l++; // 1칸만큼 재할당하고 로마숫자 D를 arr에 넣기
				}
				for (int j = 0; j < num[i] % 5; j++) { 
					cnt++;
					arr = (char*)realloc(arr, sizeof(char) * cnt);
					arr[l] = 'C'; l++; // num[1] % 5번 만큼 for문을 돌려서 한 칸 재할당하고 로마숫자 C를 arr에 넣기
				}
			}
		}
		else if (i == 2 && num[i] != 0) {  //십의 자리 수 != 0일 때
			if (num[i] % 5 == 4) { // 십의 자리 수가 9 이거나 4일 때
				cnt += 2;
				arr = (char*)realloc(arr, sizeof(char) * cnt);
				arr[l] = 'X'; l++;
				if (num[i] == 9) { arr[l] = 'C'; l++; }
				else { arr[l] = 'L'; l++; } // 이전과 동일..
			}
			else {
				if (num[i] >= 5) { // 이전과 동일
					cnt++;
					arr = (char*)realloc(arr, sizeof(char) * cnt);
					arr[l] = 'L'; l++;
				}
				for (int j = 0; j < num[i] % 5; j++) {
					cnt++;
					arr = (char*)realloc(arr, sizeof(char) * cnt);
					arr[l] = 'X'; l++; // 이전과 동일
				}
			}
		}
		else if (i == 3 && num[i] != 0) { //일의 자리 수 != 0일 때
			if (num[i] % 5 == 4) { // 이전과 동일
				cnt += 2;
				arr = (char*)realloc(arr, sizeof(char) * cnt);
				arr[l] = 'I'; l++;
				if (num[i] == 9) { arr[l] = 'X'; l++; }
				else { arr[l] = 'V'; l++; } //이전과 동일
			}
			else {
				if (num[i] >= 5) {
					cnt++;
					arr = (char*)realloc(arr, sizeof(char) * cnt);
					arr[l] = 'V'; l++;
				}
				for (int j = 0; j < num[i] % 5; j++) {
					cnt++;
					arr = (char*)realloc(arr, sizeof(char) * cnt);
					arr[l] = 'I'; l++; //이전과 동일
				}
			}
		}
	}
	arr[l] = '\0';
	printf("%s, %d", arr, l); //arr 배열 출력하고 개수 출력
}