#include <stdio.h>
#include <windows.h>

#include "graphics.h"
#include "janela.h"

int abrir_imagem(char nome[], tipo_janela janela)
{

    BITMAPFILEHEADER cabecalho;
    BITMAPINFOHEADER bitmap;
    RGBTRIPLE cor;

    FILE *imagem;
    int linha, coluna;
	int h,v, ajuste;
   imagem = fopen(nome, "ab+"); 


	fread(&cabecalho, 14, 1 , imagem);
	fread(&bitmap, 40, 1, imagem);
		
	if(bitmap.biHeight < janela.tamanho_area_desenho.Y - 60 )
	{
		v = bitmap.biHeight + 60;
	}
	else
	{
		v = janela.tamanho_area_desenho.Y + 60;
	}
		
	h = bitmap.biWidth;
	ajuste = bitmap.biWidth % 4;
		
	for(linha = v; linha > 60; linha--)
	{
		for(coluna = 0; coluna < h; coluna++)
		{
			fread(&cor, 3, 1, imagem);
			if(coluna < janela.tamanho_area_desenho.X)
			{
				putpixel(coluna, linha, RGB(cor.rgbtRed, cor.rgbtGreen, cor.rgbtBlue));
			}
		}
		fseek (imagem, ajuste, SEEK_CUR);
	}
	
	fclose(imagem);
	
	return 0;
}

int salvar_imagem(char nome[], tipo_janela janela)
{
gotoxy(2, 26);
printf("chegou1");
	BITMAPFILEHEADER cabecalho;
    BITMAPINFOHEADER bitmap;
    RGBTRIPLE cor;
    COLORREF pixel;

    FILE *imagem;
	
    int linha, coluna, ajuste;
  
	imagem = fopen(nome, "ab+");
printf("chegou");
  cabecalho.bfType = 19778;
  cabecalho.bfSize = janela.tamanho_area_desenho.X * (janela.tamanho_area_desenho.Y -  60) * 3 + 54;
  cabecalho.bfReserved1 = 0;
  cabecalho.bfReserved2 = 0;
  cabecalho.bfOffBits = 54;

  fwrite(&cabecalho, 14, 1, imagem);

  bitmap.biSize = 40;
  bitmap.biWidth = janela.tamanho_area_desenho.X;
  bitmap.biHeight = janela.tamanho_area_desenho.Y - 60;
  bitmap.biPlanes = 1;
  bitmap.biBitCount = 24;
  bitmap.biCompression = 0;
  bitmap.biSizeImage = janela.tamanho_area_desenho.X * (janela.tamanho_area_desenho.Y -  60) * 3;
  bitmap.biXPelsPerMeter = 3780;
  bitmap.biYPelsPerMeter = 3780;
  bitmap.biClrUsed = 0;
  bitmap.biClrImportant = 0;

  fwrite(&bitmap, 40, 1, imagem);

	ajuste =  janela.tamanho_area_desenho.X % 4;
	
  for(linha =janela.tamanho_area_desenho.Y -  60; linha > 0; linha--)
    {
        for(coluna = 0; coluna <  janela.tamanho_area_desenho.X; coluna++)
        {
            pixel = getpixel(coluna, linha);
            cor.rgbtRed = GetRValue(pixel);
            cor.rgbtGreen = GetGValue(pixel);
            cor.rgbtBlue = GetBValue(pixel);
            fwrite(&cor, 3, 1, imagem);
        }
		fwrite(0, 1, ajuste, imagem);
    }
    fclose(imagem);
	
	return 0;
}
