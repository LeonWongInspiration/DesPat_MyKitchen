//
//  TablewareFactory.h
//  Created by Zhang Qian on 2018/10/30.
//

#include "Tableware.h"

/**
* @brief A class used to instantiate Tableware.
*/

class TablewareFactory
{
private:
	/**
	* The total number of bowls.
	*/
	int BowlCounter=0;
	/**
	* The total number of plates.
	*/
	int PlateCounter = 0;

public:
	/**
	* @brief Get the total number of bowls.
	*
	* @return (int) The total number of bowls.
	*/
	int GetBowlCounter()
	{
		return BowlCounter;
	}
	/**
	* @brief Get the total number of plates.
	*
	* @return (int) The total number of plates.
	*/
	int GetPlateCounter()
	{
		return PlateCounter;
	}
	/**
	* @brief Instantiate classes of the bowl and plate.
	*
	* @return (Tableware*) A pointer to an object that is instantiated as a bowl or plate.
	*/
	Tableware* CreatTableware(Type type)
	{
		Tableware* temp = NULL;

		switch (type)
		{
		case Type_Bowl:

			temp = new Bowl();

			BowlCounter++;

			break;

		case Type_Plate:

			temp = new Plate();

			PlateCounter++;

			break;

		default:
			break;
		}
		return temp;
	}

};

