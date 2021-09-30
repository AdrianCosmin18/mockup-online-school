#include"Enrolment.h"

class ControlEnrolment
{
private:
	list<Enrolment*>enrolments;
	ControlPerson* cp = NULL;
	ControlCourse* cc = NULL;

public:

	void load() {

		ifstream f("enrolments.txt");
		string line;

		while (!f.eof()) {

			getline(f, line);
			Enrolment* e = new Enrolment(line);
			enrolments.push_back(e);


			Person* p = cp->GetPersonByID(e->get_studentId());
			Student* s = dynamic_cast<Student*>(p);

			Course* c = cc->GetCourseByID(e->get_courseId());

			s->add_course(c);
			//iau id-ul studentului pentru a gasi studentul si ii extrag numele
			/*int student_id = e->get_studentId();
			int poz = cp->poz_person(student_id);
			list<Person*>::iterator itr = cp->poz_itr_person(poz);
			Person* p = *itr;
			Student* s = dynamic_cast<Student*>(p);
			string student_name = s->get_name();

			int course_id = e->get_courseId();
			int poz2 = cc->poz_course(course_id);
			list<Course*>::iterator itr2 = cc->poz_itr_course(poz2);
			Course* c = *itr2;
			string course_name = c->get_name();

			s->add_course(course_name);*/


		}
	}

	ControlEnrolment() { load(); cp = new ControlPerson; cc = new ControlCourse; }

	void traverse() {

		list<Enrolment*>::iterator itr;
		for (itr = enrolments.begin(); itr != enrolments.end(); ++itr) {

			cout << (*itr)->describe();
			cout << endl;
		}
	}

	void add_enrolment(Enrolment* e) { enrolments.push_back(e); }

	int get_poz(int sid, int cid) {

		int poz = -1;
		list<Enrolment*>::iterator itr;
		for (itr = enrolments.begin(); itr != enrolments.end(); ++itr) {

			poz++;
			if ((*itr)->get_courseId() == cid and (*itr)->get_studentId() == sid)
				return poz;
		}

		return -1;
	}


	list<Enrolment*>::iterator get_itr_poz(int poz) {

		int p = -1;
		list<Enrolment*>::iterator itr;
		for (itr = enrolments.begin(); itr != enrolments.end(); ++itr) {

			p++;
			if (p == poz)return itr;
		}
	}

	void erase_enrolment(int sid, int cid) {

		int poz = get_poz(sid, cid);
		list<Enrolment*>::iterator itr = get_itr_poz(poz);
		enrolments.erase(itr);
	}


	void modify_enrolment(int sid, int cid, string date) {

		int poz = get_poz(sid, cid);
		list<Enrolment*>::iterator itr = get_itr_poz(poz);
		(*itr)->set_created_at(date);
	}

	Enrolment* GetEnrolmentByIDs(int sid, int cid) {

		list<Enrolment*>::iterator itr;
		for (itr = enrolments.begin(); itr != enrolments.end(); ++itr) {

			if ((*itr)->get_studentId() == sid and (*itr)->get_courseId() == cid)
				return *itr;
		}
	}
};

