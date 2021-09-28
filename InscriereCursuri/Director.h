#include"ControlEnrolment.h"

class Director
{
private:
	string name;
	string username;
	string password;

public:

	string get_name() { return name; }
	string get_username() { return username; }
	string get_password() { return password; }

	void set_name(string n) { name = n; }
	void set_username(string un) { username = un; }
	void set_password(string p) { password = p; }

	Director():name{"anonim"}, username{"anonim"},password{"password"}{}

	Director(string n, string un, string p):name{n}, username{un}, password{p}{}

	Director(string prp) {

		string v[3];

		int poz = prp.find(',');
		int i = -1;

		while (poz != string::npos) {

			i++;
			v[i] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');

		}

		v[2] = prp;

		name = v[0];
		username = v[1];
		password = v[2];
	}

	string describe() {

		string text = "";

		text += "\nName : " + name;
		text += "\nUsername : " + username;
		text += "\nPassword : " + password;
		text += "\n";

		return text;
	}
};

