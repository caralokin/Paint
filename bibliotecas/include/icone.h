/* 	Biblioteca: 
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422 e 023417
    Data da última modificação: 21/03/2013 
*/

#ifndef PBRUSH_ICONE_H
#define PBRUSH_ICONE_H

 #include <stdio.h>   
 
 /* A funcao fundo_preto_disquete desenha todo a area do disquete */
 void fundo_preto_disquete();
 
/*A funcao desenha_lata_disquete desenha a lata que faz proteçao ao disco 
quando n esta usando o disquete.*/
 void desenha_lata_disquete();
 
 /*A funcao desenha_branco_disquete e responsavel por desenha a area branca onde se  
escreve o nome do disquete.*/
 void desenha_branco_disquete();
 
/*A desenha_aba_clara desenha aba interna do icone abrir pasta*/
void desenha_aba_clara();

/*A desenha_aba_clara desenha aba iexterna que e tambem a mais escura do icone abrir pasta*/
void desenha_aba_escura();

#endif
