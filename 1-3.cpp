

//输出形式相同————函数构造（关于摆放物品），且循环
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stddef.h>

//void place(char object,int order,int price,int num);
int main()
{
char object;
int price,order,pay;
size_t num;
printf("请输入要摆放的商品种类,商品所放通道，商品单价，商品个数：\n");
scanf("%c %d %d %d",&object,&order,&price,&num);
//place(object,order,price,num);
char input;
int channel;
int num0=0;
printf("你好！请输入要购买的商品及其所在通道与个数:\n");
	scanf(" %s%d%d", &input,&channel,&num0);
		pay=price*num0;	
		printf("请投币（仅有1元，2元和5元三种面额）\n");
		int coin=0;
		int Sum=0;
		do{
			scanf("%d",&coin);
			if (coin == 1 || coin == 2 || coin == 5) {
            Sum += coin;
       		} 
			else {
            printf("无效的硬币，请投1元、2元或5元硬币。\n");
            continue;
        	}
		}while(Sum<=pay);
		if(Sum==pay){
			printf("投币金额足够！");
		}
		if(Sum>pay){
			printf("投币金额足够，找零%d元",Sum-pay);
		}

	return 0;
return 0;

}