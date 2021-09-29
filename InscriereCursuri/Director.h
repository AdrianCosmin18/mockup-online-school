#include"ControlEnrolment.h"

class Director
{
private:
	string name;
	string username;
	string password;
	string role;

public:

	string get_name() { return name; }
	string get_username() { return username; }
	string get_password() { return password; }
	string get_role() { return role; }

	void set_name(string n) { name = n; }
	void set_username(string un) { username = un; }
	void set_password(string p) { password = p; }
	void set_role(string r) { role = r; }

	Director():name{"anonim"}, username{"anonim"},password{"password"},role{"director"}{}

	Director(string n, string un, string p, string r):name{n}, username{un}, password{p}, role{"director"}{}

	Director(string prp) {

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

		name = v[0];
		username = v[1];
		password = v[2];
		role = v[3];
	}

	virtual string describe() {

		string text = "";

		text += "\nName : " + name;
		text += "\nUsername : " + username;
		text += "\nPassword : " + password;
		text += "\nRole : " + role;
		text += "\n";

		return text;
	}


};

