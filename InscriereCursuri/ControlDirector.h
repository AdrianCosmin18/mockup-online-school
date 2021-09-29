#include"Admin.h"

class ControlDirector
{
private:
	list<Director*>directors;

public:

	void load() {

		ifstream f("directors.txt");

		while (!f.eof()) {

			string line;

			getline(f, line);

			if (line.find("admin") != string::npos)
				directors.push_back(new Admin(line));
			else
				directors.push_back(new Director(line));
		}
	}

	ControlDirector() { load(); IntializeInvestments(); }

	void traverse() {

		list<Director*>::iterator itr;

		for (itr = directors.begin(); itr != directors.end(); ++itr) {

			cout << (*itr)->describe();
			cout << endl;
		}
	}

	int get_poz(string name) {

		int poz = -1;
		list<Director*>::iterator itr;
		for (itr = directors.begin(); itr != directors.end(); ++itr) {
			poz++;
			if ((*itr)->get_name() == name) return poz;
		}

		return -1;
	}

	list<Director*>::iterator get_itr_poz(int poz) {

		int p = -1;
		list<Director*>::iterator itr;

		for (itr = directors.begin(); itr != directors.end(); ++itr) {

			p++;
			if (p == poz)
				return itr;
		}
	}

	void erase(string name) {

		int poz = get_poz(name);

		cout << poz << endl;
		list<Director*>::iterator itr = get_itr_poz(poz);
		directors.erase(itr);
	}

	void modify(string name, string username, string password) {

		int poz = get_poz(name);
		list<Director*>::iterator itr = get_itr_poz(poz);
		(*itr)->set_username(username);
		(*itr)->set_password(password);
	}

	Director* GetDirectorByName(string name) {

		list<Director*>::iterator itr;

		for (itr = directors.begin(); itr != directors.end(); ++itr) {

			if ((*itr)->get_name() == name)
				return *itr;
		}
	}

	void IntializeInvestments() {


		list<Director*>::iterator itr;
			

		itr = get_itr_poz(2);
		Director* d = *itr;
		Admin* a = dynamic_cast<Admin*>(d);
		a->add_invest(78.2);
		a->add_invest(90.5);



		itr = get_itr_poz(3);
		Director* di = *itr;
		Admin* ai = dynamic_cast<Admin*>(di);
		ai->add_invest(50.3);
		ai->add_invest(89.89);
		ai->add_invest(69.75);

	}
};

