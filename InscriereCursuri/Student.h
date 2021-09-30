#include"Course.h"
#include<list>

class Student:public Person
{
private:
	list<Course*>courses;

public:

	Student(){}

	Student(int id, string n, string un, string t, string m, int a) :Person(id, n, un, "Student", m, a){
	

		add_course(new Course(1, "Analyze 1", "Math"));
		add_course(new Course(2, "Calculations 1", "Math"));
		add_course(new Course(3, "Data Structures", "Informatics"));
		add_course(new Course(4, "Web Techniques", "Informatics"));

	};


	Student(string prp) :Person(prp){}


	string describe() override {

		string text = "";

		text += "\nID Person : " + to_string(get_personID());
		text += "\nName : " + get_name();
		text += "\nUsername : " + get_username();
		text += "\nType : " + get_type();
		text += "\nMail : " + get_mail();
		text += "\nAge : " + to_string(get_age());
		text += "\n";

		return text;
	}

	void traverse() {

		list<Course*>::iterator itr;
		for (itr = courses.begin(); itr != courses.end(); ++itr) {

			cout << (*itr)->describe();
			cout << endl;
		}

	}

	void add_course(Course* c) { courses.push_back(c); }

	int poz_course(int id) {

		list<Course*>::iterator itr;
		int p = -1;

		for (itr = courses.begin(); itr != courses.end(); ++itr) {

			p++;

			if ((*itr)->get_courseID() == id)
				return p;

		}

		return -1;

	}

	list<Course*>::iterator poz_itr_course(int poz) {

		int p = -1;

		list<Course*>::iterator itr;

		for (itr = courses.begin(); itr != courses.end(); ++itr) {

			p++;

			if (p == poz)
				return itr;
		}

	}

	void erase_course(int id) {

		int poz = poz_course(id);

		list<Course*>::iterator itr = poz_itr_course(poz);

		courses.erase(itr);

	}
	
};

