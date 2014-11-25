#include"MyString.h"

//
void StrAssign(char *dst, const char *src)
{
    assert((dst != NULL)&&(src != NULL));
    //int i = 0;
    while( (*dst != '\0')&&(*src != '\0'))
    {
        //dst[i] = src[i];
        *dst++ = *src++;
    }
    *dst = '\0';
}

char *StrCopy(char *dst, char * src)
{
    assert(dst != NULL && src != NULL);
    char * add = dst;
    while (*src != '\0')
    {
        *dst++ = *src++;
    }
    *dst = '\0';
    return add;
}

int StrLength(char * s)
{
    assert(s != NULL);
    int len = 0;
    while(*s != '\0')
    {
        len++;
        s++;
    }
    return len;
}

int StrCompare(char *s, char *t)
{
    assert((s != NULL)&&(t != NULL));
    int i;
    for ( i=0; (s[i] != '\0')&&(t[i] != '\0'); i++)
    {
        if (s[i] != t[i])
        {
            return (s[i] - t[i]);
        }
    }
    return (s[i] - t[i]);
}

void StrConcat(char *t, char *s1, char * s2)
{
    assert((t != NULL)&&(s1 != NULL)&&(s2 != NULL));
    int i=0;
    int j = 0;
    if (t==s1)
    {
        j = StrLength(s1);
    }
    else
    {
        while (s1[i] != '\0')
        {
            t[j++] = s1[i++];
        }
    }

    i = 0;
    while (s2[i] != '\0')
    {
        t[j++] = s2[i++];
    }
    t[j] = '\0';

}

void Substring(char *sub, char * s, int pos, int len)
{
    assert((sub != NULL)&&(s != NULL));
    assert((pos>=0)&&(len>=0));
    int slen = StrLength(s);
    if (((pos+len) > slen) || (pos > slen-1))
    {
        cout<<"error parameters"<<endl;
        return ;
    }
    for (int i = 0; i < len; i++)
    {
        sub[i] = s[pos+i];
    }
    sub[len] = '\0';
}

void Replace(char **s,  char *t,  char * v)
{
    assert((*s != NULL) && (t != NULL) && (v != NULL));
    int pos = -1;
    int sLen = StrLength(*s);
    int vLen = StrLength(v);
    int tLen = StrLength(t);
    pos = FindKMP(*s, t, 0);
    while (pos>=0)
    {
        //replace the substring
        if (vLen > tLen)
        {
            char *p  = *s;
            *s =  new char[sLen + vLen - tLen +1];
            char sub[sLen-pos-tLen+1];
            Substring(sub, *s, pos + tLen, sLen-pos-tLen);
            sub[sLen-pos-tLen] = '\0';
            if (pos==0)
            {
                StrAssign(*s, v);
                StrConcat(*s, *s, sub);
            }
            else
            {
                 Substring(*s, p, 0, pos);
                 StrConcat(*s, *s, v);
                 StrConcat(*s, *s, sub);
            }
            delete p ;
            p = NULL;
        }
        else if( vLen<tLen)
        {
            // insert the replace string v
            for (int i = pos;i<pos+vLen;i++)
            {
               // (*s)[i] = v[i-pos];
                *(*s +i) = v[i-pos];
            }
            // delete the sbustring t
            for (int i=pos+tLen;i<sLen+1;i++)
            {
               // (*s)[i - tLen + vLen] = (*s)[i];
                *(*s+i - tLen + vLen) = *(*s+i);
            }
        }
        // continue to search the substring
        pos = FindKMP(*s, t, pos+vLen-1);
    }

}

int FindKMP(char *s, char *p, int start)
{
    // check the parameters
    assert((s!=NULL)&&(p!=NULL));
    assert(start>=0);
    if(start>(StrLength(s)-StrLength(p)))
    {
        cout<<"error input start position!"<<endl;
        return -1;
    }
    // get next array of p
    int *next = new int[StrLength(p)];
    GetNext(p, next);
    // find the substring
    int i = start;
    int j = 0;
    while((i<StrLength(s))&&(j<(int)StrLength(p)))
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == StrLength(p))
    {
        return (i-j);
    }
    else
    {
        return -1;
    }

}

void GetNext(char *p, int *next)
{
    assert((p != NULL)&&(next != NULL));
    int j = 0;
    int k = -1;
    next[0] = -1;
    while(j <= (StrLength(p)-1))
    {
        if((k==-1) || (p[j] == p[k]))
        {
            j++;
            k++;
            if(p[j] != p[k])
            {
                next[j] = k;
            }
            else
            {
                next[j] = next[k];
            }
        }
        else
        {
            k = next[k];
        }
    }
}

