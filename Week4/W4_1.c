//1�� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	while (1) { //������ ��� �Է¹ޱ� ���� while�� ����
		char *input; //���ڿ��� �Է¹ޱ� ���� ����
		int n; //���ڿ��� ���̸� �Է¹޴� ����
		printf("���̸� �Է��ϼ��� : ");
		scanf("%d", &n);

		input = (char*)malloc(sizeof(char) * n); // ���� n ��ŭ �����Ҵ�
		printf("���� �ϳ��� �Է��ϼ��� : ");
		scanf("%s", input);

		if (input[0] == '0') // '0' �Է¹����� while�� Ż��
			break;
		else {
			printf("�Է��� ������ : ");
			for (int i = 0; i < n; i++) { //�ƽ�Ű�ڵ尡 '0' ~ '9' �����̸� ���
				if (input[i] <= '9' && input[i] >= '0')
					printf("%d", input[i] - 48);
			}
			printf("\n");
		}
	}

	return 0;
}