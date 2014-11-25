#include"MyTree.h"

// construction 
BiTree::BiTree(void)
{
	m_root = NULL;
}

//
BiTree::~BiTree(void)
{
	if (m_root == NULL)
	{
		return;
	}
	MyTree *p;
}

ELEMTYPE BiTree::GetData()
{
	return m_root->data;
}

MyTree* BiTree::GetLeftChild()
{
	return m_root->lchild;
}

MyTree* BiTree::GetRightChild()
{
	return m_root->rchild;
}

void BiTree::CreateBiTree(void)
{
	cout<<"Please input nodes to create a binary tree:"<<endl;
	//if (cin)
	CreateBiTree(m_root);
}
void BiTree::CreateBiTree(MyTree* &root)
{
     assert(root==NULL);
     string tmp;
     cin>>tmp;
    if (tmp == "#")
	{
		root = NULL;
		return;
	}
	else
	{
        root = new MyTree;
        root->data = atoi(tmp.c_str());
		root->lchild = NULL;
		root->rchild = NULL;
		CreateBiTree(root->lchild);
		CreateBiTree(root->rchild);
	}

}


void BiTree::PreOrder(const int traversalType)
{
	assert(traversalType==TREE_RECURSE||traversalType==TREE_NO_RECURSE);
	if (m_root==NULL)
	{
		cout<<"This is an empty tree!"<<endl;
	}
	if(traversalType==TREE_RECURSE)
	{
		PreOrder(m_root);
	}
	else
	{
		PreOrderNoRecurse(m_root);
	}

}

void BiTree::PreOrder(MyTree *root)
{
	if (root==NULL)
	{
		return ;
	}
    // visit the data preorder
    VisitNode(root);
	PreOrder(root->lchild);
	PreOrder(root->rchild);

}

void BiTree::PreOrderNoRecurse(MyTree *root)
{
	if (root==NULL)
	{
		return ;
	}
	stack<MyTree*>stk;

	while(root!=NULL||!stk.empty())
	{
		while (root!=NULL)
		{
		   VisitNode(root);
		   stk.push(root);
		   root = root->lchild;
		}
        if (!stk.empty())
		{
			root = stk.top();
			stk.pop();
            root = root->rchild;
		}
	}

}
void BiTree::InOrder(const int traversalType)
{
	assert(traversalType==TREE_RECURSE||traversalType==TREE_NO_RECURSE);
	if (m_root==NULL)
	{
		cout<<"This is an empty tree!"<<endl;
		return ;
	}
	if(traversalType==TREE_RECURSE)
	{
		InOrder(m_root);
	}
	else
	{
		InOrderNoRecurse(m_root);
	}

}

void BiTree::InOrder(MyTree *root)
{
	if (root == NULL)
	{
		return ;
	}
	InOrder(root->lchild);
	VisitNode(root);
	InOrder(root->rchild);

}

void BiTree::InOrderNoRecurse(MyTree *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<MyTree *>stk;
    // use stack to store each node in the tree
    while ((root !=NULL) || !stk.empty())
    {
        while (root != NULL)
        {
            stk.push(root);
            root = root->lchild;
        }
        if (!stk.empty())
        {
            root = stk.top();// get the top element
            stk.pop();          // delete the top element
            VisitNode(root);
            root = root->rchild;
        }

    }

}
void BiTree::PostOrder(const int traversalType)
{
	assert(traversalType==TREE_RECURSE||traversalType==TREE_NO_RECURSE);

	if (m_root==NULL)
	{
		cout<<"This is an empty tree!"<<endl;
		return;
	}
	if(traversalType==TREE_RECURSE)
	{
		PostOrder(m_root);
	}
	else
	{
		PostOrderNoRecurse(m_root);
	}

}

void BiTree::PostOrder(MyTree *root)
{
	if (root==NULL)
	{
		return;
	}

	PostOrder(root->lchild);
	PostOrder(root->rchild);
	VisitNode(root);
} 
// unfinished
void BiTree::PostOrderNoRecurse(MyTree *root)
{
    if (root==NULL)
    {
        return;
    }
     stack<MyTree *>stk;

     while ((root != NULL) || !stk.empty())
     {
         while (root != NULL)
         {
             stk.push(root);
             root = root->lchild;
         }
         if (!stk.empty())
         {
             root = stk.top();
             stk.pop();
             root = root->rchild;
             if (root != NULL)
                  VisitNode(root);
         }

     }
}
void BiTree::LayerTraversal(void)
{
	if (m_root==NULL)
	{
		cout<<"This is an empty tree!"<<endl;
		return;
	}
	LayerTraversal(m_root);
}

void BiTree::LayerTraversal(MyTree *root)
{
	queue<MyTree*>que;
	que.push(root);

	while(!que.empty())
	{
		root = que.front();// get the fron element in queue
		que.pop();        // delete the fron element in queue
		VisitNode(root);
		if(root->lchild != NULL)
		{
			que.push(root->lchild);
		}
		if (root->rchild != NULL)
		{
			que.push(root->rchild);
		}
	}

}

int  BiTree::CountLeaves(void)
{
     return CountLeaves(m_root);		
}

int BiTree::CountLeaves(MyTree *root)
{
	if (root==NULL)
	{
		return 0;
	}
    if ((root->lchild==NULL) && (root->rchild==NULL))
    {
        return (1+CountLeaves(root->lchild)+CountLeaves(root->rchild));
    }
    else
    {
        return (CountLeaves(root->lchild)+CountLeaves(root->rchild));
    }
}

int  BiTree::Depth(void)
{
	return Depth(m_root);
}

int BiTree::Depth(MyTree *root)
{
	if (root==NULL)
	{
		return 0;
	}
	int ld = Depth(root->lchild);
	int rd = Depth(root->rchild);
	return ((ld>rd?ld:rd)+1);

}

int  BiTree::Width(void)
{
	return Width(m_root);
}

int BiTree::Width(MyTree *root)
{
	if (root==NULL)
	{
		return 0;
	}

	return -1;

}



