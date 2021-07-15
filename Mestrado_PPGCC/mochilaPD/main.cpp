#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int avaliaquantidade(vector<vector<int>> mochila,  int tamanho, int peso){
    vector<vector<int>>verifica ={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    for(int i=1; i<5; i++){

    }
    return 1;

}

int main()
{   vector<vector<int>> mochila ={{1,2,3,4,5},{4,2,5,8,1}};
    vector<vector<int>> verificador={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    int peso=14;
    int tamanho=5;
    avaliaquantidade(mochila,tamanho,peso);
    cout << "Hello world!" << endl;
    return 0;
}
