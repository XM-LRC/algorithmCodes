#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<vector<int> > PSet;  // ȫ�ֱ��� ����ݼ�

void PSetSolve(int n){
	vector<vector<int> > tmp;  // ���ݼ�
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
// ��ӡ�ݼ�
void disp(int n){
	printf("1��%d���ݼ�Ϊ��\n",n);
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
