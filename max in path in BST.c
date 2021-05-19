//FIND MAX FORM a TO b PATH IN BST

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* NewNode(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* Insert(struct node* head,int data){
	//printf("%d",data);
	if(head==NULL){
	head = NewNode(data);
	return head;
	}
	struct node* x = NULL;
	struct node* y = head;
	while(y!=NULL){
		x=y;
		if(data<y->data){
			y = y->left;
		}
		else{
			y = y->right;
		}
	}
	if(data<x->data){x->left = NewNode(data);}
	else {x->right = NewNode(data);}
	return head;
	
	
}
int Max(struct node* temp,int x){
	int max=x;
	while(temp->data!=x && temp !=NULL){
		if(temp->data < x)temp=temp->right;
		else{
			if(temp->data > max)max = temp->data;
			temp= temp->left;
			break;
		}
	}
	return max;
}
void main(){
	struct node* head = NULL;
	int n;
	int a,b;
	char c = ' ';
	while(c!='\n'){
		scanf("%d%c",&n,&c);
		head = Insert(head,n);
		//printf("%d",n);
	}
	scanf("%d %d",&a,&b);
	//printf("adrg");
	struct node* temp = head;
	while(1){
		if(a < temp->data && b < temp->data)temp =temp->left;
		if(a > temp->data && b > temp->data)temp = temp->right;
		else break;
	}
	int l = Max(temp,a);
	int r = Max(temp,b);
	if(l>r)printf("%d\n",l);
	else printf("%d\n",r);
	
}
