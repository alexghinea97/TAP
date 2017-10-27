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

int citesteActivitati(int nrActivitati)
{
	int timpMaxim = 0;
	for (int i = 0; i < nrActivitati; i++) {
		int profit;
		int timpLimita;

		cout << "Profit: ";		
		cin >> profit;

		cout << "Timp limita: "; 
		cin >> timpLimita;

		if (timpLimita > timpMaxim)
			timpMaxim = timpLimita;

		Activitate activitateNoua(profit, timpLimita);
		activitati.push_back(activitateNoua);
	}

	return timpMaxim;
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
		return t1 < t2;
	return p1 < p2;
}

void afisareActivitati(std::vector<Activitate> activitati)
{
	cout << "\n";
	for (int i = 0; i < activitati.size(); i++) {
		cout << "Profit: " << activitati[i].GetProfit() << endl;
		cout << "Timp Limita: " << activitati[i].GetTimpLimita() << endl;
	}
}

void construiesteProfitMaxim(std::vector<Activitate> activitati)
{
	int timpActual = activitati[0].GetTimpLimita();
	while (timpActual > 0)
	{
		activitatiCuProfitMaxim.push_back(activitati[0]);
		activitati.erase(activitati.begin());
		timpActual--;
	}
}

int main()
{
	int nrActivitati;
	int timpMaxim;
	cout << "Nr Activitati: ";
	cin >> nrActivitati;

	timpMaxim = citesteActivitati(nrActivitati);

	sort(activitati.begin(), activitati.end(), cmd);

	afisareActivitati(activitati);

	construiesteProfitMaxim(activitati);

	afisareActivitati(activitatiCuProfitMaxim);

	system("pause");
	return 0;
}
