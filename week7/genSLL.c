#include "genSLL.h"
#include<stdio.h>
#include<stdlib.h>

node * getPrev(){
    prev = root;
    while(prev->next!=cur){
        prev = prev->next; 
    }
    return prev;
}

node * makeNewNode(elementtype data){
    node* new_node = (node *) malloc (sizeof(node)); 
    new_node->addr = data;
    new_node->next = NULL;
    return new_node;
}
elementtype readNode(){
    elementtype data;
    printf("Name: "); scanf("%s", data.name);
    printf("Email: "); scanf("%s", data.email);
    printf("Phone: "); scanf("%s", data.tel);
    return data;
}

void displayNode(node* node){
    printf("%s\t%s\t%s\n", node->addr.name, node->addr.email, node->addr.tel);
}

node* insertAtHead(elementtype data){
    node* newNode = makeNewNode(data);
    newNode->next = root; cur = root;
    root = newNode;
    return root;
}

node* insertAfterCurrent(node* newNode){
    if(root==NULL){
        root=newNode;
        cur=root;
    }
    else if(cur==NULL){
        return NULL; 
    }
    else{
        newNode->next = cur->next;
        cur->next = newNode;
        cur = cur->next;
    }
    return cur;
}
node* insertBeforeCurrent(node* newNode){
    if(root==NULL){
        root=newNode;
        cur=root;
    }
    else if(cur==NULL){
        return NULL; 
    }
    else{
        prev = getPrev();
        newNode->next = cur;
        prev->next = newNode;
        cur = prev->next;
    }
    return cur;
}
void traversingList(){
    node* cur = root;
    while(cur != NULL){
        displayNode(cur);
        cur = cur->next;
    }
}

void deleteAll(){
    node* del;
    while(root!=NULL){
        del = root; 
        root = del->next;
        free(del);
    }
}

void deleteFirstElement(){
    node* del;
    if(root == NULL) return;
    del = root;
    root = del->next;
    free(del);
}

void deleteAtCurrentPosition(){
    if(cur==NULL) return;
    if(cur==root) deleteFirstElement();
    prev = getPrev();
    prev->next = cur->next;
    free(cur);
    cur = prev->next;
}

void list_reverse(){
    cur = prev = NULL;
    while(root!=NULL){
        cur=root;
        root=root->next;
        cur->next = prev;
        prev = cur;
    }
}
