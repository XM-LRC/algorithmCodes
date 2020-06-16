#include <iostream>
using namespace std;

int f_fenhua(int n,int m)
{
	if(n==1||m==1)
	   return 1;
	else if(m==n)
	   return(1+f_fenhua(n,n-1));
	else if(m>n)
	   return(f_fenhua(n,n));
	else
	   return(f_fenhua(n,m-1)+f_fenhua(n-m,m));

}

int main()
{
	int n,res;
	printf("n=");scanf("%d",&n);
	res=f_fenhua(n,n);
	printf("%d的分划数目为：%d\n",n,res);
	return 1;
}
