#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LINE 81
typedef struct {
	char model[40];
	char memory[40];
	char screen[40];
	char price[40];
} phone_t; 

struct node {
	phone_t data;
	struct node * next;
};
typedef struct node Phone;
Phone *head, *cur, *tail;

Phone * makeNode(phone_t data){
	Phone * newNode = (Phone *) malloc(sizeof(Phone));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void insertAtHead(phone_t data){
		cur = makeNode(data);
		cur->next = head;
		head = cur;
}
void importFromText(){
	FILE * fileIn = fopen("phoneDB.txt", "r");
	if(fileIn == NULL){printf("Can not read the file txt\n"); return ;}
	char buff[MAX_LINE];
	phone_t data;
	fgets(buff, MAX_LINE, fileIn);
	while(fgets(buff, MAX_LINE, fileIn)!=NULL){
		sscanf(buff, "%s %s %s %s", data.model, data.memory, data.screen, data.price);
		insertAtHead(data);
	}
	fclose(fileIn);
}
void importFromBinary(){
	FILE * fileIn = fopen("phoneDB.dat", "r");
	if(fileIn == NULL){printf("Can not read the file dat\n"); return ;}
	phone_t * data;
	while(!feof(fileIn)){
		fread(data, sizeof(phone_t), 1, fileIn);	
		insertAtHead(*data);
	}
	fclose(fileIn);
}
void displayList(){
	printf("%-15s%-15s%-15s%-15s\n", "Model", "Memory", "Screen Size", "Price");
	cur = head;
	while(cur!=NULL){
		printf("%-15s%-15s%-15s%-15s\n", cur->data.model, cur->data.memory, cur->data.screen, cur->data.price);
		cur = cur->next;
	}
}
void searchByModel(){
	printf("Enter model: ");
	char model[40];
	scanf("%s", model);
	cur = head;
	while(cur!=NULL){
		if(!strcmp(cur->data.model, model)){
			printf("What we find: model: %s|memory: %s|screen: %s|price: %s\n", cur->data.model);
			return;
		}
	}
	printf("We cannot find anything\n");

}
void searchByPrice(){
	printf("Enter price: ");
	char price[40];
	scanf("%s", price);
	cur = head;
	while(cur!=NULL){
		if(!strcmp(cur->data.price, price)){
			printf("What we find: model: %s|memory: %s|screen: %s|price: %s\n", cur->data.model, cur->data.memory, cur->data.screen, cur->data.price);
			return;
		}
	}
	printf("We cannot find anything\n");

}
void customInsert(){
printf("Print before or after\n");
printf("1. Before\n");
printf("2. After\n");
printf("Enter your choice: ");
int choice; scanf("%d", &choice);
switch(choice){

	case 1: 
		
}

}

int main(){

	return 0;
}
