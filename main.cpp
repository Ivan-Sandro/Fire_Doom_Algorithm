#include <iostream>
#include <ctime>
#include "Sistema_Allegro5.0.h"
#include "Fogo.h"

using namespace std;

constexpr short int Largura_Tela = 1080 ;
constexpr short int Altura_Tela  = 720  ;

int main()
{
    srand(time(NULL));

    bool EXIT_PROGRAM = false;

    DISPLAY Janela;
    ALLEGRO_EVENT evento;
    FOGO fg_Display;

    _Iniciar_Sistema_Allegro();

    Janela._Push_FPS(13);
    Janela._Criar_Sistema_Allegro(Largura_Tela, Altura_Tela);
    Janela._Registrar_Eventos();

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

            break;

            case ALLEGRO_EVENT_TIMER:
                fg_Display._Manter_Fogo_Padrao();

                fg_Display._Mover_Fogo(50, 30);


                al_clear_to_color(al_map_rgb(0, 0, 0));

                fg_Display._Desenhar_Fogo();

                al_flip_display();
            break;

        }
    }

    Janela._Destuir_Sistema_Allegro();

    return 0;
}
