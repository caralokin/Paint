/* 	Biblioteca: 
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422 e 023417
    Data da última modificação: 21/03/2013 
*/

 #include <windows.h>    /* tipo BYTE */
 
#include "console_v1.5.4.h"  /* tamanhoJanelaConsole(), getTamanhoFonteConsole(), Evento(), tipo EVENTO */   
#include "conio_v3.2.3.h" /* getch() */
#include "graphics.h"   /* putpixel() */

 /* A funcao fundo_preto_disquete desenha todo a area do disquete*/
void fundo_preto_disquete()
{
	/*Declarando as variaveis e inicializando*/
	BYTE componente_vermelha, componente_verde, componente_azul;
	COLORREF cor;
	int coluna, lin, canto=10;

	componente_azul = componente_vermelha = componente_verde = 0; 
	cor = RGB(componente_vermelha, componente_verde, componente_azul);
	
	/*inicio da funcao*/
	for(coluna = 25; coluna < 60; coluna++)	/*coluna comeca em 25 para da um espaco entre o canto da tela e o icone*/
	{  
		if(coluna<55)	/*condiçao que faz o canto conrtado do disquete*/
		{					/*enquanto for menor que 55 ele vai pintar todos os pixel*/
	     for(lin = 10; lin <45; lin++)
			{
			putpixel(coluna, lin, cor);
			}	
		}
		else	/*quando for maior que 55 ele vai comecar a pinta a coluna sempre uma linha a baixo*/
		{
		for(lin = canto; lin <45; lin++)
			{
			putpixel(coluna, lin, cor);
			}		
			   canto++;	/*incrementando a variavel que controla o inicio da linha depois da coluna 55*/
		}
	}
}

/*A funcao desenha_lata_disquete desenha a lata que faz proteçao ao disco 
quando nao esta se usando o disquete.*/
void desenha_lata_disquete()
{
	/*Declarando as variaveis e inicializando*/
	BYTE componente_vermelha, componente_verde, componente_azul;
	COLORREF cor;
	int coluna, lin;
	componente_azul = componente_vermelha = componente_verde = 109; 
	cor = RGB(componente_vermelha, componente_verde, componente_azul);

	/*inicio da funcao*/
	for(coluna = 30; coluna < 55; coluna++)/*desenhando e pintando de cinza*/
	{  

	    for(lin = 13; lin < 22; lin++)
			{
				putpixel(coluna, lin, cor);
			}		
	}
	componente_azul = componente_vermelha = componente_verde = 0;
	cor = RGB(componente_vermelha, componente_verde, componente_azul); /*salvando a cor branco*/
		for(coluna = 48; coluna < 52; coluna++)
	{  

	    for(lin = 14; lin < 21 ; lin++)
			{
								putpixel(coluna, lin, cor); /*imprimindo o buraco que existe na lata de proteçao do disquete*/
			}		
	}
}

 /*A funcao desenha_branco_disquete e responsavel por desenha a area branca onde se  
escreve o nome do disquete.*/
void desenha_branco_disquete()
{
	/*Declarando as variaveis e inicializando*/
	BYTE componente_vermelha, componente_verde, componente_azul;
	COLORREF cor;
	int coluna, lin;
	componente_azul = componente_vermelha = componente_verde = 255; 
	cor = RGB(componente_vermelha, componente_verde, componente_azul);
	
	/*inicio da funcao*/
	for(coluna = 28; coluna < 57; coluna++)	
	{  
	    for(lin = 25; lin < 43; lin++)
			{
				putpixel(coluna, lin, cor);
			}		
	}
}

/*A funcao desenha_aba_clara ilustra uma das abas que compoem o icone abrir pasta
* Ao clica no neste icone vai ser chamada a funcao que abre arquivos com extensao BPM*/
void desenha_aba_clara()
{
	/*Declarando as variaveis e inicializando*/
	BYTE componente_vermelha, componente_verde, componente_azul;
	COLORREF cor;
	int coluna, lin,canto=10;
	componente_vermelha = 248;
	componente_verde = 236; 
	componente_azul =153;
	cor = RGB(componente_vermelha, componente_verde, componente_azul);
	
	/*inicio da funcao*/
	for(coluna = 70; coluna < 100; coluna++)	/*sera desenhado no apartir do pixel 70 */
	{  
		if(coluna<95)	/*condiçao que posibilita criar a pequena aba da pasta  */
		{
		for(lin = canto; lin <25+canto; lin++)	/*a variavel canto esta sendo soma na segunda condiçao para criar o efeito da coluna posterior sempre comecar uma linha abaixo da anterior*/
			{
			putpixel(coluna, lin, cor);
			}	
		if(coluna%4==0)/*condicao que incrementa a o canto */
		{
			   canto++;	/*por causa dessa condicao a 4 coluna a seguinte vai comecar uma linha abaixo*/
		}
		}
		else
		{
		for(lin = canto+10; lin <25+canto; lin++)	/*criando uma pequena aba onde nas pasta reais se usa pra colocar o nome das pasta*/
			{
			putpixel(coluna, lin, cor);
			}
					if(coluna%4==0)
		{
			   canto++;
		}
		}
	}
}

void desenha_aba_escura()
{
		/*Declarando as variaveis e inicializando*/
	BYTE componente_vermelha, componente_verde, componente_azul;
	COLORREF cor;
	int coluna, lin,canto=10;
	componente_vermelha = 241;
	componente_verde = 162; 
	componente_azul =41;
	canto =10;
	cor = RGB(componente_vermelha, componente_verde, componente_azul);
	
		/*inicio da funcao*/
	for(coluna = 70; coluna < 90; coluna++)	/*a criaçao dessa segunda aba usa a mesma logica da anterior  a unica diferenca e na incrementacao da variavel  canto*/
	{  
		if(coluna<87)
		{
		for(lin = canto; lin < 25+canto; lin++)
			{
			putpixel(coluna, lin, cor);
			}		
		if(coluna%2==0)	
		{
			   canto++;/*a variavel  canto esta sendo incrementando a cada dois para criar um angulo de caida diferente uma aba da outra*/
		}
		}
		else
		{
		for(lin = canto; lin <15+canto; lin++)
			{
			putpixel(coluna, lin, cor);
			}
		if(coluna%2==0)
		{
			   canto++;
		}
		}
	}
}
