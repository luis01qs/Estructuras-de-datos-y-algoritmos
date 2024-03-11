# include <iostream>

float* procedimiento(int n)
{
    float *a;
    a = new float[n];

    for(int i=0;i<n;++i)
    {
        a[i] = i;
    }

    return a;
}

int main()
{
    int n = 10;
    float *a = procedimiento(n);
    for(int i=0;i<n;++i) std::cout << a[i] << " ";

    return 0;
}