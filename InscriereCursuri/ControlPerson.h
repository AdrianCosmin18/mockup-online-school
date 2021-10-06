#include"Teacher.h"

class ControlPerson
{
private:
	list<Person*>persons;

public:

	ControlPerson() {

		load();
	}

	list<Person*> get_persons() { return persons; }


	void load() {

		ifstream f("persons.txt");
		
		while (!f.eof()) {

			string line;

			getline(f, line);


			int poz = line.find("teacher");

			if (poz != string::npos) {

				persons.push_back(new Teacher(line));
			}
			else {

				persons.push_back(new Student(line));
			}
		}
	}

	void add_person(Person* p) { persons.push_back(p); }
	void traverse() {

		list<Person*>::iterator itr;
		for (itr = persons.begin(); itr != persons.end(); ++itr) {
			cout << (*itr)->describe() << endl;
			cout << endl;
		}
	}

	int poz_person(int id) {

		int i = -1;
		list<Person*>::iterator itr;

		for (itr = persons.begin(); itr != persons.end(); ++itr) {

			i++;
			if ((*itr)->get_personID() == id) { return i; }

		}
		return -1;
	}

	list<Person*>::iterator poz_itr_person(int poz) {

		list<Person*>::iterator itr;
		int p = -1;

		for (itr = persons.begin(); itr != persons.end(); ++itr) {

			p++;
			if (p == poz) { return itr; }
		}
	}

	void erase(int id) {

		int poz = poz_person(id);


		list<Person*>::iterator itr = poz_itr_person(poz);
		persons.erase(itr);
	}


	void modify_person(int id, string un, string m, int ag) {

		int poz = poz_person(id);
		list<Person*>::iterator itr = poz_itr_person(poz);

		(*itr)->set_username(un);
		(*itr)->set_mail(m);
		(*itr)->set_age(ag);
	}



	int GetIDbyName(string name) {

		list<Person*>::iterator itr;
		for (itr = persons.begin(); itr != persons.end(); ++itr) {

			if ((*itr)->get_name() == name)
				return (*itr)->get_personID();
		}
		return -1;
	}



	Person* GetPersonbyName(string name){
	
		int id = GetIDbyName(name);

		if (id != -1) {

			int poz = poz_person(id);
			list<Person*>::iterator itr = poz_itr_person(poz);

			return *itr;

		}
	}

	Person* GetPersonByID(int id) {


		int poz = poz_person(id);
		list<Person*>::iterator itr = poz_itr_person(poz);
		return *itr;

	}





	void AddCourseToStudent(string name, Course* c) {

		Person* p = GetPersonbyName(name);

		try {
			Student* s = (Student*)p;

			s->add_course(c);
		}
		catch (int n) {

			cout << "\nDoes not exists this person or person's name is incorect !!! ";
		}
	}


	void CountTeacherAndStudents() {

		int countt, counts;
		countt = counts = 0;
		list<Person*>::iterator itr;


		for (itr = persons.begin(); itr != persons.end(); ++itr) {

			if ((*itr)->get_type() == "teacher")
				countt++;

			if ((*itr)->get_type() == "student")
				counts++;
		}



		cout << "\nNr de profi este de : " << countt;
		cout << "\nNr de studenti este de : " << counts;
	}
};

