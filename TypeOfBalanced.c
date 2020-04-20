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

int HeightofTree(struct Node *t)  
{  
    if (t == NULL)  
    {
        return 0;  
    }
    if(t->left==NULL&&t->right==NULL)
    {
        return 0;
    }
    else
    {  
        /* This will Find the Height of each subtree */
        int LeftSubTree = HeightofTree(t->left);  
        int RightSubTree = HeightofTree(t->right);  
      
        /*Use Larger Height of each sub tree*/
        if (LeftSubTree > RightSubTree)
        {
            return(LeftSubTree + 1);  
        }  
        else
        { 
            return(RightSubTree + 1);  
        }
    }  
}  



int BalanceFactor(struct Node *p)
{
int hl,hr;
hl=HeightofTree(p->left);
hr=HeightofTree(p->right);
return hl-hr;
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

int Balanced=BalanceFactor(root);
if(Balanced==1||Balanced==0||Balanced==-1)
printf("Tree is Balanced");
else if(Balanced>1)
printf("Tree is Left ImBalanced");
else if(Balanced<-1)
printf("Tree is right ImBalanced");


return 0;
}