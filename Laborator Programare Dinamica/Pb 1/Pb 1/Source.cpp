#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Cub {

public:
	int latura;
	int culoare;
	int inaltimeMaxima;
	int nrTurnuriInaltimeMaxima;
	int indexCubPrecedent;

	Cub(int latura, int culoare)
	{
		this->latura = latura;
		this->culoare = culoare;
		this->inaltimeMaxima = 0;
		this->nrTurnuriInaltimeMaxima = 0;
		this->indexCubPrecedent = 0;
	}
};

vector<Cub> cuburi;

bool cmd(const Cub cub1, const Cub cub2)
{
	Cub a(cub1);
	Cub b(cub2);

	return a.latura < b.latura;
}

void citire(int nrCuburi)
{
	for (int i = 0; i < nrCuburi; i++)
	{
		int latura, culoare;
		cin >> latura >> culoare;

		Cub cub(latura, culoare);
		cuburi.push_back(cub);
	}
}

void calculeazaIntaltimeMaxima()
{
	for (int i = 0; i < cuburi.size(); i++)
	{
		int j = i;
		bool ok = true;
		while (j >= 0 && ok)
		{
			if (cuburi[j].culoare != cuburi[i].culoare && cuburi[i].latura > cuburi[j].latura) {
				cuburi[i].inaltimeMaxima = cuburi[i].latura + cuburi[j].inaltimeMaxima;
				cuburi[i].indexCubPrecedent = j;
				ok = false;
			}
			j--;
		}

		if (ok)
			cuburi[i].inaltimeMaxima = cuburi[i].latura;
	}
}

void calculeazaNrTurnuriInaltimeMaxima()
{
	for (int i = 0; i < cuburi.size(); i++)
	{
		int j = i - 1;
		bool ok = true;
		while (j >= 0)
		{
			if (ok) {
				if (cuburi[j].culoare != cuburi[i].culoare && cuburi[j].inaltimeMaxima + cuburi[i].latura == cuburi[i].inaltimeMaxima) {
					cuburi[i].nrTurnuriInaltimeMaxima = cuburi[j].nrTurnuriInaltimeMaxima;
					ok = false;
				}
			}
			else {
				if (cuburi[j].culoare != cuburi[i].culoare && cuburi[j].inaltimeMaxima + cuburi[i].latura == cuburi[i].inaltimeMaxima)
					cuburi[i].nrTurnuriInaltimeMaxima++;
			}

			j--;
		}

		if (ok)
			cuburi[i].nrTurnuriInaltimeMaxima = 1;
	}
}

int getIndexHMax()
{
	int hMax = 0;
	int IndexHMax = 0;

	for (int i = 0; i < cuburi.size(); i++)
		if (cuburi[i].inaltimeMaxima > hMax) {
			hMax = cuburi[i].inaltimeMaxima;
			IndexHMax = i;
		}

	return IndexHMax;
}

int getNrturnuriInaltimeMaxima()
{
	int hMax = 0;
	int nrTurnuriHMax = 0;

	for (int i = 0; i < cuburi.size(); i++)
		if (cuburi[i].inaltimeMaxima > hMax)
			hMax = cuburi[i].inaltimeMaxima;

	for (int i = 0; i < cuburi.size(); i++)
		if (cuburi[i].inaltimeMaxima == hMax && cuburi[i].nrTurnuriInaltimeMaxima > nrTurnuriHMax)
			nrTurnuriHMax = cuburi[i].nrTurnuriInaltimeMaxima;

	return nrTurnuriHMax;
}

int main()
{
	int nrCuburi, nrCulori, nrTurnuriInaltimeMaxima;
	cin >> nrCuburi >> nrCulori;

	citire(nrCuburi);
	sort(cuburi.begin(), cuburi.end(), cmd);
	calculeazaIntaltimeMaxima();
	calculeazaNrTurnuriInaltimeMaxima();

	cout << endl << getNrturnuriInaltimeMaxima() << endl;

	int index = getIndexHMax();

	while (index != 0)
	{
		cout << cuburi[index].latura << " " << cuburi[index].culoare << endl;
		index = cuburi[index].indexCubPrecedent;
	}

	system("pause");
	return 0;
}

/*

8 4
8 3
10 2
9 2
10 1
8 1
8 4
5 2
6 2

*/