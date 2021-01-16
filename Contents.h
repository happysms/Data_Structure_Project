#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <ctime>

using namespace std;

class Contents {
protected:
	//--------���� �Է��ؾ��ϴ� ����-----------
	string characters; //���� �ι�
	string place; //���
	string event; //�̺�Ʈ

	//----------�ڵ���������-----------
	string id; //�ð�.jpg or �ð�.mp4 ���·� �����. ���ð��븦 �����ϱ� ���� ���� ���� �����Ѵٸ� �ڿ� ���ڸ� ��������.    
	int year; //���� ����
	int date; //���� ��¥ !!!primary key!!!
	string keywords; // Ű����(���� �ι�, �繰, ���, �̺�Ʈ�� ������)
	int count; // �˻� Ƚ��
	int category; //�з�

public:
	Contents();

	~Contents();

	/*
	* brief: �÷��� �����Լ�
	* post: �������� �ҷ��´�.
	*/
	//virtual void play() = 0;

	/*
	* brief: ��� ������ getter
	* post: �������� ������ ��ȯ�Ѵ�.
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
	* brief: Ű����κ��� ������ ������ �Է¹޾� set�Ѵ�.
	* post: �������� ������ �����Ѵ�.
	*/
	void SetcharactersFromKB();

	void SetplaceFromKB();

	void SeteventFromKB();

	void SetRecordFromKB();
	/*
	* brief: ��� ������ ������ set.
	* post: �������� ������ �����Ѵ�.
	*/
	void Setevent(string _event);

	void Setplace(string _place);

	void Setcharacters(string _characters);

	void Setdate(int _date);

	/*
	* brief: ��� ������ ������ set.
	* pre: ���, �̺�Ʈ, �ι��� ������ set�Ǿ���Ѵ�.
	* post: ��� ������ " "�� ������ ���ڿ��� keywords�迭�� �Ҵ��Ѵ�.
	*/
	void Setkeywords(string _characters, string _event, string _place);

	/*
	* brief : ��� �������� ������ ������
	*/
	void DisplayRecordOnScreen();

	/*
	* brief : �������� ������ ȭ�鿡 ������ִ� << ������ ���۷������̴�.
	*/
	friend ostream& operator<<(ostream& cout, const Contents& data) {
		if (data.category == 1)
		{
			cout << "\t----------" << data.date << ".jpg" << "----------" << endl;
			cout << "\tī�װ�: ";
			cout << "����\t";
		}
		else if (data.category == 2) {
			cout << "\t----------" << data.date << ".mp4" << "----------" << endl;
			cout << "\tī�װ�: ";
			cout << "������\t";
		}
		else {
			cout << "\t----------" << data.date << ".mp3" << "----------" << endl;
			cout << "\tī�װ�: ";
			cout << "����\t";
		}
		cout << "\t���� �ð�: " << data.date << "\t���: " << data.place << endl;
		cout << "\t�̺�Ʈ: " << data.event << "\t\t�ι�: " << data.characters << "\t\t��ȸ ��: " << data.count << endl << endl;
		return cout;
	}

	/*
	* brief : primary key�� �������� �������� ���� ���θ� Ȯ���ϴ� ������ �����ε�
	* post : �Ķ���ͷ� ���� date�� ��ġ�ϸ� true�� �׷��� ������ false�� �����Ѵ�.
	*/
	bool operator==(const Contents& data);

	/*
	* pre: �Ķ���ͷ� ���� �������� ��� ��� ������ ���� �ʱ�ȭ�Ǿ� �־���Ѵ�.
	* post: �Ķ���ͷ� ���� �������� ��� ��������� ���� �ش� ��ü�� �Ҵ��Ѵ�.
	*/
	void operator=(const Contents& data);

	/*
	* post : �Ķ���ͷ� ���� �������� ������¥�� �ش簴ü�� �������� ������¥���� Ŭ �ÿ� true�� �׷��� ������ false�� �Ҵ���.
	*/
	bool operator<(const Contents& data);

	/*
	* post : �Ķ���ͷ� ���� �������� ������¥�� �ش簴ü�� �������� ������¥���� ���� �ÿ� true�� �׷��� ������ false�� �Ҵ���.
	*/
	bool operator>(const Contents& data);

	/*
	* pre: ������ open�Ǿ� �־���Ѵ�.
	* post: ���Ͽ� �ִ� ������ ������ �о�´�.
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
	   //cout << "���� Display" << endl;
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
   //	cout << "������ ���" << endl;
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
	//	cout << "���� ���" << endl;
	//	count++;
	//}
};


