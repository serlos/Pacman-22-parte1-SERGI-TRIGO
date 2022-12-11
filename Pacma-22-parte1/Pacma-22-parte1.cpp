// Pacma-22-parte1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAP_VERTICAL 29   // creamos macros para que no nos queden números sueltos y asegurarnos no equivocarnos
#define MAP_HORIZONTAL 120
enum TILES {EMPTY = ' ', WALL ='#', POINT='.' }; //enum define un set y nos da un entero
TILES map[MAP_VERTICAL][MAP_HORIZONTAL]; //lo ponemos aqui para poder acceder de donde queramos /reservo memoria, rellenamos nuestro array / el map guarda que es lo que tengo en cada una de las casillas
bool run = true; //para saber si estamos ejecutando la apliación o no
enum INPUT {QUIT, UP, DOWN , LEFT, RIGHT, UNKNOWN};
INPUT currentInput = INPUT::UNKNOWN;

void Setup()
{ 
	for (size_t i = 0; i < 29; i++)   //vemos el alto de la pantalla de la consola
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
	switch (currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	
	}
}

void Draw()
{
	system("CLS"); //ponemos una funciond e WINDOWS clean screen para q se vea aceptable
	for (size_t i = 0; i < 29; i++)   //imprimimos esa memoria para imprimirla por pantalla
	{
		for (size_t j = 0; j < 120; j++)
		{
			std::cout << (char)map[i][j]; //ponemos el char para decir en que queremos transformar el enum y no salga el numero entero asignado
		}
		std::cout << std::endl;
	}
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

