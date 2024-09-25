#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#define MAX 100

struct Type {
    char object[50]; // 货物
    int price[50];   // 价格
    int order[50];   // 通道
    int num[50];     // 数量
};

int Pay[MAX];      // 总价(栈)
int Num[MAX];      // 商品剩余数量(栈)
int Record[MAX];   // 所购商品的序号(栈)
int top = -1;      // 栈的顶部
int cnt = 0;       // 记录回退次数

void place(char object, int order, int price, int num);
void save_state(int pay, int num, int record);
void undo(int *pay, int *p, int *q);

int main() {
    struct Type Type; // 定义商品类型结构体
    char input_1[40]; // 用于暂时储存输入的要摆放的商品
    char input_2[40]; // 用于暂时储存输入的要购买的商品
    int sum = 0;      // 放入的总的商品种类
    int pay = 0;      // 购买商品总价
    int jug = 1;      // 循环判断
    int i = 0;        // 循环变量

    printf("请继续输入要摆放的商品种类,商品所放通道，商品单价，商品个数(输入\"END\"作为结束):\n");
    while (1) {
        scanf_s("%39s", input_1, (unsigned)_countof(input_1)); // 防止溢出
        if (strcmp(input_1, "END") == 0) {
            break; // 是否结束
        }
        Type.object[i] = input_1[0];
        scanf_s("%d%d%d", &Type.order[i], &Type.price[i], &Type.num[i]);
        i++;
    }
    sum = i; // 输入商品

    // 多次摆放商品，输入END结束
    for (int x = 0; x < sum; x++) {
        place(Type.object[x], Type.order[x], Type.price[x], Type.num[x]);
    }

    // 进货结束，开始购买
    printf("你好！请输入要购买的商品及其所在通道与个数（输入\"END\"作为结束，输入\"BACK\"回退，但是仅能回退三次）:\n");
    while (jug) {
        int found = -1; // 用于记录找到的商品索引
        int p = 0, q = 0; // 暂存
        int order0, num0; // 储存要购买的商品通道和数量

        scanf_s("%39s", input_2, (unsigned)_countof(input_2));
        if (strcmp(input_2, "END") == 0) {
            jug = 0;
            break;
        } else if (strcmp(input_2, "BACK") == 0) {
            undo(&pay, &p, &q); // 传递 pay、p、q 的地址
            if (cnt > 0) {
                printf("此时总价为%d, 还能退回%d次\n", pay, 3 - cnt);
                Type.num[p] += q; // 更新商品数量
            }
            continue; // 继续循环
        } else {
            scanf_s("%d%d", &order0, &num0); // 输入商品通道和数量
        }

        // 查找商品是否存在
        for (i = 0; i < sum; i++) {
            if (input_2[0] == Type.object[i]) {
                found = i; // 记录找到的商品索引
                break; // 找到商品后退出循环
            }
        }
        if (found == -1) {
            printf("没有该商品，请重新输入:\n");
            continue; // 跳过后续操作，直接开始下一次输入循环
        }
        if (num0 > Type.num[found]) {
            printf("该商品数量不够，只有%d个，请重新输入:\n", Type.num[found]);
            continue; // 跳过后续操作，直接开始下一次输入循环
        }

        // 检查是否存在全部售完的情况
        int soldOut = 1; // 假设商品全部售罄
        for (i = 0; i < sum; i++) {
            if (Type.num[i] > 0) {
                soldOut = 0; // 只要有一个商品未售罄，设为0
                break;
            }
        }
        if (soldOut) {
            jug = 0;
            printf("商品已售罄，暂停服务\n");
            break;
        }

        // 累加每次输入增加的总价
        save_state(pay, found, Type.num[found]); // 记录每一次状态
        pay += Type.price[found] * num0;
        Type.num[found] -= num0; // 更新商品数量
    }

    // 开始购买
    printf("总价为%d\n", pay);
    printf("请投币（仅有1元，2元和5元三种面额，不可回退）\n");
    int coin = 0;
    int Sum = 0;
    do {
        scanf_s("%d", &coin);
        if (coin == 1 || coin == 2 || coin == 5) {
            Sum += coin;
        } else {
            printf("无效的硬币，请投1元、2元或5元硬币。\n");
            continue;
        }
    } while (Sum < pay);
    
    if (Sum == pay) {
        printf("投币金额足够！\n");
    }
    if (Sum > pay) {
        printf("投币金额足够，找零%d元\n", Sum - pay);
    }

    return 0;
}

void place(char object, int order, int price, int num) {
    printf("%d: ", order);
    for (int i = 0; i < num; i++) {
        printf("%c", object);
    }
    printf("   \t%d\n", price);
}

void save_state(int pay, int num, int record) {
    if (top < MAX - 1) {
        Pay[++top] = pay;
        Num[top] = num;
        Record[top] = record;
    }
}

void undo(int *pay, int *p, int *q) {
    if (cnt < 3 && top >= 0) {
        *pay = Pay[top];  // 还原支付金额
        *p = Record[top]; // 还原商品索引
        *q = Num[top];    // 还原商品数量
        top--; // 更新栈顶
        cnt++; // 增加回退次数
    } else {
        printf("没有可以撤销的操作\n");
    }
}
