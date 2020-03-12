#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(int argc, char **argv){

    int qtEstados, qtEstadosFinais, estadoInicial;
    char alfabeto[1024];

    ifstream file("entrada1.txt");

    if(file.is_open()){

        file >> qtEstados;
        file >> alfabeto;
        file >> estadoInicial;
        file >> qtEstadosFinais;
        int *estadosFinais = new int[qtEstadosFinais];

        for(int i = 0; i < qtEstadosFinais; i++){
            file >> estadosFinais[i];
        }

        int transicao[qtEstados*(strlen(alfabeto))][2];
        char condicaoDeTransicao[qtEstados*(strlen(alfabeto))];

        for(int i = 0; i < qtEstados*(strlen(alfabeto)); i++){
            file >> transicao[i][0] >> condicaoDeTransicao[i] >> transicao[i][1];
        }

        while(!file.eof()){
            char teste[1024];
            file >> teste;
            int estadoAtual = estadoInicial;
            bool valida = false;

            if(file.eof()){
                break;
            }

            for(int i = 0; i < strlen(teste); i++){
                for(int j = 0; j < qtEstados*(strlen(alfabeto)); j++){
                    if(estadoAtual == transicao[j][0] && teste[i] == condicaoDeTransicao[j]){
                        estadoAtual = transicao[j][1];
                        break;
                    }
                }
            }

            for(int i = 0; i < qtEstadosFinais; i++){
                if(estadoAtual == estadosFinais[i]){
                    valida = true;
                }
            }
            if(valida){
                cout << "ACCEPTED" << endl;
            }else{
                cout << "REJECTED" << endl;
            }
        }

        file.close();

    }else{
        cout << "UNABLE TO OPEN FILE" << endl;
    }

    return 0;
}
