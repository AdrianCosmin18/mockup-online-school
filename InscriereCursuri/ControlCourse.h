#include"ControlPerson.h"

class ControlCourse
{
private:
	list<Course*>courses;

public:

	void load() {

		ifstream f("courses.txt");

		while (!f.eof()) {

			string line;

			getline(f, line);

			courses.push_back(new Course(line));
		}
	}

	ControlCourse() { load(); }

	void add_course(Course *c) { courses.push_back(c); }

	void traverse() {

		list<Course*>::iterator itr;

		for (itr = courses.begin(); itr != courses.end(); ++itr) {

			cout << (*itr)->describe();
			cout << endl;

		}
	}

	int poz_course(int id) {

		int poz = -1;

		list<Course*>::iterator itr;

		for (itr = courses.begin(); itr != courses.end(); ++itr) {
			
			poz++;
			if ((*itr)->get_courseID() == id) return poz;
		}

		return -1;
	}

	list<Course*>::iterator poz_itr_course(int p) {

		int poz = -1;
		list<Course*>::iterator itr;

		for (itr = courses.begin(); itr != courses.end(); ++itr) {

			poz++;
			if (poz == p)return itr;
		}
	}

	void erase_course(int id) {

		int poz = poz_course(id);
		list<Course*>::iterator itr = poz_itr_course(poz);
		courses.erase(itr);
	}

	void update_course(int id, string n, string dept) {

		int poz = poz_course(id);
		list<Course*>::iterator itr = poz_itr_course(poz);

		(*itr)->set_department(dept);
		(*itr)->set_name(n);
	}

	int GetIdByName(string n) {

		list<Course*>::iterator itr;

		for (itr = courses.begin(); itr != courses.end(); ++itr) {

			if ((*itr)->get_name() == n) {
				return (*itr)->get_courseID();
			}
		}
		return -1;
	}


	Course* GetCourseByName(string n) {

		list<Course*>::iterator itr;

		for (itr = courses.begin(); itr != courses.end(); ++itr){
		
			if ((*itr)->get_name() == n) {return *itr;}
		}
	}

};

