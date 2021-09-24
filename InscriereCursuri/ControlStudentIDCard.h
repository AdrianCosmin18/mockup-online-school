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

	list<StudentIDCard*>::iterator get_itr_poz(int id) {

		int poz = get_poz(id);
		int p = -1;
		list<StudentIDCard*>::iterator itr;

		for (itr = cards.begin(); itr != cards.end(); ++itr) {

			p++;
			if (p == poz)
				return itr;
		}
	}

	void erase_card(int id) {

		int poz = get_poz(id)+1;

		cout << poz << endl;
		list<StudentIDCard*>::iterator itr = get_itr_poz(poz);
		cards.erase(itr);
	}
};

