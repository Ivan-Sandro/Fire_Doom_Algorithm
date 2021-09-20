
#include "Painel.h"

constexpr unsigned char Quantidade_Botoes           = 15 ;
constexpr unsigned char Botao_Esconder_Botoes       = 0 ;
constexpr unsigned char Botao_Fogo_Padrao           = 1 ;
constexpr unsigned char Botao_Apagar_Fogo           = 2 ;
constexpr unsigned char Botao_Impedir_Fogo_Infinito = 3 ;
constexpr unsigned char Botao_Reduzir_Fogo_Segundo  = 4 ;

constexpr unsigned char Botao_Aumentar_Intensidade_Esquerda  = 5 ;
constexpr unsigned char Botao_Diminuir_Intensidade_Esquerda  = 6 ;
constexpr unsigned char Botao_Aumentar_Intensidade_Subir     = 7 ;
constexpr unsigned char Botao_Diminuir_Intensidade_Subir     = 8 ;
constexpr unsigned char Botao_Aumentar_Vento                 = 9 ;
constexpr unsigned char Botao_Diminuir_Vento                 = 10;
constexpr unsigned char Botao_Aumentar_Altura_Fogo           = 11;
constexpr unsigned char Botao_Diminuir_Altura_Fogo           = 12;
constexpr unsigned char Botao_Aumentar_Pincel                = 13;
constexpr unsigned char Botao_Diminuir_Pincel                = 14;

void BOTAO::_Criar_BOTAO (const char *Nome, short int Posisao_X, short int Posisao_Y, short int Tamanho_X, short int Tamanho_Y, char Tipo_Escrita){

    Posisao_X_Y[0] = Posisao_X;
    Posisao_X_Y[1] = Posisao_Y;

    Tamanho_X_Y[0] = Tamanho_X;
    Tamanho_X_Y[1] = Tamanho_Y;

    Nome_texto = Nome;
    Botao_Esquerda_Direita = Tipo_Escrita;
}

void _Definir_Botoes(BOTAO Mapa[], short int Largura){
    Mapa[Botao_Esconder_Botoes].        _Criar_BOTAO("Esconder Botoes"          , Largura - 30, 30,  30, 30, 'D');
    Mapa[Botao_Fogo_Padrao].            _Criar_BOTAO("Fogo Padrao"              , Largura - 30, 70,  30, 30, 'D');
    Mapa[Botao_Impedir_Fogo_Infinito].  _Criar_BOTAO("Impedir fogo infinito"    , Largura - 30, 110, 30, 30, 'D');
    Mapa[Botao_Reduzir_Fogo_Segundo].   _Criar_BOTAO("Reduzir fogo por segundo" , Largura - 30, 150, 30, 30, 'D');
    Mapa[Botao_Apagar_Fogo].            _Criar_BOTAO("Apagar fogo"              , Largura - 30, 190, 30, 30, 'D');

    Mapa[Botao_Aumentar_Intensidade_Esquerda]._Criar_BOTAO("+ Reduzir Esq", 250, 30,  30, 30, 'D');
    Mapa[Botao_Diminuir_Intensidade_Esquerda]._Criar_BOTAO("- Reduzir Esq", 260, 30,  30, 30, 'E');
    Mapa[Botao_Aumentar_Intensidade_Subir].   _Criar_BOTAO("+ Reduzir UP" , 250, 70,  30, 30, 'D');
    Mapa[Botao_Diminuir_Intensidade_Subir].   _Criar_BOTAO("- Reduzir UP" , 260, 70,  30, 30, 'E');
    Mapa[Botao_Aumentar_Vento].               _Criar_BOTAO("+ Vento"      , 250, 110, 30, 30, 'D');
    Mapa[Botao_Diminuir_Vento].               _Criar_BOTAO("- Vento"      , 260, 110, 30, 30, 'E');
    Mapa[Botao_Aumentar_Altura_Fogo].         _Criar_BOTAO("+ Altura Fogo", 250, 150, 30, 30, 'D');
    Mapa[Botao_Diminuir_Altura_Fogo].         _Criar_BOTAO("- Altura Fogo", 260, 150, 30, 30, 'E');
    Mapa[Botao_Aumentar_Pincel].              _Criar_BOTAO("+ Pincel"     , 250, 190, 30, 30, 'D');
    Mapa[Botao_Diminuir_Pincel].              _Criar_BOTAO("- Pincel"     , 260, 190, 30, 30, 'E');
}


void BOTAO::_Verificar_Impacto_BOTAO(int MouseX, int MouseY){
    if(Botao_Esquerda_Direita == 'D'){
        if(MouseX >= Posisao_X_Y[0] - al_get_text_width(Fonte_BOTAO, Nome_texto) - Tamanho_X_Y[0] - 10 && MouseX <= Posisao_X_Y[0] &&
           MouseY >= Posisao_X_Y[1] && MouseY <= Posisao_X_Y[1] + Tamanho_X_Y[1]){
            if(Ativado == true)
                Ativado = false;
            else
                Ativado = true;
        }
    }else{
        if(MouseX >= Posisao_X_Y[0] && MouseX <= Posisao_X_Y[0] + al_get_text_width(Fonte_BOTAO, Nome_texto) + Tamanho_X_Y[0] + 10 &&
           MouseY >= Posisao_X_Y[1] && MouseY <= Posisao_X_Y[1] + Tamanho_X_Y[1]){
            if(Ativado == true)
                Ativado = false;
            else
                Ativado = true;
        }
    }
}
void _Verificar_Click_Botoes(int MouseX, int MouseY, BOTAO Botoes[]){
    if(Botoes[Botao_Esconder_Botoes].Ativado){
        Botoes[Botao_Esconder_Botoes]._Verificar_Impacto_BOTAO(MouseX, MouseY);
    }else{
        for(unsigned char X = 0 ; X < Quantidade_Botoes ; X++)
            Botoes[X]._Verificar_Impacto_BOTAO(MouseX, MouseY);
    }
}

void BOTAO::_Desenhar_BOTAO(ALLEGRO_COLOR Cor, ALLEGRO_COLOR Cor_Preenchido){
    if(Botao_Esquerda_Direita == 'D'){
        al_draw_text(Fonte_BOTAO, Cor, Posisao_X_Y[0] - Tamanho_X_Y[0] - 10, Posisao_X_Y[1], ALLEGRO_ALIGN_RIGHT, Nome_texto);
        if(Ativado)
            al_draw_filled_rectangle(Posisao_X_Y[0] - Tamanho_X_Y[0], Posisao_X_Y[1] , Posisao_X_Y[0], Posisao_X_Y[1] + Tamanho_X_Y[1] , Cor_Preenchido);

        al_draw_rectangle(Posisao_X_Y[0] - Tamanho_X_Y[0], Posisao_X_Y[1] , Posisao_X_Y[0], Posisao_X_Y[1] + Tamanho_X_Y[1] , Cor, 2);

    }else{
        al_draw_text(Fonte_BOTAO, Cor, Posisao_X_Y[0] + Tamanho_X_Y[0] + 10, Posisao_X_Y[1], ALLEGRO_ALIGN_LEFT, Nome_texto);
        if(Ativado)
            al_draw_filled_rectangle(Posisao_X_Y[0], Posisao_X_Y[1] , Posisao_X_Y[0] + Tamanho_X_Y[0], Posisao_X_Y[1] + Tamanho_X_Y[1] , Cor_Preenchido);

        al_draw_rectangle(Posisao_X_Y[0], Posisao_X_Y[1] , Posisao_X_Y[0] + Tamanho_X_Y[0] , Posisao_X_Y[1] + Tamanho_X_Y[1] , Cor, 2);
    }
}
void _Desenhar_Botoes(BOTAO Botoes[]){
    if(Botoes[Botao_Esconder_Botoes].Ativado){
        Botoes[Botao_Esconder_Botoes]._Desenhar_BOTAO(al_map_rgb(0, 180, 0), al_map_rgb(180, 0, 0));
    }else{
        for(unsigned char X = 0 ; X < Quantidade_Botoes ; X ++)
            Botoes[X]._Desenhar_BOTAO(al_map_rgb(0, 180, 0), al_map_rgb(180, 0, 0));
    }
}

void _Eventos_Se_BOTAO_Ativo(BOTAO Botoes[], FOGO &fg_Display){

    if(Botoes[Botao_Impedir_Fogo_Infinito].Ativado)
        fg_Display._Zerar_Ultima_Fileira_Fogo();

    if(Botoes[Botao_Fogo_Padrao].Ativado)
        fg_Display._Manter_Fogo_Padrao();

    if(Botoes[Botao_Apagar_Fogo].Ativado)
        fg_Display._Apagar_Fogo();

    if(Botoes[Botao_Aumentar_Altura_Fogo].Ativado)
        fg_Display._Aumentar_Chance_Fogo_Subir();

    if(Botoes[Botao_Diminuir_Altura_Fogo].Ativado)
        fg_Display._Diminuir_Chance_Fogo_Subir();

    if(Botoes[Botao_Aumentar_Vento].Ativado)
        fg_Display._Aumentar_Chance_Fogo_Esquerda();

    if(Botoes[Botao_Diminuir_Vento].Ativado)
        fg_Display._Diminuir_Chance_Fogo_Esquerda();

    if(Botoes[Botao_Aumentar_Intensidade_Esquerda].Ativado)
        fg_Display._Aumentar_Subtrair_Esquerda();

    if(Botoes[Botao_Diminuir_Intensidade_Esquerda].Ativado)
        fg_Display._Diminuir_Subtrair_Esquerda();

    if(Botoes[Botao_Aumentar_Intensidade_Subir].Ativado)
        fg_Display._Aumentar_Subtrair_Subir();

    if(Botoes[Botao_Diminuir_Intensidade_Subir].Ativado)
        fg_Display._Diminuir_Subtrair_Subir();

    if(Botoes[Botao_Aumentar_Pincel].Ativado)
        fg_Display._Aumentar_Pincel();

    if(Botoes[Botao_Diminuir_Pincel].Ativado)
        fg_Display._Diminuir_Pincel();

    if(Botoes[Botao_Reduzir_Fogo_Segundo].Ativado)
        fg_Display._Reduzir_fogo_por_frame();
}

void _Desativar_Botoes_MOUSE_BUTTON_UP(BOTAO Botoes[]){
    Botoes[Botao_Apagar_Fogo].Ativado                   = false;
    Botoes[Botao_Aumentar_Altura_Fogo].Ativado          = false;
    Botoes[Botao_Diminuir_Altura_Fogo].Ativado          = false;
    Botoes[Botao_Aumentar_Intensidade_Esquerda].Ativado = false;
    Botoes[Botao_Diminuir_Intensidade_Esquerda].Ativado = false;
    Botoes[Botao_Aumentar_Intensidade_Subir].Ativado    = false;
    Botoes[Botao_Diminuir_Intensidade_Subir].Ativado    = false;
    Botoes[Botao_Aumentar_Vento].Ativado                = false;
    Botoes[Botao_Diminuir_Vento].Ativado                = false;
    Botoes[Botao_Aumentar_Pincel].Ativado               = false;
    Botoes[Botao_Diminuir_Pincel].Ativado               = false;
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
