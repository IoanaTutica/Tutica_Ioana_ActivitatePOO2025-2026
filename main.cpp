#include<iostream>
#include<string>

using namespace std;

class SiteWeb {
public:
	const int idSite;
	static int nrSiteUri;
	string url;
	int nrPagini;
	bool esteSecurizat;
	char* fondator;

	SiteWeb() : idSite(++nrSiteUri) {
		this->url = "Necunoscuta";
		this->nrPagini = 0;
		this->esteSecurizat = false;
		this->fondator = nullptr;
	}

	SiteWeb(string url, int nrPagini) : idSite(++nrSiteUri) {
		this->url = url;
		this->nrPagini = nrPagini;
		this->esteSecurizat = false;
		this->fondator = nullptr;
	}

	SiteWeb(string url, int nrPagini, bool esteSecurizat, const char* fondator) : idSite(++nrSiteUri) {
		this->url = url;
		this->nrPagini = nrPagini;
		this->esteSecurizat = esteSecurizat;
		if (fondator != nullptr) {
			this->fondator = new char[strlen(fondator) + 1];
			strcpy_s(this->fondator, strlen(fondator) + 1, fondator);
		}
		else {
			this->fondator = nullptr;
		}
	}

	static int getNrSiteUriCreate() {
		return nrSiteUri;
	}
};

int SiteWeb::nrSiteUri = 0;


class Utilizator {
public:
	const int idUtilizator;
	static int contorUtilizatori;
	string username;
	string email;
	int varsta;
	int* istoricConexiuniSecunde;
	int nrConexiuni;

	Utilizator() : idUtilizator(++contorUtilizatori) {
		this->username = "Anonim";
		this->email = "";
		this->varsta = 0;
		this->istoricConexiuniSecunde = nullptr;
		this->nrConexiuni = 0;
	}

	Utilizator(string username, string email) : idUtilizator(++contorUtilizatori) {
		this->username = username;
		this->email = email;
		this->varsta = 18;
		this->istoricConexiuniSecunde = nullptr;
		this->nrConexiuni = 0;
	}

	Utilizator(string username, string email, int varsta, int nrConexiuni, const int* istoric) : idUtilizator(++contorUtilizatori) {
		this->username = username;
		this->email = email;
		this->varsta = varsta;
		this->nrConexiuni = nrConexiuni;
		if (istoric != nullptr && nrConexiuni > 0) {
			this->istoricConexiuniSecunde = new int[nrConexiuni];
			for (int i = 0; i < nrConexiuni; i++) {
				this->istoricConexiuniSecunde[i] = istoric[i];
			}
		}
		else {
			this->istoricConexiuniSecunde = nullptr;
			this->nrConexiuni = 0;
		}
	}

	static void reseteazaContorUtilizatori() {
		contorUtilizatori = 0;
	}
};

int Utilizator::contorUtilizatori = 0;


class Browser {
public:
	const int idBrowser;
	static int nrBrowsereInstalate;
	static string motorCautareDefault;
	string nume;
	float versiune;
	char* companieProducatoare;

	Browser() : idBrowser(++nrBrowsereInstalate) {
		this->nume = "Necunoscut";
		this->versiune = 1.0;
		this->companieProducatoare = nullptr;
	}

	Browser(string nume, float versiune) : idBrowser(++nrBrowsereInstalate) {
		this->nume = nume;
		this->versiune = versiune;
		this->companieProducatoare = nullptr;
	}

	Browser(string nume, float versiune, const char* companie) : idBrowser(++nrBrowsereInstalate) {
		this->nume = nume;
		this->versiune = versiune;
		if (companie != nullptr) {
			this->companieProducatoare = new char[strlen(companie) + 1];
			strcpy_s(this->companieProducatoare, strlen(companie) + 1, companie);
		}
		else {
			this->companieProducatoare = nullptr;
		}
	}

	static string getMotorCautareDefault() {
		return motorCautareDefault;
	}
};

int Browser::nrBrowsereInstalate = 0;
string Browser::motorCautareDefault = "Google";


int main() {

	cout << "--- TESTARE CLASA SITEWEB ---" << endl;

	SiteWeb s1;
	cout << "S1 (default): ID=" << s1.idSite << ", URL: " << s1.url << ", Pagini: " << s1.nrPagini << endl;
    
	SiteWeb s2("google.com", 1000000);
	cout << "S2 (2 params): ID=" << s2.idSite << ", URL: " << s2.url << ", Pagini: " << s2.nrPagini << ", Securizat: " << s2.esteSecurizat << endl;

	SiteWeb s3("facebook.com", 50000, true, "Mark Zuckerberg");
	cout << "S3 (4 params): ID=" << s3.idSite << ", URL: " << s3.url << ", Securizat: " << s3.esteSecurizat;
	if (s3.fondator != nullptr) {
		cout << ", Fondator: " << s3.fondator << endl;
	}
	else {
		cout << endl;
	}

	cout << "Functie statica: Nr. site-uri create: " << SiteWeb::getNrSiteUriCreate() << endl;
	cout << endl;

	cout << "--- TESTARE CLASA UTILIZATOR ---" << endl;

	Utilizator u1;
	cout << "U1 (default): ID=" << u1.idUtilizator << ", Nume: " << u1.username << ", Email: " << u1.email << endl;

	Utilizator u2("ioana.tutica", "ioana@test.com");
	cout << "U2 (2 params): ID=" << u2.idUtilizator << ", Nume: " << u2.username << ", Email: " << u2.email << ", Varsta: " << u2.varsta << endl;

	int istoric[] = { 300, 150, 800, 120 };
	Utilizator u3("admin", "admin@site.com", 25, 4, istoric);
	cout << "U3 (5 params): ID=" << u3.idUtilizator << ", Nume: " << u3.username << ", Varsta: " << u3.varsta << ", Nr. Conexiuni: " << u3.nrConexiuni << endl;
	if (u3.istoricConexiuniSecunde != nullptr) {
		cout << "Istoric U3 (secunde): ";
		for (int i = 0; i < u3.nrConexiuni; i++) {
			cout << u3.istoricConexiuniSecunde[i] << " | ";
		}
		cout << endl;
	}

	cout << "Functie statica: Contor utilizatori (inainte): " << Utilizator::contorUtilizatori << endl;
	Utilizator::reseteazaContorUtilizatori();
	cout << "Functie statica: Contor utilizatori (dupa reset): " << Utilizator::contorUtilizatori << endl;
	cout << endl;

	cout << "--- TESTARE CLASA BROWSER ---" << endl;

	Browser b1;
	cout << "B1 (default): ID=" << b1.idBrowser << ", Nume: " << b1.nume << ", Versiune: " << b1.versiune << endl;

	Browser b2("Chrome", 105.0);
	cout << "B2 (2 params): ID=" << b2.idBrowser << ", Nume: " << b2.nume << ", Versiune: " << b2.versiune << endl;

	Browser b3("Firefox", 104.5, "Mozilla Foundation");
	cout << "B3 (3 params): ID=" << b3.idBrowser << ", Nume: " << b3.nume << ", Versiune: " << b3.versiune;
	if (b3.companieProducatoare != nullptr) {
		cout << ", Companie: " << b3.companieProducatoare << endl;
	}
	else {
		cout << endl;
	}

	cout << "Functie statica: Motor cautare default: " << Browser::getMotorCautareDefault() << endl;
	cout << "Functie statica: Nr. browsere create: " << Browser::nrBrowsereInstalate << endl;
	cout << endl;


	return 0;
}