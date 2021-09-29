#include"Director.h"

class Admin:public Director
{
private:
	list<double>investments;

public:

	Admin():Director(){}

	Admin(string n, string un, string p, string r):Director(n,un,p,"admin") {}

	/*Admin(const Admin& a):*/

	Admin(string prp) {

		string v[4];

		int poz = prp.find(',');
		int i = -1;

		while (poz != string::npos) {

			i++;
			v[i] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');

		}

		v[3] = prp;

		set_name(v[0]);
		set_username(v[1]);
		set_password(v[2]);
		set_role("admin");
	}

	string describe() override {

		string text = "";

		text += "\nName : " + get_name();
		text += "\nUsername : " + get_username();
		text += "\nPassword : " + get_password();
		text += "\nRole : " + get_role();
		if (investments.size() != 0)
			text += "\nActive Investments";
		else
			text += "\nInactive Investments";
		text += "\n";

		return text;

	}

	void add_invest(double i) { investments.push_back(i); }

	void traverse() {

		list<double>::iterator itr;
		for (itr = investments.begin(); itr != investments.end(); ++itr) {

			cout << *itr << ", ";
		}
		cout << endl;
	}

	int get_poz(double nr) {

		int poz = -1;
		list<double>::iterator itr;
		for (itr = investments.begin(); itr != investments.end(); ++itr) {

			poz++;
			if (nr == (*itr))
				return poz;
		}
	}

	list<double>::iterator get_itr_poz(int poz) {

		int p = -1;
		list<double>::iterator itr;
		for (itr = investments.begin(); itr != investments.end(); ++itr) {

			p++;
			if (p == poz)
				return itr;
		}

	}

	void erase_invest(double nr) {

		int poz = get_poz(nr);
		list<double>::iterator itr = get_itr_poz(poz);
		investments.erase(itr);
	}

};

