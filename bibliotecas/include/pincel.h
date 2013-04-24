/* 	Biblioteca: 
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422
    Data da última modificação: 21/03/2013 
*/

#ifndef PBRUSH_PINCEL_H
#define PBRUSH_PINCEL_H

#include <windows.h> 
#include "janela.h"

typedef struct pinceis
{
	COORD posicao; /*Posicao do pincel na tela*/
	COLORREF cor; /*Cor do pincel*/
	int tamanho; /*Tamanho do pincel*/
	int estado; /*Define o estado do pincel.  0 = DESATIVADO; 1 = ATIVADO*/
	int tam_personalizada; /*marca a quantidade de cores personalizadas*/
} tipo_pincel;

/*Define as conigurações iniciais do pincel*/
tipo_pincel inicia_pincel(tipo_janela janela);

void redimensiona(tipo_janela janela, tipo_pincel *pincel, int opcao);

void movimenta(tipo_janela janela, tipo_pincel *pincel, int opcao);

#endif
