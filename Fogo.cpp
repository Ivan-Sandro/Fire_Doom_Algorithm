
#include "Fogo.h"

void FOGO::_Get_Paleta_Regular_Cor(const char* Nome_Paleta, int Ponto_Inicial_X, int Ponto_Inicial_Y, int Distancia_Pixeis_X, int Distancia_Pixeis_Y, int Matriz_Paleta_X, int Matriz_Paleta_Y){

    ALLEGRO_BITMAP *Paleta = NULL;

    Paleta = al_load_bitmap(Nome_Paleta);

    if(!Paleta){
        std::cout << "ERRO AO CARREGAR O BITMAP. >> " << Nome_Paleta ;
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

void FOGO::_Definir_Matriz_Fogo(int X, int Y, int Tamanho_Quadrados_Fogo){

    Px_Tamanho_Quadrados_Fogo = Tamanho_Quadrados_Fogo;

    Largura_Matriz = int(X/Tamanho_Quadrados_Fogo);
    Altura_Matriz = int(Y/Tamanho_Quadrados_Fogo);
    std::vector <char> Linha;
    for(int B = 0 ; B < Largura_Matriz ; B++){
        Linha.push_back(0);
    }
    for(int A = 0 ; A < Altura_Matriz ; A++){
        Matriz_Fogo.push_back(Linha);
    }
}

void FOGO::_Mover_Fogo(int Chance_UP, int Chance_Left){
    for(int X = 0 ; X < Largura_Matriz ; X++){
        for(int Y = 0 ; Y < Altura_Matriz ; Y++){
                if(rand() % 100 < Chance_UP && Y > 0){
                    Matriz_Fogo[Y-1][X] = Matriz_Fogo[Y][X] -rand()%3;
                }
                if(rand () % 100 < Chance_Left && X > 0 && Y > 0){
                   Matriz_Fogo[Y-1][X-1] = Matriz_Fogo[Y][X]-rand()%3;
                }

            if(Matriz_Fogo[Y][X] < 0)Matriz_Fogo[Y][X] = 0;
        }
    }

}

void FOGO::_Manter_Fogo_Padrao(void){
    for(int A = 0 ; A < Largura_Matriz ; A++)
        Matriz_Fogo[Altura_Matriz-1][A] = Paleta_Cores.size()-1;
}


void FOGO::_Desenhar_Fogo(void){
    int X_Quadrado_Fogo;
    int Y_Quadrado_Fogo;

    for(int X = 0 ; X < Largura_Matriz ; X ++){
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
