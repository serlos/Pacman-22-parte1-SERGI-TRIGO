// Pacma-22-parte1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAP_VERTICAL 29   // creamos macros para que no nos queden números sueltos y asegurarnos no equivocarnos
#define MAP_HORIZONTAL 120
#define PERSONAJE 'O' //este sera mi personaje, puede ser cualquier cosa

enum TILES {EMPTY = ' ', WALL ='#', POINT='.' }; //enum define un set y nos da un entero
TILES map[MAP_VERTICAL][MAP_HORIZONTAL]; //lo ponemos aqui para poder acceder de donde queramos /reservo memoria, rellenamos nuestro array / el map guarda que es lo que tengo en cada una de las casillas
bool run = true; //para saber si estamos ejecutando la apliación o no
enum INPUT {QUIT, UP, DOWN , LEFT, RIGHT, UNKNOWN};
INPUT currentInput = INPUT::UNKNOWN;

int personaje_x;
int personaje_y;
int puntuacion_actual;
int puntuacion_total;

void Setup()
{ 
	personaje_x = MAP_HORIZONTAL / 2;
	personaje_y = MAP_VERTICAL / 2;
	for (size_t i = 0; i < 29; i++)   //vemos el alto de la pantalla de la consola / me relleno el mapa
	{
		for (size_t j = 0; j < 120; j++)   //vemos el ancho de la pantalla de la consola
		{
			if (i == 0 || j == 0 || i == MAP_VERTICAL - 1 || j == MAP_HORIZONTAL - 1) //declaramos donde queremos el #
			{
				map[i][j] = TILES::WALL;    //inicializamos la memoria con un valor
			}
			else
			{
				map[i][j] = TILES::EMPTY; 

			}
		}

	}
	
	map[10][10] = TILES::POINT; // añado puntos por el mapa
	map[10][11] = TILES::POINT;
	map[10][12] = TILES::POINT;
	
	
	map[11][0] = TILES::EMPTY; //hacemos huecos en el mapa 
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

	for (size_t i = 0; i < 29; i++)   //compruebo cuantos puntos tengo en el mapa y me dice mi puntuacion total
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
	if (personaje_x_new < 0) // antes de comprobar la colision, colocamos este if para que el personaje aparezca por el otro lado
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
		map[personaje_y_new][personaje_x_new] = TILES::EMPTY; //asi vacio donde está el personaje
	default:
		personaje_y = personaje_y_new;
		personaje_x = personaje_x_new;
		break;
	}
}

void Draw()
{
	system("CLS"); //ponemos una funcion de WINDOWS clean screen para q se vea aceptable
	for (size_t i = 0; i < 29; i++)   //imprimimos esa memoria para imprimirla por pantalla
	{
		for (size_t j = 0; j < 120; j++)
		{
			if (i == personaje_y && j == personaje_x) //aqui o pintamos nuestro personaje o el limite del mapa
			{
				std::cout << PERSONAJE;
			}
			else
			{
				std::cout << (char)map[i][j]; // nuestro mapa es un array de 2d ponemos el char para decir en que queremos transformar el enum y no salga el numero entero asignado
			}
		}
		std::cout << std::endl;
	}
	std::cout << puntuacion_actual << '/' << puntuacion_total;
}

int main() 
{
	Setup();
	Draw();
	while (run) //le indicamos lo que hace mientras se este ejecutando
	{
		Input();
		Logic();
		Draw();
	}
	
}

