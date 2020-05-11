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
	vector<int>::iterator it;
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
	printf("1到%d的幂集为：\n",n);
	for(int i=0;i<pow(2,n);i++)
    {
		vector<int> v = PSet[i];
		cout << "{ ";
		for(int j=0;j<v.size();j++)
			printf(" %d ",v[j]);
		cout << "}"<<endl;
	}
}
int main()
{
	int n = 5;
	PSetSolve(n);
	disp(n);
	return 0;
}
