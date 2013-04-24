/* 	Biblioteca: 
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422 e 023417
    Data da última modificação: 21/03/2013 
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h> 

#include "janela.h"
#include "conio_v3.2.3.h"
#include "wincon.h"
#include "console_v1.5.3.h"
#include "pincel.h"
#include "graphics.h"
#include "paleta_cores.h"
#include "ferramentas.h"
#include "paint_plusplus.h"
#include "bitmap.h"

/*funcao que captura um evento verifica se e uma letra ou numero que foi digitado.
parametros
leitura => e a variavel onde vai ser guardado a entrada pelo teclado
posicao_x e posicao_y => e onde sera exibido o cursor para que efetue a leitura*/
void le_entrada_teclado(char leitura[], int posicao_x, int posicao_y)
{
		int pos=0, controle=posicao_x;
		EVENTO entrada;
		while(entrada.teclado.codigo_tecla!=13) /*Condicao que so sai fora do laco quando pressionar o enter*/
			{
				gotoxy(posicao_x, posicao_y); /*possicionando o cursor onde sera efetuado a leitura*/
				entrada=Evento(); /*captando o evento*/
				if((entrada.teclado.status_tecla==LIBERADA  && entrada.teclado.codigo_tecla>47 && entrada.teclado.codigo_tecla<91)  ||  /*verifica se ouve uma tecla liberada e se essa tecla corresponde a um numero de 0  ate  z*/
				(entrada.teclado.codigo_tecla==8 && entrada.teclado.status_tecla==PRESSIONADA) || (entrada.teclado.codigo_tecla==32)) /*verifica se a tecla foi pressionada foi o espaco ou backspace*/
				{
				if(entrada.teclado.status_tecla==LIBERADA  && entrada.teclado.codigo_tecla>64 && entrada.teclado.codigo_tecla<91)  /*verifica se uma letra que foi pressionado caso verdadeiro ele guarda na string e imprime na tela*/
 
				{
				leitura[pos]=entrada.teclado.codigo_tecla; /*passando a tecla lida para a string*/
				printf("%c",leitura[pos]); /*imprimindo a tecla para o usuario ver*/
				posicao_x++; /*repossicionando o cursor uma posicao a frente da que foi impressa na tela*/
				pos++; /*atualizando a variavel de controle da string*/
				}
				
				if((entrada.teclado.status_tecla==LIBERADA  && entrada.teclado.codigo_tecla>47 && entrada.teclado.codigo_tecla<58) ||  /*verifica se foi um numero ou o espaco que foi pressionado caso verdadeiro ele guarda na string e imprime na tela*/
				(entrada.teclado.codigo_tecla==32 && entrada.teclado.status_tecla==PRESSIONADA)) 
				{
				leitura[pos]=entrada.teclado.codigo_tecla; /*passando a tecla lida para a string*/
				printf("%c",leitura[pos]); /*imprimindo a tecla para o usuario ver*/
				posicao_x++; /*repossicionando o cursor uma posicao a frente da que foi impressa na tela*/
				pos++; /*atualizando a variavel de controle da string*/
				}
				/*codigo_tecla =8 verifica se foi pressionado backspace e a posicao_x > controle valida pra nao apagar ate o final da pagina*/
				if(entrada.teclado.codigo_tecla==8 && entrada.teclado.status_tecla==PRESSIONADA && posicao_x >controle)
				{
					posicao_x --; /*decrementando a posicao x do cursor para imprimir novamente em cima da lletra digitada errada*/
					pos--; /*atualizando a variavel de controle da string*/
					gotoxy(posicao_x, posicao_y);
					leitura[pos]=' '; /*deixando em branco novamente a posicao do vetor ja que a letra que estava ali foi apagada pelo usuari*/
					printf("%c",leitura[pos]);	/*imprimindo na tela o buffer vazio para que o usuario perceba que foi apagado a letra*/
				}
				}
			}
}

/*funcao que imprime os dados na barra de status*/
void verifica_status_pincel(tipo_janela janela,tipo_pincel pincel)
{
	gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+9, janela.tamanho_maximo.Y-1); /*imprimindo a posicoa do pincel no rodapé*/
	printf("           ");
	gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+9, janela.tamanho_maximo.Y-1); /*imprimindo a posicoa do pincel no rodapé*/
	printf("%d | %d",pincel.posicao.X,pincel.posicao.Y);
	gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+35, janela.tamanho_maximo.Y-1); /*apagando o status anterior do pincel e escrevendo o proximo*/
	printf("           ");
	if(pincel.estado==0)
		{
			gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+35, janela.tamanho_maximo.Y-1); 
			printf("Desativado"); /*escrevendo o status*/
		}
	if(pincel.estado==1)
		{
			gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+35, janela.tamanho_maximo.Y-1);
			printf("Ativado"); /*escrevendo o status*/
		}
	gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+66, janela.tamanho_maximo.Y-1); /*apagando o tamanho anterior*/
	printf("           ");
	gotoxy((janela.tamanho_maximo.X-janela.tamanho_maximo.X)+66, janela.tamanho_maximo.Y-1); /*posicionando onde e impresso o tamanho do pincel*/
	printf("%d px",pincel.tamanho); /*imprime o tamanho atual*/
}

/*funcao que captura os eventos do mouse*/
void verifica_mouse(int x, int y, tipo_janela janela, tipo_ferramentas ferramentas, tipo_pincel *pincel)
{
	/*declaraçao e inicializacao das variavel*/
	char edita[20], *aux;
	int espaco, /*variavel que tem o tamanho do quadro das paletas*/
	rgb[3], /*onde sera salva os valores da nova cor RGB*/
	cont=0; /*variavel que controla a posicao do vetor rgb*/
	EVENTO entrada;
	espaco=(int) ((janela.tamanho_maximo.Y * janela.tamanho_fonte.Y)* 0.08) / 3;
	
			if(x>25 && x<25+35 && y>10 && y<10+35  ) /*verifica se esta clicando no icone salvar*/
		{
			salvar_imagem("imagem2.bmp", janela);
		}
			if(x>70 && x<70+35 && y>10 && y<10+35 ) /*verifica se esta clicando no icone abrir*/
		{
			abrir_imagem("imagem.bmp", janela);
		}
			if(x>ferramentas.posicao_edita_cor.X && x<ferramentas.posicao_edita_cor.X+30 && /*verifica se esta clicando no icone editar cor*/
			y>ferramentas.posicao_edita_cor.Y && y<ferramentas.posicao_edita_cor.Y+35 ) 
		{
			if(pincel->tam_personalizada==10) pincel->tam_personalizada=0; /*verifica se as paletas personalizadas estao cheias, caso isso aconteca ele coloca a nova cor na 1 posicao*/
			setCursorStatus(LIGAR);
						gotoxy(janela.tamanho_maximo.X - 60, janela.tamanho_maximo.Y - 1);
			printf("Digite os valores da cor: ");
			gotoxy(janela.tamanho_maximo.X - 60, janela.tamanho_maximo.Y);
			printf("Obs.: Exemplo do editar cor:169 169 169");
			le_entrada_teclado(edita, janela.tamanho_maximo.X - 30, janela.tamanho_maximo.Y-1); /*funcao que efetua a leitura de uma string atraves do evento*/
			aux = strtok (edita," "); /*copiando p/ o vetor aux tudo que tive antes do primeiro espaca*/
		  while (aux != NULL || cont<3)
		  {
				rgb[cont]=atoi(aux); /*guardando e convertendo a string que esta em aux no vetor de inteiro */
				cont++; 
			aux = strtok (NULL, " "); /*pegando o segundo falor depois do espaco*/
		}
			ferramentas.paleta_personalizada[pincel->tam_personalizada]=RGB(rgb[0],rgb[1],rgb[2]); /*guardando a cor no vetor onde esta armazenado as cores personalizadas*/
			paleta_status_pincel(ferramentas.paleta_personalizada[pincel->tam_personalizada] , janela); /*passando a nova cor para a paleta de status de cor*/
			pincel->cor=ferramentas.paleta_personalizada[pincel->tam_personalizada]; /*atualizando a cor do pincel*/
			if(pincel->tam_personalizada==0) quadrado_cor(ferramentas.posicao_personalizadas.X, ferramentas.posicao_personalizadas.Y, espaco,pincel->cor); /*imprimindo a nova cor na primeira paleta de cores personalizadas*/
			if(pincel->tam_personalizada>0) /*imprime a nova cor nas demais paletas personalizadas*/
			{
				quadrado_cor(ferramentas.posicao_personalizadas.X+(pincel->tam_personalizada*espaco), ferramentas.posicao_personalizadas.Y, espaco,pincel->cor);
			}
			gotoxy(janela.tamanho_maximo.X - 60, janela.tamanho_maximo.Y - 1); 
			printf("                                          "); /*apagando onde foi escrito a ensagem para editar cor*/
			gotoxy(janela.tamanho_maximo.X - 60, janela.tamanho_maximo.Y); 
			printf("                                          "); /*apagando onde foi escrito a ensagem para editar cor*/
			++pincel->tam_personalizada; /*incrementando a paleta de cores personalizada*/
			setCursorStatus(DESLIGAR);
		}
		if(x>(janela.tamanho_area_desenho.X - janela.tamanho_area_desenho.X)+1 && x<janela.tamanho_area_desenho.X && 
			y>(janela.tamanho_area_desenho.Y - janela.tamanho_area_desenho.Y)+tamanho_barra_ferramentas  && y<janela.tamanho_area_desenho.Y + tamanho_barra_ferramentas ) /*Delimitando a area de desenho para que quando clica na area ele capture a cor do pixel*/
		{
			pincel->cor=getpixel(x,y); /*pegando a cor do pixel e passando para a cor do pincel*/
			paleta_status_pincel(pincel->cor , janela); /*colocando a cor da paleta de status a mesma do pincel*/
		}
		
		if(x>ferramentas.posicao_padrao.X && x<ferramentas.posicao_padrao.X+espaco &&  /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y  && y+5<ferramentas.posicao_padrao.Y +espaco) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[0] , janela);
			pincel->cor=ferramentas.paleta_padrao[0];
		}
			if(x>ferramentas.posicao_padrao.X + espaco && x<ferramentas.posicao_padrao.X + (2*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y && y+5< ferramentas.posicao_padrao.Y + espaco) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[1] , janela);
			pincel->cor=ferramentas.paleta_padrao[1];
		}
			if(x>ferramentas.posicao_padrao.X + (2*espaco) && x<ferramentas.posicao_padrao.X + (3*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y && y+5< ferramentas.posicao_padrao.Y + espaco) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[2] , janela);
			pincel->cor=ferramentas.paleta_padrao[2];
		}
			if(x>ferramentas.posicao_padrao.X + (3*espaco) && x<ferramentas.posicao_padrao.X + (4*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y && y+5< ferramentas.posicao_padrao.Y + espaco) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[3] , janela);
			pincel->cor=ferramentas.paleta_padrao[3];
		}
			if(x>ferramentas.posicao_padrao.X + (4*espaco) && x<ferramentas.posicao_padrao.X + (5*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y && y+5< ferramentas.posicao_padrao.Y + espaco) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[4] , janela);
			pincel->cor=ferramentas.paleta_padrao[4];
		}
			if(x>ferramentas.posicao_padrao.X + (5*espaco) && x<ferramentas.posicao_padrao.X + (6*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y && y+5< ferramentas.posicao_padrao.Y + espaco) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[5] , janela);
			pincel->cor=ferramentas.paleta_padrao[5];
		}
			if(x>ferramentas.posicao_padrao.X + (6*espaco) && x<ferramentas.posicao_padrao.X + (7*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y && y+5< ferramentas.posicao_padrao.Y + espaco) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[6] , janela);
			pincel->cor=ferramentas.paleta_padrao[6];
		}
			if(x>ferramentas.posicao_padrao.X + (7*espaco) && x<ferramentas.posicao_padrao.X + (8*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y && y+5< ferramentas.posicao_padrao.Y + espaco) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[7] , janela);
			pincel->cor=ferramentas.paleta_padrao[7];
		}
			if(x>ferramentas.posicao_padrao.X + (8*espaco) && x<ferramentas.posicao_padrao.X + (9*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y && y+5< ferramentas.posicao_padrao.Y + espaco) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[8] , janela);
			pincel->cor=ferramentas.paleta_padrao[8];
		}
			if(x>ferramentas.posicao_padrao.X + (9*espaco) && x<ferramentas.posicao_padrao.X + (10*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y && y+5< ferramentas.posicao_padrao.Y + espaco) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[9] , janela);
			pincel->cor=ferramentas.paleta_padrao[9];
		}
			if(x>ferramentas.posicao_padrao.X  && x<ferramentas.posicao_padrao.X + (espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y + espaco && y+5< ferramentas.posicao_padrao.Y + (2*espaco)) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[10] , janela);
			pincel->cor=ferramentas.paleta_padrao[10];
		}
			if(x>ferramentas.posicao_padrao.X + (espaco) && x<ferramentas.posicao_padrao.X + (2*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y + espaco && y+5< ferramentas.posicao_padrao.Y + (2*espaco)) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[11] , janela);
			pincel->cor=ferramentas.paleta_padrao[11];
		}
			if(x>ferramentas.posicao_padrao.X + (2*espaco) && x<ferramentas.posicao_padrao.X + (3*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y + espaco && y+5< ferramentas.posicao_padrao.Y + (2*espaco)) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[12] , janela);
			pincel->cor=ferramentas.paleta_padrao[12];
		}
			if(x>ferramentas.posicao_padrao.X + (3*espaco) && x<ferramentas.posicao_padrao.X + (4*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y + espaco && y+5< ferramentas.posicao_padrao.Y + (2*espaco)) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[13] , janela);
			pincel->cor=ferramentas.paleta_padrao[13];
		}
			if(x>ferramentas.posicao_padrao.X + (4*espaco) && x<ferramentas.posicao_padrao.X + (5*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y + espaco && y+5< ferramentas.posicao_padrao.Y + (2*espaco)) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[14] , janela);
			pincel->cor=ferramentas.paleta_padrao[14];
		}
			if(x>ferramentas.posicao_padrao.X + (5*espaco) && x<ferramentas.posicao_padrao.X + (6*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y + espaco && y+5< ferramentas.posicao_padrao.Y + (2*espaco)) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[15] , janela);
			pincel->cor=ferramentas.paleta_padrao[15];
		}
			if(x>ferramentas.posicao_padrao.X + (6*espaco) && x<ferramentas.posicao_padrao.X + (7*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y + espaco && y+5< ferramentas.posicao_padrao.Y + (2*espaco)) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[16] , janela);
			pincel->cor=ferramentas.paleta_padrao[16];
		}
			if(x>ferramentas.posicao_padrao.X + (7*espaco) && x<ferramentas.posicao_padrao.X + (8*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y + espaco && y+5< ferramentas.posicao_padrao.Y + (2*espaco) ) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[17] , janela);
			pincel->cor=ferramentas.paleta_padrao[17];
		}
			if(x>ferramentas.posicao_padrao.X + (8*espaco) && x<ferramentas.posicao_padrao.X + (9*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y + espaco && y+5< ferramentas.posicao_padrao.Y + (2*espaco)) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[18] , janela);
			pincel->cor=ferramentas.paleta_padrao[18];
		}
			if(x>ferramentas.posicao_padrao.X + (9*espaco) && x<ferramentas.posicao_padrao.X + (10*espaco) && /* verifica se esta clicando nas paletas padroes*/
			y+5>ferramentas.posicao_padrao.Y + espaco && y+5< ferramentas.posicao_padrao.Y + (2*espaco)) 
		{
			paleta_status_pincel(ferramentas.paleta_padrao[19] , janela);
			pincel->cor=ferramentas.paleta_padrao[19];
		}
			if(x>ferramentas.posicao_personalizadas.X  && x<ferramentas.posicao_personalizadas.X + (espaco) && /* verifica se esta clicando nas paletas personalizadas e pega a do pixel que foi clicado desde que esteja dentro do quadrado da paleta*/
			y+5>ferramentas.posicao_personalizadas.Y && y+5< ferramentas.posicao_personalizadas.Y + (espaco)) 
		{
			pincel->cor=getpixel(x,y);
			paleta_status_pincel(pincel->cor , janela);
			ferramentas.paleta_personalizada[0]=pincel->cor;
		}
			if(x>ferramentas.posicao_personalizadas.X + espaco && x<ferramentas.posicao_personalizadas.X + (2*espaco) && 
			y+5>ferramentas.posicao_personalizadas.Y && y+5< ferramentas.posicao_personalizadas.Y + (espaco)) 
		{
			pincel->cor=getpixel(x,y);
			paleta_status_pincel(pincel->cor , janela);
			ferramentas.paleta_personalizada[1]=pincel->cor;
		}
			if(x>ferramentas.posicao_personalizadas.X + (2*espaco) && x<ferramentas.posicao_personalizadas.X + (3*espaco) &&  /* verifica se esta clicando nas paletas personalizadas e pega a do pixel que foi clicado desde que esteja dentro do quadrado da paleta*/
			y+5>ferramentas.posicao_personalizadas.Y && y+5< ferramentas.posicao_personalizadas.Y + (espaco)) 
		{
			paleta_status_pincel(ferramentas.paleta_personalizada[2] , janela);
			pincel->cor=ferramentas.paleta_personalizada[2];
		}
			if(x>ferramentas.posicao_personalizadas.X + (3*espaco) && x<ferramentas.posicao_personalizadas.X + (4*espaco) && 
			y+5>ferramentas.posicao_personalizadas.Y && y+5< ferramentas.posicao_personalizadas.Y + (espaco)) 
		{
						pincel->cor=getpixel(x,y);
			paleta_status_pincel(pincel->cor , janela);
			ferramentas.paleta_personalizada[3]=pincel->cor;
		}
			if(x>ferramentas.posicao_personalizadas.X + (4*espaco) && x<ferramentas.posicao_personalizadas.X + (5*espaco) && 
			y+5>ferramentas.posicao_personalizadas.Y && y+5< ferramentas.posicao_personalizadas.Y + (espaco) ) 
		{
			pincel->cor=getpixel(x,y);
			paleta_status_pincel(pincel->cor , janela);
			ferramentas.paleta_personalizada[4]=pincel->cor;
		}	
			if(x>ferramentas.posicao_personalizadas.X + (5*espaco) && x<ferramentas.posicao_personalizadas.X + (6*espaco) &&  /* verifica se esta clicando nas paletas personalizadas e pega a do pixel que foi clicado desde que esteja dentro do quadrado da paleta*/
			y+5>ferramentas.posicao_personalizadas.Y && y+5< ferramentas.posicao_personalizadas.Y + (espaco)) 
		{
			pincel->cor=getpixel(x,y);
			paleta_status_pincel(pincel->cor , janela);
			ferramentas.paleta_personalizada[5]=pincel->cor;
		}
			if(x>ferramentas.posicao_personalizadas.X + (6*espaco) && x<ferramentas.posicao_personalizadas.X + (7*espaco) && 
			y+5>ferramentas.posicao_personalizadas.Y && y+5< ferramentas.posicao_personalizadas.Y + (espaco)) 
		{
			pincel->cor=getpixel(x,y);
			paleta_status_pincel(pincel->cor , janela);
			ferramentas.paleta_personalizada[6]=pincel->cor;
		}
			if(x>ferramentas.posicao_personalizadas.X + (7*espaco) && x<ferramentas.posicao_personalizadas.X + (8*espaco) && 
			y+5>ferramentas.posicao_personalizadas.Y && y+5< ferramentas.posicao_personalizadas.Y + (espaco)) 
		{
			pincel->cor=getpixel(x,y);
			paleta_status_pincel(pincel->cor , janela);
			ferramentas.paleta_personalizada[7]=pincel->cor;
		}
			if(x>ferramentas.posicao_personalizadas.X + (8*espaco) && x<ferramentas.posicao_personalizadas.X + (9*espaco) &&  /* verifica se esta clicando nas paletas personalizadas e pega a do pixel que foi clicado desde que esteja dentro do quadrado da paleta*/
			y+5>ferramentas.posicao_personalizadas.Y && y+5< ferramentas.posicao_personalizadas.Y + (espaco)) 
		{
			pincel->cor=getpixel(x,y);
			paleta_status_pincel(pincel->cor , janela);
			ferramentas.paleta_personalizada[8]=pincel->cor;
		}
			if(x>ferramentas.posicao_personalizadas.X + (9*espaco) && x<ferramentas.posicao_personalizadas.X + (10*espaco) && 
			y+5>ferramentas.posicao_personalizadas.Y && y+5< ferramentas.posicao_personalizadas.Y + (espaco) ) 
		{
			pincel->cor=getpixel(x,y);
			paleta_status_pincel(pincel->cor , janela);
			ferramentas.paleta_personalizada[9]=pincel->cor;
		}

}

void SeedFill_2(int x, int y, COLORREF fill_color, COLORREF border_color)
{
	
}

/*funcao que executa o programa*/
void executa_pbrush(tipo_janela janela, tipo_ferramentas ferramentas)
{
	/*declaracao e inicializacao das variaeis*/
	tipo_pincel pincel;
	EVENTO entrada;

	pincel = inicia_pincel(janela);
	
	quadrado_cor(pincel.posicao.X,pincel.posicao.Y, 4, pincel.cor); /*coloca o pincel desativado na posicao inicial sendo seu tamanha de 4x4*/
	do{
	verifica_status_pincel(janela, pincel); 
	entrada=Evento();
	if(entrada.tipo_evento == KEY_EVENT)	/*verifica se o evento e do teclado*/
	{
	if(entrada.teclado.status_tecla==PRESSIONADA) /*verifica se a tecla foi pressionada*/
	{
	if((entrada.teclado.status_teclas_controle & LEFT_CTRL_PRESSED)==LEFT_CTRL_PRESSED) pincel.estado=(!pincel.estado);	/*Ativa ou desativa o pincel*/
	if((entrada.teclado.status_teclas_controle & LEFT_ALT_PRESSED) == LEFT_ALT_PRESSED) redimensiona(janela, &pincel, 1);	/*Aumenta o tamanho do pincel*/
	if((entrada.teclado.status_teclas_controle & RIGHT_ALT_PRESSED) == RIGHT_ALT_PRESSED) redimensiona(janela, &pincel, 2);	/*Diminui o tamanho do pincel*/
	if(pincel.estado==1)	/*pincel ativo movimenta pintando os pixel*/
	{
	if(entrada.teclado.codigo_tecla==SETA_PARA_DIREITA)	 /*compara para qual direcao o pincel vai pintar*/
		{
			movimenta(janela, &pincel, 2);
			quadrado_cor(pincel.posicao.X,pincel.posicao.Y, pincel.tamanho, pincel.cor);
		}
	if(entrada.teclado.codigo_tecla==SETA_PARA_ESQUERDA)	 
		{
		movimenta(janela, &pincel, 1);
		quadrado_cor(pincel.posicao.X,pincel.posicao.Y, pincel.tamanho, pincel.cor);
		}
	if(entrada.teclado.codigo_tecla==SETA_PARA_BAIXO)	
		{
		movimenta(janela, &pincel, 4);
		quadrado_cor(pincel.posicao.X,pincel.posicao.Y, pincel.tamanho, pincel.cor);
		}
	if(entrada.teclado.codigo_tecla==SETA_PARA_CIMA)	
		{
		movimenta(janela, &pincel, 3);
		quadrado_cor(pincel.posicao.X,pincel.posicao.Y, pincel.tamanho, pincel.cor);
	}
	}
	else /*pincel desativado movienta-se sem pintar os pixel */
	{
		if(entrada.teclado.codigo_tecla==SETA_PARA_DIREITA) /*funcao que move para a direita*/
		{
			quadrado_cor(pincel.posicao.X,pincel.posicao.Y, 4, getpixel(pincel.posicao.X+4,pincel.posicao.Y)); /*funcao que pinta o quadrado em nova posicao a funcao getpixel pega a cor do proximo pixel pra colocar no lugar onde esta o pincel*/
			movimenta(janela, &pincel, 2);
			quadrado_cor(pincel.posicao.X,pincel.posicao.Y, 4, pincel.cor); /*funcao que pinta o quadrado em nova posicao*/
		}
	if(entrada.teclado.codigo_tecla==SETA_PARA_ESQUERDA) /*move para esqurda sem pinta*/
		{
			quadrado_cor(pincel.posicao.X,pincel.posicao.Y, 4, getpixel(pincel.posicao.X-4,pincel.posicao.Y)); /*funcao que pinta o quadrado em nova posicao a funcao getpixel pega a cor do proximo pixel pra colocar no lugar onde esta o pincel*/
			movimenta(janela, &pincel, 1);
			quadrado_cor(pincel.posicao.X,pincel.posicao.Y, 4, pincel.cor); /*funcao que pinta o quadrado em nova posicao*/
		}
	if(entrada.teclado.codigo_tecla==SETA_PARA_BAIXO)	/*move para baixo sem pinta*/
		{
			quadrado_cor(pincel.posicao.X,pincel.posicao.Y, 4, getpixel(pincel.posicao.X,pincel.posicao.Y+4)); /*funcao que pinta o quadrado em nova posicao a funcao getpixel pega a cor do proximo pixel pra colocar no lugar onde esta o pincel*/
			movimenta(janela, &pincel, 4);
			quadrado_cor(pincel.posicao.X,pincel.posicao.Y, 4, pincel.cor); /*funcao que pinta o quadrado em nova posicao*/
		}
	if(entrada.teclado.codigo_tecla==SETA_PARA_CIMA) /*move para cima sem pinta*/
		{
			quadrado_cor(pincel.posicao.X,pincel.posicao.Y, 4, getpixel(pincel.posicao.X,pincel.posicao.Y-4)); /*funcao que pinta o quadrado em nova posicao a funcao getpixel pega a cor do proximo pixel pra colocar no lugar onde esta o pincel*/
			movimenta(janela, &pincel, 3);
			quadrado_cor(pincel.posicao.X,pincel.posicao.Y, 4, pincel.cor); /*funcao que pinta o quadrado em nova posicao*/

		}	
	}
	}
	}
	if(entrada.tipo_evento == MOUSE_EVENT) /*funcao que capta os eventos do mouse*/
	{
		int x=(int) (entrada.mouse.posicao.X*janela.tamanho_fonte.X); /*posicao para X e Ydo mouse em pixel*/
		int y = (int)(entrada.mouse.posicao.Y*janela.tamanho_fonte.Y);
		if(entrada.mouse.botao_pressionado & BOTAO_ESQUERDO_PRESSIONADO)  /*verifica se algum botato do mouse foi pressionado*/
		{
			verifica_mouse( x, y, janela, ferramentas, &pincel);
		}
		if(entrada.mouse.botao_pressionado & BOTAO_DIREITO_PRESSIONADO)  /*verifica se algum botato do mouse foi pressionado*/
		{
			printf("teste");
			/*SeedFill_2(x,  y, RGB(255,255,255), pincel.cor);*/
		}
	}
		}while(entrada.teclado.codigo_tecla!=ESC); /*condicao que verifica se a tecla ESC foi pressionada, caso isso aconteca se encerra o programa*/
}
