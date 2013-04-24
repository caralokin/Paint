/* 	Biblioteca: 
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422 e 023417
    Data da última modificação: 21/03/2013 
*/

#ifndef PBRUSH_paint_plusplus_H
#define PBRUSH_paint_plusplus_H

#define ESC 27

#include <stdio.h>
#include <windows.h>

#include "janela.h"
#include "conio_v3.2.3.h"
#include "pincel.h"
#include "graphics.h"
#include "ferramentas.h"

/*funcao que captura um evento verifica se e uma letra ou numero que foi digitado.
parametros
leitura => e a variavel onde vai ser guardado a entrada pelo teclado
posicao_x e posicao_y => e onde sera exibido o cursor para que efetue a leitura*/
void le_entrada_teclado(char leitura[], int posicao_x, int posicao_y);

/*funcao que imrime no rodape a posicao do pincel 
se ele esta ativado ou nao 
e o seu tamanho em pixel*/
void verifica_status_pincel(tipo_janela janela,tipo_pincel pincel);

/*funcao verifica as entradas do mouse
as variaveis x e y e a posicao do mouse em pixel
ferramentas e a estruta onde quarda as cores personalizadas e padrao
pincel estrutura que guarda os dados do pincel. Ex. posicao, tamanho, ativo ou nao */
void verifica_mouse(int x, int y, tipo_janela janela, tipo_ferramentas ferramentas, tipo_pincel *pincel);

void SeedFill_2(int x, int y, COLORREF fill_color, COLORREF border_color);

/*funcao onde o programa executa
janela recebe passa os dados da janela para funcao
ferramentas com a posicao onde sera colocada os icones*/
void executa_pbrush(tipo_janela janela, tipo_ferramentas ferramentas);

#endif
