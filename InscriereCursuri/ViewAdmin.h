#include"ViewDirector.h"

class ViewAdmin
{
private:

	ControlPerson* cp = NULL;
	ControlBook* cb = NULL;
	ControlCourse* cc = NULL;
	ControlEnrolment* ce = NULL;
	ControlStudentIDCard* cs = NULL;
	//Admin* adm = NULL;

public:

	ViewAdmin(/*Admin* adm*/) {

		cp = new ControlPerson;
		cb = new ControlBook;
		cc = new ControlCourse;
		ce = new ControlEnrolment;
		cs = new ControlStudentIDCard;

		SaveAllCoursesToStudents();
	}


	void menu() {

		cout << endl;
		cout << endl;
		cout << endl;

		cout << "Pentru a iesi apasati 0\n";
		cout << endl;
		cout << "Pentru a afisa toti studentii apasati 11\n";
		cout << "Pentru a verifica existenta unui student apasati 12\n";
		cout << "Pentru a afla detalii despre un student apasati 13\n";
		cout << "Pentru a obtine ID-ul unui student apasati 14\n";
		cout << "Pentru a afisa cursurile unui student apasati 15\n";
		cout << "Pentru a afisa toate cursurile fiecarui student in parte apasati 16\n";

		cout << "Pentru a adauga un student apasati 17\n";
		cout << "Pentru a adauga un curs unui student apasati 18\n";
		cout << "Pentru a sterge un curs al unui student apasati 19\n";
		cout << endl;







		cout << "Pentru a afisa toate cartile inchiriate de catre un student apasati 21\n";
		cout << "Pentru a verifica existenta unei carti apasati 22\n";
		cout << "Pentru a afla detalii despre o carte inchiriata apasati 23\n";
		cout << "Pentru a obtine ID-ul unui student care a inchiriat o anumita carte apasati 24\n";

		cout << "Pentru a adauga o carte apasati 25\n";
		cout << "Pentru a modifica detaliile unei carti apasati 26\n";
		cout << "Pentru a sterge o carte apasati 27\n";
		cout << endl;






		cout << "Pentru a afisa cursurile disponibile apasati 31\n";
		cout << "Pentru a verifica existenta unui curs apasati tasta 32\n";
		cout << "Pentru a afisa ID-ul unui curs apasati 33\n";
		cout << "Pentru a afla detalii despre un curs apasati tasta 34\n";

		cout << "Pentru adauga un curs apasati 35\n";
		cout << "Pentru a sterge un curs apasati 36\n";
		cout << "Pentru a modifica un curs apasati 37\n";
		cout << endl;







		cout << "Pentru a afisa lista de legitimatii 41\n";
		cout << "Pentru a verifica existenta unei legitimatii apasati tasta 42\n";
		cout << "Pentru a obtine ID-ul unui student pe baza ID-ului legitimatie  apasati tasta 43\n";

		cout << "Pentru a adauga o noua legitimatie trebuie adaugat un nou student 44\n";
		cout << "Pentru a sterge o legitimatie apasati 45\n";
		cout << "Pentru a modifica o legitimatie apasati 46\n";
		cout << endl;




		cout << "Pentru a afisa toate inregistrarile studentiilor la cursuri apasati 51\n";
		cout << "Pentru a afisa existenta unei inregistrari ale unui student la un anumit curs apasati 52\n";

		cout << "Pentru a adauga o noua inregistrare al unui student la un curs apasati 53\n";
		cout << "Pentru a sterge o inregistrare a unui student la un curs apasati 54\n";
		cout << "Pentru a modifica o inregistrare apasati 55\n";


	}


	void SaveAllCoursesToStudents() {

		int student_id;
		list<Person*>persons = cp->get_persons();
		list<Person*>::iterator itr;

		for (itr = persons.begin(); itr != persons.end(); ++itr) {

			if ((*itr)->describe().find("student") != string::npos) {

				student_id = (*itr)->get_personID();
				SaveCourseToStudent(student_id);
			}
		}
	}

	void SaveCourseToStudent(int student_id) {

		Person* p = cp->GetPersonByID(student_id);


		Student* s = dynamic_cast<Student*>(p);
		list<Course*>cs;


		list<Enrolment*> en = ce->Get_Enrolments_List_By_Student_id(student_id);



		list<Enrolment*>::iterator itr;

		for (itr = en.begin(); itr != en.end(); ++itr) {

			Course* c = cc->GetCourseByID((*itr)->get_courseId());

			s->add_course(c);
		}

	}

	void GetAllStudentsCourses() {

		list<Person*>persons = cp->get_persons();
		list<Person*>::iterator itr;

		for (itr = persons.begin(); itr != persons.end(); ++itr) {

			if ((*itr)->describe().find("student") != string::npos) {

				Student* s = dynamic_cast<Student*>(*itr);

				cout << "Studentul " << s->get_name() << " participa la cursurile : ";
				s->traverse();

			}
		}
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

	void get_details_student() {

		string name;
		cout << "Introduceti numele studentului : ";
		getline(cin, name);
		int poz = cp->GetIDbyName(name);

		if (poz != -1) {

			Person* p = cp->GetPersonbyName(name);
			Student* s = dynamic_cast<Student*>(p);
			cout << s->describe();
		}
		else
			cout << "\nNu exista acest student";
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

		int student_id = cp->GetIDbyName(name);
		Person* p = cp->GetPersonByID(student_id);


		Student* s = dynamic_cast<Student*>(p);

		SaveCourseToStudent(student_id);

		s->traverse();

	}

	void add_student() {

		cout << "\nAdaugati un student :";
		cout << "\Nume : ";
		string nume;
		getline(cin, nume);

		cout << "\nAlegeti un ID pentru student(combinatie de cifre), lista de ID-uri ocupate : ";
		cp->CoutListOfIDs();
		cout << "\nID : ";
		string i;
		getline(cin, i);
		int id = stoi(i);

		cout << "\nAdaugati un username: ";
		string username;
		getline(cin, username);

		cout << "\nAdaugati un mail: ";
		string mail;
		getline(cin, mail);

		string type = "Student";

		cout << "\nAdaugati varsta : ";
		string v;
		getline(cin, v);
		int varsta = stoi(v);

		Student* s = new Student(id, nume, username, type, mail, varsta);


		cp->add_person(s);
	}





	void GetStudentBooks() {

		string name;
		cout << "Introduceti numele studentului ale caror carti inchiriate vrei sa le vezi : ";
		getline(cin, name);

		int student_id = cp->GetIDbyName(name);

		list<Book*> books = cb->GetBookListForStudentByStudentID(student_id);

		list<Book*>::iterator itr;
		cout << "Cartile studentului " << name << " sunt : " << endl;

		for (itr = books.begin(); itr != books.end(); ++itr) {

			cout << (*itr)->get_name();
			cout << endl;
		}
	}

	void exist_book() {

		string name;
		cout << "Introduceti numele cartii : ";
		getline(cin, name);

		if (cb->GetIDbyName(name) != -1) {

			Book* b = cb->GetBookByName(name);
			cout << b->describe();
		}
		else { cout << "Cartea cu acest nume nu exista"; }

	}

	void get_details_book() {

		string name;
		cout << "Introduceti numele cartii : ";
		getline(cin, name);

		if (cb->GetIDbyName(name) != -1) {

			Book* b = cb->GetBookByName(name);
			cout << b->describe();
		}
		else { cout << "Cartea cu acest nume nu exista"; }
	}

	void GetStudentIdByBookName() {

		string name;
		cout << "Introduceti numele cartii : ";
		getline(cin, name);

		if (cb->GetIDbyName(name) != -1) {

			Book* b = cb->GetBookByName(name);
			cout << "ID-ul studentului care a inchiriat aceasta carte este : " << b->get_studentId();
			cout << endl;
		}
		else { cout << "Cartea cu acest nume nu exista"; }
	}




	void exist_course() {

		string name;
		cout << "\nIntroduceti numele cursului : ";
		getline(cin, name);

		int id = cc->GetIdByName(name);
		if (id != -1)
			cout << cc->GetCourseByID(id)->describe();
		else
			cout << "\nNu exista un curs cu acest nume";

	}

	void get_ID_Course() {

		string name;
		cout << "\nIntroduceti numele cursului : ";
		getline(cin, name);

		int id = cc->GetIdByName(name);

		if (id != -1)
			cout << "\nID-ul cursului este : " << id;
		else
			cout << "\nNumele cursului introdus nu exista";
	}

	void get_details_course() {

		string name;
		cout << "\nIntroduceti numele cursului despre care doriti sa aflati detalii : ";
		getline(cin, name);

		if (cc->GetIdByName(name) != -1) {
			Course* c = cc->GetCourseByName(name);
			cout << c->describe();
		}
		else
		{
			cout << "\nNu exista acest curs";
		}
	}



	void exist_card() {

		string name;
		cout << "\nIntroduceti numele studentului a carui legitimatie o doriti : ";
		getline(cin, name);

		Person* p = cp->GetPersonbyName(name);


		if (p->describe().find("student") != string::npos) {

			Student* s = dynamic_cast<Student*>(p);

			int student_id = cp->GetIDbyName(name);

			cout << cs->GetStudentIDCardByStudentID(student_id)->describe();

		}
		else
			cout << "\nNu exista acest student";

	}

	void get_studentID_by_cardID() {

		string a;
		cout << "\nIntroduceti ID-ul legitimatiei : ";
		getline(cin, a);
		int cardID = stoi(a);

		if (cs->GetStudentIDbyCardID(cardID) != -1)
			cout << "\nID-ul studentului este : " << cs->GetStudentIDbyCardID(cardID);
		else
			cout << "\nNu este asociat niciunui student acest ID de legitimatie";
	}




	void get_enrolment_by_IDs() {


		string a, b;
		int student_id;
		cout << "\nIntroduceti ID-ul studentului : ";
		getline(cin, a);
		student_id = stoi(a);

		int course_id;
		cout << "\nIntroduceti ID-ul cursului : ";
		getline(cin, b);
		course_id = stoi(b);

		if (ce->get_poz(student_id, course_id) != -1) {

			Enrolment* e = ce->GetEnrolmentByIDs(student_id, course_id);
			cout << e->describe();
		}
		else
			cout << "\nAcest student nu s-a inregistrat la acest curs sau nu exista acest curs sau nu exista acest student";


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

			case 16: GetAllStudentsCourses();
				break;

			case 17: add_student();
				break;

			case 21: GetStudentBooks();
				break;

			case 22: exist_book();
				break;

			case 23: get_details_book();
				break;

			case 24: GetStudentIdByBookName();
				break;

			case 31:cc->traverse();
				break;

			case 32:exist_course();
				break;

			case 33: get_ID_Course();
				break;

			case 34: get_details_course();
				break;

			case 41:cs->traverse();
				break;

			case 42:exist_card();
				break;

			case 43:get_studentID_by_cardID();
				break;

			case 51:ce->traverse();
				break;

			case 52:get_enrolment_by_IDs();
				break;

			case 0:oprire = 1;
				break;
			}

		}
	}
};

