#include"StudentIDCard.h"

class ControlStudentIDCard
{
private:
	list<StudentIDCard*>cards;

public:

	void add_card(StudentIDCard* c) { cards.push_back(c); }

	void traverse() {
		list<StudentIDCard*>::iterator itr;
		for (itr = cards.begin(); itr != cards.end(); ++itr) {
			
			cout << (*itr)->describe();
			cout << endl;
		}
	}

	void load() {

		ifstream f("cards.txt");

		while (!f.eof()) {

			string line;

			getline(f, line);

			cards.push_back(new StudentIDCard(line));
		}
	}

	ControlStudentIDCard() { load(); }

	int get_poz(int id) {

		int poz = -1;
		list<StudentIDCard*>::iterator itr;
		for (itr = cards.begin(); itr != cards.end(); ++itr) {
			poz++;
			if ((*itr)->get_id() == id) return poz;
		}

		return -1;
	}

	list<StudentIDCard*>::iterator get_itr_poz(int poz) {

		int p = -1;
		list<StudentIDCard*>::iterator itr;

		for (itr = cards.begin(); itr != cards.end(); ++itr) {

			p++;
			if (p == poz)
				return itr;
		}
	}

	void erase_card(int id) {

		int poz = get_poz(id);

		cout << poz << endl;
		list<StudentIDCard*>::iterator itr = get_itr_poz(poz);
		cards.erase(itr);
	}


	void modify_card(int id, string cs) {

		int poz = get_poz(id);
		list<StudentIDCard*>::iterator itr = get_itr_poz(poz);
		(*itr)->set_card_number(cs);
	}


	int GetCardIDbyStudentId(int sID) {

		list<StudentIDCard*>::iterator itr;

		for (itr = cards.begin(); itr != cards.end(); ++itr) {

			if ((*itr)->get_studentId() == sID)
				return (*itr)->get_id();
		}
	}

	StudentIDCard* GetStudentIDCardByStudentID(int id) {

		int IDCard = GetCardIDbyStudentId(id);

		list<StudentIDCard*>::iterator itr;
		for (itr = cards.begin(); itr != cards.end(); ++itr) {

			if ((*itr)->get_id() == IDCard)
				return *itr;
		}
	}
};

