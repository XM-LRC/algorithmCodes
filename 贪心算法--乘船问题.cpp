/*
���˴����⡣��n���ˣ���i���˵�����Ϊwi��
ÿ�Ҵ��������������ΪC��������ܳ���2�ˡ�
�������ٵĴ�װ�������ˡ�

*/
#include <iostream>
#include<algorithm>
using namespace std;
int n = 8;   // �ٶ������n�˲μӳ˴�
int num = 0; // ˫������������
int main()
{
    int C;
    cout<<"�ٶ��˴�����Ϊ:"<<n<<endl;
    cout<<"ÿ�����������Ϊ��";
    cin>>C;
    int w[n+1];
    cout<<"������ÿ���˵�����:";
    for (int i = 1; i <= n; i++)
        cin>>w[i];
    // ���򣬰���������
    sort(w+1,w+1+n);
    cout<<"�����������: ";
    for(int i =1;i<=n;i++)
        cout<<w[i]<<"  ";
    int left = 1 ,right = n;     // ������������ָ�룬ָ�����������
    while (left < right )
    {
        if(w[left] + w[right] <= C)
        {
            num++;
            left++;
            right--;
        }else {
            right--;
        }
    }

    cout<<endl<<"��������ٴ���Ϊ��"<<n-num<<endl;

    return 0;
}
