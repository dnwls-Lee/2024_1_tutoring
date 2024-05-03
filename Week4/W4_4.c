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
	int N; // N * N�� �迭�� ����� ���� ����
	double Sum = 1; // ���� ��� ���� �����س��� ���� ����
	scanf("%d", &N);

	double** arr; // N * N ����� ����� �迭
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

	for (int n = 0; n < N-2; n++) { // ���콺 �ҰŹ� ����ϱ� ���� FOR��
		if (arr[n][n] == 0) { // (n, n)�� 0�� �ƴϵ��� �ϱ� ���� IF��
			for (int i = n; i < N; i++) { // 1��° ���� 0 �� �� 0�� �ƴ� ���� ���� �ٲٱ� ���� for��
				if (arr[i][0] != 0) { 
					swap(arr, i, N); // �� ���� ���� �ٲٱ� ���� swap �Լ� ȣ��
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
			for (int i = 0; i < N; i++) { // ���� ù ��° ��Ұ� 0 �� �ƴ� ���� ����ϵ��� if�� ����
				if (arr[i][n] != 0 && i != n) {
					cal(arr, i, n, N); // ��Ľ� ����ϴ� cal �Լ� ȣ��
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