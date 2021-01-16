#include "Application.h"

void Application::Run() {
	int command;
	while (1) {
		command = GetCommand();
		switch (command) {
		case 1:
			AddContents(); break;
		case 2:
			DeleteContents(); break;
		case 3:
			DisplayAllContents(); break;
		case 4:
			SearchFromMasterList(); break;
		case 5:
			ReplaceContents(); break;
		case 6:
			SearchRun(); break;
		case 7:
			AddFolder(); break;
		case 8:
			DisplayFolder(); break;
		case 0:
			return;
		default:
			cout << "�߸��� �Է��Դϴ�..." << endl;
			break;
		}
	}
}

void Application::SearchRun() {
	int command;
	while (1) {
		command = SearchGetCommand();
		switch (command) {
		case 1:
			GetInfoList(command); break;
		case 0:
			return;
		default:
			cout << "�߸��� �Է��Դϴ�..." << endl;
			break;
		}
	}
}

int Application::SearchGetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t-------------- Command --------------- " << endl;
	cout << "\t   1 : �̺�Ʈ �˻�" << endl;
	cout << "\t   0 : �ڷΰ���" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}


int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t-------------- Command --------------- " << endl;
	cout << "\t   1 : ������ ������ �Է� �޾� ����Ʈ�� �߰�" << endl;
	cout << "\t   2 : ������ ������ �Է� �޾� ����Ʈ���� ����" << endl;
	cout << "\t   3 : ������ ����Ʈ�� ������ ��� ���" << endl;
	cout << "\t   4 : ������ ����Ʈ���� ������ ã��" << endl;
	cout << "\t   5 : ������ ���� �����ϱ�" << endl;
	cout << "\t   6 : ������ �˻�" << endl;
	cout << "\t   7 : ���� ����" << endl;
	cout << "\t   8 : ��ü ���� ����" << endl;
	cout << "\t   0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

void Application::AddContents() {
	//------------------------InfoList Add-----------------
	//�̺�Ʈ ����Ʈ�� �̺�Ʈ �߰� 
	Contents temp;
	temp.SetRecordFromKB();
	InfoType event(temp.Getevent());
	int pri = temp.Getdate();

	if (EventList.Get(event) == 0) {
		EventList.Add(event);
	}

	//�̺�Ʈ Ÿ�� �ȿ� �ִ� ����Ʈ�� �߰��� �������� primaryŰ�� �ִ´�. 
	if (event.getListPtr()->Get(pri) == 0) {
		event.getListPtr()->Add(pri);
	}
	DoublyIterator<InfoType> iter(EventList);

	int n;	
	while (iter.NotNull()) {
		cout << "\t�̺�Ʈ �� : " << iter.GetCurrentNode().data.Getname() << endl;
		InfoType event = iter.GetCurrentNode().data;
		event.getListPtr()->ResetList();
		while (event.getListPtr()->GetNextItem(n) != -1) {
			cout << "\t" << n << endl;
		}
		cout << "\t----------------------------------------------" << endl;
		iter.Next();
	}

	//------------------BestList Add --------------------------
	// ����Ʈ����Ʈ�� Add�ϱ� / �������� ��� �˻��� �� �� ���� ���� ��ȸ���� �����´�.
	// ����Ʈ�� ��� �˻��ϴ��� ���̰� 5�� ���ѵǱ� ������ �ð��� ���� �ɸ��� �ʴ´�.
	Contents best;
	DoublyIterator<Contents> Biter(BestList);
	int min = 10000; // ����� ū ����.
	while (Biter.NotNull()) {
		if (min < Biter.GetCurrentNode().data.Getcount()) {
			min = Biter.GetCurrentNode().data.Getcount();
			best = Biter.GetCurrentNode().data;
		}
		Biter.Next();
	}
	//�Է¹��� �������� ��ȸ���� min���� Ŭ ��� Best����Ʈ�� ���Խ�Ű��, min�� ���� ���� �������� �����Ѵ�. 
	if (temp.Getcount() >= min) {
		BestList.Add(temp);
	}
	//���̰� 5�� ������ ���� ���� ���� ����.
	if (BestList.GetLength() > 5) {
		BestList.Delete(best);
	}
	
	MasterList.Add(temp);
	cout << "\t�������� �߰��Ǿ����ϴ�." << endl;
}


void Application::DisplayAllContents() {
	MasterList.PrintTree(cout);
}


void Application::SearchFromMasterList() {
	Contents data;
	cout << "\tã�����ϴ� �������� �̸��� �Է��ϼ���:  (���ư��� : 0)";
	int primary;
	cin >> primary;
	cout << endl;
	if (primary == 0) {
		return;
	}
	data.Setdate(primary);
	bool found = false;
	Node<Contents>* temp = MasterList.RetrieveItem(data, found);
	temp->data.DisplayRecordOnScreen();
}

void Application::DeleteContents() {
	Contents temp;
	cout << "\t������ �������� �̸��� �Է��ϼ���:  (���ư��� : 0)";
	int primary;
	cin >> primary;
	cout << endl;
	if (primary == 0) {
		return;
	}
	temp.Setdate(primary);

	MasterList.DeleteItem(temp);
	cout << "�����Ǿ����ϴ�. " << endl;
}

void Application::ReplaceContents() {
	Contents data;
	cout << "\t������ �������� �̸��� �Է��ϼ���:  (���ư��� : 0)";
	int primary;
	cin >> primary;
	cout << endl;
	if (primary == 0) {
		return;
	}
	data.Setdate(primary);
	bool found = false;
	Node<Contents>* temp = MasterList.RetrieveItem(data, found);
	temp->data.SetRecordFromKB();
}

void Application::GetInfoList(int command) {
	if (command == 1) {
		cout << "\t�̺�Ʈ �׸�" << endl;
		DoublyIterator<InfoType> iter(EventList);
		SortedList<int>* list;
		int n;
		while (iter.NotNull()) {
			cout << "\t�̺�Ʈ �� : " << iter.GetCurrentNode().data.Getname() <<  endl;
			InfoType event = iter.GetCurrentNode().data;
			event.getListPtr()->ResetList();
			while (event.getListPtr()->GetNextItem(n) != -1) {
				cout << "\t" << n << endl;
			}
			cout << "\t----------------------------------------------"<<endl;
			iter.Next();
		}
		
	}
	else {
		cout << "\t�Է��� �ùٸ��� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n" << endl;
	}
}

void Application::AddContentsToFolder(SortedList<Contents>& list) {
	while (1) {
		cout << "\t������ ���� ������ �̸��� �Է��ϼ���(Quit : 0) : ";
		int pri;
		cin >> pri;
		if (pri == 0) {
			return;
		}
		Contents tempContents;
		tempContents.Setdate(pri);
		bool found = false;
		Node<Contents>* temp = MasterList.RetrieveItem(tempContents, found);
		temp->data.DisplayRecordOnScreen();
		list.Add(temp->data);
	}
}

void Application::AddFolder() {
	// ��������Ʈ�� ������ �߰��Ѵ�.
	cout << "\t������ �������� �Է��ϼ���(�ڷ� ���� : 0) : ";
	string fname;
	cin >> fname;
	if (fname == "0") {
		return;
	}
	Folder temp(fname);
	if (FolderList.Get(temp) == 0) {
		FolderList.Add(temp);
	}
	else {
		cout << "\t������ �ش� �������� �̹� �����մϴ�. " << endl;
	}

	// ������� ������ �������� �߰��Ѵ�.
	int select = 0;
	cout << "\t�������� �߰��Ͻðڽ��ϱ�? (Yes: 1 No: 0)";
	cin >> select;
	if (select == 1) {
		SortedList<Contents>* list = temp.getListPtr();
		AddContentsToFolder(*list);
		/* @@@����.
		Contents t;
		list->ResetList();
		while (list->GetNextItem(t) != -1) {
			t.DisplayRecordOnScreen();
		}
		*/
	}
	else if (select == 0) {
		return;
	}
}


void Application::DisplayFolder() {
	cout << "\t----------��ü ����----------" << endl;
	DoublyIterator<Folder> iter(FolderList);
	while (iter.NotNull()) {
		cout << "\t���� : " << iter.GetCurrentNode().data.Getname() << endl;
		iter.Next();
	}
	SearchFolder();
}

void Application::SearchFolder() {
	cout << "\t������ �˻��Ͻðڽ��ϱ�? (Yes : 1  No : 0)";
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "\t���� ���� �Է��ϼ���(�ڷ� ���� : 0) : ";
		string fname;
		cin >> fname;
		if (fname == "0") {
			return;
		}
		Folder temp(fname);
		if (FolderList.Get(temp) == 0) {
			cout << "\t�ش� ������ ����Ʈ�� ��������Ʈ�� �����ϴ�. " << endl;
		}
		else {
			cout << "\t----------���� : " << temp.Getname() << "----------";
			SortedList<Contents>* list = temp.getListPtr();
			Contents t;
			list->ResetList();
			while (list->GetNextItem(t) != -1) {
				t.DisplayRecordOnScreen();
			}
		}
	}
}