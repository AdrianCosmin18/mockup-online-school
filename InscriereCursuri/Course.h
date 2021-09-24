#include"Person.h"

class Course
{
private:
	int courseID;
	string name;
	string department;

public:

	int get_courseID() { return courseID; }
	string get_name() { return name; }
	string get_department() { return department; }

	void set_courseID(int id) { courseID = id; }
	void set_name(string n) { name = n; }
	void set_department(string d) { department = d; }

	Course() :courseID{ 0 }, name{ "nameless" }, department{ "empty" }{};

	Course(int id, string n, string d) : courseID{ id }, name{ n }, department{ d }{};

	Course(const Course& c) :courseID{ c.courseID }, name{ c.name }, department{ c.department }{};

	Course(string prp) {

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

		courseID = stoi(v[0]);
		name = v[1];
		department = v[2];
	}

	string describe() {
		
		string text = "";

		text += "\nID Course : " + to_string(courseID);
		text += "\nName : " + name;
		text += "\nDepartment : " + department;
		text += "\n";

		return text;

	}


};