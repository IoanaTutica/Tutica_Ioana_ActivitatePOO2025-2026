#include<iostream>
#include<string>

using namespace std;

class Carte {
public:
	const int idCarte;
	static int nrCarti;
	string titlu;
	string autor;
	int nrPagini;
	char* genLiterar;

	Carte() : idCarte(++nrCarti) {
		this->titlu = "Necunoscut";
		this->autor = "Anonim";
		this->nrPagini = 0;
		this->genLiterar = nullptr;
	}

	Carte(string titlu, string autor) : idCarte(++nrCarti) {
		this->titlu = titlu;
		this->autor = autor;
		this->nrPagini = 100;
		this->genLiterar = nullptr;
	}

	Carte(string titlu, string autor, int nrPagini, const char* gen) : idCarte(++nrCarti) {
		this->titlu = titlu;
		this->autor = autor;
		this->nrPagini = nrPagini;
		if (gen != nullptr) {
			this->genLiterar = new char[strlen(gen) + 1];
			strcpy_s(this->genLiterar, strlen(gen) + 1, gen);
		}
		else {
			this->genLiterar = nullptr;
		}
	}

	static int getNrCartiCreate() {
		return nrCarti;
	}
};

int Carte::nrCarti = 0;

class Cititor {
public:
	const int idCititor;
	static int nrCititori;
	string nume;
	int varsta;
	int nrCartiImprumutate;
	string* cartiImprumutate;

	Cititor() : idCititor(++nrCititori) {
		this->nume = "Anonim";
		this->varsta = 0;
		this->nrCartiImprumutate = 0;
		this->cartiImprumutate = nullptr;
	}

	Cititor(string nume, int varsta) : idCititor(++nrCititori) {
		this->nume = nume;
		this->varsta = varsta;
		this->nrCartiImprumutate = 0;
		this->cartiImprumutate = nullptr;
	}

	Cititor(string nume, int varsta, int nrCarti, string* carti) : idCititor(++nrCititori) {
		this->nume = nume;
		this->varsta = varsta;
		this->nrCartiImprumutate = nrCarti;
		if (carti != nullptr && nrCarti > 0) {
			this->cartiImprumutate = new string[nrCarti];
			for (int i = 0; i < nrCarti; i++) {
				this->cartiImprumutate[i] = carti[i];
			}
		}
		else {
			this->cartiImprumutate = nullptr;
		}
	}

	static int getNrCititori() {
		return nrCititori;
	}
};

int Cititor::nrCititori = 0;


class Bibliotecar {
public:
	const int idBibliotecar;
	static int nrBibliotecari;
	string nume;
	int vechimeAni;
	char* sectie;

	Bibliotecar() : idBibliotecar(++nrBibliotecari) {
		this->nume = "Necunoscut";
		this->vechimeAni = 0;
		this->sectie = nullptr;
	}

	Bibliotecar(string nume, int vechimeAni) : idBibliotecar(++nrBibliotecari) {
		this->nume = nume;
		this->vechimeAni = vechimeAni;
		this->sectie = nullptr;
	}

	Bibliotecar(string nume, int vechimeAni, const char* sectie) : idBibliotecar(++nrBibliotecari) {
		this->nume = nume;
		this->vechimeAni = vechimeAni;
		if (sectie != nullptr) {
			this->sectie = new char[strlen(sectie) + 1];
			strcpy_s(this->sectie, strlen(sectie) + 1, sectie);
		}
		else {
			this->sectie = nullptr;
		}
	}

	static int getNrBibliotecari() {
		return nrBibliotecari;
	}
};

int Bibliotecar::nrBibliotecari = 0;


int main() {
	cout << "--- TESTARE CLASA CARTE ---" << endl;
	Carte c1;
	cout << "C1 (default): ID=" << c1.idCarte << ", Titlu=" << c1.titlu << ", Autor=" << c1.autor << endl;

	Carte c2("Ion", "Liviu Rebreanu");
	cout << "C2 (2 param): ID=" << c2.idCarte << ", Titlu=" << c2.titlu << ", Autor=" << c2.autor << ", NrPagini=" << c2.nrPagini << endl;

	Carte c3("Crima si pedeapsa", "Dostoievski", 650, "Roman psihologic");
	cout << "C3 (4 param): ID=" << c3.idCarte << ", Titlu=" << c3.titlu << ", Autor=" << c3.autor;
	if (c3.genLiterar != nullptr) cout << ", Gen=" << c3.genLiterar;
	cout << endl;
	cout << "Functie statica: Nr. carti create = " << Carte::getNrCartiCreate() << endl << endl;


	cout << "--- TESTARE CLASA CITITOR ---" << endl;
	Cititor ct1;
	cout << "CT1 (default): ID=" << ct1.idCititor << ", Nume=" << ct1.nume << endl;

	Cititor ct2("Ioana", 23);
	cout << "CT2 (2 param): ID=" << ct2.idCititor << ", Nume=" << ct2.nume << ", Varsta=" << ct2.varsta << endl;

	string carti[] = { "Ion", "Morometii", "Baltagul" };
	Cititor ct3("Andrei", 22, 3, carti);
	cout << "CT3 (4 param): ID=" << ct3.idCititor << ", Nume=" << ct3.nume << ", NrCarti=" << ct3.nrCartiImprumutate << endl;
	if (ct3.cartiImprumutate != nullptr) {
		cout << "Carti imprumutate: ";
		for (int i = 0; i < ct3.nrCartiImprumutate; i++) {
			cout << ct3.cartiImprumutate[i] << " | ";
		}
		cout << endl;
	}
	cout << "Functie statica: nr. cititori = " << Cititor::getNrCititori() << endl << endl;


	cout << "--- TESTARE CLASA BIBLIOTECAR ---" << endl;
	Bibliotecar b1;
	cout << "B1 (default): ID=" << b1.idBibliotecar << ", Nume=" << b1.nume << endl;

	Bibliotecar b2("Maria", 5);
	cout << "B2 (2 param): ID=" << b2.idBibliotecar << ", Nume=" << b2.nume << ", Vechime=" << b2.vechimeAni << endl;

	Bibliotecar b3("Radu", 10, "Literatura universala");
	cout << "B3 (3 param): ID=" << b3.idBibliotecar << ", Nume=" << b3.nume << ", Sectie=";
	if (b3.sectie != nullptr) cout << b3.sectie;
	cout << endl;

	cout << "Functie statica: Nr. bibliotecari = " << Bibliotecar::getNrBibliotecari() << endl;

	return 0;
}