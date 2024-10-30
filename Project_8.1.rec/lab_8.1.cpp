#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int CountPairs(char* str, int i) {
    if (strlen(str) < 2 || str[i + 1] == 0) return 0;
    if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n')) {
        return 1 + CountPairs(str, i + 1);
    }
    return CountPairs(str, i + 1);
}

char* ReplacePairs(char* dest, const char* str, char* t, int i) {
    if (str[i + 1] == 0) return dest;

    if ((str[i] == 'n' && str[i + 1] == 'o') || (str[i] == 'o' && str[i + 1] == 'n')) {
        strcat(t, "***");
        return ReplacePairs(dest, str, t + 3, i + 2);
    }
    else {
        *t++ = str[i];
        *t = '\0';
        return ReplacePairs(dest, str, t, i + 1);
    }
}

int main() {
    char str[101];
    cout << "Enter a string:" << endl;
    cin.getline(str, 100);
    cout << "The string contains " << CountPairs(str, 0) << " pairs 'no' or 'on'" << endl;
    char dest[151];
    dest[0] = '\0';
    ReplacePairs(dest, str, dest, 0);
    cout << "Changed string (parameter): " << dest << endl;
    return 0;
}
