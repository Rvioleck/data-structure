#include <stdio.h>
#include <stdlib.h> 
static int count_leap = 1; //记录叶子结点数 
static int count_all = 0;  //记录总结点数 

typedef struct BiNode {
	char data;
	BiNode *lchild;
	BiNode *rchild;
} *Bitree;

void CreateBitree(Bitree *T) {
	char c;
	scanf("%c",&c);
	if(c == '.') {
		*T = NULL;
	} else {
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = c;
		CreateBitree(&(*T)->lchild);
		CreateBitree(&(*T)->rchild);
	}
}

void PreOrderTraverse(Bitree T){
	if(T){
		count_all++;
		if(T->lchild!=NULL && T->rchild!=NULL){
			count_leap++;
		}
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild); 
	}
}

int main(){
	Bitree T;
	printf("请按照前序遍历输入二叉树(若空输入'.'):\n"); 
	CreateBitree(&T);
	PreOrderTraverse(T);
	printf("总结点个数为：%d\n",count_all);
	printf("叶子结点个数为：%d\n",count_leap);
	printf("非叶子结点个数为：%d\n",count_all-count_leap);
}

