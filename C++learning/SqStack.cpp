//
// Created by Yabo on 2022/11/27.
//

#include "iostream"
#define MAXSIZE 100
typedef int SElemType;
using namespace std;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

bool InitStack(SqStack &S){
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
        return false;
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return true;
}

bool Push(SqStack &S, SElemType e){
    if (S.top - S.base == S.stacksize)
        return false;
    *S.top ++ = e;
    cout << "入栈成功" << endl;
    return true;
}

SElemType Pop(SqStack &S){
    if(S.top == S.base){
        cout << "栈空！" << endl;
        return NULL;
    }
    return * (-- S.top);
}

SElemType GetHead(SqStack S){
    if(S.top != S.base){
        return *(S.top - 1);
    }
    cout << "栈空！" << endl;
    return NULL;
}

bool IsStackEmpty(SqStack &S){
    if(S.top == S.base)
        return true;
    return false;
}

int StackLength(SqStack S){
    return S.top - S.base;
}

void Traverse(SqStack S){
    while (S.top > S.base){
        cout << *(S.base)++ << endl;
    }
}

bool ClearStack(SqStack &S){
    S.top = S.base;
    return true;
}

bool DestroyStack(SqStack &S){
    if(S.base){
        delete S.base;
        S.stacksize = 0;
        S.base = S.top = NULL;
    }
    return true;
}



