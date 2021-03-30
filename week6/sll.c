#include<stdio.h>
#include<stdlib.h>
// define the type of data 
// declare global variable 
/*
 * root, cur, prev
 * */

// function implementation 
// usage of ds and function in program

typedef struct {
    char name[20];
    char tel[11];
    char email[25];
} address;
struct list_el{
    address addr;
    struct list_el * next;
};
typedef struct list_el node_addr;
node_addr *root, *cur;
// might not use
node_addr *prev;

node_addr * makeNewNode(address data){
    node_addr * new_node = (node_addr *) malloc (sizeof(node_addr)); 
    new_node->addr = data;
    new_node->next = NULL;
    return new_node;
}
address readNode(){
    address data;
    printf("Name: "); scanf("%s", data.name);
    printf("Email: "); scanf("%s", data.email);
    printf("Phone: "); scanf("%s", data.tel);
    return data;
}
void displayNode(node_addr * node){
    printf("%s\t%s\t%s\n", node->addr.name, node->addr.email, node->addr.tel);
}
node_addr * insertAtHead(address data){
    node_addr * new = makeNewNode(data);
    new->next = root;
    cur = root;
    root = new;
    return root;
}
node_addr * insertAfterCurrent(node_addr * cur, node_addr * new){
    if(root==NULL){
        root=new;
        cur=root;
    }
    else if(cur==NULL){
       return NULL; 
    }
    else{
    new->next = cur->next;
    cur->next = new;
    cur = cur->next;
    }
    return cur;
}
void traversingList(node_addr * root){
    node_addr * cur = root;
    while(cur->next != NULL){
        displayNode(cur);
    }
}
int main(){
    address data = readNode(); 
    root = makeNewNode(data);
    cur = root;
    printf("How many nodes do you want to add?");
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        address temp_data = readNode();
        insertAtHead(temp_data);
        displayNode(root);
    }
    printf("Insert at current\n");
    
    int choice = 0;
    while(choice!=6){
        printf("1. Insert at Head\n");
        printf("2. Insert at Current\n");
        printf("3. Traversing List\n");
        printf("Enter your choice?"); scanf("%s", choice);
    }
    return 0;
}
