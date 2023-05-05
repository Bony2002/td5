using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <tuple>

void pagos(vector<int> precios,vector<int> dias, int i, int stocks,int ganancia,int &mayorganancia,vector<int> &cyv){
    //casos base
    int n=precios.size();
    if(i=n){
        if(ganancia>mayorganancia){
            mayorganancia=ganancia;
            cyv=dias;
        }
    }
    else if(i<n){
        if(stocks==n-i){
            vector<int> vdias=dias;
            vdias[i]=-1;
            pagos(precios,dias,i+1,stocks-1,ganancia+precios[i],mayorganancia,cyv);//vendo todo lo que me queda
        }
        else{
            if(stocks>0){
                vector<int> vdias=dias;
                vdias[i]=-1;
                pagos(precios,dias,i+1,stocks-1,ganancia+precios[i],mayorganancia,cyv);//vendo 
            }
            pagos(precios,dias,i+1,stocks,ganancia,mayorganancia,cyv);//No compro nada
            vector<int> cdias=dias;
            cdias[i]=1;
            pagos(precios,dias,i+1,stocks+1,ganancia-precios[i],mayorganancia,cyv);//Compro una
        }

    }


}









