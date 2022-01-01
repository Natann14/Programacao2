#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>

#define CORBRANCO (makecol(255, 255, 255))
#define CORPRETO 1
#define CORCINZA (makecol(160, 160, 160))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERDE (makecol(0, 255, 0))
#define CORAMARELO (makecol(255, 255, 100))
#define CORVERMELHO (makecol(255, 0, 0))

#define IMAGENAME "AFD-03.bmp"

int main(void)
{
    BITMAP *buff;
    PALETTE pal;
    int i;

    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
        exit(EXIT_FAILURE);

    set_color_depth(16);
    get_palette(pal);

    // Create a buffer for smooth animation.
    buff = create_bitmap(800,800);

    if(buff == NULL)
    {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }

    circlefill(buff, 180, 180, 100, CORVERDE);
    circle(buff, 180, 180, 108, CORVERDE);
    circle(buff, 580, 180, 108, CORBRANCO);
    circlefill(buff, 580, 180, 100, CORBRANCO);

    textprintf_ex(buff, font, 600, 660, CORVERDE, CORPRETO, "Auto1 AFD");
    textprintf_ex(buff, font, 600, 680, CORVERDE, CORPRETO, "Estado inicial: Q0");
    textprintf_ex(buff, font, 600, 700, CORVERDE, CORPRETO, "Estados finais: Q0 ou Q1");
    textprintf_ex(buff, font, 600, 720, CORVERDE, CORPRETO, "Entrada: A, B, C");
    textprintf_ex(buff, font, 180, 180, CORPRETO, CORVERDE, "Q0");
    textprintf_ex(buff, font, 580, 180, CORPRETO, CORBRANCO, "Q1");
    textprintf_ex(buff, font, 290, 180, CORBRANCO, CORPRETO, "=====================>");
    textprintf_ex(buff, font, 380, 160, CORBRANCO, CORPRETO, "C");
    textprintf_ex(buff, font, 580, 50, CORBRANCO, CORPRETO, "C"); // Q1
    textprintf_ex(buff, font, 180, 50, CORBRANCO, CORPRETO, "AB"); //Q0

    
    //seta pro lado em Q0
    textprintf_ex(buff, font, 220, 50, CORBRANCO, CORPRETO, "=====");

    //seta pra baixo em Q0
    for(i=50; i<= 70; i++)
    {
        textprintf_ex(buff, font, 220, i, CORBRANCO, CORPRETO, "|");
    }
    textprintf_ex(buff, font, 212, 68, CORBRANCO, CORPRETO, "\\|/");
    //

    textprintf_ex(buff, font, 630, 50, CORBRANCO, CORPRETO, "=====");
    for(i=50; i<=70; i++)
    {
        textprintf_ex(buff, font, 625, i, CORBRANCO, CORPRETO, "|");
    }

    textprintf_ex(buff, font, 617, 68, CORBRANCO, CORPRETO, "\\|/");

    //seta pra cima em Q0
    for(i=50; i<= 112; i++)
    {
        textprintf_ex(buff, font, 260, i, CORBRANCO, CORPRETO, "|");
    }

    //seta pra cima em Q1
    for(i=50; i<=112; i++)
    {
        textprintf_ex(buff, font, 661, i, CORBRANCO, CORPRETO, "|");
    }

    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    return 0;
}
END_OF_MAIN()
