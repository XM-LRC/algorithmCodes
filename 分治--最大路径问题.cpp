#include<iostream>
using namespace std;

typedef struct BiTree
{
	int data;
	struct BiTree *left,*right;  // ���Һ���ָ��
 }BiTree;


// ����
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
	else T = NULL;
 }


int PathMax(BiTree *T)
{
	if(T==0)return 0;  // ��Ϊ��
	else
	{
		return max(T->data+PathMax(T->left),T->data+PathMax(T->right));  // ���ؽϴ���
	}
}

// ѡ��ϴ�·�������·��
void Path(BiTree *T)
{
	if(T)
	{
		cout<<T->data<<' ';
		if(PathMax(T->left)>=PathMax(T->right))
		{
			Path(T->left);  // �ݹ�����
		}
		else
		{
			Path(T->right);  // �ݹ��Һ���
		}
	 }
}

int main()
{
	BiTree *T;
	cout<<"���������������������ṹ:";
	CreatBiTree(T);
	cout<<"���·����Ϊ��"<<PathMax(T)<<endl;
	cout<<"·�����£�";
	Path(T);
	return 0;
}
