/*
	StrReplace(S,t,v)
	fyz
	StrReplace(S,t,v)函数，串结构实现,把S串中的t串用v串替换
	2019.10.15 21:40 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXLEN 40
/*串结构定义*/
typedef struct {
	char ch[MAXLEN];
	int len;
} SString;
/*串的初始化*/
void InitString(SString *S) {
	S->len=-1;
}
/*对串赋值每次读入一个字符*/
void CreateString(SString *S,char x) {
	S->len++;
	if(S->len == MAXLEN-1) {
		printf("串已达到最大长度\n");
		return;
	}
	S->ch[S->len] = x;
}
/*StrReplace函数体，将S串中的t串用v串替换*/
int StrReplace(SString *S,SString *t,SString *v) {
	/*如果子串大于原串长度，返回错误*/
	if(t->len>S->len) {
		printf("ERROR：子串t大于原串S\n");
		return false;
	}
	/*求出t串在S串中的个数*/
	int i=0, j=0, k=0, n=0;//n值为S串中包含t串的个数
	while(i != S->len) {
		if(S->ch[i] != t->ch[j]) i++; //寻与t串头相等的S串第一个下标i
		else {
			while(S->ch[i] == t->ch[j]) {
				i++;
				j++;
				if(j == t->len) { //t串均与S串部分相等则符合，此时n自增
					n++;
					j=0;
					break;
				}
			}
			if(j != t->len &&j != 0) { //t串部分与S串部分相等时不符合，此时n不变
				i++;
				j=0;
			}
		}
	}
	i=0;
	j=0;//重置双下标
	if(n == 0) { //t串不不在S串内
		printf("ERROR：t串不为S的子串\n");
		return false;
	}
	int dxlen=abs(v->len-t->len);
	if(v->len > t->len) { //v串长度大于t串时，考虑溢出
		if(S->len + n*(v->len - t->len) > MAXLEN) {
			printf("ERROR：串S长度超过%d字符最大长度，溢出\n",MAXLEN);
			return false;
		} else {
			/*v串长度大于t串时替换*/
			SString *S1=S;
			S1->len = S->len+n*dxlen;
			/*此while语句用于查找下标并且赋值*/
			while(i != S->len) {
				if(S->ch[i] != t->ch[j]) i++;
				else {
					while(S->ch[i] == t->ch[j]) {
						i++;
						j++;
						if(j == t->len) { //同上操作查询到子串得到下标位置i 
							i-=t->len;
							j=0;
							int slen=S1->len;
							while(i!=--slen) {
								S1->ch[slen]=S1->ch[slen-dxlen]; //整个后移 
							}
							int vlen=v->len;
							while(vlen--) {
								S1->ch[i]=v->ch[j]; //直接覆盖
								j++;
								i++;
							}
							j=0;
							break;
						}
					}
					if(j != t->len &&j != 0) { //t串部分与S串部分相等时不符合，此时n不变
						i++;
						j=0;
					}
				}
			}
			S=S1;
		}
	} else {
		/*v串长度小于等于t串时替换*/
		while(i != S->len) { //此while操作同上 
			if(S->ch[i] != t->ch[j]) i++;
			else {
				while(S->ch[i] == t->ch[j]) {
					i++;
					j++;
					if(j == t->len) {
						i-=t->len;
						j=0;
						int vlen=v->len;
						while(vlen--) {
							S->ch[i]=v->ch[j]; //直接覆盖 
							j++;
							i++;
						}
						int i1=i;
						if(dxlen!=0) { //当子串t与替换串v不等时元素前移 
							while(i+dxlen!=S->len) {
								S->ch[i]=S->ch[i+dxlen];
								i++;
							}
						}
						i=i1;
						j=0;
						break;
					}
				}
				if(j != t->len &&j != 0) { //t串部分与S串部分相等时不符合，此时n不变
					i++;
					j=0;
				}
			}
		}
		S->len = S->len-n*dxlen; //压缩S至变换之后的长度，舍弃串后端的重复元素 
	}
	printf("S串包含%d个t串",n);
}

/*显示任意一串内元素*/
void ShowString(SString *S) {
	for(int i=0; i<S->len; i++) {
		printf("%c",S->ch[i]);
	}
}

int main() {
	printf("-----------输入三个字符串S，t，v-------------\n");
	printf("-----求出当将S串中的t串替换为v串后的结果-----\n\n");
	SString S,t,v;
	InitString(&S);
	InitString(&t);
	InitString(&v);
	char x,y,z;
	printf("输入串S(最大长度为%d字符)：",MAXLEN);
	while(x!='\n') {
		x=getchar();
		CreateString(&S,x);
	}
	printf("输入子串t：");
	while(y!='\n') {
		y=getchar();
		CreateString(&t,y);
	}
	printf("输入替换串v：");
	while(z!='\n') {
		z=getchar();
		CreateString(&v,z);
	}
	if(StrReplace(&S, &t, &v)) {
		printf("\n替换成功\n");
		printf("替换后S串为：");
		ShowString(&S);
	}
	puts("\n");
	system("pause");
}
