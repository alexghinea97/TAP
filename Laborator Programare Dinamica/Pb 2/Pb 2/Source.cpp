#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Traseu {

public:
	int linie;
	int coloana;

	Traseu(int linie, int coloana)
	{
		this->linie = linie;
		this->coloana = coloana;
	}
};

int matPrinc[100][100];
int matSec[100][100];

void afisareTraseu(vector<Traseu> traseu)
{
	for (int i = 0; i < traseu.size(); i++)
		cout << traseu[i].linie + 1 << " " << traseu[i].coloana + 1 << endl;
}

void constTraseu(int mat[100][100], int nrLinii, int nrColoane)
{
	vector<Traseu> traseu;
	Traseu t(nrLinii - 1, 0);
	traseu.push_back(t);

	int iStart = nrLinii - 1;
	int jStart = 0;
	int sum = matPrinc[iStart][jStart];

	while (iStart != 0 || jStart != nrColoane - 1)
	{
		if (mat[iStart - 1][jStart] > mat[iStart][jStart + 1] && iStart != 0) {
			sum += matPrinc[iStart - 1][jStart];

			Traseu t(iStart - 1, jStart);
			traseu.push_back(t);

			iStart--;
		}
		else {
			sum += matPrinc[iStart][jStart + 1];

			Traseu t(iStart, jStart + 1);
			traseu.push_back(t);

			jStart++;
		}
	}

	cout << sum << endl;
	afisareTraseu(traseu);
}

void constMat(int mat[100][100], int nrLinii, int nrColoane)
{
	matSec[0][nrColoane - 1] = mat[0][nrColoane - 1];
	for (int i = nrColoane - 2; i >= 0; i--)
		matSec[0][i] = matSec[0][i + 1] + mat[0][i];
	for (int i = 1; i < nrLinii - 1; i++)
		matSec[i][nrColoane - 1] = matSec[i - 1][nrColoane - 1] + mat[i][nrColoane - 1];

	for (int i = 1; i <= nrLinii; i++)
		for (int j = nrColoane - 2; j >= 0; j--)
			matSec[i][j] = mat[i][j] + max(matSec[i - 1][j], matSec[i][j + 1]);

	constTraseu(matSec, nrLinii, nrColoane);
}

int main()
{
	int nrLinii, nrColoane, mat[100][100];
	cin >> nrLinii >> nrColoane;

	for (int i = 0; i < nrLinii; i++)
		for (int j = 0; j < nrColoane; j++) {
			cin >> mat[i][j];
			matPrinc[i][j] = mat[i][j];
		}

	constMat(mat, nrLinii, nrColoane);

	system("pause");
	return 0;
}