#include "Contents.h"

Contents::Contents() {
	time_t timer;
	struct tm t;
	timer = time(NULL); // 현재 시각을 초 단위로 얻기
	localtime_s(&t, &timer); // 초 단위의 시간을 분리하여 구조체에 넣기
	if (category == 1) {
		id = to_string(date) + ".jpg";
	}
	else if (category == 2) {
		id = to_string(date) + ".mp4";
	}
	else {
		id = to_string(date) + ".mp3";
	}
	year = t.tm_year + 1900;
	date = (t.tm_mon + 1) * 100000000 + t.tm_mday * 1000000 + t.tm_hour * 10000 + t.tm_min * 100 + t.tm_sec;
	place = "";
	event = "";
	count = 0;

}

Contents::~Contents() {}

void Contents::SetcharactersFromKB() {
	string _characters;
	cout << "\t등장 인물 : (2명 이상일 경우 ' '를 사용하여 작성 ex)어머니 아버지)";
	cin >> _characters;
	characters = _characters;
}

void Contents::SetplaceFromKB() {
	string _place;
	cout << "\t장소 : ";
	cin >> _place;
	place = _place;
}

void Contents::SeteventFromKB() {
	string _event;
	cout << "\t이벤트 : ";
	cin >> _event;
	event = _event;
}


string Contents::Getplace() const {
	return place;
}


string Contents::Getevent() const {
	return event;
}

string Contents::Getid() const {
	return id;
}

int Contents::Getdate() const {
	return date;
}

int Contents::Getyear() const {
	return year;
}

int Contents::Getcategory() const {
	return category;
}

string Contents::Getcharacters() const {
	return characters;
}

string Contents::Getkewords() const {
	return keywords;
}

int Contents::Getcount() const {
	return count;
}

void Contents::SetRecordFromKB() {
	SetplaceFromKB();
	SeteventFromKB();
	SetcharactersFromKB();
	Setkeywords(characters, event, place);
}

void Contents::Setkeywords(string _characters, string _event, string _place) {
	string keywords; //키워드를 " "단위로 저장한다.
	keywords = _characters + " " + _event + " " + _place;
}



bool Contents::operator==(const Contents& data) {
	if (date == data.date)
		return true;
	return false;
}

void Contents::operator=(const Contents& data) {
	characters = data.characters;
	place = data.place;
	event = data.event;
	id = data.id;
	year = data.year;
	date = data.date;
	keywords = data.keywords;
	count = data.count;
	category = data.category;
}

bool Contents::operator<(const Contents& data) {
	if (date < data.date) {
		return true;
	}
	else
		return false;
}

bool Contents::operator>(const Contents& data) {
	if (date > data.date) {
		return true;
	}
	else
		return false;
}

void Contents::DisplayRecordOnScreen() {
	if (category == 1)
	{
		cout << "\t----------" << date << ".jpg" << "----------" << endl;
		cout << "\t카테고리: ";
		cout << "사진\t";
	}
	else if (category == 2) {
		cout << "\t----------" << date << ".mp4" << "----------" << endl;
		cout << "\t카테고리: ";
		cout << "동영상\t";
	}
	else {
		cout << "\t----------" <<date << ".mp3" << "----------" << endl;
		cout << "\t카테고리: ";
		cout << "음악\t";
	}
	cout << "\t생성 시간: " << date << "\t장소: " << place << endl;
	cout << "\t이벤트: " << event << "\t\t인물: " << characters << "\t\t조회 수: " << count << endl << endl;
}

void Contents::Setevent(string _event) {
	event = _event;
}

void Contents::Setplace(string _place) {
	_place = place;
}

void Contents::Setcharacters(string _characters) {
	characters = _characters;
}

void Contents::Setdate(int _date) {
	date = _date;
}
