//
//  Tableware.h
//  Created by Zhang Qian on 2018/10/30.
//

#include <iostream>

#include "Type.h"

#define BowlCapacity 300

#define PlateCapacity 150

/**
* @brief A basic class containing some basal requirements of Tableware.
*/

class Tableware
{
public:
	/**
	* The capacity of tableware.
	*/
	int capacity;
	/**
	* @brief Set the capacity of tableware.
	*
	* @param num (int): The variable receives data setting the capacity size.
	*/
	void GetCapacity(int num) 
	{
		capacity = num;
	}
	/**
	* @brief Indicate the creation state.
	*/
	virtual void WhoAmI()=0;

};

/**
* @brief A class inherited from Tableware class containing some requirements of the bowl.
*/
class Bowl : public Tableware
{
public:

	/**
	* @brief Initializes the bowl's capacity and indicate the creation state.
	*/
	Bowl()
	{
		GetCapacity(BowlCapacity);

		WhoAmI();
	}
	/**
	* @brief Indicate the creation state of the bowl.
	*/
	virtual void WhoAmI()
	{
		std::cout << "A bowl is created" << std::endl;
	}
};
/**
* @brief A class inherited from Tableware class containing some requirements of the plate.
*/
class Plate :public Tableware
{
public:
	/**
	* @brief Initializes the plate's capacity and indicate the creation state.
	*/
	Plate()
	{
		GetCapacity(PlateCapacity);

		WhoAmI();
	}
	/**
	* @brief Indicate the creation state of the plate.
	*/
	virtual void WhoAmI()
	{
		std::cout << "A Plate is created" << std::endl;
	}
};
