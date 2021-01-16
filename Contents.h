#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <ctime>

using namespace std;

class Contents {
protected:
	//--------라벨을 입력해야하는 변수-----------
	string characters; //등장 인물
	string place; //장소
	string event; //이벤트

	//----------자동지정변수-----------
	string id; //시간.jpg or 시간.mp4 형태로 저장됨. 동시간대를 구분하기 위해 같은 것이 존재한다면 뒤에 숫자를 덧붙힌다.    
	int year; //생성 연도
	int date; //생성 날짜 !!!primary key!!!
	string keywords; // 키워드(등장 인물, 사물, 장소, 이벤트의 총집합)
	int count; // 검색 횟수
	int category; //분류

public:
	Contents();

	~Contents();

	/*
	* brief: 플레이 가상함수
	* post: 콘텐츠를 불러온다.
	*/
	//virtual void play() = 0;

	/*
	* brief: 모든 정보의 getter
	* post: 콘텐츠의 정보를 반환한다.
	*/
	string Getid() const;

	int Getdate() const;

	int Getyear() const;

	int Getcategory() const;

	string Getcharacters() const;

	string Getplace() const;

	string Getevent() const;

	string Getkewords() const;

	int Getcount() const;

	/*
	* brief: 키보드로부터 콘텐츠 정보를 입력받아 set한다.
	* post: 콘텐츠의 정보를 설정한다.
	*/
	void SetcharactersFromKB();

	void SetplaceFromKB();

	void SeteventFromKB();

	void SetRecordFromKB();
	/*
	* brief: 모든 콘텐츠 정보의 set.
	* post: 콘텐츠의 정보를 설정한다.
	*/
	void Setevent(string _event);

	void Setplace(string _place);

	void Setcharacters(string _characters);

	void Setdate(int _date);

	/*
	* brief: 모든 콘텐츠 정보의 set.
	* pre: 장소, 이벤트, 인물의 정보가 set되어야한다.
	* post: 모든 정보를 " "로 연결한 문자열을 keywords배열에 할당한다.
	*/
	void Setkeywords(string _characters, string _event, string _place);

	/*
	* brief : 모든 콘텐츠의 정보를 보여줌
	*/
	void DisplayRecordOnScreen();

	/*
	* brief : 콘텐츠의 정보를 화면에 출력해주는 << 연산자 오퍼레이터이다.
	*/
	friend ostream& operator<<(ostream& cout, const Contents& data) {
		if (data.category == 1)
		{
			cout << "\t----------" << data.date << ".jpg" << "----------" << endl;
			cout << "\t카테고리: ";
			cout << "사진\t";
		}
		else if (data.category == 2) {
			cout << "\t----------" << data.date << ".mp4" << "----------" << endl;
			cout << "\t카테고리: ";
			cout << "동영상\t";
		}
		else {
			cout << "\t----------" << data.date << ".mp3" << "----------" << endl;
			cout << "\t카테고리: ";
			cout << "음악\t";
		}
		cout << "\t생성 시간: " << data.date << "\t장소: " << data.place << endl;
		cout << "\t이벤트: " << data.event << "\t\t인물: " << data.characters << "\t\t조회 수: " << data.count << endl << endl;
		return cout;
	}

	/*
	* brief : primary key를 기준으로 콘텐츠의 동일 여부를 확인하는 연산자 오버로딩
	* post : 파라미터로 받은 date가 일치하면 true를 그렇지 않으면 false를 리턴한다.
	*/
	bool operator==(const Contents& data);

	/*
	* pre: 파라미터로 받은 콘텐츠의 모든 멤버 변수의 값이 초기화되어 있어야한다.
	* post: 파라미터로 받은 콘텐츠의 모든 멤버변수의 값을 해당 객체에 할당한다.
	*/
	void operator=(const Contents& data);

	/*
	* post : 파라미터로 받은 콘텐츠의 생성날짜가 해당객체인 콘텐츠의 생성날짜보다 클 시에 true를 그렇지 않으면 false를 할당함.
	*/
	bool operator<(const Contents& data);

	/*
	* post : 파라미터로 받은 콘텐츠의 생성날짜가 해당객체인 콘텐츠의 생성날짜보다 작을 시에 true를 그렇지 않으면 false를 할당함.
	*/
	bool operator>(const Contents& data);

	/*
	* pre: 파일이 open되어 있어야한다.
	* post: 파일에 있는 콘텐츠 정보를 읽어온다.
	*/
	//int ReadDataFromFile(ifstream& fin);
};

class Photo : public Contents {
public:
	Photo() {
		category = 1;
	}

	~Photo() { }

	//void play() override{
	   //cout << "사진 Display" << endl;
	   //count++;
   //}
};

class Video : public Contents {
public:
	Video() {
		category = 2;
	};

	~Video() {};

	//void play() override {
   //	cout << "동영상 재생" << endl;
   //	count++;
   //}
};

class Music : public Contents {
public:
	Music() {
		category = 3;
	};

	~Music() {};

	//void play() override {
	//	cout << "음악 재생" << endl;
	//	count++;
	//}
};


