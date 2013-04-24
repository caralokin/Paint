/* 	Biblioteca: Janela
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422
    Data da última modificação: 21/03/2013 
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>

#include "console_v1.5.3.h"
#include "icone.h"
#include "janela.h"
#include "paleta_cores.h"
#include "graphics.h"
#include "conio_v3.2.3.h"

/*Obtem as informacoes da janela inicial*/	
tipo_janela obtem_dados_janela()
{
	tipo_janela janela;
	
	janela.cor_anterior =  getCoresJanela(); /*Obtem a cor da fonte e do fundo da janela inicial*/
	
	janela.tamanho_fonte = getTamanhoFonteConsole(); /*Obtem o tamanho da fonte em pixel*/
	
	janela.tamanho_anterior = tamanhoJanelaConsole(); /*Obetem o tamanho da janela em numero de caracteres*/
	
	janela.tamanho_maximo = MaxDimensaoJanela(); /*Obetem o tamanho maximo da janela em caracteres(na resolucao atual do monitor)*/
	
	janela.tamanho_area_desenho.X = janela.tamanho_maximo.X * janela.tamanho_fonte.X; /*Obtem  a largura total da janela em pixel*/
	
	janela.tamanho_area_desenho.Y = janela.tamanho_maximo.Y * janela.tamanho_fonte.Y - tamanho_status - tamanho_barra_ferramentas; /*Obtem a altura da area de desenho em pixel*/
	
	return janela; /*Retorna os dados obtidos*/
}
	
/*Redimensiona a janela*/
void redimensiona_janela(tipo_janela janela, int opcao)
{
	/*Maxiiza*/
	if(opcao == 1)
	{
		setPosicaoJanela(0, 0); /*Posiciona a janela no canto esquerdo superior*/
		setCursorStatus(DESLIGAR); /*Desliga o cursor*/
		setDimensaoJanela(janela.tamanho_maximo.X, janela.tamanho_maximo.Y); /*Redimensiona para o tamanho maximo*/
		setTituloConsole("Paint Brush++"); /*Define o titulo da janela*/
	}
	/*Retorna ao tamanho inicial*/
	else
	{
		setCursorStatus(LIGAR); /*Liga o cursor*/
		setDimensaoJanela(janela.tamanho_anterior.X, janela.tamanho_anterior.Y); /*Redimensiona para o tamanho inicial*/
		setTituloConsole("Prompt"); /*Define o titulo da janela*/
		textattr( (BLACK << 4) | WHITE);
	}
}

/*Desenha o layout da janela(barra de ferramentas, area de desenho, barra de status)*/
void desenha_layout(tipo_janela janela)
{
	int linha, coluna;
	
	/*Percorre todas as linhas de pixel da janela*/
	for(linha = 0; linha < janela.tamanho_maximo.Y * janela.tamanho_fonte.Y; linha++)
	{
		/*Percorre todas as colunas de pixel da janela*/
		for(coluna = 0; coluna < janela.tamanho_maximo.X * janela.tamanho_fonte.X; coluna++)
		{
			/*Se o loop estiver dentro da barra de ferramentas*/
			if(linha < tamanho_barra_ferramentas)
			{
				putpixel(coluna, linha, RGB(198, 206, 240)); /*Pinta a barra de ferramentas*/
			}
			/*Se o loop estiver dentro da area de desenho*/
			if(linha > tamanho_barra_ferramentas && linha < tamanho_barra_ferramentas + janela.tamanho_area_desenho.Y)
			{
				putpixel(coluna, linha, RGB(255, 255, 255)); /*Pinta a area de desenho*/
			}
			/*Se o loop estiver dentro da barra de status*/
			if(linha > tamanho_barra_ferramentas + janela.tamanho_area_desenho.Y)
			{
				putpixel(coluna, linha, RGB(255, 255, 255)); /*Pinta a barra de status*/
			}
		}
	}
}

/*Verifica o nome do arquivo executavel*/
void verifica_nome(char nome[])
{
	char *str1,  *str2;
	
	/*Se o nome do programa estiver errado, sera verificado se o programa nao esta sendo executado de algum diretorio acima do diretorio do programa*/
	if(strcmp(nome, "pbrush++") && strcmp(nome, "pbrush++.exe"))
	{
		str1 = strtok(nome, "\\");
		do
		{
			if(str1 != NULL) 
			{
				str2 = str1;
			}
			
			str1 = strtok(NULL, "\\");
		
		}while(str1 != NULL);
		
		if(strcmp(str2, "pbrush++")  && strcmp(str2, "pbrush++.exe") )
		{
			printf("\nO nome do programa foi modificado.\nO nome deve ser pbrush++.exe\n");
			exit (0);
		}			
	}
}
