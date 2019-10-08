#include <stdio.h>
#define MAXSIZE 100 /*宏定义表示线性表的最大长度为100*/

/*顺序表的存储结构*/
typedef struct {
	int elem1[MAXSIZE];
	int elem2[MAXSIZE];
	int last;
} SeqList;

/*给顺序表赋值*/
void CreateSeq(SeqList *S, int length) {
	S->last = length-1;
	for(int i=0; i <= S->last; i++) {
		printf("请输入顺序表的第%d个元素：",i+1);
		scanf("%d",&S->elem1[i]);
		S->elem2[i]=S->elem1[i];
	}
}

/*输出顺序表的排列结果*/
void ShowSeq(SeqList *S) {
	for(int i=0; i<=S->last; i++) {
		if(i<S->last) printf("%d--",S->elem1[i]);
		else printf("%d",S->elem1[i]);
	}
}

/*对顺序表进行奇数在前，偶数在后的排列操作*/
void func(SeqList *S) {
	int i,j; /*双指针，i从前往后，j从后往前*/
	i=0, j=S->last;
		for(int k=0; k<=S->last; k++) {
			if(S->elem2[k]%2 == 1) {
				S->elem1[i] = S->elem2[k];
				i++;
			} else {
				S->elem1[j] = S->elem2[k];
				j--;
			}
		}
/*	while(i<j) {
		while(S->elem[i]%2==1) {
			++i;
		}
		while(S->elem[j]%2==0) {
			--j;
		}
		if(i<j) {
			int tmp = S->elem[i];
			S->elem[i] = S->elem[j];
			S->elem[j] = tmp;
			++i;
			--j;
		}
	}*/
}

int main() {
	SeqList S;
	int length;
	printf("输入所创建顺序表长度：");
	scanf("%d",&length);
	CreateSeq(&S,length);
	func(&S);
	printf("奇数在前偶数在后排列结果为：");
	ShowSeq(&S);
}
