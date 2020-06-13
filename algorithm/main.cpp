#include<iostream>
using namespace std;

typedef struct BiTree
{
	int data;
	struct BiTree *left,*right;
 }BiTree;

 void CreatBiTree(BiTree *&T)
 {
 	int temp;
 	cin>>temp;
 	if(temp!=0)
 	{
 		T=new BiTree;
		T->data=temp;
 		CreatBiTree(T->left);
 		CreatBiTree(T->right);
	 }
	else T=nullptr;
 }

int PathMax(BiTree *T)
{
	if(T==0)return 0;
	else
	{
		return max(T->data+PathMax(T->left),T->data+PathMax(T->right));
	}
}

void Path(BiTree *T)
{
	if(T)
	{
		cout<<T->data<<' ';
		if(PathMax(T->left)>=PathMax(T->right))
		{
			Path(T->left);
		}
		else
		{
			Path(T->right);
		}
	 }
}

int main()
{
	BiTree *T;
	CreatBiTree(T);
	cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"最大和："<<PathMax(T)<<endl<<"此路径为：";
	Path(T);
	return 0;
}
