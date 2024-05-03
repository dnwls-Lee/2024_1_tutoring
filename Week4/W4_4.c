#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double swap(double** arr, int i, int N) {
	double temp;
	for (int j = 0; j < N; j++) {
		temp = ((-1) * arr[0][j]);
		arr[0][j] = arr[i][j];
		arr[i][j] = temp;
	}
}

double cal(double** arr, int i, int n, int N) {
	double l = arr[i][n], m = arr[n][n];
	for (int k = n; k < N; k++) {
		arr[i][k] = arr[i][k] + (arr[n][k] * (-1) * l / m);
	}
}

int main() {
	int N; // N * N의 배열을 만들기 위한 변수
	double Sum = 1; // 최종 결과 값을 도출해내기 위한 변수
	scanf("%d", &N);

	double** arr; // N * N 행렬을 만드는 배열
	arr = (double**)malloc(sizeof(double*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (double*)malloc(sizeof(double) * N);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%lf", &arr[i][j]);
		}
	}

	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%.2lf ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int n = 0; n < N-2; n++) { // 가우스 소거법 사용하기 위한 FOR문
		if (arr[n][n] == 0) { // (n, n)이 0이 아니도록 하기 위한 IF문
			for (int i = n; i < N; i++) { // 1번째 값이 0 일 때 0이 아닌 밑의 값과 바꾸기 위한 for문
				if (arr[i][0] != 0) { 
					swap(arr, i, N); // 두 개의 행을 바꾸기 위한 swap 함수 호출
					for (int j = 0; j < N; j++) {
						for (int l = 0; l < N; l++) {
							printf("%.2lf ", arr[j][l]);
						}
						printf("\n");
					}
					break;
				}
			}
			printf("\n");
			for (int i = 0; i < N; i++) { // 행의 첫 번째 요소가 0 이 아닐 때만 계산하도록 if문 설정
				if (arr[i][n] != 0 && i != n) {
					cal(arr, i, n, N); // 행렬식 계산하는 cal 함수 호출
					for (int j = 0; j < N; j++) {
						for (int l = 0; l < N; l++) {
							printf("%.2lf ", arr[j][l]);
						}
						printf("\n");
					}
					printf("\n");
				}
			}
		}
		else {
			for (int i = n; i < N; i++) {
				if (arr[i][n] != 0 && i != n) {
					cal(arr, i, n, N);
					for (int j = 0; j < N; j++) {
						for (int l = 0; l < N; l++) {
							printf("%.2lf ", arr[j][l]);
						}
						printf("\n");
					}
					printf("\n");
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%.2lf ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < N; i++) {
		Sum *= arr[i][i];
	}
	printf("%lf", Sum);
}