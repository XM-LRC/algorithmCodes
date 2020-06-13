#include<iostream>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
#define Max 20
#define n 3
#define w 7
int weight[n+1] = {0,3,4,2};  // 第一个位置不用
int values[n+1] = {0,4,5,3};

void DP()
{
    cout<<"物品重量:";
    for ( int i =1; i<=n ;i++)
    cout<<weight[i]<<"  ";
    cout<<endl<<"物品价值:";
    for(int i = 1 ;i <= n;i++)
        cout<<values[i]<<"  ";

    int maxValue[n+1][Max] ;
		for (int i=1; i<=n; i++) {
			for (int j=0; j<=w; j++) {
				if (i > 1) {
					maxValue[i][j] = maxValue[i-1][j];
					if (j/weight[i] >= 1) {
						int maxTmp = 0;
						for (int k=1; k<=j/weight[i]; k++) {
							if (maxValue[i-1][j-k*weight[i]] + k*values[i] > maxTmp) {
								maxTmp = maxValue[i-1][j-k*weight[i]] + k*values[i];
							}
						}
						maxValue[i][j] = max(maxValue[i][j], maxTmp);
					}
				} else {

					if (j/weight[1] >= 1) {
						maxValue[1][j] = j/weight[1] * values[1];
					}
				}
			}
		}
		cout<<"\n最大价值为: "<<maxValue[n][w]<<endl;


}

int main()
{
    DP();
	return 0;
}
