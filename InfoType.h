#pragma once
#include<string>
#include"SortedList.h"

class InfoType {
private:
	string name;
	SortedList<int> list;

public:
	InfoType() { }

	InfoType(string _name) { 
		name = _name;
	}

	~InfoType() { }

	void SetName(string _name) {
		name = _name;
		list.MakeEmpty();
	}

	SortedList<int>* getListPtr() {
		return &list;
	}

	bool operator==(const InfoType& Info) {
		if (Info.name == name) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator>(const InfoType& Info) {
		if (Info.name < name) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator<(const InfoType& Info) {
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

	/*
	* post : 콘텐츠의 간략한 정보를 출력한다. 
	*/

};

