//5�� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int num[4]; // �� �ڸ����� �����ϱ� ���� �迭
	int n, l = 0, cnt = 1; // �θ����ڷ� ǥ���ϱ� ���� �Է°� n, �����Ҵ��� ��Ű�� ���� cnt, �����Ҵ��ϰ� l��° �ڸ��� �迭 ����ֵ��� �ϴ� ���� l
	scanf("%d", &n);
	printf("%d = ", n);
	for (int i = 3; i >= 0; i--) { // �� �ڸ� ���� �����ϱ� ���� for��
		num[i] = n % 10;
		n /= 10;
	}
	char* arr = { 0 }; // �θ����ڸ� �����ϱ� ���� char�� ���ڿ� arr ����
	arr = (char*)malloc(sizeof(char) * cnt); // cnt��ŭ �����Ҵ�

	printf("%d + %d + %d = ", (num[1] + num[0] * 10) * 100, num[2] * 10, num[3]);

	for (int i = 0; i < 4; i++) { // �� �ڸ� ���� �θ� ���ڷ� ǥ���ϱ� ���� 4�� for�� ����
		if (i == 0 && num[i] != 0) { // õ�� �ڸ� �� != 0 �� ��
			cnt++;
			arr = (char*)realloc(arr, sizeof(char) * cnt);
			arr[l] = 'M'; // 1ĭ��ŭ ���Ҵ� ���ְ� 1000�� ǥ���ϴ� �θ������� M�� arr�� �ֱ�
		}
		if (i == 1 && num[i] != 0) { // ���� �ڸ� �� ! = 0 �� ��
			if (num[i] % 5 == 4) { // ���� �ڸ� ���� 9 �̰ų� 4�� ��
				cnt += 2;
				arr = (char*)realloc(arr, sizeof(char) * cnt);
				arr[l] = 'C'; l++;
				if (num[i] == 9) { arr[l] = 'M'; l++; }
				else { arr[l] = 'D'; l++; } // 2ĭ �Ҵ��ϰ� 9�� �� CM, 4�� �� CD�� �ǵ��� arr�� �ֱ�
			}
			else {
				if (num[i] >= 5) { // ���� �ڸ� �� 5 �̻� �� ��
					cnt++;
					arr = (char*)realloc(arr, sizeof(char) * cnt);
					arr[l] = 'D'; l++; // 1ĭ��ŭ ���Ҵ��ϰ� �θ����� D�� arr�� �ֱ�
				}
				for (int j = 0; j < num[i] % 5; j++) { 
					cnt++;
					arr = (char*)realloc(arr, sizeof(char) * cnt);
					arr[l] = 'C'; l++; // num[1] % 5�� ��ŭ for���� ������ �� ĭ ���Ҵ��ϰ� �θ����� C�� arr�� �ֱ�
				}
			}
		}
		else if (i == 2 && num[i] != 0) {  //���� �ڸ� �� != 0�� ��
			if (num[i] % 5 == 4) { // ���� �ڸ� ���� 9 �̰ų� 4�� ��
				cnt += 2;
				arr = (char*)realloc(arr, sizeof(char) * cnt);
				arr[l] = 'X'; l++;
				if (num[i] == 9) { arr[l] = 'C'; l++; }
				else { arr[l] = 'L'; l++; } // ������ ����..
			}
			else {
				if (num[i] >= 5) { // ������ ����
					cnt++;
					arr = (char*)realloc(arr, sizeof(char) * cnt);
					arr[l] = 'L'; l++;
				}
				for (int j = 0; j < num[i] % 5; j++) {
					cnt++;
					arr = (char*)realloc(arr, sizeof(char) * cnt);
					arr[l] = 'X'; l++; // ������ ����
				}
			}
		}
		else if (i == 3 && num[i] != 0) { //���� �ڸ� �� != 0�� ��
			if (num[i] % 5 == 4) { // ������ ����
				cnt += 2;
				arr = (char*)realloc(arr, sizeof(char) * cnt);
				arr[l] = 'I'; l++;
				if (num[i] == 9) { arr[l] = 'X'; l++; }
				else { arr[l] = 'V'; l++; } //������ ����
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
					arr[l] = 'I'; l++; //������ ����
				}
			}
		}
	}
	arr[l] = '\0';
	printf("%s, %d", arr, l); //arr �迭 ����ϰ� ���� ���
}