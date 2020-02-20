#include "output.h"
#include "input.h"
#include <iostream>
#include <vector>
#include <set>

int score(Input I, Output O) {
    set<int> scanned_books;
    int current_day = 0;
    for (int i = 0; i < O.A; i++) {
        LibraryOut Lo = O.L[i];
        Library L = I.libs[Lo.Y];
        for (int j = 0; j < min(Lo.K, I.D - current_day); j++) {
            scanned_books.insert(Lo.books[j]);
        }
        current_day += L.T;
    }
    int score = 0;
    for (int book_id : scanned_books) {
        score += I.S[book_id];
    }
    return score;
}