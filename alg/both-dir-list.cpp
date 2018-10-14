#include <cstdio>
#include <cstdlib>
#include <cstring>

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


// search list
Node* listSearch(int key){
    Node *cur = nil->next;
    while(cur != nil && cur->key != key){
        cur = cur->next;
    }
    return cur;
}


// delete list
void deleteNode(Node *t){
    if(t==nil) return;
    t->prev->next=t->next;
    t->next->prev=t->prev;
    free(t);
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast(){
    deleteNode(nil->prev);
}

void deleteKey(int key){
    deleteNode(listSearch(key));
}

// print result
void printList(){
    Node * cur = nil->next;
    int isf = 0;
    while(1){
        if(cur==nil)break;
        printf("%d",cur->key);
        if(++isf>0)printf(" ");
        cur=cur->next;
    }
    printf("\n");
}


int main(){
    int key, n, i;
    // int size = 0;
    char con[20];
    // int np = 0, nd = 0;
    scanf("%d",&n);
    init();
    for(i=0;i<n;i++){
        scanf("%s%d", con, &key);
        if(con[0]=='i') {

            insert(key);
            // np++;
            // size++;

        }else if(con[0]=='d'){

            if(strlen(con)>6){
                if(con[6]=='F'){
                    deleteFirst();
                }else if(con[6]=='L'){
                    deleteLast();
                }
            }else{
                deleteKey(key);
                // nd++;
            }

            // size--;

        }

    }


    printList();

    return 0;

}








































