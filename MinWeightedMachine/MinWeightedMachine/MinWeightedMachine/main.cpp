/*
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*   main.cpp
*   ��С��������������⣺�������ȶ��еķ�֧�޽編.
*/

#include<iostream>
#include<fstream>
#include <queue>
using namespace std;
int n,m,d;
int MinWeight;
int MinValue;
int **c  = NULL;
int **w = NULL;

struct Node
{
   int weight;
   int val;
   int source;   //�ĸ�������
   int level;         //�ڼ���
   Node *father;
};

//�Ż������ȼ��趨
bool operator<(Node a,Node b)  //level���ռ���
{
   if(a.weight == b.weight)return a.level <b.level;    //���������ͬ��ѡ��level��ġ�
   //ѡ��Ƚϴ��level���൱���õ���һ���Ļ���˼�룬ֻ���������ҵ��Ǹ�MinWeight
   return a.weight > b.weight;
}

Node *MinLeaf;
void MinWeightMachine()
{
   int i,j;
   MinValue = INT_MAX;
   MinWeight = INT_MAX;
   Node intital;
   intital.father  = NULL;
   intital.level = 0;
   intital.source=0;
   intital.val = 0;
   intital.weight = 0;

   priority_queue<Node>heap;   //�����ȶ��У�����һ����С�ѡ������ȥ�ͻ��Զ��ź���ġ�
   heap.push(intital);
   while(!heap.empty())
   {
       Node *fartherNode = new Node(heap.top());
       heap.pop();
       if(fartherNode->level == n)
       {
           if(fartherNode->weight <MinWeight)   //�ʼ��MinWeight ��һ���ϴ��ֵ
           {
               MinWeight = fartherNode -> weight;
               MinValue  = fartherNode ->val;
               MinLeaf = fartherNode;              //��¼��������ĸ��������
           }
       }
       else
       {
       
           int min_w = INT_MAX,    
               min_c = INT_MAX;
           //min_w�ֱ����ǰ����������ʣ�����С�����ĺͣ�min_c����ǰ��ֵ����ʣ�����С��ֵ�ĺ�
           min_c = fartherNode->val;
           min_w = fartherNode->weight;
           
           for(i=fartherNode->level+1 ; i<=n ; i++)//ѡ��ʣ��Ĳ������ۻ����й������С����,����ѡ��ÿһ����С������
           {
               int temp_min_w= INT_MAX,
                     temp_min_c = INT_MAX;
               for(j=1;j<=m;j++)   //,temp_min��¼��ǰ��һ�����С������
               {
                   temp_min_w = temp_min_w < w[i][j] ? temp_min_w:w[i][j];
                   temp_min_c = temp_min_c < c[i][j] ? temp_min_c:c[i][j];
               }
               min_w += temp_min_w;
               min_c  += temp_min_c;
           }
           
         
           if(min_w>MinWeight||min_c > d)
           {
               
               continue;
           }
       
           for(i=1 ; i<=m ; i++)    //����ѡ��ÿ���ۻ���
           {
               if(fartherNode->val  +c[fartherNode->level +1][i] <=d ||fartherNode->weight  +w[fartherNode->level +1][i] <= MinWeight)
               {
                   Node *newNode = new Node;
                   newNode->level = fartherNode->level +1;
                   newNode->father = fartherNode;
                   newNode->source = i;
                   newNode->val = fartherNode->val + c[newNode->level][i];
                   newNode->weight = fartherNode->weight + w[newNode->level][i];
                   heap.push(*newNode);
               }
           }
       }
   }

}

int main()
{
   int i,j;
   //��ȡtxt�ļ�����
   ifstream file;
   file.open("data\\input.txt", ios::in);
   if (file.fail())
   {
	   cout << "�ļ�������." << endl;
	   file.close();
	   cin.get();
	   cin.get();
   }
   else
   {
	   file >> n;  //�ļ���һ�е����ݱ�ʾ����Ԫ���ܸ����������n��
	   file >> m;
	   file >> d;
   }

   w = new int*[n+1];
   c = new int *[n+1];
   for(i = 1;i <= n ; i ++)
   {
       w[i]  = new int [m+1];
       c[i] = new int [m+1];
   }
   MinLeaf = NULL;

   file.seekg(1, ios::cur); //�ļ�ָ�����һλ����ʼ��ȡ����
   for(i = 1 ; i <= n ; i ++)
       for (j = 1 ; j <= m ; j ++)
           file>>c[i][j];
 
   for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
           file>>w[i][j];

   MinWeightMachine();
   cout<<MinWeight<<endl;
   int *result = new int[n+1];
   for(i=n;i>=1;i--)
   {
       result[i] = MinLeaf ->source;
       MinLeaf = MinLeaf ->father;
   }
   ofstream out;
   out.open("data\\output.txt", ios::out);
   out << MinWeight << endl;
   for (i = 1; i <= n; i++)
   {
	   cout << result[i] << " ";
	   out << result[i] << " ";
   }
   out<<endl;
}