#ifndef RHYLINKLIST_H
#define RHYLINKLIST_H
#include<assert.h>
#include<iostream>

using namespace std;

class RhyLinkList
{
public:
    int m_idx;
    int m_age;
    RhyLinkList  *next;
    RhyLinkList();
    RhyLinkList(int idx, int age, RhyLinkList *next=NULL);
    ~RhyLinkList();

    RhyLinkList *CreateList(int  *idx, int *age, int len);
    void PrintList(RhyLinkList &L);
    void DeleteNodeByAge(RhyLinkList &L, int age);
    void InsertNodeByIdx(RhyLinkList &L, RhyLinkList & node);
    void InsertNodeByAge(RhyLinkList &L, RhyLinkList & node);
};

#endif // RHYLINKLIST_H
