#include "output.h"
#include "input.h"
#include <iostream>
#include <algorithm>

using namespace std;

Output book_placement(Input I, vector<int> lib_order) {
    // Number of books each library can scan
    vector<int> books_can_scan;
    int current_day = 0;
    cout << I.libs[0].T << " ";
    cout << I.libs[1].T << "\n";
    for (int lib_id : lib_order) {
        Library &L = I.libs[lib_id];
        int bcs = I.D - L.T - current_day;
        bcs *= L.M;
        current_day += L.T;
        books_can_scan.push_back(bcs);
        cout << bcs << " ";
        // Sort books by price for later
        sort(L.B.begin(), L.B.end(),
            [&](const int &a, const int &b) -> bool {
                return I.S[a] > I.S[b];
            });
    }

    // Temporary print
    cout << endl;
    for (int lib_id : lib_order) {
        Library L = I.libs[lib_id];
        cout << "Lib " << lib_id << ": ";
        for (int book_id : L.B) {
            cout << "(" << book_id << ", ";
            cout << I.S[book_id] << "), ";
        }
        cout << "\n";
    }
    /// Temporary print

    set<int> used_books;
    for (int i = 0; i < books_can_scan)
}