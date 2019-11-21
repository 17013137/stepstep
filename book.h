#pragma once
#define MAX_CNT 100

typedef struct book {
	char book[20];
	char writter[20];
	char made[20];
	int borrow;
} Book;

int SaveFile(Book* list,int *num) {
	FILE *fp = fopen("booklist.txt", "wt");

	if (fp == NULL) {
		printf("\n파일 저장 실패 !!\n");
		return -1; 
	}
	for (int i = 0; i < *num; i++) {
		fprintf(fp, "%s %s %s %d\n", list[i].book, list[i].writter, list[i].made, list[i].borrow);
	}
	fclose(fp);
	printf("\n저장 완료!\n");
	return 0;
}

int LoadFile(Book* list, int *num) {
	FILE *fp = fopen("booklist.txt", "rt");
	if (fp == NULL) {
		int n = 0;
		printf("파일 불러오기 실패 !!\n");
		
		printf("\n파일을 생성하시겠습니까?(Yes = 1 , No = 0\n"); scanf("%d", &n);
		if (n == 1) {
			fp = fopen("booklist.txt", "wt");
			if (fp == NULL) {
				printf("\n파일 생성 오류로 인해 프로그램이 종료됩니다.\n");
				return -1;
			}
			fclose(fp);
			printf("\n생성완료!\n");
		}
		
	}
	for (int i = 0; ; i++, (*num)++) {
		fscanf(fp, "%s %s %s %d", list[i].book, list[i].writter, list[i].made, &list[i].borrow);
		if (feof(fp) != 0) {
			break;
		}
	}
	fclose(fp);
	printf("\n불러오기 완료 !!\n");
	return 0;

}
	
	void Borrow(Book* user, int *num){
		char title[20];
		printf("\n빌려갈 책 제목: "); scanf("%s", title);
		int cnt = 0;
		for (int i = 0; i < MAX_CNT; i++) {
			if (!strcmp(title, user[i].book)) {
				if (user[i].borrow == 1) {
					printf("\n이미 대출된 책입니다!.\n");
					break;
				}
				user[i].borrow = 1;
				printf("\n작업완료!\n");
				cnt = 1;
			}
		}
		if (cnt == 0) {
			printf("\n책을 찾을 수 없습니다.\n");
		}
}

	void Return(Book* user, int *num) {
		char title[20];
		printf("\n반납할 책 제목: "); scanf("%s", title);
		int cnt = 0;
		for (int i = 0; i < MAX_CNT; i++) {
			if (!strcmp(title, user[i].book)) {
				if (user[i].borrow == 0) {
					printf("\n이미 반납된 책입니다. \n");
					break;
				}
				user[i].borrow = 0;
				printf("\n작업완료!\n");
				cnt = 1;
			}
		}
		if (cnt == 0) {
			printf("\n책을 찾을 수 없습니다.\n");
		}
	}

	void Search(Book* user, int *num) {
		char text[20];
		printf("\n검색하실 책 제목 : "); scanf("%s", text);
		for (int i = 0; i < MAX_CNT; i++) {
			if (!strcmp(text, user[i].book)) {
				printf("%s %s %s %d\n", user[i].book, user[i].writter, user[i].made, user[i].borrow);
			}
		}

	}

	void NewBook(Book* user, int *num) {
		printf("\n  책 제목  ㅣ  작가  ㅣ  출판사  \n");
		scanf("%s %s %s", user[*num].book, user[*num].writter, user[*num].made);
		user[*num].borrow = 0;
		for (int i = 0; i < *num; i++) {
			if (!strcmp(user[*num].book,user[i].book) && !strcmp(user[*num].writter, user[i].writter)) {
				printf("\n이미 등록된 책입니다!! \n");
				break;
			}
		}
		printf("\n%s이(가) 추가되었습니다.\n",user[*num].book);
		(*num)++;
	}

	void All_Print(Book* user, int *num) {
		printf("\n모든책을 출력합니다.\n");
		for (int i = 0; i < *num; i++) {
			printf("%s %s %s %d\n", user[i].book, user[i].writter, user[i].made, user[i].borrow);
		}
	}
	