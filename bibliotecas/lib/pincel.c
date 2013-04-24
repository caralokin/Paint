/* 	Biblioteca: 
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422
    Data da última modificação: 21/03/2013 
*/

#include <windows.h>
#include "pincel.h" 
#include "janela.h"


/*Define as conigurações iniciais do pincel*/
tipo_pincel inicia_pincel(tipo_janela janela)
{
	tipo_pincel pincel;
	
	/*Posiciona o indicador do pincel no meio horizontal da tela*/
	pincel.posicao.X = (int) ((janela.tamanho_maximo.X * janela.tamanho_fonte.X)/ 2);
	
	/*Posiciona o indicador do pincel no meio vertical da tela*/
	pincel.posicao.Y = (int) ((janela.tamanho_maximo.Y * janela.tamanho_fonte.Y) / 2);
	
	/*Inicia o pincel com a cor preta*/
	pincel.cor = RGB(0, 0, 0);
	
	/*Define o tamanho inicial do painel*/
	pincel.tamanho = 1;
	
	/*Define o pincel como desativado*/
	pincel.estado = 0;
	/*Marca a posicao do vertor cores personalizadas*/
	pincel.tam_personalizada=0;

	return pincel;
}

void redimensiona(tipo_janela janela, tipo_pincel *pincel, int opcao)
{
	if(opcao == 1)
	{
		if(pincel->tamanho < janela.tamanho_area_desenho.Y - tamanho_barra_ferramentas)
		{
			++pincel->tamanho;
		}
	}
	else
	{
		if(pincel->tamanho > 1)
		{
			--pincel->tamanho;
		}
	}
}

void movimenta(tipo_janela janela, tipo_pincel *pincel, int opcao)
{
	if(opcao == 1)
	{
		if(pincel->posicao.X > 0)
		{
			--pincel->posicao.X;
		}
	}
	else if(opcao == 2)
	{
		if(pincel->posicao.X < janela.tamanho_area_desenho.X)
		{
			pincel->posicao.X++;
		}
	}
	else if(opcao == 3)
	{
		if(pincel->posicao.Y -1 > tamanho_barra_ferramentas )
		{
			--pincel->posicao.Y;
		}
	}
	if(opcao == 4)
	{
		if(pincel->posicao.Y + pincel->tamanho +  1 < janela.tamanho_area_desenho.Y + tamanho_barra_ferramentas)
		{
			++pincel->posicao.Y;
		}
	}
}
