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
		printf("\n���� ���� ���� !!\n");
		return -1; 
	}
	for (int i = 0; i < *num; i++) {
		fprintf(fp, "%s %s %s %d\n", list[i].book, list[i].writter, list[i].made, list[i].borrow);
	}
	fclose(fp);
	printf("\n���� �Ϸ�!\n");
	return 0;
}

int LoadFile(Book* list, int *num) {
	FILE *fp = fopen("booklist.txt", "rt");
	if (fp == NULL) {
		int n = 0;
		printf("���� �ҷ����� ���� !!\n");
		
		printf("\n������ �����Ͻðڽ��ϱ�?(Yes = 1 , No = 0\n"); scanf("%d", &n);
		if (n == 1) {
			fp = fopen("booklist.txt", "wt");
			if (fp == NULL) {
				printf("\n���� ���� ������ ���� ���α׷��� ����˴ϴ�.\n");
				return -1;
			}
			fclose(fp);
			printf("\n�����Ϸ�!\n");
		}
		
	}
	for (int i = 0; ; i++, (*num)++) {
		fscanf(fp, "%s %s %s %d", list[i].book, list[i].writter, list[i].made, &list[i].borrow);
		if (feof(fp) != 0) {
			break;
		}
	}
	fclose(fp);
	printf("\n�ҷ����� �Ϸ� !!\n");
	return 0;

}
	
	void Borrow(Book* user, int *num){
		char title[20];
		printf("\n������ å ����: "); scanf("%s", title);
		int cnt = 0;
		for (int i = 0; i < MAX_CNT; i++) {
			if (!strcmp(title, user[i].book)) {
				if (user[i].borrow == 1) {
					printf("\n�̹� ����� å�Դϴ�!.\n");
					break;
				}
				user[i].borrow = 1;
				printf("\n�۾��Ϸ�!\n");
				cnt = 1;
			}
		}
		if (cnt == 0) {
			printf("\nå�� ã�� �� �����ϴ�.\n");
		}
}

	void Return(Book* user, int *num) {
		char title[20];
		printf("\n�ݳ��� å ����: "); scanf("%s", title);
		int cnt = 0;
		for (int i = 0; i < MAX_CNT; i++) {
			if (!strcmp(title, user[i].book)) {
				if (user[i].borrow == 0) {
					printf("\n�̹� �ݳ��� å�Դϴ�. \n");
					break;
				}
				user[i].borrow = 0;
				printf("\n�۾��Ϸ�!\n");
				cnt = 1;
			}
		}
		if (cnt == 0) {
			printf("\nå�� ã�� �� �����ϴ�.\n");
		}
	}

	void Search(Book* user, int *num) {
		char text[20];
		printf("\n�˻��Ͻ� å ���� : "); scanf("%s", text);
		for (int i = 0; i < MAX_CNT; i++) {
			if (!strcmp(text, user[i].book)) {
				printf("%s %s %s %d\n", user[i].book, user[i].writter, user[i].made, user[i].borrow);
			}
		}

	}

	void NewBook(Book* user, int *num) {
		printf("\n  å ����  ��  �۰�  ��  ���ǻ�  \n");
		scanf("%s %s %s", user[*num].book, user[*num].writter, user[*num].made);
		user[*num].borrow = 0;
		for (int i = 0; i < *num; i++) {
			if (!strcmp(user[*num].book,user[i].book) && !strcmp(user[*num].writter, user[i].writter)) {
				printf("\n�̹� ��ϵ� å�Դϴ�!! \n");
				break;
			}
		}
		printf("\n%s��(��) �߰��Ǿ����ϴ�.\n",user[*num].book);
		(*num)++;
	}

	void All_Print(Book* user, int *num) {
		printf("\n���å�� ����մϴ�.\n");
		for (int i = 0; i < *num; i++) {
			printf("%s %s %s %d\n", user[i].book, user[i].writter, user[i].made, user[i].borrow);
		}
	}
	