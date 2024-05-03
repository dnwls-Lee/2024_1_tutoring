//6�� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Hadamard(int **arr, int n, int x, int y) { //��ǥ���� ǥ���� x, y ���� ����
	if (n == 1) { // n = 1 �� �� ������, �Ʒ����� x, y�� �� �־��ְ�, �밢�� ���⿡�� -(x, y) �� �־��ֱ�
		arr[x + 1][y] = arr[x][y + 1] = arr[x][y];
		arr[x + 1][y + 1] = -arr[x][y];
	}
	else {
		int result = 1;
		for (int i = 1; i < n; i++) {
			result *= 2;
		}
		arr[x + result][y] = arr[x][y + result] = arr[x][y]; // �����ʰ� �Ʒ� 2 ^ (n-1) ��° �ڸ��� (x, y)�� �ְ�, �밢���� * (-1) �� �־��ְ� 2 ^ (n-1) ũ���� ��� ����
		arr[x + result][y + result] = -arr[x][y];
		Hadamard(arr, n - 1, x, y);
		Hadamard(arr, n - 1, x + result, y);
		Hadamard(arr, n - 1, x, y + result);
		Hadamard(arr, n - 1, x + result, y + result);
	}
}

int main() {
	int n, result = 1; // �� ��° �ƴٸ��� ����� ������ ������ �˱� ���� ���� n ����, 2 ^ n ���� ���¸� �����ϱ� ���� result ���� ����
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		result *= 2;
	}

	int** arr; // �ƴٸ��� ����� �����ϱ� ���� arr �迭 ����
	arr = (int**)malloc(sizeof(int*) * result);
	for (int i = 0; i < result; i++) {
		arr[i] = (int*)malloc(sizeof(int) * result);
	} // result��ŭ �迭 �Ҵ�
	arr[0][0] = 1; // �ʱⰪ ����

	if (n != 0) // n�� 0�� ������ 1�� ����ϸ� �ǹǷ� �� ���� ��츸 ����
		Hadamard(arr, n, 0, 0); // �ƴٸ��� ����� ������ �Լ� ���

	for (int i = 0; i < result; i++) {
		for (int j = 0; j < result; j++) {
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}