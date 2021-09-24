#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person
{
private:
	int personID;
	string name;
	string username;
	string type;
	string mail;
	int age;

public:



	int get_personID() { return personID; }
	string get_name() { return name; }
	string get_mail() { return mail; }
	string get_username() { return username; }
	string get_type() { return type; }
	int get_age() { return age; }

	void set_personID(int id) { personID = id; }
	void set_name(string n) { name = n; }
	void set_mail(string m) { mail = m; }
	void set_username(string un) { username = un; }
	void set_type(string t) { type = t; }
	void set_age(int a) { age = a; }

	Person() : personID{ 0000 }, name{ "Nobody" }, username{ "Nobody" }, type{ "Student" }, mail{ "anonimus" }, age{ 0 }{}

	Person(int id, string n, string un, string t, string m, int a) :personID{ id }, name{ n }, username{ un }, type{ t }, mail{ m }, age{ a }{}

	Person(const Person& p) : personID{ p.personID }, name{ p.name }, username{ p.username }, type{ p.type }, mail{ p.mail }, age{ p.age }{}

	virtual string describe() {

		string text = "";

		text += "\nID Person : " + to_string(personID);
		text += "\nName : " + name;
		text += "\nUsername : " + username;
		text += "\nType : " + type;
		text += "\nMail : " + mail;
		text += "\nAge : " + to_string(age);
		text += "\n";

		return text;

	}

	bool operator==(const Person &p) {

		return this->personID == p.personID;
	}

	Person(string prp) {

		string v[6];

		int poz = prp.find(',');
		int i = -1;

		while (poz != string::npos) {

			i++;
			v[i] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');

		}

		v[5] = prp;

		personID = stoi(v[0]);
		name = v[1];
		username = v[2];
		type = v[3];
		mail = v[4];
		age = stoi(v[5]);
	}


};
;