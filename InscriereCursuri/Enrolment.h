#include"ControlBook.h"

class Enrolment
{
private:
	int studentId;
	int courseId;
	string created_at;

public:

	int get_studentId() { return studentId; }
	int get_courseId() { return courseId; }
	string get_created_at() { return created_at; }

	void set_studentId(int id) { studentId = id; }
	void set_courseId(int id) { courseId = id; }
	void set_created_at(string date) { created_at = date; }

	Enrolment(int sid, int cid, string date):studentId{sid}, courseId{cid}, created_at{date}{}

	Enrolment(string prp) {

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

		studentId = stoi(v[0]);
		courseId = stoi(v[1]);
		created_at = v[2];

	}

	string describe() {

		string text = "";
		text += "\nStudent ID : " + to_string(studentId);
		text += "\nCourse ID : " + to_string(courseId);
		text += "\nCreated at : " + created_at;
		text += "\n";

		return text;
	}

};

