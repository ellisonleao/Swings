//console.h -> Protótipos das funções de console

#ifndef __CONSOLE_H__
#define __CONSOLE_H__

//Includes necessários
#include <wtypes.h>
#include <wincon.h>
#include <string.h>

//Constantes para cores específicas
#define BACKGROUND_WHITE  (WORD) 0x00f0
#define BACKGROUND_CYAN   (WORD) 0x0030

#define FOREGROUND_YELLOW (WORD) 0x0006
#define FOREGROUND_CYAN   (WORD) 0x0003
#define FOREGROUND_WHITE  (WORD) 0x0007


/*----------------------------------------------------------------------------*\
|   clrscr                                                                     |
|                                                                              |
|   Descrição:                                                                 |
|       Limpa a tela do console.                                               |
|                                                                              |
|   Parâmetros:                                                                |
|       atributos->qualquer combinação dos seguintes valores:                  |
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
|   Descrição:                                                                 |
|       Posiciona o cursor em determinado local                                |
|                                                                              |
|   Parâmetros:                                                                |
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
|   Descrição:                                                                 |
|       Mostra uma string em determinada posição da tela com cores diferentes. |
|                                                                              |
|   Parâmetros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|       texto -> texto a ser mostrado                                          |
|       atributos->qualquer combinação dos seguintes valores:                  |
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
|   Descrição:                                                                 |
|       Mostra uma string em determinada posição da tela com cores diferentes. |
|                                                                              |
|   Parâmetros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|       texto -> texto a ser mostrado                                          |
|       atributos->qualquer combinação dos seguintes valores:                  |
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
|   Descrição:                                                                 |
|       Mostra um long em determinada posição da tela com cores diferentes.    |
|                                                                              |
|   Parâmetros:                                                                |
|       x -> coordenada horizontal.                                            |
|		y -> coordenada vertical.									 		   |
|       valor -> número a ser mostrado                                         |
|       atributos->qualquer combinação dos seguintes valores:                  |
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