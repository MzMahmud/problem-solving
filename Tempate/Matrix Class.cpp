#include <bits/stdc++.h>

using namespace std;

template<class T>
class matrix{
public:
    T **a;
    int n;
    matrix(int _n){
        n = _n;
        a = new T*[n];
        for(int i = 0;i < n;i++)
            a[i] = new T[n];

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                a[i][j] = (T) 0;
            }
        }
    }

    matrix(const matrix<T>& mat){
        n = mat.n;
        a = new T*[n];
        for(int i = 0;i < n;i++)
            a[i] = new T[n];

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                a[i][j] = mat.a[i][j];
            }
        }
    }
    ~matrix(){
        for(int i = 0;i < n;i++)
            delete [] a[i];
        delete [] a;
    }
    matrix<T>& operator=(const matrix<T>& mat){
        if (this == &mat)
            return *this;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                a[i][j] = mat.a[i][j];
            }
        }
        return *this;
    }

    matrix<T> operator+(const matrix<T>& mat){
        matrix<T> ret(mat.n);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                ret.a[i][j] = this->a[i][j] + mat.a[i][j];
            }
        }
        return ret;
    }
    matrix<T> operator-(const matrix<T>& mat){
        matrix<T> ret(mat.n);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                ret.a[i][j] = this->a[i][j] - mat.a[i][j];
            }
        }
        return ret;
    }
    matrix<T> operator%(T m){
        matrix<T> ret(n);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                ret.a[i][j] = this->a[i][j] % m;
            }
        }
        return ret;
    }
    matrix<T> operator*(const matrix<T>& mat){
        matrix<T> ret(n);

        for(int i = 0; i < n;i++)
            for(int j = 0; j < n;j++)
                for(int k = 0; k < n;k++)
                    ret.a[i][j] += a[i][k] * mat.a[k][j];


        return ret;
    }



    void print(){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

template <class T>
matrix<T> power(matrix<T> a,int b){
    if (!b){
        matrix<T> I(a.n);
        for(int i = 0;i < a.n;i++)
            I.a[i][i] = (T)1;
        return I;
    }
    matrix<T> x(a.n);
    x = power(a,b/2);

    x = x*x;

    if(b&1) x = (x*a);
    return x;
}

int main(){
    matrix<int> a(3),b(3),c(3);
    a.print();
    for(int i = 0;i < a.n;i++){
            for(int j = 0;j < a.n;j++){
                a.a[i][j] = i+j+1;
            }
        }
    a.print();
    b = a;
    b.print();
    c = a*b;
    c = c*a;
    c.print();
    a.print();
    c = power(a,4);
    c.print();
    return 0;
}
