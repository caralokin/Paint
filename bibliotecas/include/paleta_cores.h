/* 	Biblioteca: 
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422 e 023417
    Data da última modificação: 21/03/2013 
*/

#ifndef PBRUSH_PALETA_CORES_H
#define PBRUSH__H

#include <stdio.h>
#include <windows.h>

#include "console_v1.5.4.h"  /* tamanhoJanelaConsole(), getTamanhoFonteConsole(), Evento(), tipo EVENTO */   
#include "graphics.h"   /* putpixel() */
#include "janela.h"
#include "ferramentas.h"

# define numero_paletas 10
# define pos_hor 3

/*pinta a borda do quadrado onde tem a cor selecionado para o pincel
argumento int ini_col
e o valor em pixer onde comeca as colunas de um determinado quadrado da cor
argumento int fim_col 
e o valor em pixer onde termina as colunas de um determinado quadrado da cor
argumento int ini_lin
e onde a posicao em pixel onde comeca o quadrado da cor
argumento fim_lin
e onde a posicao em pixel onde termina o quadrado da cor
*/
void borda_paleta(int ini_col, int fim_col, int ini_lin, int fim_lin);

/*Desenha os quadrados coloridos da paleta de cores*/
void quadrado_cor(int x, int y, int tam, COLORREF cor);

/*Desenha as paletas de cores
argumento int tipo
->1 = Cores default
->2 = Cores Personalizadas
argumento int espaco
->espaço em pixel ocupado por cada cor da paleta
*/
void imprime_paleta(int tipo, int espaco, tipo_ferramentas ferramentas);

#endif
