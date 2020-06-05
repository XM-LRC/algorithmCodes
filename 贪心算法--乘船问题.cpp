/*
求解乘船问题。有n个人，第i个人的体重为wi。
每艘船的最大载重量均为C，且最多能乘坐2人。
试用最少的船装载所有人。

*/
#include <iostream>
#include<algorithm>
using namespace std;
int n = 8;   // 假定最多有n人参加乘船
int num = 0; // 双人坐船的数量
int main()
{
    int C;
    cout<<"假定乘船人数为:"<<n<<endl;
    cout<<"每个船最大载重为：";
    cin>>C;
    int w[n+1];
    cout<<"请输入每个人的重量:";
    for (int i = 1; i <= n; i++)
        cin>>w[i];
    // 排序，按体重升序
    sort(w+1,w+1+n);
    cout<<"排序完的体重: ";
    for(int i =1;i<=n;i++)
        cout<<w[i]<<"  ";
    int left = 1 ,right = n;     // 设置左右两个指针，指向最轻和最重
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

    cout<<endl<<"所需的最少船数为："<<n-num<<endl;

    return 0;
}
