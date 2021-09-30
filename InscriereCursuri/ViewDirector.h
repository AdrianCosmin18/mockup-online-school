#include"ControlDirector.h"

class ViewDirector
{
private:
	ControlPerson* cp = NULL;
	ControlBook* cb = NULL;
	ControlCourse* cc = NULL;
	ControlEnrolment* ce = NULL;
	ControlStudentIDCard* cs = NULL;
	ControlDirector* cd = NULL;


public:


	ViewDirector() {

		cp = new ControlPerson;
		cb = new ControlBook;
		cc = new ControlCourse;
		ce = new ControlEnrolment;
		cs = new ControlStudentIDCard;
		cd = new ControlDirector;
	}



	void menu() {

		cout << endl;
		cout << endl;
		cout << "Pentru a afisa toti studentii apasati 11\n";
		cout << "Pentru a verifica existenta unui student apasati 12\n";
		cout << "Pentru a afla detalii despre un student apasati 13\n";
		cout << "Pentru a obtine ID-ul unui student apasati 14\n";
		cout << "Pentru a afisa cursurile unui student apasati 15\n";
		cout << endl;

		cout << "Pentru a afisa lista de carti inchiriata de studenti 21\n";
		cout << "Pentru a verifica existenta unei carti apasati 22\n";
		cout << "Pentru a afla detalii despre o carte inchiriata apasati 23\n";
		cout << "Pentru a obtine ID-ul unui student care a inchiriat o anumita carte apasati 24\n";
		cout << endl;

		cout << "Pentru a afisa cursurile disponibile apasati \n";
		cout << "Pentru a verifica existenta unui curs apasati tasta 2 \n";
		cout << "Pentru a afisa ID-ul unui curs  apasati\n";
		cout << "Pentru a afla detalii despre un curs apasati tasta 3\n";
		cout << endl;

		cout << "Pentru a afisa lista de legitimatii inchiriata de studenti 4\n";
		cout << "Pentru a verifica existenta unei legitimatii apasati tasta 2 \n";
		cout << "Pentru a afla detalii despre o legitimatie apasati tasta 6\n";
		cout << "Pentru a obtine ID-ul unui student pe baza ID-ului legitimatiei apasati tasta 7\n";
		cout << endl;

		cout << "Pentru a afisa toate inregistrarile studentiilor la un anumit curs apasati\n";
		cout << "Pentru a afisa existenta unei inregistrari ale unui student la un anumit curs apasati\n";
		cout << "Pentru a afisa detalii despre o inregistrare apasati\n";
		cout << endl;

		cout << "Pentru a iesi apasati \n";
	}

	void exist_student() {

		string name;
		cout << "Introduceti numele studentului : ";
		getline(cin, name);

		if (cp->GetIDbyName(name) != -1) {

			Person* p = cp->GetPersonbyName(name);


			if (p->get_type() == "teacher")
				cout << "Nu exista acest student\n";

			else {

				Student* s = dynamic_cast<Student*>(p);
				cout << s->describe();
			}

		}

		else {
			cout << "Nu exista acest student\n\n";
		}
	}

	//ce fac daca nu exista acest student
	void get_details_student() {

		string name;
		cout << "Introduceti numele studentului : ";
		getline(cin, name);

		Person* p = cp->GetPersonbyName(name);
		Student* s = dynamic_cast<Student*>(p);
		cout << s->describe();

	}

	void get_ID_student() {

		string name;
		cout << "Introduceti numele studentului : ";
		getline(cin, name);

		Person* p = cp->GetPersonbyName(name);
		Student* s = dynamic_cast<Student*>(p);
		cout << "\nId-ul studentului " << name << " este : " << s->get_personID();
	}

	void get_courses_from_student() {

		string name;
		cout << "Introduceti numele studentului ale caror cursuri vrei sa le vezi : ";
		getline(cin, name);

		Person* p = cp->GetPersonbyName(name);
		Student* s = dynamic_cast<Student*>(p);

		s->traverse();
	}



	void play() {

		bool oprire;
		oprire = false;

		while (oprire == false) {

			menu();

			int alegere;
			string a;
			cout << "\nAlgere : "; getline(cin, a);
			alegere = stoi(a);

			switch (alegere) {

			case 11:cp->traverse();
				break;

			case 12: exist_student();
				break;

			case 13: get_details_student();
				break;

			case 14: get_ID_student();
				break;

			case 15: get_courses_from_student();
				break;



			}

		}
	}
};

