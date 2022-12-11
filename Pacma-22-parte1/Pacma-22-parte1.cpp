// Pacma-22-parte1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/// <summary>Creo macros para no tener numeros sueltos, defino sets con el enum y con al map relleno el array
// y guarda lo que tengo en cada una de las casillas. Con el bool se si se esta ejecutando o no la apliación</summary>

#include <iostream>
#include <stdlib.h>
#define MAP_VERTICAL 29   
#define MAP_HORIZONTAL 120
#define PERSONAJE 'O' 
enum TILES {EMPTY = ' ', WALL ='#', POINT='.' };
TILES map[MAP_VERTICAL][MAP_HORIZONTAL]; 
bool run = true; 
enum INPUT {QUIT, UP, DOWN , LEFT, RIGHT, UNKNOWN};
INPUT currentInput = INPUT::UNKNOWN;
int personaje_x;
int personaje_y;
int puntuacion_actual;
int puntuacion_total;


/// <summary>con Setup se ve el alto y ancho de la consola (relleno mi mapa) y declaramos donde queremos los #
// es decir los limites y añado color.</summary>

void Setup()
{ 
	system("Color 03");
	personaje_x = MAP_HORIZONTAL / 2;
	personaje_y = MAP_VERTICAL / 2;
	for (size_t i = 0; i < 29; i++)   
	{
		for (size_t j = 0; j < 120; j++)   
		{
			if (i == 0 || j == 0 || i == MAP_VERTICAL - 1 || j == MAP_HORIZONTAL - 1) 
			{
				map[i][j] = TILES::WALL;    
			}
			else
			{
				map[i][j] = TILES::EMPTY; 

			}
		}

	}
	/// <summary>Añado puntos y huecos por el mapa</summary>

	
	map[10][10] = TILES::POINT; 
	map[10][11] = TILES::POINT; 
	map[10][12] = TILES::POINT; 
	map[10][13] = TILES::POINT; 
	map[10][14] = TILES::POINT; 
	map[10][15] = TILES::POINT; 
	map[10][16] = TILES::POINT; 
	map[9][10] = TILES::POINT; 
	map[9][11] = TILES::POINT; 
	map[9][12] = TILES::POINT; 
	map[9][13] = TILES::POINT; 
	map[9][14] = TILES::POINT; 
	map[9][15] = TILES::POINT; 
	map[9][16] = TILES::POINT; 
	map[9][17] = TILES::POINT; 
	
	
	map[11][0] = TILES::EMPTY; 
	map[12][0] = TILES::EMPTY;
	map[13][0] = TILES::EMPTY;
	map[14][0] = TILES::EMPTY;

	map[11][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[12][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[13][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[14][MAP_HORIZONTAL - 1] = TILES::EMPTY;

	map[0][59] = TILES::EMPTY;
	map[0][60] = TILES::EMPTY;
	map[0][61] = TILES::EMPTY;
	map[0][62] = TILES::EMPTY;

	map[MAP_VERTICAL - 1][59] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][60] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][61] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][62] = TILES::EMPTY;

	/// <summary>compruebo los puntos que tengo en mi mapa y me dice mi puntuacion total</summary>

	for (size_t i = 0; i < 29; i++)   
	{
		for (size_t j = 0; j < 120; j++)   
		{
			if (map[i][j] == TILES::POINT)
			{
				puntuacion_total++;
			}
		}

	}

}
/// <summary>Input indico hacia donde se movera mi personaje con los inputs que le estoy indicando</summary>

void Input()
{
	char input;
	std::cin >> input;
	switch (input)
	{
	case 'w':
	case 'W':
		currentInput = INPUT::UP;
		break;
	case 's':
	case 'S':
		currentInput = INPUT::DOWN;
		break;
	case 'a':
	case 'A':
		currentInput = INPUT::LEFT;
		break;
	case 'd':
	case 'D':
		currentInput = INPUT::RIGHT;
		break;
	case 'q':
	case 'Q':
		currentInput = INPUT::QUIT;
		break;
	default:
		currentInput = INPUT::UNKNOWN;
		break;
	}
}

/// <summary>Logic Indico que cuando introduzca la Q el juego terminará y además compruebo la colision del personaje
// y hago que cuando recoja un punto ese lo rellene de "vacio", tambien hago que cuando superemos un limite donde
// no haya una pared aparezca por el limite contrario</summary>
void Logic()
{
	int personaje_y_new = personaje_y;
	int personaje_x_new = personaje_x;
	switch (currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		personaje_y_new--;
		break;
	case DOWN:
		personaje_y_new++;
		break;
	case LEFT:
		personaje_x_new--;
		break;
	case RIGHT:
		personaje_x_new++;
		break;
	
	}
	if (personaje_x_new < 0) 
	{
		personaje_x_new = MAP_HORIZONTAL - 1;
	}
	personaje_x_new = personaje_x_new % MAP_HORIZONTAL;
	
	if (personaje_y_new < 0) 
	{
		personaje_y_new = MAP_VERTICAL - 1;
	}
	personaje_y_new = personaje_y_new % MAP_VERTICAL;

	switch (map[personaje_y_new][personaje_x_new])
	{
	case TILES::WALL:
		break;
	case TILES::POINT:
		puntuacion_actual++;
		map[personaje_y_new][personaje_x_new] = TILES::EMPTY; 
	default:
		personaje_y = personaje_y_new;
		personaje_x = personaje_x_new;
		break;
	}
}

/// <summary>Draw añado una funcion de windows CLS(borrar pantalla) para que se pueda ver de mejor todo
// también indicamos char ya que nuestro mapa es un array de 2D y asi indicamos en que queremos
// transformar nuestro  enum y no salga el numero entero asignado a ese simbolo/carácter
// finalmente añadimos en la ultima linea la puntuacion actual y total</summary>
void Draw()
{
	system("CLS"); 
	for (size_t i = 0; i < 29; i++)   
	{
		for (size_t j = 0; j < 120; j++)
		{
			if (i == personaje_y && j == personaje_x) 
			{
				std::cout << PERSONAJE;
			}
			else
			{
				std::cout << (char)map[i][j]; 
			}
		}
		std::cout << std::endl;
	}
	std::cout << puntuacion_actual << '/' << puntuacion_total;
}

/// <summary>main le indicamos lo que hara mientras se ejecute</summary>
int main() 
{
	Setup();
	Draw();
	while (run) 
	{
		Input();
		Logic();
		Draw();
	}
	
}

