//
//  main.cpp
//  Created by Zhang Qian on 2018/10/31.
//

#include "../Sources/Tableware/DishUp.h"

#include <stdlib.h>

#include <time.h>

int main()
{
	srand(time(0));

	int num = rand() % 1000;

	std::cout<<"菜的数量为" << num<<std::endl;
	
	DishUp dishUp;

	dishUp.DishUpFood(num);

	getchar();
	return 0;
}