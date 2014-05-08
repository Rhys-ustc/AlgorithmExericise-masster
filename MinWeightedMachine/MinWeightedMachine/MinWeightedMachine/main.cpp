/*
* Copyright (c) 2014, Huaiyu Ruan
* University of Science and Technology of China, Image Processing Lab (http://image.ustc.edu.cn/).
* Mail:  rhyustc@gmail.com
* All rights reserved.
*
*   main.cpp
*   最小重量及其设计问题：利用优先队列的分支限界法.
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
   int source;   //哪个供货商
   int level;         //第几层
   Node *father;
};

//优化的优先级设定
bool operator<(Node a,Node b)  //level按照减序
{
   if(a.weight == b.weight)return a.level <b.level;    //如果质量相同，选择level大的。
   //选择比较大的level，相当于用到了一定的回溯思想，只是想最早找到那个MinWeight
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

   priority_queue<Node>heap;   //用优先队列，建立一个最小堆。加入进去就会自动排好序的。
   heap.push(intital);
   while(!heap.empty())
   {
       Node *fartherNode = new Node(heap.top());
       heap.pop();
       if(fartherNode->level == n)
       {
           if(fartherNode->weight <MinWeight)   //最开始给MinWeight 赋一个较大的值
           {
               MinWeight = fartherNode -> weight;
               MinValue  = fartherNode ->val;
               MinLeaf = fartherNode;              //记录是最后是哪个结点数据
           }
       }
       else
       {
       
           int min_w = INT_MAX,    
               min_c = INT_MAX;
           //min_w分别代表当前的质量加上剩余的最小质量的和，min_c代表当前价值加上剩余的最小价值的和
           min_c = fartherNode->val;
           min_w = fartherNode->weight;
           
           for(i=fartherNode->level+1 ; i<=n ; i++)//选出剩余的部件在售货商中购买的最小质量,就是选择每一层最小的质量
           {
               int temp_min_w= INT_MAX,
                     temp_min_c = INT_MAX;
               for(j=1;j<=m;j++)   //,temp_min记录当前这一层的最小的质量
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
       
           for(i=1 ; i<=m ; i++)    //依次选择每个售货商
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
   //读取txt文件数据
   ifstream file;
   file.open("data\\input.txt", ios::in);
   if (file.fail())
   {
	   cout << "文件不存在." << endl;
	   file.close();
	   cin.get();
	   cin.get();
   }
   else
   {
	   file >> n;  //文件第一行的数据表示数据元素总个数，存放在n中
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

   file.seekg(1, ios::cur); //文件指针后移一位，开始读取数据
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