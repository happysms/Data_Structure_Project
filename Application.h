#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"BinarySearchTree.h"
#include"Contents.h"
#include"DoublyLinkedList.h"
#include"InfoType.h"
#include"DoublyIterator.h"
#include"Folder.h";

class Application {
private:
	BinarySearchTree<Contents> MasterList;
	DoublyLinkedList<InfoType> EventList;
	DoublyLinkedList<InfoType> CharacterList;
	DoublyLinkedList<InfoType> PlaceList;
	DoublyLinkedList<Contents> BestList;
	DoublyLinkedList<Folder> FolderList;

public:
	/*
	* constructor
	*/
	Application() {}

	/*
	* destructor
	*/
	~Application() {}

	/*
	* brief : ���α׷��� ����� �����Ѵ�.
	* pre : ���α׷��� �����Ѵ�.
	* post : ���α׷��� ������.
	*/
	void Run();

	/*
	* brief : Search����� �����Ѵ�.
	* pre : Run�Լ����� ����Ǿ���Ѵ�.
	* post : Search����� �����ϰ� �����Ѵ�. 
	*/
	void SearchRun();

	/*
	* brief : ���α׷��� ����� �����ְ�, ����ڷκ��� �ش� ��ɿ� �ش��ϴ� ���ڸ� �Է¹޴´�.
	* return : �Է¹��� ���� ��ȯ�Ѵ�.
	*/
	int GetCommand();

	/*
	* brief : Search ����� �����ְ�, ����ڷκ��� �ش� ��ɿ� �ش��ϴ� ���ڸ� �Է¹޴´�.
	* return : �Է¹��� ���� ��ȯ�Ѵ�.
	*/
	int SearchGetCommand();

	/*
	* post : ���ο� �������� �� ����Ʈ�� �߰��ȴ�.
	*/
	void AddContents();

	/*
	* post : �ش� ������ �� ������ ������ �� ����Ʈ���� �����ȴ�.
	*/
	void DeleteContents();

	/*
	* post : �����͸���Ʈ�� ��� ������ ȭ�鿡 ����Ѵ�.
	*/
	void DisplayAllContents();

	/*
	* post : Ư�� �������� primaryŰ�� �Է¹޾� �� ���� �ش��ϴ� �������� ������ ��ġ�Ͽ� ȭ�鿡 ����Ѵ�.
	*/
	void SearchFromMasterList();

	/*
	* post : �������� primary key�� ������ �����͸���Ʈ�� ���� �� �ش� �������� ������ �����Ѵ�.
	*/
	void ReplaceContents();

	/*
	* pre : Ư�� ������ �� ����Ʈ�� ������ �����ش�. 
	* post : ����ڿ��� � ������ ����Ʈ�� ����� �������� �Է¹ް�, �ش� ���� ����Ʈ�� ȭ�鿡 ����Ѵ�. 
	*/
	void GetInfoList(int command);

	/*
	* brief : ������ �����Ѵ�.
	* post : ����ڿ��� ���� ���� �Է¹ް�, FolderList�� �ش� ���� �߰��Ѵ�.
	*/
	void AddFolder();

	/*
	* brief : ������ �������� �߰��Ѵ�.
	* post : �����κ��� �߰��� �������� primary key�� �Է¹޾� �Ķ���ͷ� �Է¹��� ������ ����Ʈ�� ���� �߰��Ѵ�. 
	*/
	void AddContentsToFolder(SortedList<Contents>& list);

	/*
	* post : ��ü ������ ȭ�鿡 ����Ѵ�. 
	*/
	void DisplayFolder();

	/*
	* post : �������� ���� ���� �Է¹��� �� �ش��ϴ� ���� ��� ���� �����������Ʈ ������ ȭ�鿡 ����Ѵ�. 
	*/
	void SearchFolder();
};