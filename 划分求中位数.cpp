#include<iostream>
using namespace std;

//划分
int partition(int *a,int low,int high)
{
    int t = a[low];
    while(low<high)
    {
        while(low<high&&a[high]>t)
            high--;
        a[low]=a[high];
        while(low<high&&a[low]<t)
            low++;
        a[high]=a[low];
    }
    return low;
}
//获取中位数的位置
int GetZhongWeiShu(int *a,int low,int high,int n)
{
    int mid;
    while(low<high)
    {
        mid=partition(a,low,high);
        if(mid==n/2)
            break;
        else if(mid<n/2)
            low = mid+1;
        else
            high = mid -1;

    }
    return mid;
}

int main()
{
    int n =7,i;
    int a[n];
    cout<<"请输入7个整数:";
    for(i=0;i<n;i++)
        cin>>a[i];
    int mid = GetZhongWeiShu(a,0,n-1,n);
    cout<<"左半部分:";
    for(i=0;i<mid;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
    cout<<"右半部分:";
    for(i=mid;i<n;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
    return 0;
}
