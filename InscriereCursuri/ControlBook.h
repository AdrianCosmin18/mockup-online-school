#include"Book.h"

class ControlBook
{
private:
	list<Book*>books;

public:

	void add_book(Book* b) { books.push_back(b); }

	void traverse() {

		list<Book*>::iterator itr;
		for (itr = books.begin(); itr != books.end(); ++itr) {

			cout << (*itr)->describe();
			cout << endl;
		}
	}

	void load() {

		ifstream f("books.txt");
		string line;

		while (!f.eof()) {

			getline(f, line);
			books.push_back(new Book(line));
		}
	}

	ControlBook() { load(); }

	int get_poz(int id) {

		int poz = -1;
		list<Book*>::iterator itr;
		for (itr = books.begin(); itr != books.end(); ++itr) {

			poz++;
			if ((*itr)->get_id() == id) return poz;
		}
		return -1;
	}

	list<Book*>::iterator get_itr_poz(int poz) {

		int p = -1;
		list<Book*>::iterator itr;
		for (itr = books.begin(); itr != books.end(); ++itr) {

			p++;
			if (p == poz)return itr;
		}
	}

	void erase_book(int id) {

		int poz = get_poz(id);
		list<Book*>::iterator itr = get_itr_poz(poz);
		
		books.erase(itr);
	}

	void modify_book(int id, string name, string date) {

		int poz = get_poz(id);
		list<Book*>::iterator itr = get_itr_poz(poz);

		(*itr)->set_name(name);
		(*itr)->set_created_at(date);
	}

	int GetIDbyName(string name) {

		list<Book*>::iterator itr;
		for (itr = books.begin(); itr != books.end(); ++itr) {

			if ((*itr)->get_name() == name)
				return (*itr)->get_id();
		}

		return -1;
	}

	list<Book*> GetBookListForStudentByStudentID(int student_id) {
		list<Book*>b;

		list<Book*>::iterator itr;
		for (itr = books.begin(); itr != books.end(); ++itr) {

			if ((*itr)->get_studentId() == student_id)
				b.push_back(*itr);
		}

		return b;
	}

	Book* GetBookByName(string name) {

		int id = GetIDbyName(name);
		list<Book*>::iterator itr;
		for (itr = books.begin(); itr != books.end(); ++itr) {

			if ((*itr)->get_id() == id)
				return *itr;
		}
	}
};

