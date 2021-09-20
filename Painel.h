#ifndef PAINEL_H_INCLUDED
#define PAINEL_H_INCLUDED

#include "Sistema_Allegro5.0.h"
#include "Fogo.h"

ALLEGRO_FONT *Fonte_BOTAO;

class BOTAO {
    private:
        short int Posisao_X_Y[2];
        short int Tamanho_X_Y[2];

        const char   *Nome_texto;

        char Botao_Esquerda_Direita;

    public:
        bool Ativado = false;

        void _Desenhar_BOTAO    (ALLEGRO_COLOR Cor, ALLEGRO_COLOR Cor_Preenchido);

        void _Criar_BOTAO (const char *Nome, short int Posisao_X, short int Posisao_Y, short int Tamanho_X, short int Tamanho_Y, char Tipo_Escrita);
        void _Verificar_Impacto_BOTAO(int MouseX, int MouseY);
};

void _Definir_Botoes(BOTAO Mapa[], short int Largura);

void _Verificar_Click_Botoes(int MouseX, int MouseY, BOTAO Botoes[]);
void _Desenhar_Botoes(BOTAO Botoes[]);

void _Eventos_Se_BOTAO_Ativo(BOTAO Botoes[], FOGO &fg_Display);
void _Desativar_Botoes_MOUSE_BUTTON_UP(BOTAO Botoes[]);

bool _Carregar_Fonte_BOTAO(const char *Local_Nome_Fonte, unsigned short int Tamanho_Fonte);
void _Destruir_Fonte_BOTAO(void);

#endif // PAINEL_H_INCLUDED
