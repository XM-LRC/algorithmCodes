/********************************************************************
@Author�����F�
@Date�� 2020-05-23
@Description��
     �����������Ĳ���
 �������ݣ�11��3,5,6,17,22
��1������һ�ö������������������Һ��ӵ����
��2�������������ϵĲ��Ҳ���
��3�������������ϵ�ɾ������

*********************************************************************/

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

/********************************************************************
@Function�������������ϵĲ��Ҳ���
@Parm�� nodeFind Ҫ���ҵĽ��

*********************************************************************/
int treeNodeFind(treeNode *nodeRoot,int nodeFind){
    while (nodeRoot){
        if (nodeFind == nodeRoot->nodeElem){
            cout<<nodeFind<<"�ڶ�������";
            return 0;
        }else if (nodeFind < nodeRoot->nodeElem){
            nodeRoot = nodeRoot->leftChild;
        }else {
            nodeRoot = nodeRoot->rightChild;
        }
    }
    cout<<nodeFind<<"���ڶ�������";
    return 1;
}

/********************************************************************
@Function�������������ϵ�ɾ������
@Parm: elem Ҫɾ������
*********************************************************************/
int Delete(treeNode **nodeDelete){
    treeNode *q,*s;
    if((*nodeDelete)->rightChild == NULL){     // ����������ֻ���ؽ�����������
		q = *nodeDelete;
		*nodeDelete = (*nodeDelete) ->leftChild;
		free(q);
	}else if((*nodeDelete)->leftChild == NULL) // ����������ֻ���ؽ�����������
	{
		q = *nodeDelete;
		*nodeDelete = (*nodeDelete)->rightChild;
		free(q);
	}
        // ��������������
	else
	{
		q = *nodeDelete;
		s = (*nodeDelete)->leftChild;
		// Ѱ��ɾ������ǰ��
		while (s->rightChild) {
			q=s;
			s=s->rightChild;
		}
		// ����ɾ���ǰ����ֵȡ����ɾ����ֵ
		(*nodeDelete)->nodeElem = s->nodeElem;
		if(q != (*nodeDelete))
			q->rightChild = s->leftChild; // �ؽ�q��������
		else
			q->leftChild=s->leftChild;    // �ؽ�q��������
		free(s);
	}
	return 1;
}

int treeNodeDelete(treeNode **nodeRoot,int elem){ // ע�⣺�˴�����Ҫ�ö���ָ�룬
                                                  // ����ɾ���ɹ�Ҳ����Ӱ���������������
    if ((*nodeRoot) == NULL){  //��㲻����
        cout<<"��㲻���ڣ��˳�ɾ������"<<endl;
        exit(1);
    }else {
        if (elem == (*nodeRoot)->nodeElem)
			return Delete(nodeRoot);
		else if (elem < (*nodeRoot)->nodeElem)
			return treeNodeDelete(&(*nodeRoot)->leftChild,elem);
		else
			return treeNodeDelete(&(*nodeRoot)->rightChild,elem);
    }
}

int main()
{
    treeNode *nodeRoot = NULL;
    nodeRoot = treeCreate(nodeRoot);
    cout<<"����������ķ������ʣ�";
    treePrint(nodeRoot);
    //����Ҫ���Һ�ɾ���ĵ�
    int nodeFind,nodeDelete;
    cout<<"\n������ҵĽ��:";
    cin>>nodeFind;
    treeNodeFind(nodeRoot,nodeFind);
    cout<<"\n����Ҫɾ���Ľ�㣺";
    cin>>nodeDelete;
    treeNodeDelete(&nodeRoot,nodeDelete);
    cout<<"����������ķ������ʣ�";
    treePrint(nodeRoot);
    return 0;
}
