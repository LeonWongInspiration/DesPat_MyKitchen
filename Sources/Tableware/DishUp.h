#pragma once

//
//  DishUp.h
//  Created by Zhang Qian on 2018/10/30.
//
#include "TablewareFactory.h"

#include "Object.h"

/**
* @brief A class used to put the food from the stovetop into the Tableware.
*/
class DishUp:public Object
{
public:

	/**
	* @brief Set the capacity of Tableware.
	*
	* @param num (int): The variable receives the number of food delivered from the stovetop.
	*/
	void DishUpFood(int num)
	{
		TablewareFactory* containFactory = new TablewareFactory();

		while (num >= 0)
		{
			if (num > 300)
			{
				num -= 300;

				containFactory->CreatTableware(Type_Bowl);

				std::cout << "The remaining portion of the dish is " << num << std::endl;

			}
			else if (num > 150 && num <= 300)
			{
				containFactory->CreatTableware(Type_Bowl);

				std::cout << "The remaining portion of the dish is 0" << std::endl;

				break;
			}
			else
			{
				containFactory->CreatTableware(Type_Plate);

				std::cout << "The remaining portion of the dish is 0" << std::endl;

				break;
			}
		}
		std::cout << "The total number of bowls is " << containFactory->GetBowlCounter() << std::endl;

		std::cout << "The total number of plates is " << containFactory->GetPlateCounter() << std::endl;

		std::cout << "Fill dish to complete!" << std::endl;
	}

};

