#include <stdio.h>
#include <stdlib.h>
/*二叉树结构*/
typedef struct BiNode {
	char data;
	BiNode *lchild;
	BiNode *rchild;
} *Bitree;

/*前序遍历建立二叉树*/
void CreateBitree(Bitree *T) {
	char c;
	scanf("%c",&c);
	if(c == ' ') {
		*T = NULL;
	} else {
		*T = (BiNode*)malloc(sizeof(BiNode));
		(*T)->data = c;
		CreateBitree(&(*T)->lchild);
		CreateBitree(&(*T)->rchild);
	}
}
/*访问并输出结点*/
void visit(char c) {
	printf("%c ",c);
}

/*前序遍历递归输出*/
void PreOrderTraverse(Bitree T) {
	if(T) {
		visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

/*中序遍历递归输出*/
void MidOrderTraverse(Bitree T) {
	if(T) {
		PreOrderTraverse(T->lchild);
		visit(T->data);
		PreOrderTraverse(T->rchild);
	}
}

/*后序遍历递归输出*/
void ProOrderTraverse(Bitree T) {
	if(T) {
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
		visit(T->data);
	}
}

/*前序遍历的非递归算法*/
void PreOrder(Bitree T) { 
	
}

/*中序遍历的非递归算法*/
void MidOrder(Bitree T) { 
	
}

/*后序遍历的非递归算法*/
void ProOrder(Bitree T) { 
	
}

int main() {
	Bitree T;
	printf("请按前序遍历输入一棵二叉树，空结点用空格' '表示：");
	CreateBitree(&T);
	printf("前序遍历结果为：");
	PreOrderTraverse(T);
	puts("");
	printf("中序遍历结果为：");
	MidOrderTraverse(T);
	puts("");
	printf("后序遍历结果为：");
	ProOrderTraverse(T);
	puts("");
}
