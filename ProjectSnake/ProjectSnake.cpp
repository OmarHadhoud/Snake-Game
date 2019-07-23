// ProjectSnake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Manager.h"
#include <iostream>
#include <vector>



int main()
{
	Manager m;
	int menu = 0;
	while (menu != 4)
	{
		switch (menu)
		{
		case 0:
			menu = m.WelcomeMenu();
			break;
		case 1:
			m.Play();
			menu = 0;
			break;
		case 2:
			m.HighScores();
			menu = 0;
			break;
		case 3:
			m.About();
			menu = 0;
			break;
		default:
			break;
		}
	}
	cout << "Thanks for playing. See u!\n\n\n";
	
    return 0;
}

