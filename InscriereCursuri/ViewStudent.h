#include"ControlEnrolment.h"

class ViewStudent
{
private:
	ControlPerson* cp = new ControlPerson;
	ControlBook* cb = new ControlBook;
	ControlCourse* cc = new ControlCourse;
	ControlEnrolment* ce = new ControlEnrolment;
	ControlStudentIDCard* cs = new ControlStudentIDCard;

public:

	void menu() {

		cout << "Pentru a afisa toti studentii apasati tasta 1 \n";
		cout << "Pentru a verifica existenta unui student, apasati tasta 2 \n";
		//cout << "Pentru a afla detalii despre un student apasati tasta 3\n";
		//cout << "Pentru a adauga un student apasati tasta 4\n";
		//cout << "Pentru a sterge un student apasati tasta 5\n";
		//cout << "Pentru a modifica un student apasati tasta 6\n";
		cout << "Pentru a afisa lista de carti inchiriata de un student3\n";
		cout << "Pentru a inchiria o carte apasati tasta 4\n";



		cout << "Pentru a iesi apasati 5\n";
	}
};

