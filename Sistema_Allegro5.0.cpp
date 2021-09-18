
#include "Sistema_Allegro5.0.h"

using namespace std;

ALLEGRO_EVENT_QUEUE*  DISPLAY::_Get_Event_Queue     (void){ return Fila_Eventos;    }
ALLEGRO_DISPLAY*      DISPLAY::_Get_Display         (void){ return Janela;          }
ALLEGRO_TIMER*        DISPLAY::_Get_Timer           (void){ return Timer;           }

unsigned short int    DISPLAY::_Get_FPS             (void){ return FPS;             }


void _Erro_Box(const char* txt){
    al_show_native_message_box(NULL, "ERROR", "Ocorreu o seguinte erro:", txt, NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void    DISPLAY::_Push_FPS  (unsigned short int PFPS){ FPS = PFPS; }


void DISPLAY::_Atualizar_Tamanho_Display (unsigned int Largura, unsigned int Altura){
    al_resize_display(Janela, Largura, Altura);
}

bool DISPLAY::_Criar_Sistema_Allegro(int Largura_Tela, int Altura_Tela){

    Janela = al_create_display(Largura_Tela, Altura_Tela);
    if(!Janela){
        _Erro_Box("Falha ao crear a janela.");
        exit(1);
    }

    Fila_Eventos = al_create_event_queue();
    if(!Fila_Eventos){
        _Erro_Box("Falha ao instalar a fila de eventos.");
        exit(1);
    }

    Timer = al_create_timer( 1.0 / FPS );
    if(!Timer){
        _Erro_Box("Falha ao criar o Timer.");
        exit(1);
    }
    return 0;
}
void DISPLAY::_Destuir_Sistema_Allegro(void){

    if(Janela)al_destroy_display(Janela);
    if(Fila_Eventos)al_destroy_event_queue(Fila_Eventos);
    if(Timer)al_destroy_timer(Timer);
}

void DISPLAY::_Registrar_Eventos(void){

    al_register_event_source(Fila_Eventos, al_get_display_event_source(Janela));
    al_register_event_source(Fila_Eventos, al_get_mouse_event_source());
    al_register_event_source(Fila_Eventos, al_get_timer_event_source(Timer));
}

void DISPLAY::_Get_Configurasao_Sistema(void){

    string Frase_Arquivo;
    ifstream Arquivo_Configurasao;

    unsigned short int Posisao_Lida_Arquivo = 0;
    unsigned int Numero_Convertido;

    Arquivo_Configurasao.open("AJUSTES.txt");

    if(!Arquivo_Configurasao.is_open()){
        _Erro_Box("Falha ao abrir o arquivo de \"AJUSTES.txt\".");
        getch();
        exit(1);
    }

    while(!Arquivo_Configurasao.eof())
    {
        getline(Arquivo_Configurasao, Frase_Arquivo);

        if(Frase_Arquivo.size() > 15)
        {
            Numero_Convertido = stoi(Frase_Arquivo.substr(15, Frase_Arquivo.size()));

            switch(Posisao_Lida_Arquivo)
            {
                case 0:
                    FPS = Numero_Convertido;
                break;

                case 1:
                    al_resize_display(DISPLAY::_Get_Display(), Numero_Convertido, al_get_display_height(DISPLAY::_Get_Display()));
                break;

                case 2:
                    al_resize_display(DISPLAY::_Get_Display(), al_get_display_width(DISPLAY::_Get_Display()), Numero_Convertido);
                break;
            }
            Posisao_Lida_Arquivo++;
        }
    }
}

bool _Iniciar_Sistema_Allegro(void){

    if(!al_init()){
        _Erro_Box("Falha ao iniciar o Allegro.");
        exit(1);
    }

    if(!al_init_image_addon()){
        _Erro_Box("Falha ao iniciar addon de imagem");
        exit(1);
    }

    if(!al_init_primitives_addon()){
        _Erro_Box("Falha ao iniciar os efeitos primitivos.");
        exit(1);
    }

    if(!al_init_font_addon()){
        _Erro_Box("Falha ao iniciar addon de font");
        exit(1);
    }

    if(!al_init_ttf_addon()){
        _Erro_Box("Falha ao iniciar addon de ttf");
        exit(1);
    }

    if(!al_install_mouse()){
        _Erro_Box("Falha ao instalar o mouse.");
        exit(1);
    }
    return 0;
}
