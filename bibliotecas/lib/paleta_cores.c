/* 	Biblioteca: 
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422 e 023417
    Data da última modificação: 21/03/2013 
*/

#include <windows.h>

#include "console_v1.5.4.h"  /* tamanhoJanelaConsole(), getTamanhoFonteConsole(), Evento(), tipo EVENTO */   
#include "graphics.h"   /* putpixel() */
#include "janela.h"
#include "ferramentas.h"

/*pinta a borda dos quadrados onde tem as cores da paleta padrao e das personalizadas*/
void borda_paleta(int ini_col, int fim_col, int ini_lin, int fim_lin)
{
	int coluna, lin;
	for(coluna = ini_col; coluna < fim_col; coluna++)
	{
	    for(lin = ini_lin; lin < fim_lin; lin++)
		{
		    if(coluna==ini_col || coluna==fim_col-1 || lin==ini_lin || lin==fim_lin-1)	/*condicao que faz pintar somente as extremidades do quadrado de preto*/
			{
			putpixel(coluna, lin,RGB(0, 0, 0) );
			}
			if(coluna==ini_col + 1 || coluna== fim_col-2 || lin==ini_lin+1 || lin==fim_lin-2) /*condicao que pinta um quadrado da mesma cor da branca dentro do quadro preto*/
			{
			if(coluna!=ini_col && coluna!=fim_col-1 && lin!=ini_lin && lin!=fim_lin-1)/*tratando para que nenhum pixel do quadrado preto seja pintado da cor dabranca*/
				{
				putpixel(coluna, lin, RGB(255, 255, 255));
				}
			}
		}
	}
}

/*Desenha os quadrados coloridos da paleta de cores*/
void quadrado_cor(int x, int y, int tam, COLORREF cor)
{
	int linha, coluna;
	
	for(linha = y; linha  < y + tam; linha++)
	{
		for(coluna = x; coluna < x + tam; coluna++)
		{
			putpixel(coluna, linha, cor);
		}
	}
}

void imprime_paleta(int tipo, int espaco, tipo_ferramentas ferramentas)
{
	/*Contadores*/
	int linha,/*Quantidade de linha de cores da paleta(default = 2, personalizada = 1)*/
		coluna,/*Quantidade de cores por linha*/
		cor = 0;/*Quantidade de cores*/
		
		/*variaveis para controle de cor*/
	/*Paleta default*/
	if(tipo == 1)
	{
		/*Percorre as linhas da palete*/
		for(linha = 0; linha <2 ; linha++)
		{
			/*Percorre as colunas da paleta*/
			for(coluna = 0;coluna < 10; coluna++)
			{
				/*Imprime a cor
				coluna * espaco = coordenada X em pixel de onde deve começar a ser impressa a respectiva cor
				linha * espaco = coordenada Y em pixel de onde deve começar a ser impressa a tespectiva cor
				*/
				quadrado_cor(coluna * espaco+ferramentas.posicao_padrao.X, linha* espaco+ferramentas.posicao_padrao.Y, espaco, ferramentas.paleta_padrao[cor]);
				borda_paleta(coluna * espaco+ferramentas.posicao_padrao.X, coluna * espaco+ferramentas.posicao_padrao.X+espaco, linha * espaco+ferramentas.posicao_padrao.Y, linha * espaco+ferramentas.posicao_padrao.Y+espaco);
				/*Passa para a proxima cor*/
				cor++;
			}
		}	
	}
	else
	{
		/*Percorre as colunas da paleta*/
		for(coluna = 0;coluna < 10; coluna++)
		{
			/*Imprime a cor
			coluna * espaco = coordenada X em pixel de onde deve começar a ser impressa a respectiva cor
			linha * espaco = coordenada Y em pixel de onde deve começar a ser impressa a tespectiva cor
			*/
	
			quadrado_cor(coluna * espaco+ferramentas.posicao_personalizadas.X,ferramentas.posicao_personalizadas.Y, espaco, ferramentas.paleta_personalizada[cor]);
			borda_paleta(coluna * espaco+ferramentas.posicao_personalizadas.X,  coluna * espaco+ferramentas.posicao_personalizadas.X+espaco, ferramentas.posicao_personalizadas.Y,ferramentas.posicao_personalizadas.Y+espaco);
			/*Passa para a proxima cor*/
			cor++;
		}
	}
}
