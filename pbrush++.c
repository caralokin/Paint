/* 	Biblioteca: Janela
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422
    Data da última modificação: 21/03/2013 
*/
/*obs. a edita cor esta funcionando o unico problema e q vc digita mas nao se ve o que esta sendo digitado
entao para funcionar e da segunte maneira digita: 42 enter 195 enter 58 enter e enter novamente
o pincel ta funcinando blz sem aquelas falhas no canto usei sua funcao de imprimir quadrados ficou blz 
a eu comentei ai vc le e ve se intende pra eu arrumar caso precise e vai precisar kkkkkkkk

Ai ficou faltando o salvar e o pintar q ainda n consegui 
*/

#include <stdio.h>
#include <windows.h>

#include "janela.h"
#include "conio_v3.2.3.h"
#include "ferramentas.h"
#include "paint_plusplus.h"

int main(int argc, char *argv[])
{
	tipo_janela janela;
	tipo_ferramentas ferramentas;

	verifica_nome(argv[0]);
	
	janela = obtem_dados_janela();
	ferramentas = inicia_ferramentas(janela);
	redimensiona_janela(janela, 1);
	/*desenha_layout(janela);*/
	desenha_ferramentas(janela,ferramentas);
	executa_pbrush(janela,ferramentas);
	redimensiona_janela(janela, 2);
	system("cls");
	return 0;
}
