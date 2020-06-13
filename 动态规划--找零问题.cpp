#include <stdio.h>
#include <iostream>
using namespace std;

//Ӳ����ֵ
int values[]={1,3,4};
int size=sizeof(values)/sizeof(*values);   //Ӳ�Ҹ���
int money=6;        // ��Ҫ�ҵ���Ǯ

void DP( int dp[], int path[]){
        dp[0] = 0;       // dp[i]�����ʾ��iԪ��Ҫ���ٸ�Ӳ��
        path[0] = 0;     // ���ڼ�¼��dp����µ�Ӳ��
        for(int i = 1; i<= money; i ++)
        {
            int mincoin = i;   // ����Ӳ�Ҹ���
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

        cout<<"�ҵ�Ӳ�Ҹ���:"<<dp[money];
        cout<<"\n�ҵ�Ӳ��:";
        while(money>0)
        {
            cout<< path[money]<<" ";
            money = money - path[money];
        }
}

int main(int argc, char *argv[])
{
    cout<<"Ӳ�ң�";
    for (int i = 0 ;i <size ;i++)
        cout<<values[i]<<" ";
    cout<<"\n��Ҫ�ҵ���Ǯ��"<<money<<endl;
    int* dp=new int[money+1];
    int* path=new int[money+1];
    DP(dp,path);
    return 0;
}
