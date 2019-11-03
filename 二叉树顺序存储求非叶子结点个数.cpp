#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

static int count = 0;

/*顺序二叉树*/
typedef struct BiNode {
	char data[MAXSIZE];
	int num=0;
} SeqBitree;

/*层序遍历输入建立二叉树*/
void CreateBitree(SeqBitree *T,char c) {
	T->data[(++T->num)] = c;
}

void GetCount(SeqBitree *T){
	for(int i=1; i<=(T->num-1)/2; i++){
		if(T->data[2*i]!='.' || T->data[2*i+1]!='.')/*&&T->data[i]!='.'*/{
			count++;
		}
	} 
} 

int main() {
	SeqBitree T;
	char c;
	printf("请按照层序遍历顺序输入(完全)二叉树（若空输入'.'）："); 
	while(c!='\n') {
		c=getchar();
		CreateBitree(&T,c);
	}
	GetCount(&T);
	printf("非叶子结点个数为：%d\n",count);

}

