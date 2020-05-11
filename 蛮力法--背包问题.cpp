#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<vector<int> > PSet;  // 全局变量 存放幂集

void PSetSolve(int n){
	vector<vector<int> > tmp;  // 子幂集
	vector<int> v;
	PSet.push_back(v);
	vector<vector<int> >::iterator pit;
	for(int i=1;i<=n;i++){
		tmp = PSet;
		for(pit=tmp.begin();pit!=tmp.end();pit++){
			(*pit).push_back(i);
		}
		for(pit=tmp.begin();pit!=tmp.end();pit++){
			PSet.push_back(*pit);
		}
	}

}
// 打印幂集
void disp(int n){

    int weigh[n+1]={0,5,3,2,1};
	int value[n+1]={0,4,4,3,1};
	int sumw=0;
	int sumv=0;
	for(int i=0;i<pow(2,n);i++)
    {
        sumv=0;
        sumw=0;
		vector<int> v = PSet[i];
		for(int j=0;j<v.size();j++)
			{
			    sumw+=weigh[v[j]];
			    sumv+=value[v[j]];
			}
        if(sumw==6)
        {
            cout<<"选择方案:"<<endl;
            cout << "{ ";
            for(int j=0;j<v.size();j++)
			    printf(" %d ",v[j]);
            cout << "}"<<endl;
            cout<<"重量:"<<sumw<<endl;
		    cout<<"价值:"<<sumv<<endl<<endl;
        }
	}
}
int main()
{
	int n = 5;
	PSetSolve(n);
	disp(n);
	return 0;
}
