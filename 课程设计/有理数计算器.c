/*
	有理数计算器
	fyz
	1）由输入的分子和分母生成一个有理数;2）求两个有理数的和；
	3）求两个有理数的差；4）求两个有理数的乘积；
	5）求有理数的分子;6）求有理数的分母
	2019.10.17 19:50
*/
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
typedef struct {
	int num; //分子 numerator
	int den; //分母 denominator
	double value;
} Rational;

/*有理数结构初始化*/
void InitRational(Rational *R) {
	R->num = 0;
	R->den = 1; //分母不为0
	R->value = 0;
}

/*用分子分母求出有理数的值*/
void getRationalValue(Rational *R) {
	R->value = (float)R->num/R->den;
}

/*有理数结构赋值*/
void CreateRational(Rational *R,int numerator, int denominator) {
	R->num = numerator;
	R->den = denominator;
}

/*化简有理数的分子分母*/
Rational SimplifyRational(Rational *R) {
	int x;//最大公约数x
	int a=R->den;
	int b=R->num;
	if(a<b) {
		int t=b;
		b=a;
		a=t;
	}
	int t1;
	while(b!=0) {
		t1=a%b;
		a=b;
		b=t1;
	}
	x=a;
	R->den/=a;
	R->num/=a;
	return *R;
}

/*求两个有理数的和*/
Rational SumRational(Rational *R1,Rational *R2) {
	Rational R;
	int n1,n2,x;//x为最大公约数
	n1=R1->den;
	n2=R2->den;
	if(n1==n2) {
		R.num = R1->num+R2->num;
		R.den = R1->den;
		return R;
	} else if(n1>n2) {
		int t;
		while(n2!=0) {
			t=n1%n2;
			n1=n2;
			n2=t;
		}
		x=n1;
	} else {
		int t;
		while(n1!=0) {
			t=n2%n1;
			n2=n1;
			n1=t;
		}
		x=n2;
	}
	R.den = R1->den*R2->den/x;
	R.num = (R2->den*R1->num+R1->den*R2->num)/x;
	return R;
}

Rational MinusRational(Rational *R1,Rational *R2) {
	Rational R;
	int n1,n2,x;//x为最大公约数
	n1=R1->den;
	n2=R2->den;
	if(n1==n2) {
		R.num = R1->num+R2->num;
		R.den = R1->den;
		return R;
	} else if(n1>n2) {
		int t;
		while(n2!=0) {
			t=n1%n2;
			n1=n2;
			n2=t;
		}
		x=n1;
	} else {
		int t;
		while(n1!=0) {
			t=n2%n1;
			n2=n1;
			n1=t;
		}
		x=n2;
	}
	R.den = R1->den*R2->den/x;
	R.num = (R2->den*R1->num-R1->den*R2->num)/x;
	return R;
}

Rational MultiplyRational(Rational *R1,Rational *R2) {
	Rational R;
	R.den = R1->den*R2->den;
	R.num = R1->num*R2->num;
	return R;
}


int main() {
	while(1) {
		int i=0;
		printf("\t\t\t\t====================================\n");
		printf("\t\t\t\t==========有理数计算器==============\n");
		printf("\t\t\t\t==========①.求两数之和=============\n");
		printf("\t\t\t\t==========②.求两数之差=============\n");
		printf("\t\t\t\t==========③.求两数之积=============\n");
		printf("\t\t\t\t==========④.退出程序  =============\n");
		printf("\t\t\t\t====================================\n");
		printf("请输入要进行的操作：");
		scanf("%d",&i);
		switch(i) {
			case 1: {
				system("cls");
				printf("\t\t\t\t====================================\n");
				printf("\t\t\t\t===========求两数之和===============\n");
				printf("\t\t\t\t==========①.输入两个数=============\n");
				printf("\t\t\t\t==========②.返回主页面=============\n");
				printf("\t\t\t\t==========③.退出程序  =============\n");
				printf("\t\t\t\t====================================\n");
				int j=0;
				printf("请输入要进行的操作：");
				scanf("%d",&j);
				switch(j) {
					case 1: {
						system("cls");
						printf("\t\t\t\t====================================\n");
						printf("\t\t\t\t===========求两数之和===============\n");
						printf("\t\t\t\t====================================\n");
						printf("输入第一个数的分子和分母：");
						int den1,num1;
						scanf("%d%d",&num1,&den1);
						printf("输入第二个数的分子和分母：");
						int den2,num2;
						scanf("%d%d",&num2,&den2);
						system("cls");
						Rational R1,R2;
						InitRational(&R1);
						InitRational(&R2);
						CreateRational(&R1,num1,den1);
						CreateRational(&R2,num2,den2);
						Rational R3=SumRational(&R1,&R2);
						R3=SimplifyRational(&R3);
						getRationalValue(&R3);
						printf("\t\t\t\t====================================\n");
						printf("\t\t\t\t===========求两数之和===============\n");
						printf("\t\t\t\t==========①.查看结果的分子分母=====\n");
						printf("\t\t\t\t==========②.返回主页面=============\n");
						printf("\t\t\t\t==========③.退出程序  =============\n");
						printf("\t\t\t\t====================================\n");
						printf("%d/%d + %d/%d = %lf\n",num1,den1,num2,den2,R3.value);
						printf("两数之和的结果为:%lf\n",R3.value);
						int k=0;
						printf("请输入要进行的操作：");
						scanf("%d",&k);
						switch(k) {
							case 1: {
								system("cls");
								printf("\t\t\t\t====================================\n");
								printf("\t\t\t\t===========求两数之和===============\n");
								printf("\t\t\t\t====================================\n");
								printf("%d/%d + %d/%d = %lf = %d/%d\n",num1,den1,num2,den2,R3.value,R3.num,R3.den);
								printf("其分子为:%d\n其分母为:%d\n",R3.num,R3.den);
								system("pause");
								system("cls");
								break;
							}
							case 2: {
								system("cls");
								break;
							}
							case 3: {
								return 0;
								break;
							}
						}
						break;
					}
					case 2: {
						system("cls");
						break;
					}
					case 3: {
						return 0;
						break;
					}
				}
				break;
			}
			case 2: {
				system("cls");
				printf("\t\t\t\t====================================\n");
				printf("\t\t\t\t===========求两数之差===============\n");
				printf("\t\t\t\t==========①.输入两个数=============\n");
				printf("\t\t\t\t==========②.返回主页面=============\n");
				printf("\t\t\t\t==========③.退出程序  =============\n");
				printf("\t\t\t\t====================================\n");
				int j=0;
				printf("请输入要进行的操作：");
				scanf("%d",&j);
				switch(j) {
					case 1: {
						system("cls");
						printf("\t\t\t\t====================================\n");
						printf("\t\t\t\t===========求两数之差===============\n");
						printf("\t\t\t\t====================================\n");
						printf("输入第一个数的分子和分母：");
						int den1,num1;
						scanf("%d%d",&num1,&den1);
						printf("输入第二个数的分子和分母：");
						int den2,num2;
						scanf("%d%d",&num2,&den2);
						system("cls");
						Rational R1,R2;
						InitRational(&R1);
						InitRational(&R2);
						CreateRational(&R1,num1,den1);
						CreateRational(&R2,num2,den2);
						Rational R3=MinusRational(&R1,&R2);
						R3=SimplifyRational(&R3);
						getRationalValue(&R3);
						printf("\t\t\t\t====================================\n");
						printf("\t\t\t\t===========求两数之差===============\n");
						printf("\t\t\t\t==========①.查看结果的分子分母=====\n");
						printf("\t\t\t\t==========②.返回主页面=============\n");
						printf("\t\t\t\t==========③.退出程序  =============\n");
						printf("\t\t\t\t====================================\n");
						printf("%d/%d - %d/%d = %lf\n",num1,den1,num2,den2,R3.value);
						printf("两数之差的结果为:%lf\n",R3.value);
						int k=0;
						printf("请输入要进行的操作：");
						scanf("%d",&k);
						switch(k) {
							case 1: {
								system("cls");
								printf("\t\t\t\t====================================\n");
								printf("\t\t\t\t===========求两数之差===============\n");
								printf("\t\t\t\t====================================\n");
								printf("%d/%d - %d/%d = %lf = %d/%d\n",num1,den1,num2,den2,R3.value,R3.num,R3.den);
								printf("其分子为:%d\n其分母为:%d\n",R3.num,R3.den);
								system("pause");
								system("cls");
								break;
							}
							case 2: {
								system("cls");
								break;
							}
							case 3: {
								return 0;
								break;
							}
						}
						break;
					}
					case 2: {
						system("cls");
						break;
					}
					case 3: {
						return 0;
						break;
					}
				}
				break;
			}
			case 3: {
				system("cls");
				printf("\t\t\t\t====================================\n");
				printf("\t\t\t\t===========求两数之积===============\n");
				printf("\t\t\t\t==========①.输入两个数=============\n");
				printf("\t\t\t\t==========②.返回主页面=============\n");
				printf("\t\t\t\t==========③.退出程序  =============\n");
				printf("\t\t\t\t====================================\n");
				int j=0;
				printf("请输入要进行的操作：");
				scanf("%d",&j);
				switch(j) {
					case 1: {
						system("cls");
						printf("\t\t\t\t====================================\n");
						printf("\t\t\t\t===========求两数之积===============\n");
						printf("\t\t\t\t====================================\n");
						printf("输入第一个数的分子和分母：");
						int den1,num1;
						scanf("%d%d",&num1,&den1);
						printf("输入第二个数的分子和分母：");
						int den2,num2;
						scanf("%d%d",&num2,&den2);
						system("cls");
						Rational R1,R2;
						InitRational(&R1);
						InitRational(&R2);
						CreateRational(&R1,num1,den1);
						CreateRational(&R2,num2,den2);
						Rational R3=MultiplyRational(&R1,&R2);
						R3=SimplifyRational(&R3);
						getRationalValue(&R3);
						printf("\t\t\t\t====================================\n");
						printf("\t\t\t\t===========求两数之积===============\n");
						printf("\t\t\t\t==========①.查看结果的分子分母=====\n");
						printf("\t\t\t\t==========②.返回主页面=============\n");
						printf("\t\t\t\t==========③.退出程序  =============\n");
						printf("\t\t\t\t====================================\n");
						printf("%d/%d × %d/%d = %lf\n",num1,den1,num2,den2,R3.value);
						printf("两数之积的结果为:%lf\n",R3.value);
						int k=0;
						printf("请输入要进行的操作：");
						scanf("%d",&k);
						switch(k) {
							case 1: {
								system("cls");
								printf("\t\t\t\t====================================\n");
								printf("\t\t\t\t===========求两数之积===============\n");
								printf("\t\t\t\t====================================\n");
								printf("%d/%d × %d/%d = %lf = %d/%d\n",num1,den1,num2,den2,R3.value,R3.num,R3.den);
								printf("其分子为:%d\n其分母为:%d\n",R3.num,R3.den);
								system("pause");
								system("cls");
								break;
							}
							case 2: {
								system("cls");
								break;
							}
							case 3: {
								return 0;
								break;
							}
						}
						break;
					}
					case 2: {
						system("cls");
						break;
					}
					case 3: {
						return 0;
						break;
					}
				}
				break;
			}
			case 4: {
				return 0;
				break;
			}
		}
	}
}



//调试用码 
/*	int num1,den1,num2,den2;
	Rational R1,R2;
	InitRational(&R1);
	InitRational(&R2);
	CreateRational(&R1,1,2);
	CreateRational(&R2,1,6);
	Rational R3=MultiplyRational(&R1,&R2);
	R3=SimplifyRational(&R3);
	getRationalValue(&R3);
	printf("%d,%d,%f",R3.num,R3.den,R3.value);
}*/



