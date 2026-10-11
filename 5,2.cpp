// Лабораторна робота № 5.2

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |" << setw(10) << "ln(1-x)" << " |"
        << setw(10) << "S" << " |" << setw(5) << "n" << " |" << endl;
    cout << "-----------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        s = S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << log(1 - x) << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "-----------------------------------------" << endl;
    return 0;
}

double S(const double x, const double eps, int& n, double s)
{
    n = 1;
    double a = -x;      // перший доданок a1 = -x
    s = a;
    while (abs(a) >= eps)
    {
        n++;
        a = A(x, n, a);
        s += a;
    }
    return s;
}

double A(const double x, const int n, double a)
{
    double R = x * (n - 1) / n;   // a(n) = a(n-1) * x * (n-1)/n
    a *= R;
    return a;
}
