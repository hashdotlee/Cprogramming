#include<stdio.h>
#include<stdlib.h>

typedef struct  {

	char phone[11];
	char name[40];
	char email[40];
} phone_t;
int main(){
	printf("How many records do you want to save?");
	int n; scanf("%d", &n);
	phone_t * phonebook = (phone_t *) malloc(n*sizeof(phone_t));	
	for(int i = 0; i < n; i++){
		printf("Enter the name: "); scanf("%s", (phonebook+i)->name);
		printf("Enter the email: "); scanf("%s", (phonebook+i)->email);
		printf("Enter the phone: "); scanf("%s", (phonebook+i)->phone);
	}
	printf("Enter data success\n");
	FILE * fileOut = fopen("phonebook.dat", "w+");
	if(fileOut == NULL){printf("Cannot open file\n"); exit(1);}
	fwrite(phonebook, sizeof(phone_t),n, fileOut);
	fclose(fileOut);
	free(phonebook);
	return 0;
}
