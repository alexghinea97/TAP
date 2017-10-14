#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Activitate
{
	int profit;
	int timpLimita;

public:
	Activitate(int profit, int timpLimita)
	{
		this->profit = profit;
		this->timpLimita = timpLimita;
	}

	int GetTimpLimita()
	{
		return this->timpLimita;
	}

	int GetProfit()
	{
		return this->profit;
	}
};
std::vector<Activitate> activitati;
std::vector<Activitate> activitatiCuProfitMaxim;

void citesteActivitati(int nrActivitati)
{
	for (int i = 0; i < nrActivitati; i++) {
		int profit;
		int timpLimita;

		cout << "Profit: ";		cin >> profit;
		cout << "Timp limita: "; cin >> timpLimita;
		Activitate activitateNoua(profit, timpLimita);
		activitati.push_back(activitateNoua);
	}
}

bool cmd(const Activitate act2, const Activitate act1)
{
	Activitate a(act1);
	Activitate b(act2);

	int t1 = a.GetTimpLimita();
	int t2 = b.GetTimpLimita();

	int p1 = a.GetProfit();
	int p2 = b.GetProfit();

	if (t1 != t2)
		return t1 > t2;
	return p1 < p2;
}

void afisareActivitati(std::vector<Activitate> activitati)
{
	for (int i = 0; i < activitati.size(); i++) {
		cout << "Profit: " << activitati[i].GetProfit() << endl;
		cout << "Timp Limita: " << activitati[i].GetTimpLimita() << endl;
	}
}

int main()
{
	int nrActivitati;
	cout << "Nr Activitati: ";
	cin >> nrActivitati;

	citesteActivitati(nrActivitati);

	sort(activitati.begin(), activitati.end(), cmd);

	afisareActivitati(activitati);
	system("pause");
	return 0;
}
