
#include "Painel.h"

constexpr unsigned char Quantidade_Botoes           = 3 ;
constexpr unsigned char Botao_Fogo_Padrao           = 0 ;
constexpr unsigned char Botao_Apagar_Fogo           = 1 ;
constexpr unsigned char Botao_Impedir_Fogo_Infinito = 2 ;

void BOTAO::_Criar_BOTAO (const char *Nome, short int Posisao_X, short int Posisao_Y, short int Tamanho_X, short int Tamanho_Y){

    Posisao_X_Y[0] = Posisao_X;
    Posisao_X_Y[1] = Posisao_Y;

    Tamanho_X_Y[0] = Tamanho_X;
    Tamanho_X_Y[1] = Tamanho_Y;

    Nome_texto = Nome;
}

void _Definir_Botoes(BOTAO Mapa[], short int Largura){
    Mapa[Botao_Fogo_Padrao].            _Criar_BOTAO("Fogo Padrao"          , Largura - 30, 30, 30, 30);
    Mapa[Botao_Impedir_Fogo_Infinito].  _Criar_BOTAO("Impedir fogo infinito", Largura - 30, 70, 30, 30);
    Mapa[Botao_Apagar_Fogo].            _Criar_BOTAO("Apagar fogo"          , Largura - 30, 110, 30, 30);
}

void BOTAO::_Verificar_Impacto_BOTAO(int MouseX, int MouseY){
    if(MouseX >= Posisao_X_Y[0] - al_get_text_width(Fonte_BOTAO, Nome_texto) - Tamanho_X_Y[0] - 10 && MouseX <= Posisao_X_Y[0] &&
       MouseY >= Posisao_X_Y[1] && MouseY <= Posisao_X_Y[1] + Tamanho_X_Y[1]){
        if(Ativado == true)
            Ativado = false;
        else
            Ativado = true;
    }
}
void _Verificar_Click_Botoes(int MouseX, int MouseY, BOTAO Botoes[]){
    for(unsigned char X = 0 ; X < Quantidade_Botoes ; X++)
        Botoes[X]._Verificar_Impacto_BOTAO(MouseX, MouseY);
}

void _Desenhar_Botoes(BOTAO Botoes[]){
    for(unsigned char X = 0 ; X < Quantidade_Botoes ; X ++)
        Botoes[X]._Desenhar_BOTAO(al_map_rgb(0, 180, 0), al_map_rgb(180, 0, 0));
}

void _Eventos_Se_BOTAO_Ativo(BOTAO Botoes[], FOGO &fg_Display){
    if(Botoes[Botao_Impedir_Fogo_Infinito]._Get_Ativado())
        fg_Display._Zerar_Ultima_Fileira_Fogo();
    if(Botoes[Botao_Fogo_Padrao]._Get_Ativado())
        fg_Display._Manter_Fogo_Padrao();
    if(Botoes[Botao_Apagar_Fogo]._Get_Ativado())
        fg_Display._Apagar_Fogo();
}

void BOTAO::_Desenhar_BOTAO(ALLEGRO_COLOR Cor, ALLEGRO_COLOR Cor_Preenchido){

    al_draw_text(Fonte_BOTAO, Cor, Posisao_X_Y[0] - Tamanho_X_Y[0] - 10, Posisao_X_Y[1], ALLEGRO_ALIGN_RIGHT, Nome_texto);

    if(Ativado)
        al_draw_filled_rectangle(Posisao_X_Y[0] - Tamanho_X_Y[0], Posisao_X_Y[1] , Posisao_X_Y[0], Posisao_X_Y[1] + Tamanho_X_Y[1] , Cor_Preenchido);

    al_draw_rectangle(Posisao_X_Y[0] - Tamanho_X_Y[0], Posisao_X_Y[1] , Posisao_X_Y[0], Posisao_X_Y[1] + Tamanho_X_Y[1] , Cor, 2);
}

bool BOTAO::_Get_Ativado(){
    return Ativado;
}

bool _Carregar_Fonte_BOTAO(const char *Local_Nome_Fonte, unsigned short int Tamanho_Fonte){
    Fonte_BOTAO = al_load_font(Local_Nome_Fonte, Tamanho_Fonte, 0);

    if(!Fonte_BOTAO){
        _Erro_Box("Falha ao carregar a fonte do botao");
        exit(1);
    }
    return 0;
}

void _Destruir_Fonte_BOTAO(){
    if(Fonte_BOTAO)al_destroy_font(Fonte_BOTAO);
}
