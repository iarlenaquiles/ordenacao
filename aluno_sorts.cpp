
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>
#define TAM 20
#include "../libs/sortview.h"
#include "../libs/player.h"

static SortView sview;
using namespace std;

vector<int> init_bubble(int qtd, int min, int max){
    vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }

    return vet;
}

void bubble(vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam - 1; j++){
            if(vet[j] > vet[j + 1]){
                sview.show(vet, {j, j + 1}, "ry");
                swap(vet[j], vet[j + 1]);
                sview.show(vet, {j, j + 1}, "ry");
            }

        }
    }
}
int bubble_sort(){

    srand(time(NULL));
    my_player->autoplay = true;
    sview.set_bar_view();
    sview.set_thickness(8);

    vector<int> vet = init_bubble(50, 90, 300);
    bubble(vet);
    my_player->wait();
    return 0;

}

//Selection
vector<int> init_selection(int qtd, int min, int max){
    vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }

    return vet;
}

void selection(vector<int> &vet){
    int max = vet.size();

    for(int i = 0; i < (max - 1); i++){
        for(int j = i + 1; j < max; j++){
            sview.show(vet, {i, j}, "rb");
            if(vet[i] > vet[j]){
                sview.show(vet, {i, j}, "rb");
                swap(vet[i], vet[j]);
                sview.show(vet, {i, j}, "gy");

            }
            sview.show(vet, {i, j}, "rb");
        }
    }

}

int selection_sort(){
    srand(time(NULL));
    my_player->autoplay = true;
    sview.set_bar_view();
    sview.set_thickness(8);

    vector<int> vet = init_selection(50, 90, 300);
    selection(vet);
    my_player->wait();
    return 0;
}
//fim selection

vector<int> init_marge(int qtd, int min, int max){
    vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }

    return vet;
}


void merge(vector<int> &vet, int inicio, int meio, int fim){
    vector<int> temp;

    int parte1, parte2, tamanho, i, j, k;

    bool fim1 = false;
    bool fim2 = false;

    tamanho = fim - inicio + 1;

    parte1 = inicio;
    parte2 = meio + 1;

    for(i = 0; i < tamanho; i++){
        if(!fim1 && !fim2){
            if(vet[parte1] < vet[parte2]){
                temp.push_back(vet[parte1++]);
                sview.show(vet, {i}, "r");
            }else{
                temp.push_back(vet[parte2++]);
                sview.show(vet, {i}, "r");
            }

            if(parte1 > meio) fim1 = true;
            if(parte2 > fim) fim2 = true;
        }else{
            if(!fim1){
                temp.push_back(vet[parte1++]);
                sview.show(vet, {i}, "r");
            }else{
                temp.push_back(vet[parte2++]);
                sview.show(vet, {i}, "r");
            }
        }
    }
    for(j = 0, k = inicio; j < tamanho; j++, k++){
        vet[k] = (temp[j]);
        sview.show(vet, {j}, "r");
    }

    //    for(int i = 0; i < 49; i++){
    //        sview.show(vet, {i}, "r");
    //    }
}
void mergeSort(vector<int> &vet, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim) / 2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}


int merge_sort(){
    srand(time(NULL));
    my_player->autoplay = true;
    sview.set_bar_view();
    sview.set_thickness(8);

    vector<int> origem = init_marge(50, 90, 300);

    mergeSort(origem, 0, 49);
    my_player->wait();
    return 0;
}

vector<int> init_quick(int qtd, int min, int max){
    vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }

    return vet;
}

void quick(vector<int> &vet, int inicio, int fim){
    int pivo, i, j, meio;

    i = inicio;
    j = fim;

    meio = (i + j) / 2;

    pivo = vet[meio];

    do{
        while(vet[i] < pivo) i++;
        while(vet[j] > pivo) j--;

        if(i <= j){
            sview.show(vet, {i,j}, "rb");
            swap(vet[i], vet[j]);
            sview.show(vet, {i,j}, "gy");
            i++;
            j--;
        }
    }while(j > i);

    if(inicio < j) quick(vet, inicio, j);
    if(i < fim) quick(vet, i, fim);
}


int quick_sort(){
    srand(time(NULL));
    my_player->autoplay = true;
    sview.set_bar_view();
    sview.set_thickness(8);

    vector<int> vet = init_quick(50, 90, 300);
    quick(vet, 0, 49);
    my_player->wait();
    return 0;
}

//int main(){
//    //bubble_sort();
//    //quick_sort();
//    //selection_sort();
//    //merge_sort();

//}

