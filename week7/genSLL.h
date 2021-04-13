typedef struct {
    char name[20];
    char tel[11];
    char email[25];
} elementtype;

struct list_el{
    elementtype addr;
    struct list_el * next;
};

typedef struct list_el node;
node *root, *cur;
// might not use
node *prev;

node* makeNewNode(elementtype data);
elementtype readNode();
void displayNode(node* nodePt);
node* insertAtHead(elementtype data);
node* insertAfterCurrent(node* newNode);
node* insertBeforeCurrent(node* newNode);
void traversingList();
void deleteAll();
void deleteFirstElement();
void deleteAtCurrentPosition();
void list_reverse();
