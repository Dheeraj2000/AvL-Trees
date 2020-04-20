//Insert in AvL Trees

#include <stdio.h>
#include<stdlib.h>

struct Node
{
struct Node *left;
int data;
int height;
struct Node *right;
}*root=NULL;

int NodeHeight(struct Node *p)
{
int hl,hr;
hl=p && p->left?p->left->height:0;
hr=p && p->right?p->right->height:0;
return hl>hr?hl+1:hr+1;
}


int BalanceFactor(struct Node *p)
{
int hl,hr;
hl=p && p->left?p->left->height:0;
hr=p && p->right?p->right->height:0;
return hl-hr;
}


struct Node *LLRotation(struct Node *p)
{
struct Node *pl=p->left;
struct Node *plr=pl->right;
pl->right=p;
p->left=plr;
p->height=NodeHeight(p);
pl->height=NodeHeight(pl);
if(root==p)
root=pl;
return pl;
}


struct Node *LRRotation(struct Node *p)
{
struct Node *pl=p->left;
struct Node *plr=pl->right;
pl->right=plr->left;
p->left=plr->right;
plr->left=pl;
plr->right=p;
pl->height=NodeHeight(pl);
p->height=NodeHeight(p);
plr->height=NodeHeight(plr);
if(root==p)
root=plr;
return plr;
}


struct Node *RRRotation(struct Node *p)
{
return NULL;
}
struct Node *RLRotation(struct Node *p)
{
return NULL;
}


struct Node *RInsert(struct Node *p,int key)
{
struct Node *t=NULL;
if(p==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->data=key;
t->height=1;
t->left=t->right=NULL;
return t;
}
if(key < p->data)
p->left=RInsert(p->left,key);
else if(key > p->data)
p->right=RInsert(p->right,key);

p->height=NodeHeight(p);

if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1)
return LLRotation(p);
else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
return LRRotation(p);
else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1)
return RRRotation(p);
else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)
return RLRotation(p);
return p;
}


int main()
{
    
root=RInsert(root,1);
RInsert(root,2);
RInsert(root,3);
RInsert(root,4);
RInsert(root,5);
RInsert(root,6);
RInsert(root,7);
printf("UnBalanced Tree is converted to Balanced Tree Successfully");
return 0;
}