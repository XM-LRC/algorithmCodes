/********************************************************************
@Author�����F�
@Date�� 2020-05-23
@Description��
    ˳���Ĳ���
    �������ݣ�2��15��33��11��17��16��223��128
��1������˳���
��2��˳������˳�����
��3��˳����������
*********************************************************************/

#include <iostream>
#include<stdlib.h>
using namespace std;

/********************************************************************
@Function������ṹ��
@Parm��nodeElem �������
@Parm��next ���ָ��
*********************************************************************/
typedef struct listNode{
    int nodeElem;
    struct listNode *next;
};

/********************************************************************
@Function��ͨ��β�巨����˳���
*********************************************************************/
listNode *listCreate(){
    int elem;
    listNode *nodeHead, *tail, *node;
    nodeHead = (listNode *)malloc(sizeof(listNode));
    tail = nodeHead;
    cout<<"����������,��0������";
    cin>>elem;
    while (elem != 0){
        node = (listNode *)malloc(sizeof(listNode));
        node->nodeElem = elem;
        tail->next = node;
        tail = node ;
        cin>>elem;
    }
    tail->next = NULL;
    return nodeHead;
}

/********************************************************************
@Function����ӡ��ʾ˳���
@Parm: nodeHead  ����ͷָ��
*********************************************************************/
void listPrint(listNode *nodeHead){
    listNode * nodePoint = nodeHead->next; // ���ָ��ָ���һ����Ч�Ľ��
    cout<<"��ʾ���ݣ�";
    while (nodePoint){
        cout<<nodePoint->nodeElem<<" ";
        nodePoint = nodePoint->next;
    }
    cout<<endl;
}
/********************************************************************
@Function�����˳�����
@Parm��Elem ��Ҫ���ҵĽ������
@Parm��nodeHead ͷ���ָ��
*********************************************************************/
void nodeFind(listNode *nodeHead,int elem){
    listNode * nodePoint= nodeHead->next;  // ���ָ��ָ���һ����Ч�Ľ��
    while(nodePoint && (nodePoint->nodeElem != elem)){
        nodePoint = nodePoint->next;
    }
    if (nodePoint != NULL){  // �жϽ��ָ���Ƿ�ָ��ĩβ
        cout<<"���ҽ����"<<elem<<"��������"<<endl;
    }else{
        cout<<"���ҽ����"<<elem<<"����������"<<endl;
    }
}

/********************************************************************
@Function��ѡ���������������
@Parm��nodeHead ͷ���ָ��
*********************************************************************/
void listSelectSort(listNode *nodeHead){
    listNode *prePoint = nodeHead->next; // ǰһ�����ָ��
    listNode *aftPoint ;                 // ��һ�����ָ��
    while (prePoint){
        aftPoint = prePoint->next;
        while (aftPoint){
            if(aftPoint->nodeElem < prePoint->nodeElem){  // �ȽϽ��ֵ��С
                int temp = aftPoint->nodeElem;
                aftPoint->nodeElem = prePoint->nodeElem;
                prePoint->nodeElem = temp;
            }
            aftPoint = aftPoint->next;  // ��һ�����ָ�����
        }
        prePoint = prePoint->next;      // ǰһ�����ָ�����
    }
}

int main()
{
    listNode *nodeHead;       // ����ͷ���
    nodeHead = listCreate();  // ��������
    cout<<"����ǰ��";
    listPrint(nodeHead);      // ��ʾ����֮ǰ����
    listSelectSort(nodeHead); // ��������
    cout<<"�����";
    listPrint(nodeHead);      // ��ʾ����֮������
    int findNode;
    cout<<"��������Ҫ���ҵĽ�㣺";
    cin>>findNode;
    nodeFind(nodeHead,findNode);
    return 0;
}
