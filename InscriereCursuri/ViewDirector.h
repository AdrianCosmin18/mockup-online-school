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

		cout << "Pentru a afisa toti studentii apasati 11\n";
		cout << "Pentru a verifica existenta unui student apasati  12\n";
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


};

