#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Library {
public:
	int N, T, M;
	vector<int> B;
};

class Input {
public:
	int B, L, D;
	vector<int> S;
	vector<Library> libs;
};

Input load_input() {
	Input I;
	cin >> I.B >> I.L >> I.D;
	for (int i = 0; i < B; i++) {
		int s;
		cin >> s;
		I.S.push_back(s);
	}
	for (int i = 0; i < L; i++) {
		Library L;
		for (int j = 0; j < L; j++) {
			cin >> L.N >> L.T >> L.M;
			for (int k = 0; k < L.N; k++) {
				int id;
				cin >> id;
				L.B.push_back(id);
			}
		}
		I.libs.push_back(L);
	}
	return I;
}