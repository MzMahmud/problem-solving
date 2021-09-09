#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING n as parameter.
 */
bool isPermutationDivibleBy8Below1000(string numStr) {
    sort(numStr.begin(), numStr.end());
    int n;
    do {
        n = stoi(numStr);
        if (n % 8 == 0)
            return true;
    } while (next_permutation(numStr.begin(), numStr.end()));
    return false;
}

bool isPermutationDivibleBy8(const string &numStr) {
    if (numStr.length() <= 3)
        return isPermutationDivibleBy8Below1000(numStr);

    for (int i = 0; i < numStr.length(); ++i) {
        for (int j = i + 1; j < numStr.length(); ++j) {
            for (int k = j + 1; k < numStr.length(); ++k) {
                char str[4] = {};
                str[0]      = numStr[i];
                str[1]      = numStr[j];
                str[2]      = numStr[k];
                if (isPermutationDivibleBy8Below1000(str))
                    return true;
            }
        }
    }
    return false;
}

string solve(string n) { return isPermutationDivibleBy8(n) ? "YES" : "NO"; }

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n;
        getline(cin, n);

        string result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end());

    return s;
}
