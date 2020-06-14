#include<iostream>
using namespace std;

typedef struct BiTree
{
	int data;
	struct BiTree *left,*right;  // 左右孩子指针
 }BiTree;


// 建树
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
	if(T==0)return 0;  // 树为空
	else
	{
		return max(T->data+PathMax(T->left),T->data+PathMax(T->right));  // 返回较大者
	}
}

// 选择较大路径，输出路径
void Path(BiTree *T)
{
	if(T)
	{
		cout<<T->data<<' ';
		if(PathMax(T->left)>=PathMax(T->right))
		{
			Path(T->left);  // 递归左孩子
		}
		else
		{
			Path(T->right);  // 递归右孩子
		}
	 }
}

int main()
{
	BiTree *T;
	cout<<"建立二叉树，请输入树结构:";
	CreatBiTree(T);
	cout<<"最大路径和为："<<PathMax(T)<<endl;
	cout<<"路径如下：";
	Path(T);
	return 0;
}
