#include "pch.h"
#include "input.h"
#include <algorithm> 


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
	bool used;
	int index;
};


int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that  
// can be put in a knapsack of capacity W  
int knapSack(int W, vector<dp_lib> dp_libs, int n)
{

	// Base Case  
	if (n == 0 || W == 0)
		return 0;

	int wt = dp_libs[n - 1].signtime;
	double val = dp_libs[n - 1].average_output * min(W - wt, dp_libs[n - 1].lifetime);


	// If weight of the nth item is more  
	// than Knapsack capacity W, then  
	// this item cannot be included 
	// in the optimal solution  
	if (wt > W)
		return knapSack(W, dp_libs, n - 1);

	// Return the maximum of two cases:  
	// (1) nth item included  
	// (2) not included  
	else return max(val + knapSack(W - wt, dp_libs, n - 1),
		knapSack(W, dp_libs, n - 1));
}

int K[10001][10001];
// Prints the items which are put in a knapsack of capacity W 
void printknapSack(int W, vector<dp_lib> dp_libs, int n)
{
	int i, w;

	vector<int> wt;
	vector<int> val;
	for (int i = 0; i < dp_libs.size(); i++)
	{
		wt.push_back(dp_libs[i].signtime);
		val.push_back(dp_libs[i].average_output * min(W - wt[i], dp_libs[i].lifetime));
	}

	// Build table K[][] in bottom up manner 
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
					K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	// stores the result of Knapsack 
	int res = K[n][W];
	printf("%d\n", res);

	w = W;
	for (i = n; i > 0 && res > 0; i--) {

		// either the result comes from the top 
		// (K[i-1][w]) or from (val[i-1] + K[i-1] 
		// [w-wt[i-1]]) as in Knapsack table. If 
		// it comes from the latter one/ it means  
		// the item is included. 
		if (res == K[i - 1][w])
			continue;
		else {

			// This item is included. 
			cout << dp_libs[i - 1].index << " ";

			// Since this weight is included its  
			// value is deducted 
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
}

int main()
{
    string filename = "b_read_on";

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
		new_lib.index = lib.index;
		dp_libs.push_back(new_lib);
	}
	 
	int W = I.D;
	int n = I.L;
	printknapSack(W, dp_libs, n);

    return 0;
}
