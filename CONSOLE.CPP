//Console.cpp - Definição das funções de console

#include "console.h"

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
void clrscr( WORD atributos)
{
	#define MY_BUFSIZE 1024			// Tamanho do buffer para o título da janela

	COORD coordScreen = { 0, 0 };   // Posição do cursor
	BOOL bSuccess;					// Auxiliar para armazenamento do retorno das funções
	DWORD cCharsWritten,
	      dwConSize;                // Número de caracteres atuais da janela
	CONSOLE_SCREEN_BUFFER_INFO csbi;// Informações sobre a janela
	HANDLE hConsole;				// Handle para a janela
 

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Recupera informações sobre a janela
	bSuccess = GetConsoleScreenBufferInfo( hConsole, &csbi );

	//Calcula número de caracteres
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
 
	//Preenche janela com brancos
    bSuccess = FillConsoleOutputCharacter( hConsole, (TCHAR) ' ',
							dwConSize, coordScreen, &cCharsWritten );
 
	//Preenche janela com o atributo escolhido
	bSuccess = FillConsoleOutputAttribute( hConsole, atributos,
							dwConSize, coordScreen, &cCharsWritten );
 
	//Posiciona o cursor no canto superior esquerdo 
	bSuccess = SetConsoleCursorPosition( hConsole, coordScreen );
}

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
void gotoxy (int x, int y)
{
	HANDLE hConsole;			// Handle para a janela
	COORD coord = { x, y };		// Posição do cursor

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Posiciona o cursor no canto superior esquerdo 
	SetConsoleCursorPosition( hConsole, coord );
}

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
void mostratexto ( int x, int y, char *texto, WORD atributos )
{
	HANDLE hConsole;			// Handle para a janela
	COORD coord = { x, y };		// Posição do cursor
	DWORD dChar;				// Número de caracteres impressos

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Altera os atributos da janela
	SetConsoleTextAttribute (hConsole, atributos);

	//Posiciona o cursor na posição indicada
	SetConsoleCursorPosition( hConsole, coord );

	//Imprime frase
	WriteConsole (hConsole, texto, strlen(texto), &dChar, NULL);
}

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
void mostrar ( int x, int y, WORD atributos, char *texto )
{
	HANDLE hConsole;			// Handle para a janela
	COORD coord = { x, y };		// Posição do cursor
	DWORD dChar;				// Número de caracteres impressos

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Altera os atributos da janela
	SetConsoleTextAttribute (hConsole, atributos);

	//Posiciona o cursor na posição indicada
	SetConsoleCursorPosition( hConsole, coord );

	//Imprime frase
	WriteConsole (hConsole, texto, strlen(texto), &dChar, NULL);
}


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
void mostrar ( int x, int y, WORD atributos, long valor )
{
	HANDLE hConsole;			// Handle para a janela
	COORD coord = { x, y };		// Posição do cursor
	DWORD dChar;				// Número de caracteres impressos

	//Recupera o handle da janela de console
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

	//Altera os atributos da janela
	SetConsoleTextAttribute (hConsole, atributos);

	//Posiciona o cursor na posição indicada
	SetConsoleCursorPosition( hConsole, coord );

	//Monta string
	char texto[10];
	ltoa(valor, texto, 10);

	//Imprime frase
	WriteConsole (hConsole, texto, strlen(texto), &dChar, NULL);
}