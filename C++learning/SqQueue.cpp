//
// Created by Yabo on 2022/11/27.
//
#include "iostream"
#define MAXSIZE 100
using namespace std;
typedef int QElemtype;
typedef struct {
    QElemtype *base;
    int front, rear;
}SqQueue;


bool InitQueue(SqQueue &Q){
    Q.base = new QElemtype[MAXSIZE];
    if(!Q.base)
        return false;
    Q.front = Q.rear = 0;
    return true;
}

int QueueLength(SqQueue Q){
    return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}

bool EnQueue(SqQueue &Q, QElemtype e){
    if((Q.rear + 1)%MAXSIZE == Q.front)
        return false;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1)%MAXSIZE;
    return true;
}

QElemtype DeQueue(SqQueue &Q){
    if(Q.front == Q.rear){
        cout << "队列为空！" << endl;
        return NULL;
    }
    QElemtype e = Q.base[Q.front];
    Q.front = (Q.front + 1)%MAXSIZE;
    return e;
}

QElemtype GetHead(SqQueue Q){
    if(Q.front != Q.rear)
        return Q.base[Q.front];
    cout << "队列为空！" << endl;
    return NULL;
}

bool ClearQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
    return true;
}

bool DestroyQueue(SqQueue &Q){
    delete Q.base;
    Q.base = NULL;
    Q.front = Q.rear = 0;
    return true;
}

void QueueTraverse(SqQueue Q){
    int i = Q.front;
    while (i != Q.rear){
        cout << Q.base[i] << " ";
        i = ( i + 1)%MAXSIZE;
    }
}