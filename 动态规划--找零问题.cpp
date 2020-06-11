#include <stdio.h>
#include <iostream>

using namespace std;

void makeChange(int values[], int types, int total, int coinUsed[], int cointTrack[]){
        coinUsed[0] = 0;
        cointTrack[0] = 0;
        for(int i = 1; i<= total; i ++){
                int mincoin = i;
                int lastin  = 0;
                for(int j = 0; j < types; j ++){
                        if(values[j] <= i){
                                if(coinUsed[i - values[j]] + 1 < mincoin){
                                        mincoin = coinUsed[i - values[j]] + 1;
                                        lastin = values[j];
                                }
                        }
                }
                coinUsed[i] = mincoin;
                cointTrack[i] = lastin;
        }
        while(total>0)
        {
                cout<< cointTrack[total]<<" ";
                total -= cointTrack[total];
        }
}

int main(int argc, char *argv[])
{
        //硬币面值
        int value[]={1,2,3};
        //硬币数组大小
        size_t size=sizeof(value)/sizeof(*value);
        //要找零的数
        int money=6;
        //保存每个面值对应最小值，因为0号位置舍弃，故加1
        int* coinsUsed=new int[money+1];
        int* coinsTrack=new int[money+1];
        makeChange(value,size,money,coinsUsed,coinsTrack);
}
