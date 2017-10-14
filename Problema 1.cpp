#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Cub {
	private:
		int latura;
		int culoare;
		bool isAdded;

	public: 
		Cub(int latura, int culoare) {
			this->latura = latura;
			this->culoare = culoare;
			this->isAdded = false;
		}

		int GetCuloare() {
			return this->culoare;
		}

		int GetLatura() {
			return this->latura;
		}
};
std::vector<Cub> cuburi;
std::vector<Cub> turn;

bool cmd(const Cub cub1, const Cub cub2)
{
	Cub a(cub1);
	Cub b(cub2);

	int l1 = a.GetLatura();
	int l2 = b.GetLatura();

	if (l1 != l2)
		return l1 > l2;
	return l1 < l2;
}

void citireCuburi(int nrCuburi)
{
	for (int i = 0; i < nrCuburi; i++) {
		int culoare;
		int latura;

		cout << "Latura: ";
		cin >> latura;

		cout << "Culoare: ";
		cin >> culoare;
		cout << endl;

		Cub cub(latura, culoare);
		cuburi.push_back(cub);
	}
}

void afisareTurn(std::vector<Cub> turn)
{
	for (int i = 0; i < turn.size(); i++)
		cout << "Latura: "
		<< turn[i].GetLatura()
		<< endl
		<< "Culoare: "
		<< turn[i].GetCuloare();
}

void construiesteTurn()
{
	while (cuburi.size()) {
		bool wasFound = false;

		for (int i = 0; i < cuburi.size(); i++) {
			if (cuburi[i].GetCuloare() != turn[turn.size() - 1].GetCuloare()) {
				turn.push_back(cuburi[i]);
				cuburi.erase(cuburi.begin() + i);
				wasFound = true;
			}
		}

		if (!wasFound)
			break;
	}
}

int main()
{
	int nrCulori;
	int nrCuburi;

	cout << "Nr Cuburi: ";
	cin >> nrCuburi;
	cout << "Nr Culori: ";
	cin >> nrCulori;

	citireCuburi(nrCuburi);

	sort(cuburi.begin(), cuburi.end(), cmd);

	turn.push_back(cuburi[0]);
	cuburi.erase(cuburi.begin());

	construiesteTurn();

	afisareTurn(turn);

	system("pause");
	return 0;
}
