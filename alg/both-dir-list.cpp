#include <iostream>

// def of both-direction Node 
struct Node {
    int key;
    Node *prev, *next;
};

// initialize both-dir list
Node *nil;

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil->next=nil;
    nil->prev=nil;
}

// insert 
void insert(int key){
    Node *x = (Node *)malloc(sizeof(Node));
    x->key=key;
    // add element just after sentinnel
    x->next=nil->next;
    nil->next->prev=x;
    nil->next=x;
    x->prev=nil;
}



















