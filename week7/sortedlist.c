#include<stdio.h>
#define ID_LENGTH 40
#define NAME_LENGTH 40

typedef struct student_t {
    char id[ID_LENGTH];
    char name[NAME_LENGTH]; 
    int grade;
    struct student_t * next;
} Student;
Student * root, cur, prev;

Student *add_student(Student *root, Student *to_add){
    Student *curr_std, *prev_std = NULL;
    if(root == NULL) return to_add;
    if(to_add->grade > root->grade){
        to_add->next = root;
        return to_add;
    }
    curr_std = root;
    while(curr_std != NULL  &&  to_add->grade < curr_std->grade){
        prev_std = curr_std;
        curr_std = curr_std->next;
    }
    prev_std->next = to_add;
    to_add->next = curr_std;
    return root;
}

int main(){

    return 0;
}

