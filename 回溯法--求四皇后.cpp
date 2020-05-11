#include<stdio.h>

int count = 0;
int isCorrect(int i, int j, int (*Q)[4])
{
    int s, t;
    for(s=i,t=0; t<4; t++)
        if(Q[s][t]==1 && t!=j)
            return 0;//�ж���
    for(t=j,s=0; s<4; s++)
        if(Q[s][t]==1 && s!=i)
            return 0;//�ж���
    for(s=i-1,t=j-1; s>=0&&t>=0; s--,t--)
        if(Q[s][t]==1)
            return 0;//�ж����Ϸ�
    for(s=i+1,t=j+1; s<4&&t<4;s++,t++)
        if(Q[s][t]==1)
            return 0;//�ж����·�
    for(s=i-1,t=j+1; s>=0&&t<4; s--,t++)
        if(Q[s][t]==1)
            return 0;//�ж����Ϸ�
    for(s=i+1,t=j-1; s<4&&t>=0; s++,t--)
        if(Q[s][t]==1)
            return 0;//�ж����·�

    return 1;//���򷵻�
}

void Queue(int j, int (*Q)[4])
{
    int i,k;
    if(j==4){//�ݹ��������
        for(i=0; i<4; i++){
                //�õ�һ���⣬����Ļ����ʾ
            for(k=0; k<4; k++)
                printf("%d ", Q[i][k]);
            printf("\n");
        }
        printf("\n");
        count++;
        return ;
    }
    for(i=0; i<4; i++){
        if(isCorrect(i, j, Q)){//���Q[i][j]���Է��ûʺ�
            Q[i][j]=1;//���ûʺ�
            Queue(j+1, Q);//�ݹ��������������ռ���
            Q[i][j]=0;//���������ʵ�ֻ��ݵ���һ��
        }
    }
}

int main()
{
    int Q[4][4];
    int i, j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            Q[i][j] = 0;
    Queue(0, Q);
    printf("The number of the answers are %d\n", count);
    return 0;
}
