#include "Tree.h"
Tree::Tree() {
	size = 0;
	root = NULL;
}

Tree::~Tree() {

}

void Tree::AddToTree(int p) {
	if (root == NULL) {
		Node* tmp = new Node(p, NULL, NULL, NULL);
		root = tmp;
	}
	else {
		Node* prev = NULL;
		Node* current = root;
		while (current != NULL) {
			prev = current;
			if (current->info < p)
				current = current->right;
			else if (current->info > p)
				current = current->left;
		}
		if (prev->info < p) {
			prev->right = new Node(p, NULL, NULL, prev);
			size++;
		}
		else if (prev->info > p) {
			prev->left = new Node(p, NULL, NULL, prev);
			size++;
		}
	}
}

Node* Tree::FindNode(int p) {
	Node* tmp = root;
	while (tmp != NULL && tmp->info != p) {
		if (tmp->info < p)
			tmp = tmp->left;
		else if (tmp->info > p)
			tmp = tmp->right;
	}
	return tmp;
}

Node* Tree::FindNode(int p, Node* tmp) {
	if (tmp != NULL) {
		if (tmp->info == p)
			return tmp;
		else if (tmp->info < p)
			return FindNode(p, tmp->right);
		else if (tmp->info > p)
			return FindNode(p, tmp->left);
	}
}

void Tree::PreOrder() {
	PreOrder(root);
}

void Tree::PreOrder(Node* p) {
	if (p != NULL) {
		cout << "[" << p->info << "] ";
		PreOrder(p->left);
		PreOrder(p->right);
	}
}

void Tree::InOrder() {
	InOrder(root);
}

void Tree::InOrder(Node* p) {
	if (p != NULL) {
		PreOrder(p->left);
		cout << "[" << p->info << "] ";
		PreOrder(p->right);
	}
}

void Tree::PostOrder() {
	PostOrder(root);
}

void Tree::PostOrder(Node* p) {
	if (p != NULL) {
		PreOrder(p->left);
		PreOrder(p->right);
		cout << "[" << p->info << "] ";
	}
}

int Tree::NumberOfNodes(Node* p) {
	if (p == NULL)
		return NULL;

	return 1+ NumberOfNodes(p->left) + NumberOfNodes(p->right);
}

int Tree::LargestRightSubtree(Node* p) {
	if (p == NULL)
		return NULL;

	int left = LargestRightSubtree(p->left);
	int right = LargestRightSubtree(p->right);

	if (left < NumberOfNodes(p->right))
		left = NumberOfNodes(p->right);
	else if (right < NumberOfNodes(p->right))
		right = NumberOfNodes(p->right);


	if (left > right)
		return left;
	else return right;
}

Node* Tree::LargestRightSubtree() {
	int value = LargestRightSubtree(root);
	Node* result = SearchLargestRightSubtree(root, value);
	return result;
}

Node* Tree::SearchLargestRightSubtree(Node* p, int value) {
	if (p == NULL)
		return NULL;
	else if (p->right != NULL && NumberOfNodes(p->right) == value)
		return p;

	Node* p1 = SearchLargestRightSubtree(p->left, value);
	Node* p2 = SearchLargestRightSubtree(p->right, value);
	if (p1 != NULL && NumberOfNodes(p1->right) == value)
		return p1;
	else if (p2 != NULL && NumberOfNodes(p2->right) == value)
		return p2;
}

int Tree::FindClosestValueLeaf(Node* p, int value) {
	if (p == NULL)
		return NULL;
	
	int leftInfo = FindClosestValueLeaf(p->left, value);
	int rightInfo = FindClosestValueLeaf(p->right, value);

	int leftRez = abs(leftInfo - value);
	int rightRez = abs(rightInfo - value);

	if (leftRez < rightRez && leftRez >= 0)
		return leftInfo;
	else if (leftRez > rightRez && rightRez >= 0)
		return rightInfo;

	if (p->left == NULL && p->right == NULL)
		return p->info;
}

Node* Tree::TestSearch(Node* p, int value) {
	if (p == NULL)
		return NULL;
	else if (p->info == value)
		return p;
	else if (p->left != NULL && p->left->info == value)
		return p->left;
	else if (p->right != NULL && p->right->info == value)
		return p->right;

	Node* p1 = TestSearch(p->left, value);
	Node* p2 = TestSearch(p->right, value);

	if (p1 != NULL && p1->info == value)
		return p1;
	else if (p2 != NULL && p2->info == value)
		return p2;
}

Node* Tree::FindClosestValueLeaf(int p) {
	int value = FindClosestValueLeaf(root, p);
	Node* result = TestSearch(root, value);
	return result;
}

int Tree::SumOfTree(Node* p) {
	if (p == NULL)
		return NULL;

	return SumOfTree(p->left) + SumOfTree(p->right) + p->info;
}