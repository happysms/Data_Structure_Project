#pragma once
#include<iostream>
#include"Contents.h"
using namespace std;

template<typename T>
struct Node {
	T data;
	Node* left;
	Node* right;
};

template<typename T>
class BinarySearchTree {
public:
	// ������
	BinarySearchTree();
	// �Ҹ���
	~BinarySearchTree() { }

	/**
	*	@brief	Tree�� Empty���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� ��������� true����, �ƴϸ� false ����
	*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree�� Full���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� Full�̸� true ����, �ƴϸ� false ����
	*/
	bool IsFull()const;

	/**
	*	@brief	Tree�� ����
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree�� node�� �� ������ Ȯ����
	*	@pre	none
	*	@post	none
	*	@return	Tree�� node ������ ����
	*/
	int GetLength() const;

	/**
	*	@brief	Tree�� �� node�� �߰��Ѵ�
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree�� �� node�� �߰���
	*/
	void Add(T item);

	/**
	*	@brief	Tree���� ������� �ϴ� node�� ã�� ����
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree���� �Է��� node�� ������
	*/
	void DeleteItem(T item);

	/**
	*	@brief	�Է��� ���� node�� Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	node�� Tree�� �ִ��� �˻������ �˷���
	*/
	Node<T>* RetrieveItem(T& item, bool& found)const;

	/**
	*	@brief	Tree�� node�� ��ũ���� ����Ѵ�.
	*	@pre	none
	*	@post	��ũ���� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
	*/
	void PrintTree(ostream& out) const;



private:
	Node<T>* root;		// Node Ÿ���� root
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
}

template<typename T>
bool BinarySearchTree<T>::IsEmpty() const {
	if (root = NULL) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
bool BinarySearchTree<T>::IsFull() const {
	Node<T>* temp;
	try {
		temp = new Node<T>;
		delete temp;
		return false;
	}
	catch (bad_alloc exception) {
		return true;
	}
}

template<typename T>
void BinarySearchTree<T>::MakeEmpty() {
	MakeEmptyTree(root);
}

template<typename T>
int BinarySearchTree<T>::GetLength() const {
	return Countnodes(root);
}

template<typename T>
void BinarySearchTree<T>::DeleteItem(T item) {
	Delete(root, item);
}


// Tree�� ���ο� node �߰�
template<typename T>
void BinarySearchTree<T>::Add(T item) {
	Insert(root, item);					// �� node �߰��ϴ� �Լ� ȣ��
}

template<typename T>
Node<T>* BinarySearchTree<T>::RetrieveItem(T& item, bool& found) const {
	Retrieve(root, item, found);
	return root;
}

template<typename T>
void BinarySearchTree<T>::PrintTree(ostream& out)const {
	cout << "[InOrder]" << endl;
	PrintInOrderTraversal(root, out);			// InOrder ������� ���
	cout << endl << "[PreOrder]" << endl;
	PrintPreOrderTraversal(root, out);			// PreOrder ������� ���
	cout << endl << "[PostOrder]" << endl;
	PrintPostOrderTraversal(root, out);			// PostOrder ������� ���
}

template<typename T>
void PrintInOrderTraversal(Node<T>* root, ostream& out) {
	if (root != NULL) {
		PrintInOrderTraversal(root->left, out);
		out << (root->data);
		PrintInOrderTraversal(root->right, out);
	}
}

// PreOrder ������� ����ϴ� �Լ�
template<class ItemType>
void PrintPreOrderTraversal(Node<ItemType>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		out << (root->data);							// root�� ���� ���
		PrintPreOrderTraversal(root->left, out);	// root�� �������� ���� PreOrder �Լ� �ٽ� ȣ��
		PrintPreOrderTraversal(root->right, out);	// root�� ���������� ���� PreOrder �Լ� �ٽ� ȣ��
	}
}

// PostOrder ������� ����ϴ� �Լ�
template<class ItemType>
void PrintPostOrderTraversal(Node<ItemType>* root, ostream& out)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintPostOrderTraversal(root->left, out);	// root�� �������� ���� �ٽ� PostOrder �Լ� ȣ��
		PrintPostOrderTraversal(root->right, out);	// root�� ���������� ���� �ٽ� PostOrder �Լ� ȣ��
		out << (root->data);							// root�� �� ���
	}
}

//global func
template<typename T>
void MakeEmptyTree(Node<T>*& root)
{
	root = NULL;			// root ��带 Null�� ��
}

template<typename T>
int Countnodes(Node<T>* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return CountNodes(root->left) + CountNodes(root->right) + 1;
	}
}

template<typename T>
void Insert(Node<T>*& root, T item) {
	if (root == NULL) {
		root = new Node<T>;
		root->data = item;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data > item)
		Insert(root->left, item);
	else if (root->data < item) {
		Insert(root->right, item);
	}
}

template<typename T>
void Delete(Node<T>*& root, T item) {
	if (item < root->data) {
		Delete(root->left, item);
	}
	else if (item > root->data) {
		Delete(root->right, item);
	}
	else
		DeleteNode(root);
}

template<typename T>
void DeleteNode(Node<T>*& root) {
	T item;
	Node<T>* temp;
	temp = root;

	if (root->left == NULL) {
		root = root->right;
		delete temp;
	}
	else if (root->right == NULL) {
		root = root->left;
		delete temp;
	}
	else {
		GetPredecessor(root->left, item);
		root->data = item;
		Delete(root->left, item);
	}
}

template<typename T>
void GetPredecessor(Node<T>* root, T& item) {
	while (root->right != NULL) {
		root = root->right;
	}
	item = root->data;
}

template<typename T>
void Retrieve(Node<T>* root, T& item, bool& found) {
	if (root != NULL) {
		found = false;
	}
	else if (item < root->data)
		Retrieve(root->left, item, found);
	else if (item > root->data)
		Retrieve(root->right, item, found);
	else {
		item = (root->data);
		found = true;
	}
}