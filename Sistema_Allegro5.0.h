#ifndef SISTEMA_ALLEGRO5_0_H_INCLUDED
#define SISTEMA_ALLEGRO5_0_H_INCLUDED

/*****************************************************
*   Biblioteca que carrega o sistema do Allegro
*   Classe Display guarda os ponteiros do Allegro que instalamos e criamos.
*   Facilitando o uso do Allegro até para outros programas.
*   Autor: Ivan Sandro Gomes Vieira Nóbrega
*
******************************************************/

#include <conio.h>
#include <fstream>
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

class DISPLAY{
    private:
        ALLEGRO_DISPLAY *Janela = NULL;
        ALLEGRO_TIMER *Timer = NULL;
        ALLEGRO_EVENT_QUEUE *Fila_Eventos = NULL;

        unsigned short int FPS;

    public:
        ALLEGRO_EVENT_QUEUE*    _Get_Event_Queue    (void);
        ALLEGRO_DISPLAY*        _Get_Display        (void);
        ALLEGRO_TIMER*          _Get_Timer          (void);
        unsigned short int      _Get_FPS            (void);

        void _Push_FPS  (unsigned short int PFPS);

        void _Atualizar_Tamanho_Display (unsigned int Largura, unsigned int Altura);
        void _Registrar_Eventos         (void);

        bool _Criar_Sistema_Allegro     (int Largura_Tela, int Altura_Tela);
        void _Destuir_Sistema_Allegro   (void);
        void _Get_Configurasao_Sistema  (void);

};


void _Erro_Box(const char *txt);

bool _Iniciar_Sistema_Allegro(void);

#endif // SISTEMA_ALLEGRO5_0_H_INCLUDED
