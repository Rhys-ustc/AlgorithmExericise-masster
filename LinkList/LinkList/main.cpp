#include<iostream>
#include"RhyLinkList.h"

using namespace std;

int main()
{
    int len = 8;
    int idx[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int age[8] = {15, 18, 13, 22, 50, 18, 30, 20};

    RhyLinkList *L = NULL;
    //1. create list and print list
    cout<<"1. Create link list and print it out :"<<endl;
    L = L->CreateList(idx, age, len);
    L->PrintList(L);
    //2. delete node by age
    cout<<"2. delete node by age:"<<endl;
    L->DeleteNodeByAge(L, 20);
    L->PrintList(L);
    L->DeleteNodeByAge(L, 15);
    L->PrintList(L);
    L->DeleteNodeByAge(L, 18);
    L->PrintList(L);
    // 3. insert node by idx
    RhyLinkList node(6,23);
    L->InsertNodeByIdx(L, node);
    L->PrintList(L);
    node.m_idx = 1;
    node.m_age = 25;
    L->InsertNodeByIdx(L, node);
    L->PrintList(L);

}
