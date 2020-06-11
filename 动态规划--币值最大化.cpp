
#include<iostream>
using namespace std;
#define max(x,y)  (x>y)?x:y

// ��ȡ����ֵ
int solve(int *coin,int *before,int num)
{
    // ��ʼ������
    before[0] = 0;
    before[1] = coin[1];

    for (int i = 2; i <= num ; i++)
    {
        before[i] = max(coin[i]+before[i-2],before[i-1]);
    }
    return before[num];
}

// ѡ������������Ӳ�ң������˻�ȥ��before��ȡֵ
void backChoose(int *choice,int *before,int *coin,int n)
{
    int k = 0;
    for (int i = n; i >= 1; i--)
    {
        if (before[i] == before[i - 1])
        {
            choice[k++] = coin[--i]; //��ѡ��ǰ���Ǹ�����ǰ���Ǹ�Ӳ�ҷ���
        }

        else
        {
            choice[k++] = coin[i--];//û��ѡ��ǰ���Ǹ������������

        }
    }
    for (int i = 0; i < k;i++)
        cout<<choice[i]<<"  ";
    cout<<endl;
}

int main()
{
    int num ;
    cout<<"�������ж��ٸ�Ӳ��:";
    cin>>num;
    int coin[num+1];
    cout<<"������Ӳ�ҵļ�ֵ:";
    for (int i = 1;i <=num ; i++)
    {
        cin>>coin[i];
    }
    int before[num+1];
    int maxValue = solve(coin,before,num); // ȥ����ֵ
    int choice[num+1];
    cout<<"ѡ���Ӳ������:";
    backChoose(choice,before,coin,num);   // ѡ��Ӳ��
    cout<<"����ֵΪ:"<<maxValue<<endl;
}
