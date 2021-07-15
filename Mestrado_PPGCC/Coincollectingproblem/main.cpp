/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void imprimeresposta( vector<int> &vect)
    {
        for (int i=0; i< 3; i++)
        {
          cout<<vect[i]<<endl;
        }
    }

int verificatrocodisponivel(int trocodisponivel, vector<vector<int>> &vect)
    {

        int dinheirototal=0;
        for (int i=0; i< 3; i++)
        {
          dinheirototal= vect[2][i]+dinheirototal;
        }
        if(trocodisponivel>dinheirototal){
                cout<<"Verificamos e nao ha dinheiro suficiente para o troco \n";
                return 1;
        }
        if(trocodisponivel<dinheirototal){
                cout<<"ha dinheiro suficiente para o troco \n";
                return 0;
        }


    }

int retiramoeda(int troconecessario,  vector<vector<int>> &caixa, int quantdemoeda,vector<int> &resposta )
    {

        if(troconecessario==0 || quantdemoeda<0){
            return 0;
        }

        int verificamoeda=troconecessario/caixa[0][quantdemoeda];

        if(verificamoeda>0){


            if (caixa[1][quantdemoeda]>0){

                troconecessario=troconecessario-caixa[0][quantdemoeda];
                caixa[1][quantdemoeda]=caixa[1][quantdemoeda]-1;
                resposta[quantdemoeda]=resposta[quantdemoeda]+1;
                retiramoeda( troconecessario,caixa, quantdemoeda,resposta);
            }

            if(caixa[1][quantdemoeda]==0){

            quantdemoeda=quantdemoeda-1;
            retiramoeda( troconecessario,caixa, quantdemoeda,resposta);
            }
        }
        if(verificamoeda<=0){

            quantdemoeda=quantdemoeda-1;
            retiramoeda( troconecessario,caixa, quantdemoeda,resposta);
        }




    }

int main()
{
    vector<vector<int>> caixa = { {1, 5, 25}, {16, 8, 10}, {16, 40, 250}};
    vector<int> quantidadedetroco = { 0, 0, 0};
    int dinheirototal=0;
    for (int i=0; i< 3; i++)
        {
          dinheirototal= caixa[2][i]+dinheirototal;
        }
    cout<<"Voce tem um total de troco="<<dinheirototal<<endl;
    cout<<"\n";
    cout<< "Digite o troco em centavos" << endl;

    int troco;
    cin>>troco;


    int naotemmoeda=verificatrocodisponivel(troco,caixa);
    if(naotemmoeda==1)cout<<"\n nao existe moeda disponivel para fazer o troco \n";

    retiramoeda(troco,caixa,2,quantidadedetroco);
    imprimeresposta(quantidadedetroco);
    return 0;
}
