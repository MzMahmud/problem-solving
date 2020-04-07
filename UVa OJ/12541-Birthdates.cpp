#include <cstring>
#include <iostream>

using namespace std;

struct Person {
    string name;
    int d, m, y;
    Person() { d = -1; }

    Person &operator=(const Person &other) {
        name = other.name;
        d = other.d;
        m = other.m;
        y = other.y;
        return *this;
    }

    bool operator<(const Person &other) const {
        if (y != other.y)
            return y > other.y;
        if (m != other.m)
            return m > other.m;
        return d > other.d;
    }
};

istream &operator>>(istream &is, Person &p) {
    is >> p.name >> p.d >> p.m >> p.y;
    return is;
}

ostream &operator<<(ostream &os, const Person &p) {
    os << p.name;
    return os;
}

int main() {
    int n;
    cin >> n;
    Person youngest, oldest;
    while (n--) {
        Person p;
        cin >> p;
        if (youngest.d < 0 || p < youngest)
            youngest = p;

        if (oldest.d < 0 || oldest < p)
            oldest = p;
    }
    cout << youngest << endl;
    cout << oldest << endl;
    return 0;
}