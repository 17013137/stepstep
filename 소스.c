#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "book.h"


int main() {
	int cnt = 0;
	int num = 0;
	Book *user[MAX_CNT];
	LoadFile(user, &cnt);
	while (1) {
		Screen();
		scanf("%d", &num);
		if (num == 1) {
			Borrow(user, &cnt);
		}
		else if (num == 2) {
			Return(user, &cnt);
		}
		else if (num == 3) {
			Search(user, &cnt);
		}
		else if (num == 4) {
			NewBook(user, &cnt);
		}
		else if (num == 5) {
			All_Print(user, &cnt);
		}
		else if (num == 0) {
			printf("\n프로그램이 종료되었습니다.\n");
			return -1;
		}
		else if (num == 6) {
			printf("\n프로그램이 저장되었습니다.\n");
			SaveFile(user, &cnt);
			
		}
		else {
			printf("화면에 맞는 번호를 입력해주세요.");
			getchar();
			
		}
	}
}