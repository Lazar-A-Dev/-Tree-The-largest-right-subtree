#pragma once
#include<iostream>
using namespace std;
class Node {
public:
	int info;
	Node* left, *right, *parent;

public:
	Node() {
		info = 0;
		left = right = parent = NULL;
	}

	Node(int info, Node* left, Node* right, Node* parent) {
		this->info = info;
		this->left = left;
		this->right = right;
		this->parent = parent;
	}

	~Node() {}
};