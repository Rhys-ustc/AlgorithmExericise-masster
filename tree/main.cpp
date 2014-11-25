#include"MyTree.h"
#include"MacroDef.h"

#include<iostream>

using namespace std;

int main()
{
	BiTree T;
        // Create tree by input from the terminate
	T.CreateBiTree();
	// preorder 
	const int traversalRecurse = TREE_RECURSE;
	const int traversalNoRecurse = TREE_NO_RECURSE;

	cout<<"PreOrder recursively: ";
	T.PreOrder(traversalRecurse);
    cout<<endl;
    cout<<"PreOrder no recursively: ";
	T.PreOrder(traversalNoRecurse);
	// Inorder
	cout<<endl<<"InOrder recursively: ";
	T.InOrder(traversalRecurse);
    cout<<endl<<"InOrder no recursively: ";
    T.InOrder(traversalNoRecurse);
	cout<<endl;
	// PostOrder
	cout<<"PostOrder recursively: ";
	T.PostOrder(traversalRecurse);
    cout<<endl<<"PostOrder no recursively: ";
    T.PostOrder(traversalNoRecurse);
	cout<<endl;
	// layer traversal
	cout<<"layer traversal: ";
	T.LayerTraversal();
	cout<<endl;
        // count leaves
	cout<<"tree leaves: "<<T.CountLeaves()<<endl;
	// tree depth
	cout<<"tree depth: "<<T.Depth()<<endl;
	// tree Width
	cout<<"tree width: "<<T.Width()<<endl;


	return 0;
}
