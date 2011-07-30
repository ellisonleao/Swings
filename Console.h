//console.h -> Prot�tipos das fun��es de console

#ifndef __CONSOLE_H__
#define __CONSOLE_H__

//Includes necess�rios
#include <wtypes.h>
#include <wincon.h>
#include <string.h>

//Constantes para cores espec�ficas
#define BACKGROUND_WHITE  (WORD) 0x00f0
#define BACKGROUND_CYAN   (WORD) 0x0030

#define FOREGROUND_YELLOW (WORD) 0x0006
#define FOREGROUND_CYAN   (WORD) 0x0003
#define FOREGROUND_WHITE  (WORD) 0x0007


/*----------------------------------------------------------------------------*\
|   clrscr                                                                     |
|                                                                              |
|   Descri��o:                                                                 |
|       Limpa a tela do console.                                               |
|                                                                              |
|   Par�metros:                                                                |
|       atributos->qualquer combina��o dos seguintes valores:                  |
|					FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED,		   |
|                   FOREGROUND_YELLOW, FOREGROUND_CYAN, FOREGROUND_WHITE       |
|					FOREGROUND_INTENSITY,									   |
|					BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED,		   |
|                   BACKGROUND_WHITE, BACKGROUND_CYAN                          |
|					BACKGROUND_INTENSITY									   |
|                                                                              |
|       Exemplos:                                                              |
|         //Limpa a tela com letras brancas em fundo preto                     |
|         clrscr(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);         |
|                                                                              |
|         //Limpa a tela com letras pretas em fundo branco                     |
|         clrscr(BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);         |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void clrscr( WORD atributos  = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED  );

/*----------------------------------------------------------------------------*\
|   gotoxy                                                                     |
|                                                                              |
|   Descri��o:                                                                 |
|       Posiciona o cursor em determinado local                                |
|                                                                              |
|   Par�metros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void gotoxy (int x, int y);

/*----------------------------------------------------------------------------*\
|   mostratexto                                                                |
|                                                                              |
|   Descri��o:                                                                 |
|       Mostra uma string em determinada posi��o da tela com cores diferentes. |
|                                                                              |
|   Par�metros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|       texto -> texto a ser mostrado                                          |
|       atributos->qualquer combina��o dos seguintes valores:                  |
|					FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED,		   |
|                   FOREGROUND_YELLOW, FOREGROUND_CYAN, FOREGROUND_WHITE       |
|					FOREGROUND_INTENSITY,									   |
|					BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED,		   |
|                   BACKGROUND_WHITE, BACKGROUND_CYAN                          |
|					BACKGROUND_INTENSITY									   |
|                                                                              |
|       Exemplos:                                                              |
|         //Mostra a frase em letras amarelas e fundo branco                   |
|         mostratexto(5,5,"Oi", FOREGROUND_YELLOW | BACKGROUND_WHITE);         |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void mostratexto ( int x, int y, char *texto, WORD atributos );

/*----------------------------------------------------------------------------*\
|   mostrar                                                                    |
|                                                                              |
|   Descri��o:                                                                 |
|       Mostra uma string em determinada posi��o da tela com cores diferentes. |
|                                                                              |
|   Par�metros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|       texto -> texto a ser mostrado                                          |
|       atributos->qualquer combina��o dos seguintes valores:                  |
|					FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED,		   |
|                   FOREGROUND_YELLOW, FOREGROUND_CYAN, FOREGROUND_WHITE       |
|					FOREGROUND_INTENSITY,									   |
|					BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED,		   |
|                   BACKGROUND_WHITE, BACKGROUND_CYAN                          |
|					BACKGROUND_INTENSITY									   |
|                                                                              |
|       Exemplos:                                                              |
|         //Mostra a frase em letras amarelas e fundo branco                   |
|         mostratexto(5,5,"Oi", FOREGROUND_YELLOW | BACKGROUND_WHITE);         |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void mostrar ( int x, int y, WORD atributos, char *texto );

/*----------------------------------------------------------------------------*\
|   mostrar                                                                    |
|                                                                              |
|   Descri��o:                                                                 |
|       Mostra um long em determinada posi��o da tela com cores diferentes.    |
|                                                                              |
|   Par�metros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|       valor -> n�mero a ser mostrado                                         |
|       atributos->qualquer combina��o dos seguintes valores:                  |
|					FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED,		   |
|                   FOREGROUND_YELLOW, FOREGROUND_CYAN, FOREGROUND_WHITE       |
|					FOREGROUND_INTENSITY,									   |
|					BACKGROUND_BLUE, BACKGROUND_GREEN, BACKGROUND_RED,		   |
|                   BACKGROUND_WHITE, BACKGROUND_CYAN                          |
|					BACKGROUND_INTENSITY									   |
|                                                                              |
|       Exemplos:                                                              |
|         //Mostra a frase em letras amarelas e fundo branco                   |
|         mostratexto(5,5,"Oi", FOREGROUND_YELLOW | BACKGROUND_WHITE);         |
|                                                                              |
|   Retorno:                                                                   |
|                                                                              |
\*----------------------------------------------------------------------------*/
void mostrar ( int x, int y, WORD atributos, long valor );

#endif