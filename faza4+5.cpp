#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
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
        titlu = "Necunoscut";
        autor = "Anonim";
        nrPagini = 0;
        genLiterar = nullptr;
    }

    Carte(string titlu, string autor, int nrPagini, const char* gen) : idCarte(++nrCarti) {
        this->titlu = titlu;
        this->autor = autor;
        this->nrPagini = nrPagini;
        if (gen != nullptr) {
            genLiterar = new char[strlen(gen) + 1];
            strcpy_s(genLiterar, strlen(gen) + 1, gen);
        } else genLiterar = nullptr;
    }

    Carte(const Carte& c) : idCarte(++nrCarti) {
        titlu = c.titlu; autor = c.autor; nrPagini = c.nrPagini;
        if (c.genLiterar != nullptr) {
            genLiterar = new char[strlen(c.genLiterar) + 1];
            strcpy_s(genLiterar, strlen(c.genLiterar) + 1, c.genLiterar);
        } else genLiterar = nullptr;
    }

    ~Carte() { if (genLiterar != nullptr) delete[] genLiterar; }

    Carte& operator=(const Carte& c) {
        if (this != &c) {
            if (genLiterar != nullptr) delete[] genLiterar;
            titlu = c.titlu; autor = c.autor; nrPagini = c.nrPagini;
            if (c.genLiterar != nullptr) {
                genLiterar = new char[strlen(c.genLiterar) + 1];
                strcpy_s(genLiterar, strlen(c.genLiterar) + 1, c.genLiterar);
            } else genLiterar = nullptr;
        }
        return *this;
    }

    // bool operator==(const Carte& c) { return titlu == c.titlu && autor == c.autor; }
    // bool operator>(const Carte& c) { return nrPagini > c.nrPagini; }

    Carte operator+(int pagini) const { Carte t(*this); t.nrPagini += pagini; return t; }

    friend ostream& operator<<(ostream& out, const Carte& c) {
        out << "Carte: " << c.titlu << " (" << c.autor << "), "
            << c.nrPagini << " pagini, gen: "
            << (c.genLiterar ? c.genLiterar : "necunoscut");
        return out;
    }

    // friend istream& operator>>(istream& in, Carte& c) {
    //     cout << "Titlu: "; in >> ws; getline(in, c.titlu);
    //     cout << "Autor: "; in >> ws; getline(in, c.autor);
    //     cout << "Nr pagini: "; in >> c.nrPagini;
    //     cout << "Gen (linie): "; {
    //         string g; in >> ws; getline(in, g);
    //         if (c.genLiterar != nullptr) delete[] c.genLiterar;
    //         if (!g.empty()) {
    //             c.genLiterar = new char[g.size() + 1];
    //             strcpy_s(c.genLiterar, g.size() + 1, g.c_str());
    //         } else c.genLiterar = nullptr;
    //     }
    //     return in;
    // }

    static int getNrCarti() { return nrCarti; }

    // void afis() const { cout << *this << endl; }

    void scrieInFisierText(ofstream& fout) const {
        fout << titlu << "\n" << autor << "\n" << nrPagini << "\n";
        fout << (genLiterar ? genLiterar : "NULL") << "\n";
    }

    void citesteDinFisierText(ifstream& fin) {
        getline(fin, titlu);
        getline(fin, autor);
        fin >> nrPagini;
        fin.ignore();
        
        string g;
        getline(fin, g);
        if (genLiterar) delete[] genLiterar;
        if (g != "NULL") {
            genLiterar = new char[g.size() + 1];
            strcpy_s(genLiterar, g.size() + 1, g.c_str());
        } else genLiterar = nullptr;
    }
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
        nume = "Anonim"; varsta = 0; nrCartiImprumutate = 0; cartiImprumutate = nullptr;
    }

    Cititor(string nume, int varsta, int nrCarti, string* carti) : idCititor(++nrCititori) {
        this->nume = nume; this->varsta = varsta; nrCartiImprumutate = nrCarti;
        if (carti != nullptr && nrCarti > 0) {
            cartiImprumutate = new string[nrCarti];
            for (int i = 0; i < nrCarti; i++) cartiImprumutate[i] = carti[i];
        } else cartiImprumutate = nullptr;
    }

    Cititor(const Cititor& c) : idCititor(++nrCititori) {
        nume = c.nume; varsta = c.varsta; nrCartiImprumutate = c.nrCartiImprumutate;
        if (c.cartiImprumutate != nullptr && c.nrCartiImprumutate > 0) {
            cartiImprumutate = new string[c.nrCartiImprumutate];
            for (int i = 0; i < c.nrCartiImprumutate; i++) cartiImprumutate[i] = c.cartiImprumutate[i];
        } else cartiImprumutate = nullptr;
    }

    ~Cititor() { if (cartiImprumutate != nullptr) delete[] cartiImprumutate; }

    // Cititor& operator=(const Cititor& c) {
    //     if (this != &c) {
    //         if (cartiImprumutate != nullptr) delete[] cartiImprumutate;
    //         nume = c.nume; varsta = c.varsta; nrCartiImprumutate = c.nrCartiImprumutate;
    //         if (c.cartiImprumutate != nullptr) {
    //             cartiImprumutate = new string[c.nrCartiImprumutate];
    //             for (int i = 0; i < c.nrCartiImprumutate; i++) cartiImprumutate[i] = c.cartiImprumutate[i];
    //         } else cartiImprumutate = nullptr;
    //     }
    //     return *this;
    // }

    // Cititor operator+(int nr) const { Cititor t(*this); t.nrCartiImprumutate += nr; return t; }
    // bool operator<(const Cititor& c) { return nrCartiImprumutate < c.nrCartiImprumutate; }
    // bool operator==(const Cititor& c) { return nume == c.nume && varsta == c.varsta; }

    friend ostream& operator<<(ostream& out, const Cititor& c) {
        out << "Cititor: " << c.nume << ", varsta " << c.varsta
            << ", carti imprumutate: " << c.nrCartiImprumutate;
        return out;
    }

    // friend istream& operator>>(istream& in, Cititor& c) {
    //     cout << "Nume: "; in >> ws; getline(in, c.nume);
    //     cout << "Varsta: "; in >> c.varsta;
    //     cout << "Nr carti imprumutate: "; in >> c.nrCartiImprumutate;
    //     if (c.cartiImprumutate != nullptr) { delete[] c.cartiImprumutate; c.cartiImprumutate = nullptr; }
    //     if (c.nrCartiImprumutate > 0) {
    //         c.cartiImprumutate = new string[c.nrCartiImprumutate];
    //         for (int i = 0; i < c.nrCartiImprumutate; i++) {
    //             cout << "Titlu carte [" << (i + 1) << "]: ";
    //             in >> ws; getline(in, c.cartiImprumutate[i]);
    //         }
    //     }
    //     return in;
    // }

    static int getNrCititori() { return nrCititori; }

    void scrieInFisierText(ofstream& fout) const {
        fout << nume << "\n" << varsta << "\n" << nrCartiImprumutate << "\n";
        for (int i = 0; i < nrCartiImprumutate; i++)
            fout << cartiImprumutate[i] << "\n";
    }

    void citesteDinFisierText(ifstream& fin) {
        getline(fin, nume);
        fin >> varsta >> nrCartiImprumutate;
        fin.ignore();

        if (cartiImprumutate) delete[] cartiImprumutate;

        if (nrCartiImprumutate > 0) {
            cartiImprumutate = new string[nrCartiImprumutate];
            for (int i = 0; i < nrCartiImprumutate; i++)
                getline(fin, cartiImprumutate[i]);
        } else cartiImprumutate = nullptr;
    }

    void scrieInFisierBinar(ofstream& fout) const {
        size_t len = nume.size();
        fout.write((char*)&len, sizeof(len));
        fout.write(nume.c_str(), len);

        fout.write((char*)&varsta, sizeof(varsta));
        fout.write((char*)&nrCartiImprumutate, sizeof(nrCartiImprumutate));

        for (int i = 0; i < nrCartiImprumutate; i++) {
            size_t l = cartiImprumutate[i].size();
            fout.write((char*)&l, sizeof(l));
            fout.write(cartiImprumutate[i].c_str(), l);
        }
    }

    void citesteDinFisierBinar(ifstream& fin) {
        size_t len;
        fin.read((char*)&len, sizeof(len));
        nume.resize(len);
        fin.read(&nume[0], len);

        fin.read((char*)&varsta, sizeof(varsta));
        fin.read((char*)&nrCartiImprumutate, sizeof(nrCartiImprumutate));

        if (cartiImprumutate) delete[] cartiImprumutate;
        cartiImprumutate = nullptr;

        if (nrCartiImprumutate > 0) {
            cartiImprumutate = new string[nrCartiImprumutate];
            for (int i = 0; i < nrCartiImprumutate; i++) {
                size_t l;
                fin.read((char*)&l, sizeof(l));
                cartiImprumutate[i].resize(l);
                fin.read(&cartiImprumutate[i][0], l);
            }
        }
    }

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
        nume = "Necunoscut"; vechimeAni = 0; sectie = nullptr;
    }

    Bibliotecar(string nume, int vechimeAni, const char* sectie) : idBibliotecar(++nrBibliotecari) {
        this->nume = nume; this->vechimeAni = vechimeAni;
        if (sectie != nullptr) {
            this->sectie = new char[strlen(sectie) + 1];
            strcpy_s(this->sectie, strlen(sectie) + 1, sectie);
        } else this->sectie = nullptr;
    }

    Bibliotecar(const Bibliotecar& b) : idBibliotecar(++nrBibliotecari) {
        nume = b.nume; vechimeAni = b.vechimeAni;
        if (b.sectie != nullptr) {
            sectie = new char[strlen(b.sectie) + 1];
            strcpy_s(sectie, strlen(b.sectie) + 1, b.sectie);
        } else sectie = nullptr;
    }

    ~Bibliotecar() { if (sectie != nullptr) delete[] sectie; }

    // Bibliotecar& operator=(const Bibliotecar& b) {
    //     if (this != &b) {
    //         if (sectie != nullptr) delete[] sectie;
    //         nume = b.nume; vechimeAni = b.vechimeAni;
    //         if (b.sectie != nullptr) {
    //             sectie = new char[strlen(b.sectie) + 1];
    //             strcpy_s(sectie, strlen(b.sectie) + 1, b.sectie);
    //         } else sectie = nullptr;
    //     }
    //     return *this;
    // }

    // bool operator>(const Bibliotecar& b) { return vechimeAni > b.vechimeAni; }
    // bool operator==(const Bibliotecar& b) { return nume == b.nume; }
    // Bibliotecar operator+(int ani) const { Bibliotecar t(*this); t.vechimeAni += ani; return t; }

    friend ostream& operator<<(ostream& out, const Bibliotecar& b) {
        out << "Bibliotecar: " << b.nume << ", vechime " << b.vechimeAni
            << ", sectie: " << (b.sectie ? b.sectie : "necunoscut");
        return out;
    }

    // friend istream& operator>>(istream& in, Bibliotecar& b) {
    //     cout << "Nume: "; in >> ws; getline(in, b.nume);
    //     cout << "Vechime (ani): "; in >> b.vechimeAni;
    //     cout << "Sectie (linie): "; {
    //         string s; in >> ws; getline(in, s);
    //         if (b.sectie != nullptr) delete[] b.sectie;
    //         if (!s.empty()) {
    //             b.sectie = new char[s.size() + 1];
    //             strcpy_s(b.sectie, s.size() + 1, s.c_str());
    //         } else b.sectie = nullptr;
    //     }
    //     return in;
    // }

    static int getNrBibliotecari() { return nrBibliotecari; }

    void scrieInFisierBinar(ofstream& fout) const {
        size_t len = nume.size();
        fout.write((char*)&len, sizeof(len));
        fout.write(nume.c_str(), len);

        fout.write((char*)&vechimeAni, sizeof(vechimeAni));

        if (sectie) {
            size_t lg = strlen(sectie);
            fout.write((char*)&lg, sizeof(lg));
            fout.write(sectie, lg);
        } else {
            size_t lg = 0;
            fout.write((char*)&lg, sizeof(lg));
        }
    }

    void citesteDinFisierBinar(ifstream& fin) {
        size_t len;
        fin.read((char*)&len, sizeof(len));
        nume.resize(len);
        fin.read(&nume[0], len);

        fin.read((char*)&vechimeAni, sizeof(vechimeAni));

        size_t lg;
        fin.read((char*)&lg, sizeof(lg));

        if (sectie) delete[] sectie;

        if (lg > 0) {
            sectie = new char[lg + 1];
            fin.read(sectie, lg);
            sectie[lg] = '\0';
        } else sectie = nullptr;
    }
};
int Bibliotecar::nrBibliotecari = 0;

class Imprumut {
private:
    Carte c; // has-a Carte
    Cititor ct; // has-a Cititor
    int nrZile;
    float penalizareZi;

public:
    Imprumut() : c(), ct(), nrZile(0), penalizareZi(0) {}

    Imprumut(Carte c, Cititor ct, int nrZile, float penalizare)
        : c(c), ct(ct), nrZile(nrZile), penalizareZi(penalizare) {}

    float calcPenalizare() const {
        return nrZile * penalizareZi;
    }

    friend ostream& operator<<(ostream& out, const Imprumut& i) {
        out << "Imprumut -> Zile: " << i.nrZile
            << ", Penalizare/zi: " << i.penalizareZi
            << ", Total: " << i.calcPenalizare();
        return out;
    }
};

int main() {
    // // ---- vector1:carte
    // int n1; cout << "Nr carti (vector): "; cin >> n1;
    // Carte* vCarti = (n1 > 0) ? new Carte[n1] : nullptr;
    // for (int i = 0; i < n1; i++) {
    //     cout << "\n-- Carte #" << (i + 1) << " --\n";
    //     cin >> vCarti[i];
    // }
    // cout << "\n== Afisare vector CARTI ==\n";
    // for (int i = 0; i < n1; i++) cout << vCarti[i] << endl;

    // // --- vector2: cititor
    // int n2; cout << "\nNr cititori (vector): "; cin >> n2;
    // Cititor* vCit = (n2 > 0) ? new Cititor[n2] : nullptr;
    // for (int i = 0; i < n2; i++) {
    //     cout << "\n-- Cititor #" << (i + 1) << " --\n";
    //     cin >> vCit[i];
    // }
    // cout << "\n== Afisare vector CITITORI ==\n";
    // for (int i = 0; i < n2; i++) cout << vCit[i] << endl;

    // // --- vector 3: bibliotecar
    // int n3; cout << "\nNr bibliotecari (vector): "; cin >> n3;
    // Bibliotecar* vBib = (n3 > 0) ? new Bibliotecar[n3] : nullptr;
    // for (int i = 0; i < n3; i++) {
    //     cout << "\n-- Bibliotecar #" << (i + 1) << " --\n";
    //     cin >> vBib[i];
    // }
    // cout << "\n== Afisare vector BIBLIOTECARI ==\n";
    // for (int i = 0; i < n3; i++) cout << vBib[i] << endl;

    // int r, c; cout << "\nDimensiune matrice CARTI (linii, coloane): "; cin >> r >> c;
    // Carte** M = nullptr;
    // if (r > 0 && c > 0) {
    //     M = new Carte*[r];
    //     for (int i = 0; i < r; i++) M[i] = new Carte[c];

    //     for (int i = 0; i < r; i++) {
    //         for (int j = 0; j < c; j++) {
    //             cout << "\n-- Carte M[" << i << "][" << j << "] --\n";
    //             cin >> M[i][j];
    //         }
    //     }

    //     cout << "\n== Afisare MATRICE CARTI ==\n";
    //     for (int i = 0; i < r; i++) {
    //         for (int j = 0; j < c; j++) {
    //             cout << "[" << i << "," << j << "] " << M[i][j] << "\n";
    //         }
    //     }
    // }

    // if (vCarti) delete[] vCarti;
    // if (vCit) delete[] vCit;
    // if (vBib) delete[] vBib;
    // if (M) {
    //     for (int i = 0; i < r; i++) delete[] M[i];
    //     delete[] M;
    // }

    // return 0;

    Carte c1("Ion", "Rebreanu", 300, "roman");
    string cartiTemp[] = {"Ion"};
    Cititor ct1("Ioana", 21, 1, cartiTemp);

    Imprumut I(c1, ct1, 5, 2.5f);

    cout << "\n== TESTARE IMPRUMUT (FAZA 5) ==\n";
    cout << I << endl;

    ofstream foutText("carte.txt");
    c1.scrieInFisierText(foutText);
    foutText.close();

    ifstream finText("carte.txt");
    Carte c2;
    c2.citesteDinFisierText(finText);
    finText.close();

    cout << "\n== Citire din fisier text ==\n";
    cout << c2 << endl;

    ofstream foutBin("cititor.bin", ios::binary);
    ct1.scrieInFisierBinar(foutBin);
    foutBin.close();

    ifstream finBin("cititor.bin", ios::binary);
    Cititor ct2;
    ct2.citesteDinFisierBinar(finBin);
    finBin.close();

    cout << "\n== Citire din fisier binar ==\n";
    cout << ct2 << endl;


    return 0;
}
