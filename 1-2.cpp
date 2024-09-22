#include<stdio.h>
#include<string.h>

int main()
{
	int pay=0;
	int coin=0;
	int Sum=0;
	printf("请输入总价：");
	scanf("%d",&pay); 
	printf("总价为%d元\n",pay);
	printf("请投币（仅有1元，2元和5元三种面额）\n");
	
		do{
			scanf(" %d",&coin);
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