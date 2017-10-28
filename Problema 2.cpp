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
	for (int i = 0; i < texte.size(); i++)
	{
		cout << "Lungime: " << texte[i].getLungime() << endl;
		cout << "Frecventa: " << texte[i].getFrecventa() << endl;
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
	return f1 < f2;
}

int main()
{
	int nrTexte;

	cout << "Nr texte: ";
	cin >> nrTexte;

	citireTexte(nrTexte);

	sort(texte.begin(), texte.end(), cmd);

	afisareTexte();

	system("pause");

	return 0;
}
