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

    Carte(const Carte& c) : idCarte(++nrCarti) {
        this->titlu = c.titlu;
        this->autor = c.autor;
        this->nrPagini = c.nrPagini;
        if (c.genLiterar != nullptr) {
            this->genLiterar = new char[strlen(c.genLiterar) + 1];
            strcpy_s(this->genLiterar, strlen(c.genLiterar) + 1, c.genLiterar);
        }
        else {
            this->genLiterar = nullptr;
        }
    }

    ~Carte() {
        if (this->genLiterar != nullptr) {
            delete[] this->genLiterar;
        }
    }

    string getTitlu() { return this->titlu; }
    void setTitlu(string titlu) { this->titlu = titlu; }

    string getAutor() { return this->autor; }
    void setAutor(string autor) { this->autor = autor; }

    int getNrPagini() { return this->nrPagini; }
    void setNrPagini(int nrPagini) { this->nrPagini = nrPagini; }

    char* getGenLiterar() { return this->genLiterar; }
    void setGenLiterar(const char* gen) {
        if (this->genLiterar != nullptr)
            delete[] this->genLiterar;
        if (gen != nullptr) {
            this->genLiterar = new char[strlen(gen) + 1];
            strcpy_s(this->genLiterar, strlen(gen) + 1, gen);
        }
        else {
            this->genLiterar = nullptr;
        }
    }

    const int getIdCarte() const { return this->idCarte; }

    static int getNrCarti() { return nrCarti; }

    friend void afiseazaInfoCarte(Carte c);
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

    Cititor(const Cititor& c) : idCititor(++nrCititori) {
        this->nume = c.nume;
        this->varsta = c.varsta;
        this->nrCartiImprumutate = c.nrCartiImprumutate;
        if (c.cartiImprumutate != nullptr && c.nrCartiImprumutate > 0) {
            this->cartiImprumutate = new string[c.nrCartiImprumutate];
            for (int i = 0; i < c.nrCartiImprumutate; i++) {
                this->cartiImprumutate[i] = c.cartiImprumutate[i];
            }
        }
        else {
            this->cartiImprumutate = nullptr;
        }
    }

    ~Cititor() {
        if (this->cartiImprumutate != nullptr) {
            delete[] this->cartiImprumutate;
        }
    }

    string getNume() { return this->nume; }
    void setNume(string nume) { this->nume = nume; }

    int getVarsta() { return this->varsta; }
    void setVarsta(int varsta) { this->varsta = varsta; }

    int getNrCartiImprumutate() { return this->nrCartiImprumutate; }

    string* getCartiImprumutate() { return this->cartiImprumutate; }

    static int getNrCititori() { return nrCititori; }

    friend void calculeazaCartiTotale(Cititor c);
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

    Bibliotecar(const Bibliotecar& b) : idBibliotecar(++nrBibliotecari) {
        this->nume = b.nume;
        this->vechimeAni = b.vechimeAni;
        if (b.sectie != nullptr) {
            this->sectie = new char[strlen(b.sectie) + 1];
            strcpy_s(this->sectie, strlen(b.sectie) + 1, b.sectie);
        }
        else {
            this->sectie = nullptr;
        }
    }

    ~Bibliotecar() {
        if (this->sectie != nullptr) {
            delete[] this->sectie;
        }
    }

    string getNume() { return this->nume; }
    void setNume(string nume) { this->nume = nume; }

    int getVechime() { return this->vechimeAni; }
    void setVechime(int vechime) { this->vechimeAni = vechime; }

    char* getSectie() { return this->sectie; }
    void setSectie(const char* sectie) {
        if (this->sectie != nullptr)
            delete[] this->sectie;
        if (sectie != nullptr) {
            this->sectie = new char[strlen(sectie) + 1];
            strcpy_s(this->sectie, strlen(sectie) + 1, sectie);
        }
        else {
            this->sectie = nullptr;
        }
    }

    static int getNrBibliotecari() { return nrBibliotecari; }
};

int Bibliotecar::nrBibliotecari = 0;


void afiseazaInfoCarte(Carte c) {
    cout << "Cartea \"" << c.titlu << "\" de " << c.autor
         << " are " << c.nrPagini << " pagini si este de genul: "
         << (c.genLiterar != nullptr ? c.genLiterar : "necunoscut") << endl;
}

void calculeazaCartiTotale(Cititor c) {
    cout << "Cititorul " << c.nume << " a imprumutat "
         << c.nrCartiImprumutate << " carti." << endl;
}


int main() {
    cout << "--- TESTARE CLASA CARTE ---" << endl;
    Carte c1("Ion", "Liviu Rebreanu", 320, "Roman realist");
    Carte c2 = c1;
    afiseazaInfoCarte(c1);
    cout << "Nr carti create: " << Carte::getNrCarti() << endl << endl;

    cout << "--- TESTARE CLASA CITITOR ---" << endl;
    string carti[] = { "Ion", "Baltagul", "Morometii" };
    Cititor cit1("Ioana", 22, 3, carti);
    Cititor cit2 = cit1;
    calculeazaCartiTotale(cit1);
    cout << "Nr cititori: " << Cititor::getNrCititori() << endl << endl;

    cout << "--- TESTARE CLASA BIBLIOTECAR ---" << endl;
    Bibliotecar b1("Radu", 8, "Literatura romana");
    Bibliotecar b2 = b1;
    cout << "Bibliotecarul " << b1.getNume()
         << " lucreaza la sectia: " << b1.getSectie()
         << " si are vechime de " << b1.getVechime() << " ani" << endl;
    cout << "Nr bibliotecari: " << Bibliotecar::getNrBibliotecari() << endl;

    return 0;
}
