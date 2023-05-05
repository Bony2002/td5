using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <tuple>
#include <algorithm>




int sumas_distintas(int n){
    vector<int> memoria(n+1,0);
    memoria[1]=1;
    memoria[2]=1;
    memoria[3]=2;
    memoria[4]=4;
    int i=0;
    while(i<=n){
        memoria[i]=memoria[i-4]+memoria[i-3]+memoria[i-1];
        i+=1;
    }
    return memoria[n];
}
int valormax(vector<int> v){
    int i=0;
    int max=0;
    while(i<v.size()){
        if(v[i]>max){
            max=v[i];
        }
        i+=1;
    }
    return max;
}
int barras(vector<int> precios,vector<int> longitudes,vector<int> &memoria,int longitud){
    if(memoria[longitud]!=-1){
        return memoria[longitud];
    }
    if(longitud==0){
        return 0;
    }
    vector<int> aux={};
    int i=0;
    int temp=0;
    while(i<precios.size()){
        if((longitud-longitudes[i])>=0){
            temp=barras(precios,longitudes,memoria,longitud-longitudes[i])+precios[i];
            aux.emplace_back(temp);
        }
        i+=1;
    }
    int final= valormax(aux);
    memoria[longitud]=final;
    return final;
}

void reconstruccion(vector<int> precios, vector<int> longitudes, int precio,int n,int i,vector<int> actuales,vector<int> &solucion){
    if(precio==0 && n==0){
        solucion=actuales;
    }
    else{
        if(n>0 && precio>0 && i<precios.size()){
            vector<int> aux=actuales;
            aux.emplace_back(longitudes[i]);
            reconstruccion(precios,longitudes,precio-precios[i],n-longitudes[i],i,aux,solucion);
            reconstruccion(precios,longitudes,precio,n,i+1,actuales,solucion);
        }
    }
}
int main(){
    vector<int> longitudes = {2,3,5};
    vector<int> precios = {80,140,170};
    int n = 10;
    vector<int> memo(n+1, -1);
    int precio=barras(precios, longitudes, memo, n);
    cout << precio<< endl;
    vector<int> solucion;
    reconstruccion(precios,longitudes,precio,n,0,{},solucion);
    for (int i:solucion){
        cout<<i<<endl;
    }
}

