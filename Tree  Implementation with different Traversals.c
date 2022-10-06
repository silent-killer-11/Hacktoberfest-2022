#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *rptr;
struct node *lptr;
};
int c=0;int fr=-1,rr=-1,top=-1;
struct node *q[50];struct node *s[50];
void create(struct node **root1,int da)
{
struct node *temp=(*root1);
struct node *new=(struct node*)malloc(sizeof(struct node));
new->data=da;
new->lptr=NULL;
new->rptr=NULL;
if(*root1==NULL)
{
*root1=new;
}
else
{
while(1)
{
if(temp->data < new->data && temp->rptr==NULL)
{
temp->rptr=new;
break;
}
else if(temp->data > new->data && temp->lptr==NULL)
{
temp->lptr=new;
break;
}
else if(temp->data > new->data)
temp=temp->lptr;
else if(temp->data < new->data)
temp=temp->rptr;
else{}
}
}
}
void inorder(struct node *root1)
{
if(root1==NULL)
return;
inorder(root1->lptr);
printf("%d ",root1->data);
inorder(root1->rptr);
}
void preorder(struct node *root1)
{
if(root1==NULL)
return;
printf("%d ",root1->data);
inorder(root1->lptr);
inorder(root1->rptr);
}
void Postorder(struct node *root1)
{
if(root1==NULL)
return;
inorder(root1->lptr);
inorder(root1->rptr);
printf("%d ",root1->data);
}
void enqueue(struct node *troot)
{
if(fr==-1 && rr==-1)
{fr=0;
rr=0;
q[rr]=troot;}
else
{
rr++;
q[rr]=troot;
}
}
int *dequeue()
{
int *temp1=q[fr];
fr++;
if(fr==(rr+1))
{
fr=-1;
rr=-1;
}
return temp1;
}
void levelordertraverse(struct node *root1)
{
enqueue(root1);
while(fr!=-1 || rr!=-1)
{
struct node *t=dequeue();
printf("%d ",t->data);
if(t->lptr!=NULL)
enqueue(t->lptr);
if(t->rptr!=NULL)
enqueue(t->rptr);
}
printf("\n");
}
void push(struct node *troot)
{
top++;
s[top]=troot;
}
int* pop()
{
int *temp1=s[top];
top--;
return temp1;
}
void NRpreorder(struct node *root1)
{
struct node *ptr=root1;
push(NULL);
while(ptr!=NULL)
{
printf("%d ",ptr->data);
if(ptr->rptr!=NULL)
push(ptr->rptr);
if(ptr->lptr!=NULL)
ptr=ptr->lptr;
else
ptr=pop();
}
printf("\n");
}
int main()
{
struct node *root=NULL;
int i=1,e;
while(i)
{
printf("Enter Data");
scanf("%d",&e);
create(&root,e);
printf("IF CONTINUE PRESS 1 TO STOP PRESS 0");
scanf("%d",&i);
}
printf("INORDER TRAVERSAL\n");
inorder(root);
printf("\n");
printf("PREORDER TRAVERSAL\n");
preorder(root);
printf("\n");
printf("POSTORDER TRAVERSAL\n");
posttraverse(root);
printf("\n");
printf("LEVEL ORDER TRAVERSAL\n");
levelordertraverse(root);
printf("NON-RECURSIVE PREORDER TRAVERSAL\n");
NRpreorder(root);
return 0;
}
