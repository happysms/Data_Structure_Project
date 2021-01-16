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
	* brief : 프로그램의 기능을 제어한다.
	* pre : 프로그램을 시작한다.
	* post : 프로그램을 끝낸다.
	*/
	void Run();

	/*
	* brief : Search기능을 제어한다.
	* pre : Run함수에서 실행되어야한다.
	* post : Search기능을 수행하고 종료한다. 
	*/
	void SearchRun();

	/*
	* brief : 프로그램의 기능을 보여주고, 사용자로부터 해당 기능에 해당하는 숫자를 입력받는다.
	* return : 입력받은 값을 반환한다.
	*/
	int GetCommand();

	/*
	* brief : Search 기능을 보여주고, 사용자로부터 해당 기능에 해당하는 숫자를 입력받는다.
	* return : 입력받은 값을 반환한다.
	*/
	int SearchGetCommand();

	/*
	* post : 새로운 콘텐츠가 각 리스트에 추가된다.
	*/
	void AddContents();

	/*
	* post : 해당 콘텐츠 및 콘텐츠 정보가 각 리스트에서 삭제된다.
	*/
	void DeleteContents();

	/*
	* post : 마스터리스트의 모든 정보를 화면에 출력한다.
	*/
	void DisplayAllContents();

	/*
	* post : 특정 콘텐츠의 primary키를 입력받아 그 값에 해당하는 콘텐츠의 정보를 서치하여 화면에 출력한다.
	*/
	void SearchFromMasterList();

	/*
	* post : 콘텐츠의 primary key를 가져와 마스터리스트에 접근 후 해당 콘텐츠의 정보를 수정한다.
	*/
	void ReplaceContents();

	/*
	* pre : 특정 정보가 들어간 리스트의 내용을 보여준다. 
	* post : 사용자에게 어떤 정보의 리스트를 출력할 것인지를 입력받고, 해당 정보 리스트를 화면에 출력한다. 
	*/
	void GetInfoList(int command);

	/*
	* brief : 폴더를 생성한다.
	* post : 사용자에게 폴더 명을 입력받고, FolderList에 해당 값을 추가한다.
	*/
	void AddFolder();

	/*
	* brief : 폴더에 콘텐츠를 추가한다.
	* post : 유저로부터 추가할 콘텐츠의 primary key를 입력받아 파라미터로 입력받은 폴더의 리스트에 값을 추가한다. 
	*/
	void AddContentsToFolder(SortedList<Contents>& list);

	/*
	* post : 전체 폴더를 화면에 출력한다. 
	*/
	void DisplayFolder();

	/*
	* post : 유저에게 폴더 명을 입력받은 뒤 해당하는 폴더 명과 폴더 멤버변수리스트 내용을 화면에 출력한다. 
	*/
	void SearchFolder();
};