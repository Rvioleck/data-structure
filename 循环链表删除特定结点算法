#include <stdio.h>
#include <stdlib.h>

/*单链表的存储结构*/
typedef struct Node {
	int data;
	struct Node *next;
} CLL;

/*得到某个结点的前驱结点*/
CLL *GetPreNode(CLL *L) {
	CLL *s;
	/*为空则返回NULL*/
	if(!L) {
		return NULL;
	}
	s = L->next;
	while(L!=s->next) {
		s = s->next;
	}
	return s;
}

/*删除该结点的前驱结点*/
void DelClinklist(CLL *s) {
	CLL *pre = GetPreNode(s);
	if (pre) {
		GetPreNode(pre)->next = pre->next;
	}
}

/*展示单链表*/
void ShowCLL(CLL *L) {
	CLL *s;
	s = L->next;
	printf("%d", L->data);
	while (L != s) {
		printf("-->%d", s->data);
		s = s->next;
	}
	puts("");
}

int main() {
	int y;
	printf("输入要创建的链表结点个数：");
	scanf("%d",&y);
	CLL n[y];
	printf("请输入循环链表的%d个结点的值：\n",y);
	/*对链表进行赋值并且让其末指针指向头部*/
	for(int i=0; i<y; i++){
		scanf("%d",&n[i].data);
		if(i<y-1) n[i].next=&n[i+1];
		else n[i].next=&n[0];
	}
	printf("原链表为: \n");
	ShowCLL(&n[0]);
	printf("请输入要删除结点为第几个：\n");
	int x;
	scanf("%d",&x);
	DelClinklist(&n[x]);
	printf("删除第%d个结点后的链表为：\n",x);
	ShowCLL(&n[0]);
}
