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
	// 생성자
	BinarySearchTree();
	// 소멸자
	~BinarySearchTree() { }

	/**
	*	@brief	Tree가 Empty인지 확인
	*	@pre	none
	*	@post	none
	*	@return	Tree가 비어있으면 true리턴, 아니면 false 리턴
	*/
	bool IsEmpty()const;

	/**
	*	@brief	Tree가 Full인지 확인
	*	@pre	none
	*	@post	none
	*	@return	Tree가 Full이면 true 리턴, 아니면 false 리턴
	*/
	bool IsFull()const;

	/**
	*	@brief	Tree를 비운다
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree에 node가 몇 개인지 확인함
	*	@pre	none
	*	@post	none
	*	@return	Tree의 node 개수를 리턴
	*/
	int GetLength() const;

	/**
	*	@brief	Tree에 새 node를 추가한다
	*	@pre	ItemType의 객체를 생성
	*	@post	Tree에 새 node가 추가됨
	*/
	void Add(T item);

	/**
	*	@brief	Tree에서 지우고자 하는 node를 찾고 지움
	*	@pre	ItemType의 객체를 생성
	*	@post	Tree에서 입력한 node가 삭제됨
	*/
	void DeleteItem(T item);

	/**
	*	@brief	입력한 값의 node를 Tree에서 검색함
	*	@pre	찾고자 하는 item과 검색결과에 대한 found 설정
	*	@post	node가 Tree에 있는지 검색결과를 알려줌
	*/
	Node<T>* RetrieveItem(T& item, bool& found)const;

	/**
	*	@brief	Tree의 node를 스크린에 출력한다.
	*	@pre	none
	*	@post	스크린에 Tree가 InOrder, PreOrder, PostOrder 방법으로 각각 출력됨.
	*/
	void PrintTree(ostream& out) const;



private:
	Node<T>* root;		// Node 타입의 root
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


// Tree에 새로운 node 추가
template<typename T>
void BinarySearchTree<T>::Add(T item) {
	Insert(root, item);					// 새 node 추가하는 함수 호출
}

template<typename T>
Node<T>* BinarySearchTree<T>::RetrieveItem(T& item, bool& found) const {
	Retrieve(root, item, found);
	return root;
}

template<typename T>
void BinarySearchTree<T>::PrintTree(ostream& out)const {
	cout << "[InOrder]" << endl;
	PrintInOrderTraversal(root, out);			// InOrder 방법으로 출력
	cout << endl << "[PreOrder]" << endl;
	PrintPreOrderTraversal(root, out);			// PreOrder 방법으로 출력
	cout << endl << "[PostOrder]" << endl;
	PrintPostOrderTraversal(root, out);			// PostOrder 방법으로 출력
}

template<typename T>
void PrintInOrderTraversal(Node<T>* root, ostream& out) {
	if (root != NULL) {
		PrintInOrderTraversal(root->left, out);
		out << (root->data);
		PrintInOrderTraversal(root->right, out);
	}
}

// PreOrder 방법으로 출력하는 함수
template<class ItemType>
void PrintPreOrderTraversal(Node<ItemType>* root, ostream& out)
{
	if (root != NULL)								// root가 존재하는 경우
	{
		out << (root->data);							// root를 먼저 출력
		PrintPreOrderTraversal(root->left, out);	// root의 왼쪽으로 가서 PreOrder 함수 다시 호출
		PrintPreOrderTraversal(root->right, out);	// root의 오른쪽으로 가서 PreOrder 함수 다시 호출
	}
}

// PostOrder 방법으로 출력하는 함수
template<class ItemType>
void PrintPostOrderTraversal(Node<ItemType>* root, ostream& out)
{
	if (root != NULL)								// root가 존재하는 경우
	{
		PrintPostOrderTraversal(root->left, out);	// root의 왼쪽으로 가서 다시 PostOrder 함수 호출
		PrintPostOrderTraversal(root->right, out);	// root의 오른쪽으로 가서 다시 PostOrder 함수 호출
		out << (root->data);							// root의 값 출력
	}
}

//global func
template<typename T>
void MakeEmptyTree(Node<T>*& root)
{
	root = NULL;			// root 노드를 Null로 함
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