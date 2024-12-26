#include<stdio.h>
#include<string.h>

struct Account {
	char tk[50];
	char mk[50];
};

void login(struct Account acc[], int n);
void saveAcc(struct Account acc[], int n);	
int readAcc(struct Account acc[]);
void dangKy(struct Account acc[], int *n);

int main(){
	struct Account acc[100];
	int n=readAcc(acc);
	int choice;
	do{
		printf("MENU\n");
		printf("1. Dang nhap\n");
		printf("2. Dang ky\n");
		printf("3. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				login(acc, n);
				break;
			case 2:
				dangKy(acc, &n);
				break;
		}
	}while(choice!=3);
}

void login(struct Account acc[], int n){
	char tk[50];
	char mk[50];
	printf("Nhap ten tai khoan: ");
	scanf("%s", &tk);
	printf("Nhap mat khau: ");
	scanf("%s", &mk);
	for(int i=0; i<n; i++){
		if(strcmp(acc[i].tk, tk)==0 && strcmp(acc[i].mk, mk)==0){
			printf("Dang nhap thanh cong\n");
			return;
		}
	}
	printf("Dang nhap that bai\n");
}

void saveAcc(struct Account acc[], int n){
	FILE *file;
	file=fopen("acc.bin", "wb");
	if(file==NULL){
		printf("Khong mo duoc file\n");
		return 1;
	}
	fwrite(acc, sizeof(struct Account), n, file);
	fclose(file);
}

int readAcc(struct Account acc[]){
	FILE *file;
	file=fopen("acc.bin", "rb");
	int n=0;
	while(fread(&acc[n], sizeof(struct Account), 1, file)){
		n++;
	}
	fclose(file);
	return n;
}

void dangKy(struct Account acc[], int *n){
	char tk[50];
	char mk[50];
	char xnmk[50];
	printf("Nhap tai khoan: ");
	scanf("%s", tk);
	for(int i=0; i<*n; i++){
		if(strcmp(acc[i].tk, tk)==0){
			printf("Tai khoan da ton tai. Hay chon ten tai khoan khac\n");
			return 0;
		}
	}
	printf("Nhap mat khau: ");
	scanf("%s", &mk);
	printf("Xac nhan mat khau: ");
	scanf("%s", &xnmk);
	if(strcmp(mk, xnmk)!=0){
		printf("Khong khop mat khau. Hay thu lai\n");
		return;
	}
	strcpy(acc[*n].tk, tk);
	strcpy(acc[*n].mk, mk);
	(*n)++;
	saveAcc(acc, *n);
	printf("Dang ky thanh cong\n");
}
