#include<iostream>
#include<string>
using namespace std;

class Carte {
private:
	const int idCarte;
	static int nrCarti;
	string titlu;
	string autor;
	int nrPagini;
	char* genLiterar;

public:
	Carte() : idCarte(++nrCarti) {
		this->titlu = "Necunoscut";
		this->autor = "Anonim";
		this->nrPagini = 0;
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
		else this->genLiterar = nullptr;
	}

	Carte(const Carte& c) : idCarte(++nrCarti) {
		this->titlu = c.titlu;
		this->autor = c.autor;
		this->nrPagini = c.nrPagini;
		if (c.genLiterar != nullptr) {
			this->genLiterar = new char[strlen(c.genLiterar) + 1];
			strcpy_s(this->genLiterar, strlen(c.genLiterar) + 1, c.genLiterar);
		}
		else this->genLiterar = nullptr;
	}

	~Carte() {
		if (this->genLiterar != nullptr)
			delete[] this->genLiterar;
	}

	Carte& operator=(const Carte& c) {
		if (this != &c) {
			if (this->genLiterar != nullptr)
				delete[] this->genLiterar;
			this->titlu = c.titlu;
			this->autor = c.autor;
			this->nrPagini = c.nrPagini;
			if (c.genLiterar != nullptr) {
				this->genLiterar = new char[strlen(c.genLiterar) + 1];
				strcpy_s(this->genLiterar, strlen(c.genLiterar) + 1, c.genLiterar);
			}
			else this->genLiterar = nullptr;
		}
		return *this;
	}

	bool operator==(const Carte& c) const {
		return this->titlu == c.titlu && this->autor == c.autor;
	}

	bool operator>(const Carte& c) const {
		return this->nrPagini > c.nrPagini;
	}

	Carte operator+(int pagini) const {
		Carte temp(*this);
		temp.nrPagini += pagini;
		return temp;
	}

	friend ostream& operator<<(ostream& out, const Carte& c) {
		out << "Carte: " << c.titlu << " (" << c.autor << "), " << c.nrPagini << " pagini, gen: " << (c.genLiterar ? c.genLiterar : "necunoscut");
		return out;
	}

	friend void comparaCarti(const Carte& c1, const Carte& c2);

	static int getNrCarti() { return nrCarti; }
};

int Carte::nrCarti = 0;

class Cititor {
private:
	const int idCititor;
	static int nrCititori;
	string nume;
	int varsta;
	int nrCartiImprumutate;
	string* cartiImprumutate;

public:
	Cititor() : idCititor(++nrCititori) {
		this->nume = "Anonim";
		this->varsta = 0;
		this->nrCartiImprumutate = 0;
		this->cartiImprumutate = nullptr;
	}

	Cititor(string nume, int varsta, int nrCarti, string* carti) : idCititor(++nrCititori) {
		this->nume = nume;
		this->varsta = varsta;
		this->nrCartiImprumutate = nrCarti;
		if (carti != nullptr && nrCarti > 0) {
			this->cartiImprumutate = new string[nrCarti];
			for (int i = 0; i < nrCarti; i++)
				this->cartiImprumutate[i] = carti[i];
		}
		else this->cartiImprumutate = nullptr;
	}

	Cititor(const Cititor& c) : idCititor(++nrCititori) {
		this->nume = c.nume;
		this->varsta = c.varsta;
		this->nrCartiImprumutate = c.nrCartiImprumutate;
		if (c.cartiImprumutate != nullptr && c.nrCartiImprumutate > 0) {
			this->cartiImprumutate = new string[c.nrCartiImprumutate];
			for (int i = 0; i < c.nrCartiImprumutate; i++)
				this->cartiImprumutate[i] = c.cartiImprumutate[i];
		}
		else this->cartiImprumutate = nullptr;
	}

	~Cititor() {
		if (this->cartiImprumutate != nullptr)
			delete[] this->cartiImprumutate;
	}

	Cititor& operator=(const Cititor& c) {
		if (this != &c) {
			if (this->cartiImprumutate != nullptr)
				delete[] this->cartiImprumutate;
			this->nume = c.nume;
			this->varsta = c.varsta;
			this->nrCartiImprumutate = c.nrCartiImprumutate;
			if (c.cartiImprumutate != nullptr) {
				this->cartiImprumutate = new string[c.nrCartiImprumutate];
				for (int i = 0; i < c.nrCartiImprumutate; i++)
					this->cartiImprumutate[i] = c.cartiImprumutate[i];
			}
			else this->cartiImprumutate = nullptr;
		}
		return *this;
	}

	Cititor operator+(int nr) const {
		Cititor temp(*this);
		temp.nrCartiImprumutate += nr;
		return temp;
	}

	bool operator<(const Cititor& c) const {
		return this->nrCartiImprumutate < c.nrCartiImprumutate;
	}

	bool operator==(const Cititor& c) const {
		return this->nume == c.nume && this->varsta == c.varsta;
	}

	friend ostream& operator<<(ostream& out, const Cititor& c) {
		out << "Cititor: " << c.nume << ", varsta " << c.varsta << ", carti imprumutate: " << c.nrCartiImprumutate;
		return out;
	}

	friend void afiseazaCititor(const Cititor& c);
	static int getNrCititori() { return nrCititori; }
};

int Cititor::nrCititori = 0;

class Bibliotecar {
private:
	const int idBibliotecar;
	static int nrBibliotecari;
	string nume;
	int vechimeAni;
	char* sectie;

public:
	Bibliotecar() : idBibliotecar(++nrBibliotecari) {
		this->nume = "Necunoscut";
		this->vechimeAni = 0;
		this->sectie = nullptr;
	}

	Bibliotecar(string nume, int vechimeAni, const char* sectie) : idBibliotecar(++nrBibliotecari) {
		this->nume = nume;
		this->vechimeAni = vechimeAni;
		if (sectie != nullptr) {
			this->sectie = new char[strlen(sectie) + 1];
			strcpy_s(this->sectie, strlen(sectie) + 1, sectie);
		}
		else this->sectie = nullptr;
	}

	Bibliotecar(const Bibliotecar& b) : idBibliotecar(++nrBibliotecari) {
		this->nume = b.nume;
		this->vechimeAni = b.vechimeAni;
		if (b.sectie != nullptr) {
			this->sectie = new char[strlen(b.sectie) + 1];
			strcpy_s(this->sectie, strlen(b.sectie) + 1, b.sectie);
		}
		else this->sectie = nullptr;
	}

	~Bibliotecar() {
		if (this->sectie != nullptr)
			delete[] this->sectie;
	}

	Bibliotecar& operator=(const Bibliotecar& b) {
		if (this != &b) {
			if (this->sectie != nullptr)
				delete[] this->sectie;
			this->nume = b.nume;
			this->vechimeAni = b.vechimeAni;
			if (b.sectie != nullptr) {
				this->sectie = new char[strlen(b.sectie) + 1];
				strcpy_s(this->sectie, strlen(b.sectie) + 1, b.sectie);
			}
			else this->sectie = nullptr;
		}
		return *this;
	}

	bool operator>(const Bibliotecar& b) const {
		return this->vechimeAni > b.vechimeAni;
	}

	bool operator==(const Bibliotecar& b) const {
		return this->nume == b.nume;
	}

	Bibliotecar operator+(int ani) const {
		Bibliotecar temp(*this);
		temp.vechimeAni += ani;
		return temp;
	}

	friend ostream& operator<<(ostream& out, const Bibliotecar& b) {
		out << "Bibliotecar: " << b.nume << ", vechime " << b.vechimeAni << ", sectie: " << (b.sectie ? b.sectie : "necunoscut");
		return out;
	}

	static int getNrBibliotecari() { return nrBibliotecari; }
	friend void comparaBibliotecari(const Bibliotecar& b1, const Bibliotecar& b2);
};

int Bibliotecar::nrBibliotecari = 0;

void comparaCarti(const Carte& c1, const Carte& c2) {
	if (c1 > c2)
		cout << "Cartea " << c1.getNrCarti() << " are mai multe pagini decat cealalta" << endl;
	else
		cout << "Cartea a doua este mai voluminoasa sau egala ca pagini" << endl;
}

void afiseazaCititor(const Cititor& c) {
	cout << "Cititorul " << c << endl;
}

void comparaBibliotecari(const Bibliotecar& b1, const Bibliotecar& b2) {
	if (b1 > b2)
		cout << b1 << " are mai multa experienta" << endl;
	else
		cout << b2 << " are mai multa experienta" << endl;
}

int main() {
	Carte c1("Ion", "Liviu Rebreanu", 300, "Roman realist");
	Carte c2("Baltagul", "M. Sadoveanu", 250, "Roman traditional");
	Carte c3 = c2;
	c3 = c1;
	cout << c1 << endl << c2 << endl;
	cout << (c1 == c2) << endl;
	cout << (c1 > c2) << endl;
	cout << (c1 + 50) << endl;
	comparaCarti(c1, c2);

	string carti1[] = { "Ion", "Morometii" };
	string carti2[] = { "Ion", "Morometii", "Baltagul" };
	Cititor ct1("Ioana", 21, 2, carti1);
	Cititor ct2("Andrei", 22, 3, carti2);
	Cititor ct3 = ct2;
	ct3 = ct1;
	cout << ct1 << endl << ct2 << endl;
	cout << (ct1 == ct2) << endl;
	cout << (ct1 < ct2) << endl;
	cout << (ct1 + 2) << endl;
	afiseazaCititor(ct1);

	Bibliotecar b1("Radu", 5, "Literatura");
	Bibliotecar b2("Maria", 8, "Istorie");
	Bibliotecar b3 = b1;
	b3 = b2;
	cout << b1 << endl << b2 << endl;
	cout << (b1 == b2) << endl;
	cout << (b1 > b2) << endl;
	cout << (b1 + 3) << endl;
	comparaBibliotecari(b1, b2);

	return 0;
}
