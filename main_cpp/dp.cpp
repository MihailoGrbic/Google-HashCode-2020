#include "pch.h"
#include "input.h"


using namespace std;

#ifdef DEBUG
    #define D(X) X
#else
    #define D(X)
#endif

class dp_lib
{
public:
	int signtime, lifetime;
	double average_output;
};


int main()
{
    string filename = "a_example";

    Input I = load_input(filename);

	vector<dp_lib> dp_libs;
	for (auto lib : I.libs)
	{
		dp_lib new_lib;
		new_lib.signtime = lib.T;
		new_lib.lifetime = lib.N / lib.M;
		if (new_lib.lifetime * lib.M < lib.N) new_lib.lifetime++;

		long long sum = 0;
		for (int book : lib.B) sum += I.S[book];
		double average_book = (double)sum / lib.B.size();
		new_lib.average_output = average_book * lib.M;
	}

    return 0;
}
