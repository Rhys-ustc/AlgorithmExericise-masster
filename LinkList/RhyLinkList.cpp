#include "RhyLinkList.h"

RhyLinkList::RhyLinkList()
{
    age = -1;
    idx = -1;
    next = NULL;
}

RhyLinkList:: RhyLinkList(int idx, int age, RhyLinkList *Next)
{
    assert((idx>=0)&&(age>0));
    m_age = age;
    m_idx = idx;
    next = Next;
}
RhyLinkList::~RhyLinkList()
{
    delete [] next;
    next = NULL;
}

// create list
RhyLinkList  *RhyLinkList:: CreateList(int  *idx, int *age, int len)
{
    assert((idx!=NULL)&&(age!=NULL));

    RhyLinkList * head = new RhyLinkList(idx[0], age[0]);
    RhyLinkList * p = head;
    for(int i = 1;i<len;i++)
    {
        RhyLinkList  *q = new RhyLinkList(idx[i], age[i]);
        p->next = q;
        p = p->next;
    }
    // is this safe ?
    return head;

}

// print the list
void RhyLinkList:: PrintList(RhyLinkList &L)
{
    assert(L!=NULL);
   RhyLinkList * p = L;
   cout<<"idx"<<",age"<<endl;
    while(!p)
    {
        cout<<p->m_idx<<", "<<p->m_age<<endl;
        p = p->next;
    }

}
void RhyLinkList:: DeleteNodeByAge(RhyLinkList &L, int age)
{
    assert((L!=NULL)&&(age>0));

    RhyLinkList * p = L;
    if(p->m_age==age)
    {
        L = L->next;
        delete [] p;
        return ;
    }
    while(!p)
    {
        if(p->next->m_age==age)
        {
            RhyLinkList *q = p->next;
            p->next = q->next;
            delete [] q;
        }
        else
        {
            p = p->next;
        }
    }

}
void RhyLinkList:: InsertNodeByIdx(RhyLinkList &L, RhyLinkList &node)
{
    assert((L!=NULL)&&(idx>=0));

    RhyLinkList *p = L;
    RhyLinkList  *q = new RhyLinkList(node.m_idx, node.m_age);
    // if has to insert before head
    if(L.m_idx>=idx)
    {
      q->next = L;
      L = q;
    }
    else
    {
        while((!p->next)&&(p->next->m_idx<node.m_idx))
        {
            p = p->next;
        }
        //insert the node
        q->next = p->next;
        p->next = q;
        // node idx ++ after inserted one
        while(!q->next)
        {
            q = q->next;
            q->m_idx++;
        }
    }

}

