#include"ControlStudentIDCard.h"

class Book
{
private:
	int id;
	int studentId;
	string name;
	string created_at;

public:

	int get_id() { return id; }
	int get_studentId() { return studentId; }
	string get_created_at() { return created_at; }
	string get_name() { return name; }

	void set_id(int i) { id = i; }
	void set_studentId(int id) { studentId = id; }
	void set_created_at(string date) { created_at = date; }
	void set_name(string n) { name = n; }

	Book(int ID, int SID, string n, string date):id{ID}, studentId{SID}, name{n}, created_at{date}{}

	Book(string prp) {

		string v[4];
		int i = -1;

		int poz = prp.find(',');

		while (poz != string::npos) {

			i++;
			v[i] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');

		}

		v[3] = prp;

		id = stoi(v[0]);
		studentId = stoi(v[1]);
		name = v[2];
		created_at = v[3];

	}

	string describe() {

		string text = "";

		text += "\nID Card : " + to_string(id);
		text += "\nID Student : " + to_string(studentId);
		text += "\nBook's Name : " + name;
		text += "\nCreated at : " + created_at;
		text += "\n";

		return text;
	}


};

