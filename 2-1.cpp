//输出形式相同————函数构造（关于摆放物品），且循环
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stddef.h>
struct Type {
    char object[50];//商品
    int price[50];//价格
    int order[50];//通道
    int num[50];//数量
	};
void place(char object,int order,int price,int num);
int main()
{
struct Type Type;//定义商品类型结构体
char input_1[40];//用于暂时储存输入的要摆放的商品，便于判断要不要停止摆放
char input_2[40];//用于暂时储存输入的要购买的商品，便于判断是否有该商品
int sum;//放入的总的商品种类，循环时作为上限
int pay=0;//购买商品总价
int order0;//储存要购买的商品通道
int num0;//储存要购买的商品数量
int jug=1;//循环判断
int i=0;//循环变量
int x=0;//循环变量
int n=0;//循环变量
printf("请输入要摆放的商品种类,商品所放通道，商品单价，商品个数(输入\"END\"作为结束):\n");

 while (1) {
 scanf("%s", input_1);
 if (strcmp(input_1, "END") == 0) {
 break;
 }
 Type.object[i] = input_1[0];
 scanf(" %d%d%d", &Type.order[i], &Type.price[i], &Type.num[i]);
 i++;
sum=i;
//printf("%d\n",sum);检查运行到哪里了
 }
//多次摆放商品，输入END结束
 for(x=0;x<i;x++){
place(Type.object[x],Type.order[x], Type.price[x], Type.num[x]);
 }
//展示摆放情况
//进货结束，开始购买
printf("你好！请输入要购买的商品及其所在通道与个数（输入\"END\"作为结束）:\n");
//输入购买的商品，并判断是否结束
while(jug){
		int found=-1;  // 用于记录找到的商品索引
			int order0;
			int num0;	
			scanf(" %s", &input_2);
			if (strcmp(input_2, "END") == 0) {
			jug=0;
		    break;
		 	}
		 	else{
		 	scanf(" %d%d", &order0,&num0);
			 }
		 	//printf("1st\n");	检查运行到哪里了


// 查找商品是否存在
// 如果没有找到商品或数量不对，则提示重新输入，并继续下一次循环
		    for (i=0;i<sum;i++){
		        if (input_2[0]==Type.object[i]) {
		            found=i;  // 记录找到的商品索引
		            break;  // 找到商品后退出循环
		            }
		        } 
		    if (found==-1) {
		        printf("没有该商品，请重新输入:\n");
		        continue;  // 跳过后续操作，直接开始下一次输入循环
		    	}
			if (num0>Type.num[found]) {
		        printf("该商品数量不够，只有%d个，请重新输入:\n",Type.num[found]);
		        continue;  // 跳过后续操作，直接开始下一次输入循环
		    	}
//检查是否存在全部售完的情况
			for (i=0;i<sum;i++)	{
				if (Type.object[i]==0) {
		            n++;
		            }
				}
		    if(n>=sum){
				jug=0;
				printf("商品已售罄，暂停服务");
				}	
//累加每次输入增加的总价
		    pay+=Type.price[found]*num0;
			Type.num[found]-=num0;	
			//printf("目前总价为%d\n",pay); 检查运行到哪里了
		}
//开始购买			
		printf("总价为%d\n",pay);
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
}




void place(char object,int order,int price,int num)
{
	int i;
	printf("%d:",order);
	printf("  ");
	for(i=0;i<num;i++)
		{
		printf("%c",object);
		}
	printf("   ");
	printf("\t%d\n",price);
}
