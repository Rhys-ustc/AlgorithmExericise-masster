#include"MyString.h"
#include <iostream>

using namespace std;

int main()
{
    //string operation
    char s[] = "abcdabcadedeabcabcasd";
    char *p = "aaaaaaaaa";
    char *v = "AAAAAAAAAA";
    // string length
    int sLen = StrLength(s);
    cout<<"original string: "<<endl;
    cout<<s<<" "<<", length:"<<sLen<<endl;
    //string assign
    //char *tmp = new char[StrLength(p)+1];
    char assign[] = "ee";
    StrAssign(assign, p);
    cout<<"string assign function:"<<endl;
    cout<<"src: "<<p<<", dst: "<<assign<<endl;

    // string copy
    char * tmp;
    tmp = new char[StrLength(v)+1];
    StrCopy(tmp, v);
    cout<<"string copy: "<<endl;
    cout<<"src: "<<v<<", dst: "<<tmp<<endl;
    delete tmp;
    tmp = NULL;
    //string compare
    cout<<"string compare:"<<endl;
    cout<<"p: "<<p<<", v: "<<v<<", result:"<<StrCompare(p, v)<<endl;

    //string concact:
    cout<<"string concact:"<<endl;
    char sign[5] = "abca";

    cout<<"size of sign :"<<sizeof(sign)<<endl;
    char *ptr = sign;
    cout<<"after sign :"<<*(ptr+6)<<endl;

    cout<<"size of sign:"<<sizeof(sign)<<endl;
    cout<<"sign: "<<sign<<", v: "<<v;
    StrConcat(sign, p, v);
    cout<<", concact sign and v: "<<sign<<endl;
    cout<<"size of sign:"<<sizeof(sign)<<endl;
    ptr = sign;
    cout<<"after concact :"<<*(ptr+6)<<endl;
    //substring
    cout<<"substring:"<<endl;
    tmp = new char[3];
    Substring(tmp, p, 0, 3);
    cout<<"src :"<<p<<", get substring of 3 element from position 0: "<<tmp<<endl;

    // string replace:
    char *ss = new char[StrLength(s)+1];
    StrCopy(ss, s);
    cout<<"string repalce:"<<endl;
    cout<<"s: "<<ss<<endl;
    cout<<"p: "<<p<<", repalce string :"<<v<<endl;
    Replace(&ss, p, v);
    cout<<"replace result:"<<ss<<endl;

    return 0;
}

