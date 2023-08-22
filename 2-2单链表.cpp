//带头结点的单链表
#include<iostream>
using namespace std;

struct lnode{
int data;
lnode *next;
};

bool initial(lnode* &head);
bool insert(lnode* &head,int i,int num);
bool insertNext(lnode* &node,int num);
bool insertPerior(lnode* &node,int num);
bool remove(lnode* &head,int i,int &num);
bool removeI(lnode* &node);
int main(){
lnode *head;
initial(head);
insert(head,1,6);
insert(head,2,5);
cout<<head->next->next->data;
return 0;
}


bool initial(lnode* &head){
    head=new lnode;
    if(head==NULL) return false;
    head->next = NULL;
    return true;
}
bool insert(lnode* &head,int i,int num){//在第i个位置上插入结点
if(i<1) return false;//
lnode*p=head;//指向头结点
int j=0;//计数器
while(p!=NULL&&j<i-1){
p=p->next;
j++;
}
if(p==NULL) return false;
lnode* newnode= new lnode;
newnode->data=num;
newnode->next=p->next;
p->next=newnode;
return true;
}

bool insertNext(lnode* &node,int num){//后插结点
if(node==NULL) return 0;
lnode* newnode=new lnode;
if(newnode==NULL) return 0;
newnode->data=num;
newnode->next=node->next;
node->next=newnode;
return 1;
}
bool insertPerior(lnode* &node,int num){//前插结点
    if(node==NULL) return 0;
    lnode* newnode= new lnode;
    newnode->data=node->data;
    newnode->next=node->next;
    node->data=num;
    node->next=newnode;
    return 1;
}
bool remove(lnode* &head,int i,int &num){//删除第i个节点
    if(i<1) return 0;
    lnode* p=head;
    int j=0 ;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if (p==NULL) return 0;
    lnode *q=p->next;
    num=q->data;
    p->next=q->next;
    delete q;
    return 1;
}
bool removeI(lnode* &node){//删除指定结点
   if(node==NULL) return false;
   lnode* p=node->next;
   node->data=p->data;
   node->next=p->next;
   delete p;
   return 1;
}