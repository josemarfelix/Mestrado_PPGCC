#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &sol,int n){
    cout<<endl;
    for(int j = 0; j < n; j++){
			 if(sol[j] == 0){
                return;
            }
            cout << sol[j] << " ";

		}
		cout <<endl;
}

int custo(vector<int> &sol,int n){
   int novo_valor=0;
   for(int i=0;i<n;i++){
      novo_valor+=sol[i];
    }
    return novo_valor;
}
void backtracking(vector<int> v,int n, vector<int> & sol, int pos,int valor){

    if(custo(sol,n)<valor){
      print(sol,n);
    }
         for(int i=pos;i<n;i++){
                sol[pos] = v[i];
                backtracking(v,n, sol, pos+1,valor);
                sol[pos] = 0;
	    }
}

int main(){
	vector<int> v {1, 2, 3, 4};
	int n = v.size();
	vector<int> sol{0,0,0,0};
    int valor =5;
	backtracking(v,n,sol,0,valor);

	return 0;
}
