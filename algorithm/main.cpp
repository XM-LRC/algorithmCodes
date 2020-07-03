
#include <iostream>
#include<stdlib.h>
using namespace std;

/********************************************************************
@Function�����������
@Parm: nodeElem �������
@Parm��leftChild ���ӽ��ָ��
@Parm��rightChild �Һ��ӽ��ָ��

*********************************************************************/
typedef struct treeNode{
    int nodeElem;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
}treeNode;


/********************************************************************
@Function�����������
@Parm��nodeRoot ���ڵ�ָ��
@Parm��insertNode ������Ǹ����
@return: ���ظ��ڵ�ָ��
*********************************************************************/
treeNode *insertNodes(treeNode *nodeRoot,treeNode *insertNode){
    treeNode *nextPoint;  // ��һ��ָ��
    treeNode *nowPoint;   // ��ǰָ��
    nextPoint = nodeRoot;
    if (nodeRoot == NULL){ // ע�⣺�˴�һ���������ǣ������޷�����
        return insertNode;
    }
        while (nextPoint){
            nowPoint = nextPoint; // ��ǰָ���ס���ڵ�״̬
            if (insertNode->nodeElem == nextPoint->nodeElem ){
                return nodeRoot;
            }else if (insertNode->nodeElem < nextPoint->nodeElem){
                nextPoint = nextPoint->leftChild;
            } else {
                nextPoint = nextPoint->rightChild;
            }
        }
        // ����Ҷ�ӽ�㣬���в���
        if(nowPoint->nodeElem > insertNode->nodeElem){ //������������Ҷ�ӽ��
            nowPoint->leftChild = insertNode;
        }else {
            nowPoint->rightChild = insertNode;
        }
        return nodeRoot;
}

/********************************************************************
@Function����������������
@Parm��nodeRoot ���ڵ�
*********************************************************************/
treeNode *treeCreate(treeNode *nodeRoot){
    int elem;
    treeNode *insertNode;
    cout<<"����������,��0����:";
    cin>>elem;
    while (elem != 0){
        insertNode = (treeNode *)malloc(sizeof(treeNode));
        insertNode->nodeElem = elem;
        insertNode->leftChild = NULL;
        insertNode->rightChild = NULL;
        // ִ�в������
        nodeRoot = insertNodes(nodeRoot,insertNode);
        cin>>elem;
    }
    return nodeRoot;
}
/********************************************************************
@Function�������������ϵ���ʾ����
@Parm�� nodeRoot ���ڵ�

*********************************************************************/
void treePrint(treeNode *nodeRoot){
   // cout<<"����������,��0����:";
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
    cout<<"����������ķ������ʣ�";
    treePrint(nodeRoot);
    return 0;
}

