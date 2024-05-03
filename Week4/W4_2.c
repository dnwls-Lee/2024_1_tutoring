//2번 문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

temp[20] = { 0 }; // 크기를 비교한 후의 값을 임시저장하는 전역변수

int merge(int *arr, int left, int right, int mid) {
	int cnt = 0; // temp 배열에 값을 저장하기 위한 변수
	int i = left, j = mid + 1;
	while (i <= mid && j <= right) { //왼쪽 배열이나 오른쪽 배열이 완전히 다 temp 배열에 들어갈 때까지 반복
		if (arr[i] < arr[j]) { //왼쪽 배열에 있는 값이 오른쪽 배열에 있는 값보다 작을 때
			temp[cnt] = arr[i]; cnt++; i++; //temp 배열에 왼쪽 배열에 있는 값 넣고 1씩 추가
		}
		else {
			temp[cnt] = arr[j]; cnt++; j++; //temp 배열에 오른쪽 배열에 있는 값 넣고 1씩 추가
		}
	}
	if (i <= mid) { //왼쪽 배열에 있는 값이 temp 배열에 다 들어가지 못했을 때
		while (i <= mid) { //왼쪽 배열에 있는 값이 완전히 다 빌 때까지 temp에 값 넣기
			temp[cnt] = arr[i];
			i++; cnt++;
		}
	}
	else {
		while (j <= right) { //오른쪽 배열에 있는 값이 temp 배열에 다 들어가지 못했을 때..
			temp[cnt] = arr[j];  
			j++; cnt++;
		}
	}
	for (int k = left, l = 0; k <= right; k++, l++) //temp 배열에서 크기 순으로 정렬한 값들을 arr 배열에 집어넣기
		arr[k] = temp[l];
}

int mergesort(int *arr, int left, int right) {
	int mid = (left + right) / 2; // 중간점을 구하기 위한 변수

	if (left < right) { //크기가 1인 배열이 될 때까지 나누기
		mergesort(arr, left, mid); // 왼쪽의 배열 나누기
		mergesort(arr, mid + 1, right); // 오른쪽의 배열 나누기
		merge(arr, left, right, mid); // 크기가 1만큼 다 줄었을 때 크기 비교하기 위해 merge 함수 호출
	}
}

int main() {
	srand(time(NULL));
	int arr[20] = { 0 }; //난수 20개를 저장하기 위한 배열

	for (int i = 0; i < 20; i++) {
		int random = rand() % 201 - 100;
		arr[i] = random;
	}
	mergesort(arr, 0, 19); // left = 0. right = 19로 두고 arr 배열 병합정렬하도록 mergesort 함수 호출

	for (int i = 0; i < 20; i++) // 병합정렬한 후 arr 배열 출력
		printf("%2d ", arr[i]);
}