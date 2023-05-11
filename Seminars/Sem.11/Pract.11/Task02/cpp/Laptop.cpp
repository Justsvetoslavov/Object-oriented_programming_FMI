#include "Laptop.h"

Laptop::Laptop(double CPU_power,const  char* vide_card_mode, int video_count, int power_supply, int RAM_amount) :
	Computer( CPU_power, vide_card_mode, video_count,  power_supply,  RAM_amount){}

void  Laptop::print() const 
{
	std::cout << "This is a laptop" << std::endl;
}

void  Laptop::changeCpu(double newCPU)
{
	Computer::changeCpu(newCPU);
}

void Laptop::changeVideo(const char* video,int video_count) 
{
	Computer::changeVideo(video,video_count);
}

void Laptop::changePower(int newPower) 
{
	Computer::changePower(newPower);
}

void  Laptop::changeRam(int newRAM) 
{
	Computer::changeRam(newRAM);
}

void Laptop::setPeripherals() 
{
	peripheralsCount = 3;
	initPeripherals();
	strcpy(peripherals[0], "mouse pad");
	strcpy(peripherals[1], "keyboard");
	strcpy(peripherals[2], "monitor");
}