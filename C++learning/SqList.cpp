//
// Created by Yabo on 2022/11/26.
//

#include "iostream"
#define MAXSIZE 100
typedef int Elemtype;
typedef struct {
    Elemtype* data;
    int length;
}SqList;
using namespace std;

bool InitList(SqList &L){
    L.data = new int[MAXSIZE];
    if(L.data == NULL)
        return false;
    L.length = 0;
    cout << "顺序表初始化完成！" << endl;
    return true;
}

bool CreatList(SqList &L, int n){
    if(n<0 || n > MAXSIZE)
        return false;
    for(int i = 0;i < n; i++){
        cin >> L.data[i];
        L.length++;
    }
    return true;
}

bool InsertElem(SqList &L, int i, Elemtype e){
    if(i < 1 || i > L.length+1){
        cout << "位置无效！";
        return false;
    }
    if(L.length >= MAXSIZE){
        cout << "当前存储空间已满";
        return false;
    }
    for(int j = L.length; j >= i; j --){
        L.data[j] = L.data[j - 1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

int LocateElem(SqList L, Elemtype e){
    for (int i = 0; i < L.length; ++i) {
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}

bool DeleteElem(SqList &L, int i){
    if(i < 1 || i > L.length){
        cout << "位置无效！";
        return false;
    }
    for(int j = i; j < L.length; ++j){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

bool isEmpty(SqList L){
    if (L.length == 0){
        return true;
    } else{
        return false;
    }
}

bool isFull(SqList L){
    if (L.length == MAXSIZE){
        return true;
    } else{
        return false;
    }
}

int GetLength(SqList L){
    return L.length;
}

void TraverseSqlist(SqList L){
    for (int i = 0; i < L.length; ++i) {
        cout << "第" << i + 1 << "个元素的值是" << L.data[i] << endl;
    }
}
void ClearSqList(SqList &L){
    L.length = 0;
    cout<<"---已清空顺序表---"<<endl;
}

//销毁顺序表L
void DestroySqList(SqList &L){
    delete [] L.data;
    L.length=0;
    L.data=nullptr;
    cout<<"---已销毁顺序表---"<<endl;
}

#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
void EnableMemLeakCheck()
{
    int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    tmpFlag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(tmpFlag);
}


int main(){
    EnableMemLeakCheck();
    SqList L;
    InitList(L);

    bool b1 = CreatList(L, 5);
    cout << b1 << endl;


    bool b2 = InsertElem(L, 2, 6);
    cout << b2 << endl;

    bool b3 = LocateElem(L, 3);
    cout << b3 << endl;

    bool b4 = DeleteElem(L, 3);
    cout << b4 << endl;

    TraverseSqlist(L);
    DestroySqList(L);




}