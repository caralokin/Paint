/* 	Biblioteca: Janela
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422
    Data da última modificação: 21/03/2013 
*/

#ifndef PBRUSH_JANELA_H
#define PBRUSH_JANELA_H

#include <stdio.h>
#include <windows.h>

#include "console_v1.5.4.h"

#define tamanho_barra_ferramentas 60 /*Define a largura da barra de ferramentas*/
#define tamanho_status 30 /*Define a largura da barra de status*/

/*Estrutura que armazenara as informacoes sobre a janela*/
typedef struct janelas
{
	CORES cor_anterior; /*Cor da fonte e do fundo*/
	COORD tamanho_fonte; /*Tamanho da fonte*/
	COORD tamanho_anterior; /*Tamanho da janela em numeros de caracteres antes de ser redimensionada*/
	COORD tamanho_maximo; /*Tamanho maximo que a janela pode assumir, em numeros de caracteres*/
	COORD tamanho_area_desenho; /*Tamanho da area de desenho em pixel, após retirado o espaço nescessario para a barra de ferramentas e da barra de status*/

}tipo_janela;

/*Obtem as informacoes da janela inicial
Entrada
->void
Retorno
->Uma estrutura do tipo 'tipo_janela'
*/	
tipo_janela obtem_dados_janela();

/*Redimensiona a janela
Entrada
->Uma estrutura do tipo 'tipo_janela' e um inteiro
Opcao
-> 1:Maximiza; 2:Retorna ao tamanho original
Retorno
->void
*/
void redimensiona_janela(tipo_janela janela, int opcao);

void desenha_layout(tipo_janela janela);

/*Verifica o nome do arquivo executavel
Entrada
->Uma string
Retorno
->void
*/
void verifica_nome(char nome[]);

#endif
