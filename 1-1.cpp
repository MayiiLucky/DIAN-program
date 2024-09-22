//输出形式相同————函数构造（关于摆放物品），且循环
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stddef.h>

void place(char object,int order,int price,int num);
//定义函数，统一的输出形式可简化操作
int main()
{
char object;
int price,order;
size_t num;
printf("请输入要摆放的商品种类,商品所放通道，商品单价，商品个数：\n");
scanf("%c %d %d %d",&object,&order,&price,&num);
place(object,order,price,num);
return 0;
}

void place(char object,int order,int price,int num)
{
	int i;
	printf("%d:",order);
	printf(" ");
	for(i=0;i<num;i++)
	{
		printf("%c",object);
	}
	printf("  ");
	printf("%d",price);
}