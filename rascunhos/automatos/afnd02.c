#include<stdio.h>
#include<stdlib.h>
#include<allegro.h>

// $ gcc salvalle.c -o salvalle.x -Wall `allegro-config --cflags --libs`


/* Definicoes de algumas cores */

#define CORBRANCO (makecol(255,255,255))
#define CORPRETO 1
#define CORCINZA (makecol(160,160,160))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERDE (makecol(0, 255, 0))
#define CORAMARELO (makecol(255,255,100))
#define CORVERMELHO (makecol(255, 0, 0))
#define AZULCLARO (makecol(127, 255, 212))

#define IMAGENAME "afnd02.bmp" /* nome do arquivo de imagem */


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
  //circle(buff, 180, 580, 108, CORAMARELO);
  circlefill(buff, 180, 580, 100, CORAMARELO);
  circle(buff, 580, 180, 108, CORBRANCO);
  circlefill(buff, 580, 180, 100, CORBRANCO);
  circlefill(buff, 580, 580, 100, CORAZUL);
  circle(buff, 580, 580, 108, CORBRANCO);

  textprintf_ex(buff, font, 340, 710, CORVERDE, CORPRETO, "Auto1 AFND");
  textprintf_ex(buff, font, 340, 730, CORVERDE, CORPRETO, "Estado inicial: Q0");
  textprintf_ex(buff, font, 340, 750, CORVERDE, CORPRETO, "Estados finais: Q1 ou Q3");
  textprintf_ex(buff, font, 340, 770, CORVERDE, CORPRETO, "Entrada: A, B, C");
  textprintf_ex(buff, font, 180, 180, CORPRETO, CORVERDE, "Q0");
  textprintf_ex(buff, font, 180, 580, CORPRETO, CORAMARELO, "Q2");
  textprintf_ex(buff, font, 580, 180, CORPRETO, CORBRANCO, "Q1");
  textprintf_ex(buff, font, 580, 580, CORBRANCO, CORAZUL, "Q3");
  textprintf_ex(buff, font, 290, 180, CORBRANCO, CORPRETO, "=====================>");
  textprintf_ex(buff, font, 380, 160, CORBRANCO, CORPRETO, "B");

  for(i=300; i<=450; i++)
  {
      textprintf_ex(buff, font, 180, i, CORBRANCO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 200, 380, CORBRANCO, CORPRETO, "E");

  textprintf_ex(buff, font, 580, 50, CORBRANCO, CORPRETO, "AB");

  textprintf_ex(buff, font, 180, 700, CORBRANCO, CORPRETO, "B");

  textprintf_ex(buff, font, 172, 450, CORBRANCO, CORPRETO, "\\|/");


  textprintf_ex(buff, font, 290, 580, CORBRANCO, CORPRETO, "=====================>");


  textprintf_ex(buff, font, 220, 700, CORBRANCO, CORPRETO, "=====");

  for(i=680; i<=700; i++)
  {
      textprintf_ex(buff, font, 220, i, CORBRANCO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 212, 685, CORBRANCO, CORPRETO, "/|\\");

  for(i=645; i<=700; i++)
  {
      textprintf_ex(buff, font, 260, i, CORBRANCO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 630, 50, CORBRANCO, CORPRETO, "=====");

  for(i=50; i<=70; i++)
  {
      textprintf_ex(buff, font, 625, i, CORBRANCO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 617, 68, CORBRANCO, CORPRETO, "\\|/");

  for(i=50; i<=112; i++)
  {
      textprintf_ex(buff, font, 661, i, CORBRANCO, CORPRETO, "|");
  }


  for(i=680; i<=700; i++)
  {
      textprintf_ex(buff, font, 625, i, CORBRANCO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 617, 685, CORBRANCO, CORPRETO, "/|\\");

  for(i=645; i<=700; i++)
  {
      textprintf_ex(buff, font, 661, i, CORBRANCO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 630, 700, CORBRANCO, CORPRETO, "=====");

  for(i=310; i<=450; i++)
  {
      textprintf_ex(buff, font, 580, i, AZULCLARO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 240, 310, AZULCLARO, CORPRETO, "===========================================");

  for(i=300; i<=310; i++)
  {
      textprintf_ex(buff, font, 230, i, AZULCLARO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 222, 290, AZULCLARO, CORPRETO, "/|\\");

  textprintf_ex(buff, font, 290, 550, CORAMARELO, CORPRETO, "<===============");

  for(i=250; i<=550; i++)
  {
      textprintf_ex(buff, font, 420, i, CORAMARELO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 428, 250, CORAMARELO, CORPRETO, "=====>");

  textprintf_ex(buff, font, 250, 480, CORBRANCO, CORPRETO, "A");

  textprintf_ex(buff, font, 580, 700, CORBRANCO, CORPRETO, "C");

  textprintf_ex(buff, font, 600, 380, CORBRANCO, CORPRETO, "A");

  textprintf_ex(buff, font, 380, 600, CORBRANCO, CORPRETO, "C");

  textprintf_ex(buff, font, 455, 223, CORBRANCO, CORPRETO, "E");

  for(i=50; i<=97; i++)
  {
      textprintf_ex(buff, font, 245, i, CORBRANCO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 197, 68, CORBRANCO, CORPRETO, "\\|/");

  textprintf_ex(buff, font, 210, 50, CORBRANCO, CORPRETO, "=====");

  for(i=50; i<=60; i++)
  {
       textprintf_ex(buff, font, 205, i, CORBRANCO, CORPRETO, "|");
  }

  textprintf_ex(buff, font, 180, 50, CORBRANCO, CORPRETO, "A");





  save_bitmap(IMAGENAME, buff, pal);
  destroy_bitmap(buff);
  allegro_exit();

    return 0;
}
END_OF_MAIN()
