#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void imprime(vector <int> respostadetroco, vector<vector<int>> &caixa){
    int trocodisponivel=0;
    for(int i=0;i<3;i++){
        cout<<respostadetroco[i]<<endl;
        trocodisponivel=respostadetroco[i]*caixa[0][i]+trocodisponivel;
    }
    cout<<trocodisponivel<<endl;
}

int calculatroco(int troco, vector<vector<int>> &caixa,vector<int> respostadetroco,int moeda){

    if(moeda<0 || troco<=0){
        cout<<"\n o valor de cada moeda e: \n"<<endl;
        imprime(respostadetroco,caixa);
        return 1;
    }

    int conta=troco/caixa[0][moeda];
    int avalia=caixa[1][moeda]-conta;


    if(avalia<=0){
        troco=troco-(caixa[1][moeda]*caixa[0][moeda]);
        respostadetroco[moeda]=caixa[1][moeda];
        moeda=moeda-1;
        calculatroco(troco,caixa,respostadetroco,moeda);
    }
    if(avalia>0){
        troco=troco-(conta*caixa[0][moeda]);
        respostadetroco[moeda]=conta;
        moeda=moeda-1;
        calculatroco(troco,caixa,respostadetroco,moeda);
    }

}

int main()
{
    vector<vector<int>> caixa = { {1, 5, 25}, {15, 30, 4}, {15, 150, 100}};
    vector<int> respostadetroco = { 0, 0, 0};

    int dinheirototal=0;
    for (int i=0; i< 3; i++)
        {
          dinheirototal= caixa[2][i]+dinheirototal;
        }


    cout<<"O troco disponivel ="<<dinheirototal<<endl;
    cout<<"\n";
    cout<< "Digite o troco em centavos abaixo do troco disponivel" << endl;

    int troco;
    cin>>troco;

    calculatroco(troco,caixa,respostadetroco,2);

    return 0;
}
