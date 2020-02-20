#include <vector>

using namespace std;

class LibraryOut {
	int Y, K;
	vector<int> books;
}

class Output {
	int A;
	vector<LibraryOut> L;
}

void print_output(Output O) {
	cout << O.A << '\n';
	for (int i = 0; i < O.A; i++) {
		LibraryOut L = O.L[i];
		cout << L.Y << L.K;
		for (int j = 0; j < L.K; j++) {
			cout << L.books[i] << " ";
		}
		cout << "\n";
	}
}
