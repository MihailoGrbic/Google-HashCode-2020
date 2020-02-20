#ifndef INPUT_H
#define INPUT_H


#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Library {
public:
	int N, T, M;
	int index;
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
	for (int i = 0; i < I.B; i++) {
		int s;
		cin >> s;
		I.S.push_back(s);
	}
	for (int i = 0; i < I.L; i++) {
		Library lib;
		input >> lib.N >> lib.T >> lib.M;
		for (int k = 0; k < lib.N; k++) {
		}
		I.libs.push_back(lib);
	}
	return I;
}

#endif // INPUT_H
