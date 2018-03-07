#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

string word;
vector<string> siruriBinare;
int l[500];

void citire(int nrSiruriBinare)
{
	siruriBinare.push_back("0");
	siruriBinare.push_back("1");

	for (int i = 0; i < nrSiruriBinare; i++) {
		string sir;
		cin >> sir;
		siruriBinare.push_back(sir);
	}

	cin >> word;
}

int main()
{
	int nrSiruriBinare;
	cin >> nrSiruriBinare;
	citire(nrSiruriBinare);

	vector <string> res;

	for (int i = 1; i <= word.size(); i++)
	{
		int min = INT_MAX;
		string subsirBinar;

		for (int j = 0; j < siruriBinare.size(); j++)
			if (siruriBinare[j].size() <= i)
			{
				string substr = word.substr(i - siruriBinare[j].size(), siruriBinare[j].size());

				if (substr.compare(siruriBinare[j]) == 0)
					if (l[i - siruriBinare[j].size()] < min)
					{
						min = l[i - siruriBinare[j].size()];
						subsirBinar = siruriBinare[j];
					}
			}

		res.push_back(subsirBinar);
		l[i] = min + 1;
	}

	int wordSize = word.size();
	stack<string> st;
	while (wordSize - 1 >= 0)
	{
		st.push(res[wordSize - 1]);
		wordSize = wordSize - res[wordSize - 1].size();
	}

	cout << endl << st.top();
	st.pop();
	while (!st.empty())
	{
		cout << "+" << st.top();
		st.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}

/*
3
01
010
1001010010011
*/
