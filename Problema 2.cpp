#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Text
{
	int lungime;
	int frecventa;

public:
	Text(int lungime, int frecventa)
	{
		this->lungime = lungime;
		this->frecventa = frecventa;
	}

	int getLungime()
	{
		return this->lungime;
	}

	int getFrecventa()
	{
		return this->frecventa;
	}
};
std::vector<Text> texte;
std::vector<vector<Text>> benzi(100);

void citireTexte(int nrTexte)
{
	for (int i = 0; i < nrTexte; i++) {
		int lungime, frecventa;
		cout << "Lungime: ";
		cin >> lungime;
		cout << "Frecventa: ";
		cin >> frecventa;

		Text t(lungime, frecventa);
		texte.push_back(t);
	}
}

void afisareTexte()
{
	cout << endl;
	cout << "Asezarea textelor este: " << endl;
	for (int i = 0; i < texte.size(); i++)
	{
		cout << "\tLungime: " << texte[i].getLungime() << endl;
		cout << "\tFrecventa: " << texte[i].getFrecventa() << endl;
		cout << endl;
	}
}

bool cmd(const Text t1, const Text t2)
{
	Text a(t1);
	Text b(t2);

	int l1 = a.getLungime();
	int l2 = b.getLungime();

	int f1 = a.getFrecventa();
	int f2 = b.getFrecventa();

	if (l1 != l2)
		return l1 < l2;
	return f1 > f2;
}

void afisareBenzi(int nrBenzi)
{
	cout << endl;
	for (int i = 0; i < nrBenzi; i++)
	{
		cout << "Banda " << i << ": " << endl;
		for (int j = 0; j < benzi[i].size(); j++)
		{
			cout << "\tLungime: " << benzi[i][j].getLungime() << endl;
			cout << "\tFrecventa: " << benzi[i][j].getFrecventa() << endl;
		}
	}
}

void construiesteBenzi(int nrBenzi)
{
	int bandaActuala = 0;
	while (texte.size())
	{
		benzi[bandaActuala % nrBenzi].push_back(texte[0]);
		bandaActuala++;
		texte.erase(texte.begin());
	}
}

int main()
{
	int nrTexte, nrBenzi;

	cout << "Nr texte: ";
	cin >> nrTexte;

	citireTexte(nrTexte);
	//punctul a
	sort(texte.begin(), texte.end(), cmd);

	afisareTexte();

	//punctul b
	cout << "Nr benzi: ";
	cin >> nrBenzi;

	construiesteBenzi(nrBenzi);

	afisareBenzi(nrBenzi);

	system("pause");

	return 0;
}
