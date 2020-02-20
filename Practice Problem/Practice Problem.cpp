#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct pizza
{
	int slices;
	int index;
	pizza(int slices, int index) : slices(slices), index(index) {}
};

int main()
{
	string file_name = "b_small";
	int m, n;

	ifstream input(file_name + ".in", ios::in);
	input >> m >> n;
	vector<struct pizza> slice_vector;
	for (int i = 0; i < n; i++)
	{
		int slices;
		input >> slices;
		slice_vector.push_back(pizza(slices, i));
	}
	input.close();

	sort(slice_vector.begin( ), slice_vector.end( ), [ ](const pizza left, const pizza right)
	{
   	return left.slices < right.slices;
	});

	int counter = 0, k = 0;
	for (int i = 0; (i < n) && (counter < m); i++)
	{
		counter += slice_vector[i].slices;
		k++;
	}
	k--;


	ofstream output(file_name + ".out", ios::out);
	output << k << endl;
	for (int i = 0; i < k; i++)
	{
		output << slice_vector[i].index << " ";
	}
	output.close();
}
