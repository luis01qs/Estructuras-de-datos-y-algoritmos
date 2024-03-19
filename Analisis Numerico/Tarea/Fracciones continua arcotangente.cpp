# include <bits/stdc++.h>

using ld = long double;
using namespace std;

int main()
{
    ld x = 1/sqrt(3);

    int n = 100;
    vector<ld> A(n), B(n), a(n), b(n);

    a[1] = x;
    b[1] = 1;

    A[0] = 0;
    A[1] = a[1];
    
    B[0] = 1;
    B[1] = b[1];

    ld c = x*x;
    for(int i=2;i<n;++i)
    {
        a[i] = -(2*i-3)*(2*i-3)*c;
        b[i] = (pow(-1, i))*((2*i-3)*c-(2*i-1));

        A[i] = b[i]*A[i-1]+a[i]*A[i-2];
        B[i] = b[i]*B[i-1]+a[i]*B[i-2];

        //cout << a[i] << " " << b[i] << endl;

        cout << i << " -> ";
        cout << A[i]/B[i] << endl;
    }

    return 0;
}