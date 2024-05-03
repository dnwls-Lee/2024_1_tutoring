//3�� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int M, N, low, high; //M�� ��, N�� ��, low�� �� �Ǵ� �� �߿� ���� ��
	scanf("%d %d", &M, &N); //��, �� �Է�
	if (M > N) { low = N; high = M; } //�� �� ũ�� �� �� low, high�� ����
	else { low = M; high = N; }

	int **A = (int**)malloc(sizeof(int*) * N); //��� A �����Ҵ�
	for (int i = 0; i < N; i++) {
		A[i] = (int*)malloc(sizeof(int) * M);
	}
	int **AT = (int**)malloc(sizeof(int*) * M); //��� AT �����Ҵ�
	for (int i = 0; i < M; i++) {
		AT[i] = (int*)malloc(sizeof(int) * N);
	}
	int **Sum = (int**)malloc(sizeof(int*) * low); //��� A*AT �����Ҵ�
	for (int i = 0; i < low; i++) {
		Sum[i] = (int*)malloc(sizeof(int) * low);
	}
	int **Sum2 = (int**)malloc(sizeof(int*) * high); //��� A*AT �����Ҵ�
	for (int i = 0; i < high; i++) {
		Sum2[i] = (int*)malloc(sizeof(int) * high);
	}

	for (int i = 0; i < N; i++) { //��� A �Է¹ް� A transpose �� �ֱ�
		for (int j = 0; j < M; j++) {
			int random = rand() % 21 - 10;
			A[i][j] = random;
			AT[j][i] = A[i][j];
		}
	}
	printf("\n");
	for (int i = 0; i < N; i++) { //��� A ���
		for (int j = 0; j < M; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < M; i++) { //��� AT ���
		for (int j = 0; j < N; j++) {
			printf("%d ", AT[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < low; i++) { //��� �� Sum ���ϱ�
		for (int j = 0; j < low; j++) {
			Sum[i][j] = 0;
			for (int k = 0; k < high; k++) {
				Sum[i][j] += A[i][k] * AT[k][j];
			}
		}
	}
	printf("\n");
	for (int i = 0; i < low; i++) { //��İ� A*AT ���
		for (int j = 0; j < low; j++) {
			printf("%d ", Sum[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < high; i++) { //��� �� Sum2 ���ϱ�
		for (int j = 0; j < high; j++) {
			Sum2[i][j] = 0;
			for (int k = 0; k < low; k++) {
				Sum2[i][j] += A[k][j] * AT[i][k];
			}
		}
	}
	printf("\n");
	for (int i = 0; i < high; i++) { //��İ� A*AT ���
		for (int j = 0; j < high; j++) {
			printf("%d ", Sum2[i][j]);
		}
		printf("\n");
	}
}