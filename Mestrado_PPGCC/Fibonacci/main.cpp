#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Fib(int n){
    vector<int> f;
    f.push_back(0);
    f.push_back(1);
    for(int i=2;i<=n;i++){
        f.push_back(f[i-1]+f[i-2]);
    }
    return f[n];
}

int main()
{
    cout << "Calcule o n-esimo numero fibonacci. \n insira o número" << endl;
    int n;
    cin>>n;
    int resposta=Fib(n);
    cout<<resposta;
    return 0;
}
