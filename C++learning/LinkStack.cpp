//
// Created by Yabo on 2022/11/27.
//

#include "iostream"
using namespace std;
typedef int SElemType;

typedef struct SNode{
    SElemType data;
    struct SNode *next;
}StackNode, * LinkStack;

bool InitStack(LinkStack &S){
    S = NULL;
    return true;
}

bool Push(LinkStack &S, SElemType e){
    LinkStack p = new StackNode ;
    p -> data = e;
    p ->next = S;
    S = p;
    return true;
}

SElemType Pop(LinkStack &S){
    if(S == NULL){
        cout << "栈空！" << endl;
        return NULL;
    }
    SElemType e = S -> data;
    LinkStack p = S;
    S = S -> next;
    delete p;
    return e;
}

SElemType GetHead(LinkStack S){
    if (S != NULL)
        return S -> data;
    return NULL;
}

bool IsStackEmpty(LinkStack S){
    if(S == NULL)
        return true;
    return false;
}

bool DestroyStack(LinkStack &S){
    while (!IsStackEmpty(S))
        Pop(S);
    return true;
}

int StackLength(LinkStack S){
    LinkStack p = S;
    int count = 0;
    while (p){
        count ++;
        p = p -> next;
    }
    return count;
}

void StackTraverse(LinkStack S){
    LinkStack p = S;
    if(p == NULL){
        cout << "栈为空！" << endl;
        exit(-1);
    }
    while (p){
        cout << p -> data;
        p = p -> next;
    }
}



