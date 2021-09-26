#include"Enrolment.h"

class ControlEnrolment
{
private:
	list<Enrolment*>enrolments;

public:

	void load() {

		ifstream f("enrolments.txt");
		string line;

		while (!f.eof()) {

			getline(f, line);

			enrolments.push_back(new Enrolment(line));
		}
	}

	ControlEnrolment() { load(); }

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

