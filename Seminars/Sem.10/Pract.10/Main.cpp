#include "String.hpp"
#include "CarPart.hpp"
#include "Tyre.hpp"
#include "Accumulator.hpp"
#include "Engine.hpp"
#include "FuelTank.hpp"
#include "Car.hpp"
#include <iostream>

int main()
{
	//Make two cars adn use dragRace func
	//Car* dragRace(Car* car1, Car* car2);
	char manufacturerTyre[10] = "Michelin";
	String manufacturer(manufacturerTyre);
	char descriptionTyre[20] = "Pilot Sport 4";
	String description(descriptionTyre);
	Tyre tyre1(1, manufacturer, description, 156, 50, 15);
	Tyre tyre2(2, manufacturer, description, 156, 50, 15);
	Tyre tyre3(3, manufacturer, description, 156, 50, 15);
	Tyre tyre4(4, manufacturer, description, 156, 50, 15);
	Tyre tyres1[4] = { tyre1, tyre2, tyre3, tyre4 };

	char manufacturerAccumulator[10] = "Bosch";
	String manufacturerAcc(manufacturerAccumulator);
	char descriptionAccumulator[20] = "S5";
	String descriptionAcc(descriptionAccumulator);
	char bateryType[10] = "Li-Ion";
	String batery(bateryType);
	Accumulator accumulator1(1, manufacturerAcc, descriptionAcc, batery, 100);

	char manufacturerEngine[10] = "BMW";
	String manufacturerEng(manufacturerEngine);
	char descriptionEngine[20] = "N55";
	String descriptionEng(descriptionEngine);
	Engine engine1(1, manufacturerEng, descriptionEng, 306);

	char manufacturerFuelTank[10] = "BMW";
	String manufacturerFT(manufacturerFuelTank);
	char descriptionFuelTank[20] = "N55";
	String descriptionFT(descriptionFuelTank);
	FuelTank fuelTank1(1, manufacturerFT, descriptionFT, 60, 60);

	Car car1(fuelTank1, engine1, tyres1, accumulator1, 0, 1500);

	char manufacturerTyre2[10] = "Michelin";
	String manufacturer2(manufacturerTyre2);
	char descriptionTyre2[20] = "Pilot Sport 4";
	String description2(descriptionTyre2);
	Tyre tyre5(1, manufacturer2, description2, 156, 50, 15);
	Tyre tyre6(2, manufacturer2, description2, 156, 50, 15);
	Tyre tyre7(3, manufacturer2, description2, 156, 50, 15);
	Tyre tyre8(4, manufacturer2, description2, 156, 50, 15);
	Tyre tyres2[4] = { tyre5, tyre6, tyre7, tyre8 };

	char manufacturerAccumulator2[10] = "Bosch";
	String manufacturerAcc2(manufacturerAccumulator2);
	char descriptionAccumulator2[20] = "S5";
	String descriptionAcc2(descriptionAccumulator2);
	char bateryType2[10] = "Li-Ion";
	String batery2(bateryType2);
	Accumulator accumulator2(1, manufacturerAcc2, descriptionAcc2, batery2, 100);

	char manufacturerEngine2[10] = "BMW";
	String manufacturerEng2(manufacturerEngine2);
	char descriptionEngine2[20] = "N55";
	String descriptionEng2(descriptionEngine2);
	Engine engine2(1, manufacturerEng2, descriptionEng2, 306);

	char manufacturerFuelTank2[10] = "Audi";
	String manufacturerFT2(manufacturerFuelTank2);
	char descriptionFuelTank2[20] = "Q7";
	String descriptionFT2(descriptionFuelTank2);
	FuelTank fuelTank2(1, manufacturerFT2, descriptionFT2, 60, 60);

	Car car2(fuelTank2, engine2, tyres2, accumulator2, 0, 1400);

	dragRace(&car1, &car2);


	return 0;

}