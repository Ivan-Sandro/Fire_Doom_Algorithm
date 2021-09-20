#ifndef FOGO_H_INCLUDED
#define FOGO_H_INCLUDED

#include <vector>
#include "Sistema_Allegro5.0.h"


class FOGO{
    private:
        std::vector <std::vector <char>> Matriz_Fogo;

        std::vector<ALLEGRO_COLOR> Paleta_Cores;

        short int Largura_Matriz, Altura_Matriz;

        short int Px_Tamanho_Quadrados_Fogo;

        unsigned char Chance_Fogo_Subir, Chance_Fogo_Esquerda;
        unsigned char Intensidade_Subir, Intensidade_Esquerda;

    public:

        void _Get_Paleta_Regular_Cor (const char* Nome_Paleta, int Ponto_Inicial_X, int Ponto_Inicial_Y, int Distancia_Pixeis_X, int Distancia_Pixeis_Y, int Matriz_Paleta_X, int Matriz_Paleta_Y);
        void _Definir_Matriz_Fogo(int X, int Y, short int Tamanho_Quadrados_Fogo);
        void _Mover_Fogo();
        void _Desenhar_Fogo(void);
        void _Desenhar_Com_Mouse(int X, int Y);

        void _Manter_Fogo_Padrao            (void);
        void _Zerar_Ultima_Fileira_Fogo     (void);
        void _Apagar_Fogo                   (void);
        void _Aumentar_Chance_Fogo_Subir    (void);
        void _Diminuir_Chance_Fogo_Subir    (void);
        void _Aumentar_Chance_Fogo_Esquerda (void);
        void _Diminuir_Chance_Fogo_Esquerda (void);
        void _Aumentar_Subtrair_Subir       (void);
        void _Diminuir_Subtrair_Subir       (void);
        void _Aumentar_Subtrair_Esquerda    (void);
        void _Diminuir_Subtrair_Esquerda    (void);
};

#endif // FOGO_H_INCLUDED
