#include<iostream>
using namespace std;
#include"Tree.h"
void main() {
	Tree t;
	t.AddToTree(22);
	t.AddToTree(19);
	t.AddToTree(44);
	t.AddToTree(12);
	t.AddToTree(13);
	t.AddToTree(14);
	t.AddToTree(15);
	t.AddToTree(16);
	t.AddToTree(3);
	t.AddToTree(5);

	t.PreOrder();
	cout << endl;
	//cout << "Number of nodes: " << t.NumberOfNodes(t.root->left);
	//cout << "Find closest value to leaf: " << t.FindClosestValueLeaf(10)->info << endl;
	//cout << "Sum of tree: " << t.SumOfTree(t.root) << endl;
	cout << "Node with largest subtree: " << t.LargestRightSubtree()->info << endl;
	system("pause");

}