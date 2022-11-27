//
// Created by Yabo on 2022/11/27.
//
#include "iostream"
typedef int ElemData;
using namespace std;

typedef struct LNode{
    ElemData data;
    struct LNode * next;
}LNode, * LinkList;

bool InitList(LinkList &L){
    L = new LNode;
    if(!L) return false;
    L->next = NULL;
    cout << "列表初始化成功！" << endl;
    return true;
}

bool CreateLinkList_H(LinkList &L, int n){
    LinkList p;
    for(int i = 0; i < n; ++ i){
        p = new LNode;
        cin >> p -> data;
        p -> next = L -> next;
        L -> next = p;
    }
    return true;
}

bool CreateLinkList_T(LinkList &L, int n){
    LinkList p, q=L;
    for (int i = 0; i < n; ++i) {
        p = new LNode;
        cin >> p ->data;
        p -> next = NULL;
        q -> next = p;
        q = p;
    }
    return true;
}

LinkList GetElem(LinkList L, int i){
    int j = 1;
    LinkList p = L -> next;
    while (p && j < i){
        p = p -> next;
        j ++;
    }
    if (i == 0)
        return L;
    if(!p || j > i)
        return NULL;
    return p;
}

int LocateElem(LinkList &L, ElemData e){
    int i = 0;                          //返回值为e的元素在链表中的索引
    LinkList p = L -> next;
    while ( p && p ->data != e){
        p = p -> next;
        i++;
    }
    return i;
}

bool InsertLNode(LinkList &L, int i, ElemData e){ //就效果来看，i是指插入的位置顺序，即位序，而不是索引
    LinkList p = L; //LinkList p = L -> next;这样即可按索引插入。
    int j = 0;
    while (p && j < i - 1){
        p = p -> next;
        j++;
    }
    if( !p || j > i - 1)
        return false;

    LinkList q = new LNode;
    q -> data = e;
    q -> next = p -> next;
    p -> next = q;
    return true;
}

bool DeleteLNode(LinkList &L, int i){
    LinkList p = L;
    int j = 0;
    while (p -> next && j < i - 1){
        p = p -> next;
        j ++;
    }
    if(!(p -> next) || j > i - 1)
        return false;
    LinkList q = p -> next;
    p -> next = q -> next;
    delete q;
    return true;
}

int LinkListLength(LinkList L){
    LinkList p = L -> next;
    int i = 0;
    while (p){
        i++;
        p = p -> next;
    }
    return i;
}

bool ClearLinkList(LinkList &L){
    LinkList  p = L -> next;
    LinkList q;
    while (p){
        q = p -> next;
        delete p;
        p = q;
    }
    L ->next = NULL;
    return true;
}

bool DestroyLinkList(LinkList &L){
    LinkList p;
    while (L){
        p = L;
        L = L -> next;
        delete p;
    }
    cout << "销毁成功！" << endl;
    return true;
}

bool isEmpty(LinkList L){
    return L -> next == NULL ? true : false;
}

void TraverseLinklist(LinkList L) {
    LinkList p = L -> next;
    while (p){
        cout << p -> data << "->";
        p = p -> next;
    }
    cout << endl;
}



int main(){
    LinkList L;
    InitList(L);

    bool b1 = CreateLinkList_H(L, 5);
    cout << b1 << endl;


    bool b2 = InsertLNode(L, 2, 6);
    cout << b2 << endl;

    bool b3 = LocateElem(L, 3);
    cout << b3 << endl;

    bool b4 = DeleteLNode(L, 3);
    cout << b4 << endl;

    bool b5 = isEmpty(L);
    cout << b5 << endl;

    TraverseLinklist(L);

    DestroyLinkList(L);


}