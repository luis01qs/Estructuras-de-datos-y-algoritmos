# include <bits/stdc++.h>

using namespace std;

int main()
{
    long double x = 10000;
    long double v = (x-1)/4;

    int n = 1000;
    vector<long double> A(n), B(n);
    A[0] = 0;
    A[1] = v;
    B[0] = 1;
    B[1] = 1;

    cout << A[0]/B[0] << endl;
    cout << A[1]/B[1] << endl;
    for(int i=2;i<=n;++i)
    {
        A[i] = A[i-1]+v*A[i-2];
        B[i] = B[i-1]+v*B[i-2];
        cout << i << " -> ";
        cout << 1 + 2*A[i]/B[i] << endl;

        if(abs(1+2*A[i]/B[i] - (1+2*A[i-1]/B[i-1])) < 0.000001) break;
    }
}