
#include "Fogo.h"
#include <iostream>

void FOGO::_Get_Paleta_Regular_Cor(const char* Nome_Paleta, int Ponto_Inicial_X, int Ponto_Inicial_Y, int Distancia_Pixeis_X, int Distancia_Pixeis_Y, int Matriz_Paleta_X, int Matriz_Paleta_Y){

    ALLEGRO_BITMAP *Paleta = NULL;

    Paleta = al_load_bitmap(Nome_Paleta);

    if(!Paleta){
        _Erro_Box("Erro ao carregar a Paleta do Fogo");
        system("pause");
        return;
    }

    for (int Y = Ponto_Inicial_Y ; Y < Ponto_Inicial_Y + Matriz_Paleta_Y * Distancia_Pixeis_Y ; Y += Distancia_Pixeis_Y){
    for (int X = Ponto_Inicial_X ; X < Ponto_Inicial_X + Matriz_Paleta_X * Distancia_Pixeis_X ; X += Distancia_Pixeis_X){
            Paleta_Cores.push_back(al_get_pixel(Paleta, X, Y));
        }
    }
    al_destroy_bitmap(Paleta);
}

void FOGO::_Definir_Matriz_Fogo(int X, int Y, short int Tamanho_Quadrados_Fogo){

    Px_Tamanho_Quadrados_Fogo = Tamanho_Quadrados_Fogo;
    Chance_Fogo_Esquerda = 40;
    Chance_Fogo_Subir = 70;
    Intensidade_Esquerda = 3;
    Intensidade_Subir = 2;

    Largura_Matriz = 1 + int(X/Tamanho_Quadrados_Fogo);
    Altura_Matriz = 1 + int(Y/Tamanho_Quadrados_Fogo);

    std::vector <char> Linha;
    for(int A = 0 ; A < Largura_Matriz ; A++){
        Linha.push_back(0);
    }

    for(int B = 0 ; B < Altura_Matriz ; B++){
        Matriz_Fogo.push_back(Linha);
    }
}

void FOGO::_Mover_Fogo(){
    for(int X = 0 ; X < Largura_Matriz ; X++){
        for(int Y = 0 ; Y < Altura_Matriz ; Y++){

            if(rand() % 100 < Chance_Fogo_Subir && Y > 0){
                Matriz_Fogo[Y-1][X] = Matriz_Fogo[Y][X] -rand() % Intensidade_Subir;
                if(Matriz_Fogo[Y-1][X] < 0)Matriz_Fogo[Y-1][X] = 0;
            }

            if(rand () % 100 < Chance_Fogo_Esquerda && X > 0 && Y > 0){
                Matriz_Fogo[Y-1][X-1] = Matriz_Fogo[Y][X]-rand() % Intensidade_Esquerda;
                if(Matriz_Fogo[Y-1][X-1] < 0)Matriz_Fogo[Y-1][X-1] = 0;
            }
        }
    }

}

void FOGO::_Desenhar_Fogo(void){
    int X_Quadrado_Fogo;
    int Y_Quadrado_Fogo;

    for(int X = 0 ; X < Largura_Matriz ; X++){
        for(int Y = 0 ; Y < Altura_Matriz ; Y++){
            if(Matriz_Fogo[Y][X] > 0){

            X_Quadrado_Fogo = X * Px_Tamanho_Quadrados_Fogo;
            Y_Quadrado_Fogo = Y * Px_Tamanho_Quadrados_Fogo;

            al_draw_filled_rectangle(X_Quadrado_Fogo, Y_Quadrado_Fogo, X_Quadrado_Fogo + Px_Tamanho_Quadrados_Fogo, Y_Quadrado_Fogo + Px_Tamanho_Quadrados_Fogo,
                                     Paleta_Cores[Matriz_Fogo[Y][X]]);
            }
        }
    }

}

void FOGO::_Desenhar_Com_Mouse(int X, int Y){

    short int dX, dY;
    short int lugar_Pintado_X = X/Px_Tamanho_Quadrados_Fogo;
    short int lugar_Pintado_Y = Y/Px_Tamanho_Quadrados_Fogo;

    for(dX = -2 ; dX < 3 ; dX++){
        for(dY = -2 ; dY < 3; dY++){

        if(dX + lugar_Pintado_X < 0 || dX + lugar_Pintado_X > Largura_Matriz-2 ||
           dY + lugar_Pintado_Y < 0 || dY + lugar_Pintado_Y > Altura_Matriz-1)
            break;
        else
            Matriz_Fogo[dY + lugar_Pintado_Y][dX + lugar_Pintado_X] = Paleta_Cores.size()-1;
        }
    }
}

void FOGO::_Manter_Fogo_Padrao(void){
        for(int A = 0 ; A < Largura_Matriz-1 ; A++)
            Matriz_Fogo[Altura_Matriz-1][A] = Paleta_Cores.size()-1;
}
void FOGO::_Apagar_Fogo(void){
    for(int X = 0 ; X < Largura_Matriz ; X++){
        for(int Y = 0 ; Y < Altura_Matriz ; Y++){
            Matriz_Fogo[Y][X] = 0;
        }
    }
}
void FOGO::_Zerar_Ultima_Fileira_Fogo(void){
    for(int X = 0 ; X < Largura_Matriz ; X++)
        Matriz_Fogo[Altura_Matriz-1][X] = 0;
}

void FOGO::_Aumentar_Chance_Fogo_Subir    (void){
    if(Chance_Fogo_Subir < 100)
        Chance_Fogo_Subir += 1;
}
void FOGO::_Diminuir_Chance_Fogo_Subir    (void){
    if(Chance_Fogo_Subir > 0)
        Chance_Fogo_Subir -= 1;
}
void FOGO::_Aumentar_Chance_Fogo_Esquerda (void){
    if(Chance_Fogo_Esquerda < 100)
        Chance_Fogo_Esquerda += 1;
}
void FOGO::_Diminuir_Chance_Fogo_Esquerda (void){
    if(Chance_Fogo_Esquerda > 0)
        Chance_Fogo_Esquerda -= 1;
}
void FOGO::_Aumentar_Subtrair_Subir       (void){
    if(Intensidade_Subir < 10)
        Intensidade_Subir += 1;
}
void FOGO::_Diminuir_Subtrair_Subir       (void){
    if(Intensidade_Subir > 1)
        Intensidade_Subir -= 1;
}
void FOGO::_Aumentar_Subtrair_Esquerda    (void){
    if(Intensidade_Esquerda < 10)
        Intensidade_Esquerda += 1;
}
void FOGO::_Diminuir_Subtrair_Esquerda    (void){
    if(Intensidade_Esquerda > 1)
        Intensidade_Esquerda -= 1;
}
