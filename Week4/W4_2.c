//2�� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

temp[20] = { 0 }; // ũ�⸦ ���� ���� ���� �ӽ������ϴ� ��������

int merge(int *arr, int left, int right, int mid) {
	int cnt = 0; // temp �迭�� ���� �����ϱ� ���� ����
	int i = left, j = mid + 1;
	while (i <= mid && j <= right) { //���� �迭�̳� ������ �迭�� ������ �� temp �迭�� �� ������ �ݺ�
		if (arr[i] < arr[j]) { //���� �迭�� �ִ� ���� ������ �迭�� �ִ� ������ ���� ��
			temp[cnt] = arr[i]; cnt++; i++; //temp �迭�� ���� �迭�� �ִ� �� �ְ� 1�� �߰�
		}
		else {
			temp[cnt] = arr[j]; cnt++; j++; //temp �迭�� ������ �迭�� �ִ� �� �ְ� 1�� �߰�
		}
	}
	if (i <= mid) { //���� �迭�� �ִ� ���� temp �迭�� �� ���� ������ ��
		while (i <= mid) { //���� �迭�� �ִ� ���� ������ �� �� ������ temp�� �� �ֱ�
			temp[cnt] = arr[i];
			i++; cnt++;
		}
	}
	else {
		while (j <= right) { //������ �迭�� �ִ� ���� temp �迭�� �� ���� ������ ��..
			temp[cnt] = arr[j];  
			j++; cnt++;
		}
	}
	for (int k = left, l = 0; k <= right; k++, l++) //temp �迭���� ũ�� ������ ������ ������ arr �迭�� ����ֱ�
		arr[k] = temp[l];
}

int mergesort(int *arr, int left, int right) {
	int mid = (left + right) / 2; // �߰����� ���ϱ� ���� ����

	if (left < right) { //ũ�Ⱑ 1�� �迭�� �� ������ ������
		mergesort(arr, left, mid); // ������ �迭 ������
		mergesort(arr, mid + 1, right); // �������� �迭 ������
		merge(arr, left, right, mid); // ũ�Ⱑ 1��ŭ �� �پ��� �� ũ�� ���ϱ� ���� merge �Լ� ȣ��
	}
}

int main() {
	srand(time(NULL));
	int arr[20] = { 0 }; //���� 20���� �����ϱ� ���� �迭

	for (int i = 0; i < 20; i++) {
		int random = rand() % 201 - 100;
		arr[i] = random;
	}
	mergesort(arr, 0, 19); // left = 0. right = 19�� �ΰ� arr �迭 ���������ϵ��� mergesort �Լ� ȣ��

	for (int i = 0; i < 20; i++) // ���������� �� arr �迭 ���
		printf("%2d ", arr[i]);
}