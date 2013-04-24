/* 	Biblioteca: 
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422 e 023417
    Data da última modificação: 21/03/2013 
*/

#ifndef PBRUSH_FERRAMENTAS_H
#define PBRUSH_FERRAMENTAS_H

#include <stdio.h>
#include <windows.h>
#include <string.h>

#include "conio_v3.2.3.h"

typedef struct ferramentas
{
	COORD posicao_padrao; /*posicao das paletas padrao*/
	COORD posicao_personalizadas; /*posicao das paletas personalizadas*/
	COLORREF paleta_padrao[20]; /*vetor que vai guarda as cores padrao*/
	COLORREF paleta_personalizada[10]; /*vetor que vai guarda as cores personalizadas*/
	COORD posicao_icone_abrir; /*guarda a posicao do icone abrir arquivos*/
	COORD posicao_icone_salvar; /*guarda a posicao do icone salvar*/
	COORD posicao_edita_cor; /*guarda a posicao do icone editar cor*/
}tipo_ferramentas;

/*funcao que inicializa as variaveis necessarias para contruir as ferramentas*/
tipo_ferramentas inicia_ferramentas(tipo_janela janela);

/*A desenha_icon_abrire responsavel por chamar a funcao que vai 
abrir os  arquivos com extensao bmp*/
void desenha_icon_abrir();

/*A funcao desenha_disquete e responsavel por desenha o icone que ao ser clicado  vai chamar a funcao que salva na extensao bmp*/
void desenha_disquete();

/*pinta a borda do quadrado onde tem a cor selecionado para o pincel*/
void borda_status_pincel();

/* paleta que exibe a cor selecionada a funcao recebe a cor a qual o quadrado vai ser pintado
O paramentro de entrada e do tipo COLORREF  e a estrura com as informacoes da tela*/
void paleta_status_pincel(COLORREF color, tipo_janela janela);
/*desenha o icone deeditar cor e salva sua posicao na estrutura ferramentas*/
void desenha_edita_cor(tipo_ferramentas ferramentas);

/*chama as funcoes que vao desenhar as ferramentas na tela*/
void desenha_ferramentas(tipo_janela janela,tipo_ferramentas ferramentas);
#endif
