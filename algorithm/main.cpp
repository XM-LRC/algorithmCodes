
#include <iostream>
#include<stdlib.h>
using namespace std;

/********************************************************************
@Function：创建树结点
@Parm: nodeElem 存放数据
@Parm：leftChild 左孩子结点指针
@Parm：rightChild 右孩子结点指针

*********************************************************************/
typedef struct treeNode{
    int nodeElem;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
}treeNode;


/********************************************************************
@Function：插入树结点
@Parm：nodeRoot 根节点指针
@Parm：insertNode 插入的那个结点
@return: 返回根节点指针
*********************************************************************/
treeNode *insertNodes(treeNode *nodeRoot,treeNode *insertNode){
    treeNode *nextPoint;  // 下一个指针
    treeNode *nowPoint;   // 当前指针
    nextPoint = nodeRoot;
    if (nodeRoot == NULL){ // 注意：此处一定不能忘记，否则无法创建
        return insertNode;
    }
        while (nextPoint){
            nowPoint = nextPoint; // 当前指针记住现在的状态
            if (insertNode->nodeElem == nextPoint->nodeElem ){
                return nodeRoot;
            }else if (insertNode->nodeElem < nextPoint->nodeElem){
                nextPoint = nextPoint->leftChild;
            } else {
                nextPoint = nextPoint->rightChild;
            }
        }
        // 到达叶子结点，进行插入
        if(nowPoint->nodeElem > insertNode->nodeElem){ //如果插入结点大于叶子结点
            nowPoint->leftChild = insertNode;
        }else {
            nowPoint->rightChild = insertNode;
        }
        return nodeRoot;
}

/********************************************************************
@Function：创建二叉排序树
@Parm：nodeRoot 根节点
*********************************************************************/
treeNode *treeCreate(treeNode *nodeRoot){
    int elem;
    treeNode *insertNode;
    cout<<"请输入数据,以0结束:";
    cin>>elem;
    while (elem != 0){
        insertNode = (treeNode *)malloc(sizeof(treeNode));
        insertNode->nodeElem = elem;
        insertNode->leftChild = NULL;
        insertNode->rightChild = NULL;
        // 执行插入操作
        nodeRoot = insertNodes(nodeRoot,insertNode);
        cin>>elem;
    }
    return nodeRoot;
}
/********************************************************************
@Function：二叉排序树上的显示操作
@Parm： nodeRoot 根节点

*********************************************************************/
void treePrint(treeNode *nodeRoot){
   // cout<<"请输入数据,以0结束:";
    if(nodeRoot)
	{
		treePrint(nodeRoot->leftChild);
		cout<<nodeRoot->nodeElem<<" ";
		treePrint(nodeRoot->rightChild);


	}
}

int main()
{
    treeNode *nodeRoot = NULL;
    nodeRoot = treeCreate(nodeRoot);
    cout<<"按中序遍历的方法访问：";
    treePrint(nodeRoot);
    return 0;
}

