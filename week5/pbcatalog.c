#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
#include<sys/ioctl.h>
#include<unistd.h>
typedef struct {
	char model[40];
	char memory[10];
	char screensize[10];
	char price[10];
} phone_t;
phone_t * phoneDB; 
int n = 0;
void convert(){
	FILE * fileIn, *fileOut;
	if((fileIn = fopen("phoneDB.txt", "r")) == NULL){printf("Cannot open file txt\n"); return;}
	if((fileOut = fopen("phoneDB.dat", "wb")) == NULL){printf("Cannot open file dat\n"); return;}
	phone_t * buff = (phone_t *)malloc(sizeof(phone_t));
	char title[81];
	fgets(title, 81, fileIn);
	printf("%s", title);
	while(fscanf(fileIn,"%s %s %s %s", buff->model, buff->memory, buff->screensize, buff->price)!=EOF){
		fwrite(buff, sizeof(phone_t), 1, fileOut);
	}
	printf("Success\n");
	free(buff);
	fclose(fileIn);
	fclose(fileOut);
}
void readApart(int begin, int end){
	FILE * fileIn;
	if((fileIn = fopen("phoneDB.dat", "rb")) == NULL){printf("Cannot handle the dat file"); return;};
	fseek(fileIn, (begin-1)*sizeof(phone_t), SEEK_SET);
	n = end - begin + 1;
	if(sizeof(*phoneDB)){
		phoneDB = realloc(phoneDB, sizeof(phone_t)*n);
	}
	else {
		phoneDB = (phone_t *)malloc(sizeof(phone_t)*n);
	}
	fread(phoneDB, sizeof(phone_t), n, fileIn);
}
void readFull(){
	FILE * fileIn;
	if((fileIn = fopen("phoneDB.dat", "rb")) == NULL){printf("Cannot handle the phoneDB.dat file"); return;};
	fseek(fileIn, 0, SEEK_SET);
	int begin = ftell(fileIn);
	fseek(fileIn, 0, SEEK_END);
	int end = ftell(fileIn);
	n = (end - begin)/sizeof(phone_t);
	fseek(fileIn, 0, SEEK_SET);
	if(sizeof(*phoneDB)){
		phoneDB = realloc(phoneDB, end-begin);
	}
	else {
		phoneDB = (phone_t *)malloc(end-begin);
	}
	while(!feof(fileIn)){
		fread(phoneDB, sizeof(phone_t), n, fileIn);
	}
	fclose(fileIn);
}
void display(){
	FILE * fileIn;
	if((fileIn = fopen("phoneDB.dat", "rb")) == NULL){printf("Cannot open the phoneDB.dat\n"); return;}
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	phone_t * buff = (phone_t *)malloc(sizeof(phone_t));
	fseek(fileIn, 0, SEEK_SET);
	int n = 0;
	while(1){
		n++;
		fread(buff, sizeof(phone_t), 1, fileIn);
		if(feof(fileIn)){
			break;
		}
		else if(n == w.ws_row){
			n = 0;
			printf("--next--");
			__fpurge(stdin);
			getchar();
		}
		printf("%s %s %s %s\n", buff->model, buff->memory, buff->screensize, buff->price);
	}
	printf("\n");
	free(buff);
	fclose(fileIn);
}
void search(char * model){
	for(int i = 0; i < n; i++){
		if(!strcmp(phoneDB[i].model, model)){
			printf("What I have found: model: %s memory: %s screensize: %s price: %s\n", phoneDB[i].model, phoneDB[i].memory, phoneDB[i].screensize, phoneDB[i].price);
			return;
		}
	
	}
	printf("Cannot not found in the memory\n");
}
int main(){
	int choice = 0;
	char isReadApart;
	char model[40];
	while(choice!=5){
		printf("1. Import DB from text\n");
		printf("2. Import from DB\n");
		printf("3. Print all DB\n");
		printf("4. Search by model\n");
		printf("5. Exit\n");

		printf("Enter your choice: "); scanf("%d", &choice);
		switch(choice){
			case 1:
				convert();
				break;
			case 2:

				printf("Do you want to read apart? (read full is default) (y/n): ");
				__fpurge(stdin);
				scanf("%c", &isReadApart);
				if(isReadApart == 'y'){
					int begin, end;
					printf("Begin record: "); scanf("%d", &begin);
					printf("End record: "); scanf("%d", &end);
					readApart(begin, end);
				}
				else if(isReadApart == 'n'){
					readFull();
				}
				break;
			case 3:
				display();
				break;
			case 4: 
				printf("Enter model you want to search for: ");
				scanf("%s", model);
				search(model);
				break;
			case 5: 
				printf("End!\n");
				break;
			default: 
				printf("Please enter your choice first\n");
				break;

		}
	}

	free(phoneDB);
	return 0;
}
