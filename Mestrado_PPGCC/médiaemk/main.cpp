#include <iostream>
#include <bits/stdc++.h>
using namespace std;

float calculamedia(vector<int> &vetor, int num){
    int cont=0;
    float media=0;
    for(int i=0; i<4;i++){
        if(vetor[i]<num){
            media=vetor[i]+media;
            cont=cont+1;
    }
    }
    media=media/cont;
    return media;
}

int soma(vector<int> &solucao){
    int resultado=0;
    for(int i=0; i<4;i++){
        resultado=solucao[i]+resultado;
    }
    return resultado;
}
void print(vector<int> &solucao){
    for(int i=0;i<4;i++){
        cout<<solucao[i]<<endl;
        if(i==3)cout<<endl;
    }
}

void subconjunto(vector<int> vetor, int tamanho, vector<int> &solucao,int pos, int valor){

    if(soma(solucao)<valor){
        print(solucao);
    }

    for(int i=pos; i<4;i++){
        solucao[pos]=vetor[i];
        subconjunto(vetor,tamanho,solucao,pos+1,valor);
        solucao[pos]=0;
        pos=pos+1;
    }
}


int main()
{   vector <int> vetor;
    for(int i=0;i<4;i++){
        int entra;
        cout<<"insira 4 valores para o vetor"<<endl;
        cin>>entra;
        vetor.push_back(entra);
    }
    cout<<"entre com um numero para calcular a media abaixo"<<endl;
    int num;
    cin>>num;
    //cout << "media: " << calculamedia(vetor,num)<< endl;

    cout<<endl<<"o subconjuntos desse vetor sao"<<endl;

    vector <int> solucao={0,0,0,0};
    subconjunto(vetor,vetor.size(),solucao,0, 5);

    return 0;
}
