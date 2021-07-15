#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> &tabuleiro)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf(" %d ", tabuleiro[i][j]);
        printf("\n");
    }
}

bool seguro(vector<vector<int>> &tabuleiro, int linha, int coluna){
    //verifica linha
        for(int verificaI=coluna+1;verificaI<4;verificaI++){
            if(tabuleiro[verificaI][coluna]==1)
                return false;
            }

        for(int verificaI=coluna-1;verificaI>=0;verificaI--){
            if(tabuleiro[verificaI][coluna]==1)
                return false;
            }

    //verifica coluna
        for(int verificaJ=linha+1;verificaJ<4;verificaJ++){
            if(tabuleiro[linha][verificaJ]==1)
                return false;
            }

        for(int verificaJ=linha-1;verificaJ>=0;verificaJ--){
            if(tabuleiro[linha][verificaJ]==1)
                return false;
            }

         //diagonal secundária
        int lin, col;
        for(lin=linha-1, col=coluna+1 ; lin>=0 && col<4; lin--, col++){
            if(tabuleiro[lin][col]==1)
            return false;
        }
        for(lin=linha+1, col=coluna-1 ; lin<4 && col>=0; lin++, col--){
            if(tabuleiro[lin][col]==1)
            return false;
        }

        //diagonal principal
        for( lin=linha+1, col=coluna+1 ; lin<4 && col<4; lin++, col++){
            if(tabuleiro[lin][col]==1)
            return false;
        }
        for(lin=linha-1, col=coluna-1 ; lin>=0 && col>=0; lin--, col--){
            if(tabuleiro[lin][col]==1)
            return false;
        }

        return true;
}


void executar(vector<vector<int>> &tabuleiro, int linha, int coluna){

    if(coluna==4){
    printSolution(tabuleiro);
    system ("pause");
    return ;
    }

    else{
        tabuleiro[linha][coluna]=1;

        bool verifica= seguro(tabuleiro,linha,coluna);

        if(verifica==1){
            executar(tabuleiro,0,coluna+1);
        }

        if(verifica==0){
            tabuleiro[linha][coluna]=0;
            if(linha<4){
                executar(tabuleiro,linha+1,coluna);
            }
        executar(tabuleiro,0,coluna-1);

        }


    }

}

int main()
{
    vector< vector <int>> matriz{{0,0,0,0},
                                {0,0,0,0},
                                {0,0,0,0},
                                {0,0,0,0}};
    matriz[0][0]=1;


    executar(matriz,1,1);



    return 0;
}
