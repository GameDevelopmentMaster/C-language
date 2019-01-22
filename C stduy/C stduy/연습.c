	

#include<stdio.h>

	int main() {
		int key, num = 0, i, j;
		scanf_s("%d", &key);
		num = key;
		for (i = 0; i < key;i++) {
			for (j = key;j >0 ;j--) {
				printf("%d ", num);
				num--;
			}
			printf("\n");
			num = key * (i + 2);
		}
	}