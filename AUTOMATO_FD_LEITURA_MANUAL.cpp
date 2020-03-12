#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char ** argv){

    int qtTeste, estadoInicial, qtEstadosFinais;
    char alfabeto[1024];
    char teste[1300];

    cin >> qtTeste;
    cin >> alfabeto;
    cin >> estadoInicial;
    cin >> qtEstadosFinais;

    int estadosFinais[qtEstadosFinais], transicao[qtTeste*(strlen(alfabeto))][2];
    char condicaoDeTransicao[qtTeste*(strlen(alfabeto))];

    for(int i = 0; i < qtEstadosFinais; i++){
        cin >> estadosFinais[i];
    }

    for(int i = 0; i < qtTeste*(strlen(alfabeto)); i++){
        for(int j = 0; j < 2; j++){
            cin >> transicao[i][j];
            if(j < 1){
                cin >> condicaoDeTransicao[i];
            }
        }
    }


    while(cin >> teste){

        bool valida = false;
        int estadoAtual = estadoInicial;

        for(int i = 0; i < strlen(teste); i++){
            for(int j = 0; j < qtTeste*(strlen(alfabeto)); j++){
                if(transicao[j][0] == estadoAtual && teste[i] == condicaoDeTransicao[j]){
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
            cout << "ACEITA" << endl;
        }else{
            cout << "REJEITA" << endl;
        }
    }

    return 0;
}
