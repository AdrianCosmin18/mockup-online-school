#include"ControlCourse.h"

class StudentIDCard
{
private:
	int id;
	int studentId;
	string card_series;

public:

	int get_id() { return id; }
	int get_studentId() { return studentId; }
	string get_card_number() { return card_series; }

	void set_id(int i) { id = i; }
	void set_studentId(int id) { studentId = id; }
	void set_card_number(string card) { card_series = card; }

	StudentIDCard(int i, int id, string card):id{i}, studentId{id}, card_series{card}{}

	StudentIDCard(string prp) {

		string v[3];
		int i = -1;

		int poz = prp.find(',');

		while (poz != string::npos) {

			i++;
			v[i] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');

		}

		v[2] = prp;
		
		id = stoi(v[0]);
		studentId = stoi(v[1]);
		card_series = v[2];

	}

	string describe() {

		string text = "";

		text += "\nID Card : " + to_string(id);
		text += "\nID Student : " + to_string(studentId);
		text += "\nCard Serie : " + card_series;
		text += "\n";

		return text;
	}

};

