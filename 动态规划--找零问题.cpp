#include <stdio.h>
#include <iostream>
using namespace std;

//硬币面值
int values[]={1,3,4};
int size=sizeof(values)/sizeof(*values);   //硬币个数
int money=6;        // 需要找的零钱

void DP( int dp[], int path[]){
        dp[0] = 0;       // dp[i]数组表示找i元需要多少个硬币
        path[0] = 0;     // 用于记录在dp情况下的硬币
        for(int i = 1; i<= money; i ++)
        {
            int mincoin = i;   // 最少硬币个数
            int lastin  = 0;
            for(int j = 0; j < size; j ++)
            {
                if(values[j] <= i && dp[i - values[j]] + 1 < mincoin)
                {
                    mincoin = dp[i - values[j]] + 1;
                    lastin = values[j];
                }
            }
        dp[i] = mincoin;
        path[i] = lastin;
        }

        cout<<"找的硬币个数:"<<dp[money];
        cout<<"\n找的硬币:";
        while(money>0)
        {
            cout<< path[money]<<" ";
            money = money - path[money];
        }
}

int main(int argc, char *argv[])
{
    cout<<"硬币：";
    for (int i = 0 ;i <size ;i++)
        cout<<values[i]<<" ";
    cout<<"\n需要找的零钱："<<money<<endl;
    int* dp=new int[money+1];
    int* path=new int[money+1];
    DP(dp,path);
    return 0;
}
