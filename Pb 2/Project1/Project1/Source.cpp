#include<iostream>
#include<vector>

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

int main()
{
	int nrTexte;

	cout << "Nr texte: ";
	cin >> nrTexte;


	return 0;
}