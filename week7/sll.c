#include<stdio.h>
#include<stdlib.h>
#include "genSLL.h"
// define the type of data 
// declare global variable 
/*
 * root, cur, prev
 * */

// function implementation 
// usage of ds and function in program

int main(){
    elementtype data1 = readNode(); 
    root = makeNewNode(data1);
    cur = root;
    printf("How many node do you want to add: ");
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        elementtype newData = readNode();
        insertAtHead(newData);
    }
    traversingList();
    // Test Insert At Head
    displayNode(cur);
    printf("Insert At Head\n");
    elementtype data2 = readNode(); 
    insertAtHead(data2);
    traversingList();
    // Test Insert After Current 
    printf("Insert After Current\n");
    elementtype data3 = readNode(); 
    insertAtHead(data3);
    traversingList();
    // Test Insert After Current 
    printf("Insert Before Current\n");
    elementtype data4 = readNode(); 
    insertAtHead(data4);
    traversingList();
    // Test Delete At Head 
    printf("Delete At Head\n");
    elementtype data5 = readNode(); 
    insertAtHead(data5);
    traversingList();
    // Test Delete At Current 
    printf("Delete At Current\n");
    elementtype data6 = readNode(); 
    insertAtHead(data6);
    traversingList();
    deleteAll();
    return 0;
}
