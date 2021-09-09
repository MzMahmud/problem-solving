#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */
int operator%(const string &number, int m) {
    int powerOfTen = 1;
    int remainder  = 0;
    for (int i = number.length() - 1; i >= 0; --i) {
        int digit  = (number[i] - '0') % m;
        remainder  = (remainder + (digit * powerOfTen) % m) % m;
        powerOfTen = (powerOfTen * 10) % m;
    }
    return remainder % m;
}

string solve(int n) {
    queue<string> q;
    q.push("9");
    while (!q.empty()) {
        const string &front = q.front();
        if (front % n == 0)
            return front;
        q.pop();
        q.push(front + "0");
        q.push(front + "9");
    }
    return "-1";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

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
