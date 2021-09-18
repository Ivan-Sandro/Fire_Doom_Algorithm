#ifndef FOGO_H_INCLUDED
#define FOGO_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include "Sistema_Allegro5.0.h"


class FOGO{
    private:
        std::vector <std::vector <char>> Matriz_Fogo;

        std::vector<ALLEGRO_COLOR> Paleta_Cores;

        int Largura_Matriz, Altura_Matriz;

        int Px_Tamanho_Quadrados_Fogo;

    public:

        void _Get_Paleta_Regular_Cor (const char* Nome_Paleta, int Ponto_Inicial_X, int Ponto_Inicial_Y, int Distancia_Pixeis_X, int Distancia_Pixeis_Y, int Matriz_Paleta_X, int Matriz_Paleta_Y);
        void _Definir_Matriz_Fogo(int X, int Y, int Tamanho_Quadrados_Fogo);
        void _Mover_Fogo(int Chance_UP, int Chance_Left);
        void _Desenhar_Fogo(void);
        void _Manter_Fogo_Padrao();

};

#endif // FOGO_H_INCLUDED
