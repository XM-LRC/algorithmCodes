#include<stdio.h>
//#define line 10
int c ( int a , int b )
{
    int value = 0;
    if ( b == 1 ||  b == a )//��ͷ�ͽ�β
    {
    value = 1;
    }
    else
        value = c ( a - 1 , b - 1)+c(a-1,b);//�м��ֵ���ݹ�
    return value;
}
int main()
{
    int n;
    int j = 0;
    printf("��Ҫ���������?\n");
    scanf("%d",&n);
    while ( n > 13 ) // ȷ�����뷶Χzhi��ʹ�Ժ����������Խ��
    {
        scanf("%d",&n);
    }
    for ( int i = 0 ; i < n ; i++)
    {
        for ( j = 0 ; j < i + 1 ; j++)//���������
        {
        printf("%4d",c(i+1,j+1));
        }
        printf("\n");//����
    }
}
