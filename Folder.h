#pragma once
#include<string>
#include<iostream>
#include"SortedList.h"
#include"Contents.h"
using namespace std;

class Folder {
private:
	string name;
	SortedList<Contents> list;

public:
	Folder() {}

	Folder(string _name) {
		name = _name;
	}

	void SetName(string _name) {
		name = _name;
	}

	bool operator==(const Folder& Info) {
		if (name == Info.name) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator>(const Folder& Info) {
		if (Info.name < name) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator<(const Folder& Info) {
		if (Info.name > name) {
			return true;
		}
		else {
			return false;
		}
	}

	string Getname() {
		return name;
	}
	
	SortedList<Contents>* getListPtr() {
		return &list;
	}
};

