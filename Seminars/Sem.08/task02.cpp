#include <iostream>
#include <fstream>
#include "Car.h"

const char FILE_CARS[] = "cars.txt";

void carsToFile(const Car* cars, const int& length)
{
	std::ofstream file(FILE_CARS);
	if (!file.is_open())
	{
		std::cout << "Could not open file " << FILE_CARS << "\n";
		return;
	}

	for (size_t i = 0; i < length; i++)
	{
		file << cars[i].getBrand()
			<< "\n" << cars[i].getOwner().getFName()
			<< "\n" << cars[i].getOwner().getLName()
			<< "\n" << cars[i].getOwner().getGender()
			<< "\n" << cars[i].getOwner().getYearOfBirth()
			<< "\n" << cars[i].getYearOfRegistration() << "\n";
	}
	file.close();
}

void carsFromFile(Car* cars, const int& length)
{
	std::ifstream file(FILE_CARS);
	if (!file.is_open())
	{
		std::cout << "Could not open file " << FILE_CARS << "\n";
		return;
	}

	for (size_t i = 0; i < length; i++)
	{
		char buffer[128];
		file.getline(buffer, 127);
		cars[i].setBrand(buffer);

		Person owner;
		file.getline(buffer, 127);
		owner.setFName(buffer);
		file.getline(buffer, 127);
		owner.setLName(buffer);
		file.getline(buffer, 1);
		owner.setGender(buffer[0]);
		unsigned year;
		file >> year;
		owner.setYearOfBirth(year);
		cars[i].setOwner(owner);

		file >> year;
		cars[i].setYearOfRegistration(year);
	}
	file.close();
}

void printCar(const Car& car)
{
	std::cout << "Brand: " << car.getBrand()
		<< "\nOwner: " << car.getOwner().getFName()
		<< " " << car.getOwner().getLName()
		<< ", " << car.getOwner().getGender()
		<< ", born " << car.getOwner().getYearOfBirth()
		<< "\nYear of registration: " << car.getYearOfRegistration() << "\n";
}

void getTopBrand(char* brand)
{
	Car cars[5];
	carsFromFile(cars, 5);
	int maxCount = 1, curCount = 1;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = i; j < 5; j++)
		{
			if (strcmp(cars[i].getBrand(), cars[j].getBrand()) == 0)
			{
				curCount++;
			}
		}
		if (curCount > maxCount)
		{
			maxCount = curCount;
			strcpy(brand, cars[i].getBrand());
		}
		if (curCount == maxCount && strcmp(cars[i].getBrand(), brand) < 0)
		{
			strcpy(brand, cars[i].getBrand());
		}
		curCount = 1;
	}
}

int main()
{
	Car cars[] = { { "Kia", Person("Ivan", "Ivanov", 'm', 1989), 2015 },
				   { "Audi", Person("Maria", "Dimitrova", 'f', 1999), 2019 },
				   { "Ford", Person("Nikola", "Nikolov", 'm', 1980), 2000 },
		           { "Kia", Person("Nina", "Ivanova", 'f', 1980), 2011 },
				   { "Audi", Person("Todor", "Nikolov", 'm', 1979), 2014 } };
	carsToFile(cars, 5);
	Car carsFile[5];
	carsFromFile(carsFile, 5);
	for (size_t i = 0; i < 5; i++)
	{
		printCar(carsFile[i]);
	}

	char topBrand[129];
	getTopBrand(topBrand);
	for (size_t i = 0; topBrand[i] != '\0'; i++)
	{
		std::cout << topBrand[i];
	}
	std::cout << "\n";
	return 0;
}
