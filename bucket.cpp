#include <iostream>
#include <list>
#include <vector>

using namespace std;

int pega_digito(int value, int casa){
    if(casa == 0)
        return value % 10;
    return pega_digito(value / 10, casa - 1);
}

int main(){
    list<int> lista;
    for(int i = 0; i < 20; i++){
        lista.push_back(rand() % 1000);
    }

    vector<list<int>> baldes(10);

    for(int casa = 0; casa < 4; casa++){
        while(!lista.empty()){
            int value = lista.front();
            lista.pop_front();
            baldes[pega_digito(value, casa)].push_back(value);
        }


    for(int balde = 0; balde < 10; balde++){
        while(!baldes[balde].empty()){
            lista.push_back(baldes[balde].front());
            baldes[balde].pop_front();
        }
    }
}

    for(auto x : lista)
        cout << x << " ";
    cout << endl;
    return 0;
}
