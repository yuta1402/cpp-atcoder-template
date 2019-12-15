#ifndef STRING_HPP
#define STRING_HPP

#include <vector>
#include <string>

using namespace std;

/*!
@fn z_algorithm
@brief 長さNの文字列Sについて, S[0:N-1]とS[i:N-1] (0 < i < N)の最長共通接頭辞の長さを求める
*/
vector<int> z_algorithm(const string& s)
{
    const int n = s.size();
    vector<int> z(n);
    z[0] = n;

    int i = 1;
    int j = 0;
    while (i < n) {
        while (i+j < n && s[j] == s[i+j]) {
            ++j;
        }
        z[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }

        int k = 1;
        while (i+k < n && k+z[k] < j) {
            z[i+k] = z[k];
            ++k;
        }
        i += k;
        j -= k;
    }

    return z;
}

#endif
