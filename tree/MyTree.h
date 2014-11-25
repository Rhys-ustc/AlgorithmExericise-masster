#ifndef MYTREE_H
#define MYTREE_H
#include<iostream>
#include<string>
#include <cstdlib>
#include<assert.h>
#include"MacroDef.h"
#include<stack>
#include<queue>

using namespace std;

struct MyTree 
{
      MyTree *lchild;
	  MyTree *rchild;
	  ELEMTYPE data;
};

class BiTree
{
   public:
          BiTree();
	  ~BiTree();
	  ELEMTYPE GetData(void);
	  MyTree *GetLeftChild(void);
	  MyTree *GetRightChild(void);

	  void CreateBiTree(void);
      void PreOrder(const int traversalType=TREE_RECURSE);
	  void InOrder(const int traversalType=TREE_RECURSE);
	  void PostOrder(const int traversalType=TREE_RECURSE);
	  void LayerTraversal(void); 
	  int CountLeaves(void);
	  int Depth(void);
	  int Width(void);
   private:
      inline void VisitNode(MyTree *node)
	      {
		      cout<<node->data<<" ";
	      };
	  void CreateBiTree(MyTree *&root);
      void PreOrder(MyTree *root);
	  void PreOrderNoRecurse(MyTree *root);
	  void InOrder(MyTree *root);
	  void InOrderNoRecurse(MyTree *root);
	  void PostOrder(MyTree *root);
	  void PostOrderNoRecurse(MyTree *root);
	  void LayerTraversal(MyTree *root); 
	  int CountLeaves(MyTree *root);
	  int Depth(MyTree *root);
	  int Width(MyTree *root);
 
   private:
	  MyTree *m_root;

};

#endif

