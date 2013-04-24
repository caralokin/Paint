/* 	Biblioteca: Janela
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422
    Data da última modificação: 21/03/2013 
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>

#include "janela.h"
#include "ferramentas.h"
#include "console_v1.5.3.h"
#include "icone.h"
#include "paleta_cores.h"
#include "graphics.h"
#include "conio_v3.2.3.h"



/*funcao que inicializa as variaveis necessarias para contruir as ferramentas*/
tipo_ferramentas inicia_ferramentas(tipo_janela janela)
{
	tipo_ferramentas ferramentas;
	int posicao_x, posicao_y;
	posicao_x=(janela.tamanho_maximo.X * janela.tamanho_fonte.X);
	posicao_y=(janela.tamanho_maximo.Y* janela.tamanho_fonte.Y);
	ferramentas.posicao_padrao.X = ferramentas.posicao_personalizadas.X = (int) (posicao_x- (posicao_x%(posicao_x-230)) );/*Marca em pixel o inicio das paletas*/
	ferramentas.posicao_padrao.Y = (int)  (posicao_y%(posicao_y-3));	 /*colocando a paleta padrao na posicao 3 em pixel*/
	ferramentas.posicao_personalizadas.Y = ((((janela.tamanho_maximo.Y * janela.tamanho_fonte.Y)* 0.08) / 3)*2.3);/*posicionando a paleta personalizada abaixo da padrao*/
	posicao_x = (janela.tamanho_maximo.X * janela.tamanho_fonte.X); /*calculando a posicao x para coloca o editor de cor*/
	posicao_x=posicao_x - (posicao_x%(posicao_x-40));
	posicao_y = (janela.tamanho_maximo.Y * janela.tamanho_fonte.Y); /*calculando a posicao y para colocar o editor de cor*/
	posicao_y=posicao_y%(posicao_y-10);
	ferramentas.posicao_edita_cor.X=posicao_x;	/*passando os valores para as variavel responsaveis*/
	ferramentas.posicao_edita_cor.Y=posicao_y;
	
	ferramentas.paleta_padrao[0] = RGB(0, 0, 0); ferramentas.paleta_padrao[1] = RGB(127, 127, 127); ferramentas.paleta_padrao[2] = RGB(136, 0, 21); ferramentas.paleta_padrao[3] = RGB(237, 28, 36); ferramentas.paleta_padrao[4] = RGB(255, 127, 39); /*inicializando as cores padroes*/
	ferramentas.paleta_padrao[5] = RGB(255, 242, 0); ferramentas.paleta_padrao[6] = RGB(34, 177, 76); ferramentas.paleta_padrao[7] = RGB(0, 162, 232); ferramentas.paleta_padrao[8] = RGB(63, 72, 204); ferramentas.paleta_padrao[9] = RGB(163, 73, 164);
	ferramentas.paleta_padrao[10] = RGB(255, 255, 255); ferramentas.paleta_padrao[11] = RGB(195, 195, 195); ferramentas.paleta_padrao[12] = RGB(185,122, 87); ferramentas.paleta_padrao[13] = RGB(255, 174, 201); ferramentas.paleta_padrao[14] = RGB(255, 201, 14);
	ferramentas.paleta_padrao[15] = RGB(239, 228, 176); ferramentas.paleta_padrao[16] = RGB(181, 230, 29); ferramentas.paleta_padrao[17] = RGB(153, 217, 234); ferramentas.paleta_padrao[18] = RGB(112, 146, 190); ferramentas.paleta_padrao[19] = RGB(200, 191, 231);
	
	ferramentas.paleta_personalizada[0] = ferramentas.paleta_personalizada[1] = ferramentas.paleta_personalizada[2] = ferramentas.paleta_personalizada[3] = RGB(198, 206, 240); /*inicializando as cores personalizadas com a mesma cor da barra de ferramentas*/
	ferramentas.paleta_personalizada[4] = ferramentas.paleta_personalizada[5] = ferramentas.paleta_personalizada[6] = ferramentas.paleta_personalizada[7] = RGB(198, 206, 240);
	ferramentas.paleta_personalizada[8] = ferramentas.paleta_personalizada[9] = RGB(198, 206, 240);
	return ferramentas;
}


/*A desenha_icon_abrire responsavel por chamar a funcao que vai 
abrir os  arquivos com extensao bmp*/
void desenha_icon_abrir()
{
	desenha_aba_clara();	/*chamada das funcoes que juntas desenha o icone de abrir arquivos*/
	desenha_aba_escura();
}

/*A funcao desenha_disquete e responsavel por desenha o icone que ao ser clicado 
vai chamar a funcao que salva na extensao bmp*/
void desenha_disquete()
{
	fundo_preto_disquete();	/*chamada das funcoes que juntas vao desenhar o disquete*/
	desenha_lata_disquete();
	desenha_branco_disquete();
}

/* paleta que exibe a cor selecionada*/
void paleta_status_pincel(COLORREF color, tipo_janela janela)
{
	int linha,/*Quantidade de linha de cores da paleta(default = 2, personalizada = 1)*/
		coluna,/*Quantidade de cores por linha*/
		posicao = (int) (janela.tamanho_maximo.X * janela.tamanho_fonte.X);/*informa onde comeca a paletas de cores padrao*/
	int pos_col = (int) (posicao- (posicao%(posicao-264)) ) , /*posicionando a paleta antes das cores padrao*/
		tam=21; /*tamanho do quadrado*/
	for(coluna=pos_col+2;coluna<pos_col+tam-2;coluna++)
	{
		for(linha=12+2; linha<12+tam-2;linha++)
		{
			putpixel(coluna, linha, color);
		}
	}
	borda_paleta(pos_col, pos_col+tam, 12, 12 + tam); /*imprimindo a borda*/
}

void desenha_edita_cor(tipo_ferramentas ferramentas)
{
	/*declaracao de variaveis e icnicializacao*/
	BYTE componente_vermelha, componente_verde, componente_azul;
	COLORREF cor;
	int coluna, lin;
	
	componente_azul = 80; 
	componente_vermelha = componente_verde = 0; 
		for(lin = ferramentas.posicao_edita_cor.Y ; lin < ferramentas.posicao_edita_cor.Y + 35; lin++) /* esse for faz o degrade da cor azul com 10 pixel delargura e 35 de comprimento*/
		    {
				cor = RGB(componente_vermelha, componente_verde, componente_azul);
				for(coluna = ferramentas.posicao_edita_cor.X; coluna < ferramentas.posicao_edita_cor.X + 10; coluna++)
				{			
					putpixel(coluna, lin, cor);
				}
	 componente_azul+=4; /*incrementando a cor*/
			}
			componente_azul = 0; 
	componente_vermelha = 80;
	componente_verde = 0; 
		for(lin = ferramentas.posicao_edita_cor.Y; lin < ferramentas.posicao_edita_cor.Y + 35; lin++) /*criando o degrade da cor vermelha com  as mesmas medidas da anterior*/
		    {
				cor = RGB(componente_vermelha, componente_verde, componente_azul);
				for(coluna = ferramentas.posicao_edita_cor.X + 10; coluna < ferramentas.posicao_edita_cor.X + 20; coluna++)
					{			
						putpixel(coluna, lin, cor);
					}
	 componente_vermelha+=4; /*incrementando a cor */
			}
			componente_azul = 0; 
	componente_vermelha = 0;
	componente_verde = 80; 
		    for(lin = ferramentas.posicao_edita_cor.Y; lin < ferramentas.posicao_edita_cor.Y + 35; lin++)/*criando o degrade da cor verde com as mesmas medidias das anteriores*/
		    {
				cor = RGB(componente_vermelha, componente_verde, componente_azul);
					for(coluna = ferramentas.posicao_edita_cor.X + 20; coluna < ferramentas.posicao_edita_cor.X + 30; coluna++)
					{			
			putpixel(coluna, lin, cor);
					}
	 componente_verde+=4; /*incrementando a cor*/
			}
}

void desenha_ferramentas(tipo_janela janela, tipo_ferramentas ferramentas)
{
	/*declaracao de variaveis e inicializacao*/
	int espaco;
	COLORREF cor_pincel;
	cor_pincel=RGB(0,0,0);
	espaco = (int) ((janela.tamanho_maximo.Y * janela.tamanho_fonte.Y)* 0.08) / 3; /*varivel que guarda o tamanho do quadrado de cada cor*/
	
	gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+1, janela.tamanho_maximo.Y-1);	/*posicionando o status na tela*/
	textattr( (WHITE << 4) | BLACK); /*trocando a cor da letra e do fundo da letra*/
	printf("Status:");
	gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+25, janela.tamanho_maximo.Y-1); /*posicionando a palavra pincel*/
	printf("Pincel:");
	gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+50, janela.tamanho_maximo.Y-1); /*posicionando a plalavra taanho*/
	printf("Tamanho Pincel:");
	desenha_disquete (); /*funcao que desenha o disquete*/
	gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+3,(janela.tamanho_maximo.Y-janela.tamanho_maximo.Y)+5);
	printf("Salvar ");	/*Escreve em baixo de cada icone a sua funcao*/
	printf("Abrir");
	desenha_icon_abrir (); /*Desenha  o icone da pasta*/
	paleta_status_pincel(cor_pincel,janela); /*desenha a paleta de status que mostra a cor selecionada do pincel*/
	imprime_paleta(1, espaco,ferramentas); /*imprimi  as paletas padrao*/
	imprime_paleta(0, espaco,ferramentas); /*imprime paleta personalizada*/
	desenha_edita_cor(ferramentas); /*desenha o icone de editar cor*/
}
