# include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("prueba.txt", "r", stdin);

    int n = 100;
    //cin>>n;

    vector<double> a(n+1), b(n+1);
    for(int i=1;i<=n;++i) a[i] = 1;
    for(int i=1;i<=n;++i) b[i] = 6;

    vector<double> A(n+1), B(n+1);
    
    A[0] = 0;
    A[1] = a[1];
    B[0] = 1;
    B[1] = b[1];

    for(int i=2;i<=n;++i)
    {
        A[i] = b[i]*A[i-1]+a[i]*A[i-2];
        B[i] = b[i]*B[i-1]+a[i]*B[i-2];
        cout << A[i]/B[i] << endl;
    }

    return 0;
}