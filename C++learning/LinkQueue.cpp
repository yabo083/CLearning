//
// Created by Yabo on 2022/11/27.
//

#include "iostream"
#define MAXSIZE 100
using namespace std;
typedef int QElemtype;

typedef struct QNode{
    QElemtype data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

bool InitQueue(LinkQueue &Q){
    Q.front = Q.rear = new QNode;
    Q.front -> next = NULL;
    return true;
}

bool EnQueue(LinkQueue &Q, QElemtype e){
    QueuePtr p = new QNode;
    p -> data = e;
    p ->next = NULL;
    Q.rear -> next = p;
    Q.rear = p;
    return true;
}

QElemtype DeQueue(LinkQueue &Q){
    if(Q.front == Q.rear){
        cout << "队列为空！" << endl;
        return NULL;
    }
    QueuePtr p = Q.front -> next;
    QElemtype e = p -> data;
    Q.front -> next = p -> next;
    if(Q.rear == p )
        Q.rear = Q.front;
    delete p;
    return e;
}

QElemtype GetHead(LinkQueue Q){
    if(Q.front != Q.rear)
        return Q.front -> next -> data;
    cout << "队列为空！" << endl;
    return NULL;
}

bool IsQueueEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
        return true;
    return false;
}

int QueueLength(LinkQueue Q){
    QueuePtr p = Q.front -> next;
    int count = 0;
    while (p){
        count ++;
        p = p -> next;
    }
    return count;
}

bool ClearQueue(LinkQueue &Q){
    QueuePtr p = Q.front -> next;
    QueuePtr q;

    while (p){
        q = p -> next;
        delete p;
        p = q;
    }
    Q.front -> next = NULL;
    Q.rear = Q.front; //将尾指针先指到队头
    return true;
}

bool DestroyQueue(LinkQueue &Q){
    while (Q.front){
        Q.rear = Q.front -> next;
        delete Q.front;
        Q.front = Q.rear;
    }
    return true;
}

void QueueTraverse(LinkQueue Q){
    QueuePtr p = Q.front -> next;
    while (p){
        cout << p -> data << "";
        p = p -> next;
    }
}




