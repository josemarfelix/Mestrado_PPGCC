#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Fib(int n){
    if(n==0 || n==1){
        return 1;
    }

    return Fib(n-1)+Fib(n-2);
}

int main()
{
    cout << "Calcule o n-esimo numero fibonacci. \n -Insira o numero:" << endl;
    int n;
    cin>>n;
    int resposta=Fib(n);
    cout<<resposta<<endl;
    return 0;
}
