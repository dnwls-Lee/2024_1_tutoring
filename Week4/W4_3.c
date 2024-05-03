//3번 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int M, N, low, high; //M은 행, N은 열, low는 행 또는 열 중에 작은 것
	scanf("%d %d", &M, &N); //행, 열 입력
	if (M > N) { low = N; high = M; } //행 열 크기 비교 후 low, high에 넣음
	else { low = M; high = N; }

	int **A = (int**)malloc(sizeof(int*) * N); //행렬 A 동적할당
	for (int i = 0; i < N; i++) {
		A[i] = (int*)malloc(sizeof(int) * M);
	}
	int **AT = (int**)malloc(sizeof(int*) * M); //행렬 AT 동적할당
	for (int i = 0; i < M; i++) {
		AT[i] = (int*)malloc(sizeof(int) * N);
	}
	int **Sum = (int**)malloc(sizeof(int*) * low); //행렬 A*AT 동적할당
	for (int i = 0; i < low; i++) {
		Sum[i] = (int*)malloc(sizeof(int) * low);
	}
	int **Sum2 = (int**)malloc(sizeof(int*) * high); //행렬 A*AT 동적할당
	for (int i = 0; i < high; i++) {
		Sum2[i] = (int*)malloc(sizeof(int) * high);
	}

	for (int i = 0; i < N; i++) { //행렬 A 입력받고 A transpose 값 넣기
		for (int j = 0; j < M; j++) {
			int random = rand() % 21 - 10;
			A[i][j] = random;
			AT[j][i] = A[i][j];
		}
	}
	printf("\n");
	for (int i = 0; i < N; i++) { //행렬 A 출력
		for (int j = 0; j < M; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < M; i++) { //행렬 AT 출력
		for (int j = 0; j < N; j++) {
			printf("%d ", AT[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < low; i++) { //행렬 곱 Sum 구하기
		for (int j = 0; j < low; j++) {
			Sum[i][j] = 0;
			for (int k = 0; k < high; k++) {
				Sum[i][j] += A[i][k] * AT[k][j];
			}
		}
	}
	printf("\n");
	for (int i = 0; i < low; i++) { //행렬곱 A*AT 출력
		for (int j = 0; j < low; j++) {
			printf("%d ", Sum[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < high; i++) { //행렬 곱 Sum2 구하기
		for (int j = 0; j < high; j++) {
			Sum2[i][j] = 0;
			for (int k = 0; k < low; k++) {
				Sum2[i][j] += A[k][j] * AT[i][k];
			}
		}
	}
	printf("\n");
	for (int i = 0; i < high; i++) { //행렬곱 A*AT 출력
		for (int j = 0; j < high; j++) {
			printf("%d ", Sum2[i][j]);
		}
		printf("\n");
	}
}