#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

void StrAssign(char *dst, const char *src);
char *StrCopy(char *dst, char * src);
int StrLength(char * s);
int StrCompare(char *s, char *t);
void StrConcat(char *t, char *s1, char * s2);
void Substring(char *sub, char * s, int pos, int len);
void Replace(char **s, char *t, char *v);
int FindKMP(char *s, char *p, int start);
void GetNext(char *s, int *next);

#endif // MYSTRING_H
