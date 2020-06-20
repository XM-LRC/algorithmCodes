#include<stdio.h>
//#define line 10
int c ( int a , int b )
{
    int value = 0;
    if ( b == 1 ||  b == a )//开头和结尾
    {
    value = 1;
    }
    else
        value = c ( a - 1 , b - 1)+c(a-1,b);//中间的值，递归
    return value;
}
int main()
{
    int n;
    int j = 0;
    printf("你要输入多少行?\n");
    scanf("%d",&n);
    while ( n > 13 ) // 确保输入范围zhi，使以后输出，不会越界
    {
        scanf("%d",&n);
    }
    for ( int i = 0 ; i < n ; i++)
    {
        for ( j = 0 ; j < i + 1 ; j++)//控制列输出
        {
        printf("%4d",c(i+1,j+1));
        }
        printf("\n");//分行
    }
}
