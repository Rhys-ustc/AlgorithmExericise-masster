#include<iostream>
#include"RhyLinkList.h"

using namespace std;

int main()
{
    int len = 8;
    int age[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int idx[8] = {15, 18, 13, 22, 50, 18, 30, 20};

    RhyLinkList *L;
    // create list and print list
    L = L->CreateList(idx, age, len);
    L->PrintList(L);

}
