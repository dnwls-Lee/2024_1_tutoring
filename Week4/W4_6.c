//6번 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Hadamard(int **arr, int n, int x, int y) { //좌표축을 표현할 x, y 변수 선언
	if (n == 1) { // n = 1 일 때 오른쪽, 아래에는 x, y의 값 넣어주고, 대각선 방향에는 -(x, y) 값 넣어주기
		arr[x + 1][y] = arr[x][y + 1] = arr[x][y];
		arr[x + 1][y + 1] = -arr[x][y];
	}
	else {
		int result = 1;
		for (int i = 1; i < n; i++) {
			result *= 2;
		}
		arr[x + result][y] = arr[x][y + result] = arr[x][y]; // 오른쪽과 아래 2 ^ (n-1) 번째 자리에 (x, y)값 넣고, 대각선은 * (-1) 값 넣어주고 2 ^ (n-1) 크기의 행렬 구현
		arr[x + result][y + result] = -arr[x][y];
		Hadamard(arr, n - 1, x, y);
		Hadamard(arr, n - 1, x + result, y);
		Hadamard(arr, n - 1, x, y + result);
		Hadamard(arr, n - 1, x + result, y + result);
	}
}

int main() {
	int n, result = 1; // 몇 번째 아다마르 행렬을 구현할 것인지 알기 위해 변수 n 선언, 2 ^ n 꼴의 형태를 저장하기 위해 result 변수 선언
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		result *= 2;
	}

	int** arr; // 아다마르 행렬을 구현하기 위한 arr 배열 선언
	arr = (int**)malloc(sizeof(int*) * result);
	for (int i = 0; i < result; i++) {
		arr[i] = (int*)malloc(sizeof(int) * result);
	} // result만큼 배열 할당
	arr[0][0] = 1; // 초기값 설정

	if (n != 0) // n이 0일 때에는 1만 출력하면 되므로 그 외의 경우만 생각
		Hadamard(arr, n, 0, 0); // 아다마르 행렬을 구현할 함수 출력

	for (int i = 0; i < result; i++) {
		for (int j = 0; j < result; j++) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}