#include <ctime>
#include <iostream>
#include <string>
#include "Sistema_Allegro5.0.h"
#include "Fogo.h"
#include "Painel.h"

using namespace std;

constexpr short int Largura_Tela   = 1080 ;
constexpr short int Altura_Tela    = 720  ;



int main()
{
    srand(time(NULL));

    bool EXIT_PROGRAM = false;
    unsigned char Clicando = false;

    DISPLAY Janela;
    ALLEGRO_EVENT evento;
    FOGO fg_Display;
    BOTAO Botoes[15];

    _Iniciar_Sistema_Allegro();
    _Definir_Botoes(Botoes, Largura_Tela);

    Janela._Push_FPS(15);
    Janela._Criar_Sistema_Allegro(Largura_Tela, Altura_Tela);
    Janela._Registrar_Eventos();

    _Carregar_Fonte_BOTAO("QumpellkaNo12.OTF", 24);

    fg_Display._Get_Paleta_Regular_Cor("Fire_DOOM.PNG", 0, 0, 1, 1, 36, 1);
    fg_Display._Definir_Matriz_Fogo(Largura_Tela, Altura_Tela, 10);

    al_start_timer(Janela._Get_Timer());

    while(!EXIT_PROGRAM)
    {
        al_wait_for_event(Janela._Get_Event_Queue(), &evento);

        switch(evento.type)
        {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                EXIT_PROGRAM = true;
            break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                _Verificar_Click_Botoes(evento.mouse.x, evento.mouse.y, Botoes);
                Clicando = true;
            break;

            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                _Desativar_Botoes_MOUSE_BUTTON_UP(Botoes);
                Clicando = false;
            break;

            case ALLEGRO_EVENT_MOUSE_AXES:
                if(Clicando)
                    fg_Display._Desenhar_Com_Mouse(evento.mouse.x, evento.mouse.y);
            break;

            case ALLEGRO_EVENT_TIMER:
                fg_Display._Mover_Fogo();

                _Eventos_Se_BOTAO_Ativo(Botoes, fg_Display);

                al_clear_to_color(al_map_rgb(0, 0, 0));
                fg_Display._Desenhar_Fogo();
                _Desenhar_Botoes(Botoes);

                al_flip_display();
            break;

        }
    }

    Janela._Destuir_Sistema_Allegro();
    _Destruir_Fonte_BOTAO();

    return 0;
}
