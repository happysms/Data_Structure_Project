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
			cout << "잘못된 입력입니다..." << endl;
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
			cout << "잘못된 입력입니다..." << endl;
			break;
		}
	}
}

int Application::SearchGetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t-------------- Command --------------- " << endl;
	cout << "\t   1 : 이벤트 검색" << endl;
	cout << "\t   0 : 뒤로가기" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}


int Application::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t-------------- Command --------------- " << endl;
	cout << "\t   1 : 콘텐츠 정보를 입력 받아 리스트에 추가" << endl;
	cout << "\t   2 : 콘텐츠 정보를 입력 받아 리스트에서 삭제" << endl;
	cout << "\t   3 : 마스터 리스트의 내용을 모두 출력" << endl;
	cout << "\t   4 : 마스터 리스트에서 콘텐츠 찾기" << endl;
	cout << "\t   5 : 콘텐츠 정보 수정하기" << endl;
	cout << "\t   6 : 콘텐츠 검색" << endl;
	cout << "\t   7 : 폴더 생성" << endl;
	cout << "\t   8 : 전체 폴더 보기" << endl;
	cout << "\t   0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}

void Application::AddContents() {
	//------------------------InfoList Add-----------------
	//이벤트 리스트에 이벤트 추가 
	Contents temp;
	temp.SetRecordFromKB();
	InfoType event(temp.Getevent());
	int pri = temp.Getdate();

	if (EventList.Get(event) == 0) {
		EventList.Add(event);
	}

	//이벤트 타입 안에 있는 리스트에 추가한 콘텐츠의 primary키를 넣는다. 
	if (event.getListPtr()->Get(pri) == 0) {
		event.getListPtr()->Add(pri);
	}
	DoublyIterator<InfoType> iter(EventList);

	int n;	
	while (iter.NotNull()) {
		cout << "\t이벤트 명 : " << iter.GetCurrentNode().data.Getname() << endl;
		InfoType event = iter.GetCurrentNode().data;
		event.getListPtr()->ResetList();
		while (event.getListPtr()->GetNextItem(n) != -1) {
			cout << "\t" << n << endl;
		}
		cout << "\t----------------------------------------------" << endl;
		iter.Next();
	}

	//------------------BestList Add --------------------------
	// 베스트리스트에 Add하기 / 콘텐츠를 모두 검사해 그 중 가장 작은 조회수를 가져온다.
	// 리스트를 모두 검사하더라도 길이가 5로 제한되기 때문에 시간이 오래 걸리지 않는다.
	Contents best;
	DoublyIterator<Contents> Biter(BestList);
	int min = 10000; // 충분히 큰 숫자.
	while (Biter.NotNull()) {
		if (min < Biter.GetCurrentNode().data.Getcount()) {
			min = Biter.GetCurrentNode().data.Getcount();
			best = Biter.GetCurrentNode().data;
		}
		Biter.Next();
	}
	//입력받은 콘텐츠의 조회수가 min보다 클 경우 Best리스트에 포함시키고, min의 값을 가진 콘텐츠는 삭제한다. 
	if (temp.Getcount() >= min) {
		BestList.Add(temp);
	}
	//길이가 5를 넘으면 가장 작은 수를 뺀다.
	if (BestList.GetLength() > 5) {
		BestList.Delete(best);
	}
	
	MasterList.Add(temp);
	cout << "\t콘텐츠가 추가되었습니다." << endl;
}


void Application::DisplayAllContents() {
	MasterList.PrintTree(cout);
}


void Application::SearchFromMasterList() {
	Contents data;
	cout << "\t찾고자하는 콘텐츠의 이름을 입력하세요:  (돌아가기 : 0)";
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
	cout << "\t삭제할 콘텐츠의 이름을 입력하세요:  (돌아가기 : 0)";
	int primary;
	cin >> primary;
	cout << endl;
	if (primary == 0) {
		return;
	}
	temp.Setdate(primary);

	MasterList.DeleteItem(temp);
	cout << "삭제되었습니다. " << endl;
}

void Application::ReplaceContents() {
	Contents data;
	cout << "\t수정할 콘텐츠의 이름을 입력하세요:  (돌아가기 : 0)";
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
		cout << "\t이벤트 항목" << endl;
		DoublyIterator<InfoType> iter(EventList);
		SortedList<int>* list;
		int n;
		while (iter.NotNull()) {
			cout << "\t이벤트 명 : " << iter.GetCurrentNode().data.Getname() <<  endl;
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
		cout << "\t입력이 올바르지 않습니다. 다시 입력해주세요.\n" << endl;
	}
}

void Application::AddContentsToFolder(SortedList<Contents>& list) {
	while (1) {
		cout << "\t폴더에 넣을 콘텐츠 이름을 입력하세요(Quit : 0) : ";
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
	// 폴더리스트에 폴더를 추가한다.
	cout << "\t생성할 폴더명을 입력하세요(뒤로 가기 : 0) : ";
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
		cout << "\t폴더에 해당 콘텐츠가 이미 존재합니다. " << endl;
	}

	// 만들어진 폴더에 콘텐츠를 추가한다.
	int select = 0;
	cout << "\t콘텐츠를 추가하시겠습니까? (Yes: 1 No: 0)";
	cin >> select;
	if (select == 1) {
		SortedList<Contents>* list = temp.getListPtr();
		AddContentsToFolder(*list);
		/* @@@실험.
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
	cout << "\t----------전체 폴더----------" << endl;
	DoublyIterator<Folder> iter(FolderList);
	while (iter.NotNull()) {
		cout << "\t폴더 : " << iter.GetCurrentNode().data.Getname() << endl;
		iter.Next();
	}
	SearchFolder();
}

void Application::SearchFolder() {
	cout << "\t폴더를 검색하시겠습니까? (Yes : 1  No : 0)";
	int select = 0;
	cin >> select;
	if (select == 1) {
		cout << "\t폴더 명을 입력하세요(뒤로 가기 : 0) : ";
		string fname;
		cin >> fname;
		if (fname == "0") {
			return;
		}
		Folder temp(fname);
		if (FolderList.Get(temp) == 0) {
			cout << "\t해당 폴더가 리스트에 폴더리스트에 없습니다. " << endl;
		}
		else {
			cout << "\t----------폴더 : " << temp.Getname() << "----------";
			SortedList<Contents>* list = temp.getListPtr();
			Contents t;
			list->ResetList();
			while (list->GetNextItem(t) != -1) {
				t.DisplayRecordOnScreen();
			}
		}
	}
}