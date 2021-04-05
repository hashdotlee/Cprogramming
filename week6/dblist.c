#include<stdio.h>
#include<stdlib.h>
struct node {
	int age;
	struct node * next;
	struct node * prev;
};
typedef struct node student;
student * head;
student * tail;
student * current;

student * create(){
	student * new = (student * )malloc(sizeof(student));
	printf("Enter student age: ");scanf("%d", &new->age);
	new->next = NULL;
	new->prev = NULL;
	return new;
}
void append(){
	student * node = create();
	node->prev = tail;
	if(tail==NULL){
		head = node;
		current = node;
	}
	else {
		tail->next = node;
	}
	tail = node;
}
void insert(){
	student * node = create();
	node->next = current;
	if(current == NULL){
		head = node;
		tail = node;
	}
	else {
		node->prev = current->prev;
		current->prev->next = node;
		current->prev = node;
	}
	current = node;
}
void delete(){
	while(head!=NULL){
		current = head;
		head = head->next;
		free(current);
	}
}

int main(){
	insert();
for(int i = 0; i < 3; i++){
	append();
}
current = head;
while(current!=NULL){
	printf("Student age: %d\n", current->age);
	current = current->next;
}
current = tail;
insert();
current = tail;
while(current!=NULL){
	printf("Student age: %d\n", current->age);
	current = current->prev;
}
delete();
return 0;
}
