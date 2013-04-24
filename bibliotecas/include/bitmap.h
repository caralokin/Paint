/* 	Biblioteca: Janela
    Descrição: 
    Programador: Alvaro Leonel e Leandro
    RGM: 023422
    Data da última modificação: 21/03/2013 
*/

#ifndef PBRUSH_BITMAP_H
#define PBRUSH_BITMAP_H

#include <stdio.h>
#include <windows.h>

#include "janela.h"

int abrir_imagem(char *nome, tipo_janela janela);


int salvar_imagem(char *nome, tipo_janela janela);

#endif
