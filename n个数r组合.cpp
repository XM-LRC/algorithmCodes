
#include<stdio.h>
#include<stdlib.h>
#include<aglori

void f_myfun(int n,int r,int *a,int *total)
{
  	  int i,j;
  	  for(i=n;i>=r;i--)
  	  {
  	  	a[r]=i;
  	  	if(r==1)
  	  	{
  	  		for(j=a[0];j>0;j--)
  	  		    printf("%5d",a[j]);
  	  		(*total)++;
  	  		printf("\n");
  	  	}
  	  	else
  	  	  f_myfun(i-1,r-1,a,total);

	  }

}

int main()
{
	int i,n,r,total=0;
	printf("n=");
	scanf("%d",&n);
	printf("r=");
	scanf("%d",&r);
	int *a=(int *)calloc(n+1,sizeof(int));
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+10);
	//Êä³ö
		int a[r];
		a[0]=r;
		f_myfun(n,r,a,&total);
		printf("--------------------\n\tTotal=%d",total);

}
