#include "GamingConsole.h"

GamingConsole::GamingConsole(double CPU_power,const  char* vide_card_mode, int video_count,int power_supply, int RAM_amount) :
	Computer(CPU_power, vide_card_mode, video_count, power_supply, RAM_amount){}

void GamingConsole::print()const
{
	std::cout << "This is a Gaming Console" << std::endl;
}

void   GamingConsole::changeCpu(double newCPU) 
{
	Computer::changeCpu(newCPU);
}

void GamingConsole::changeVideo(const char* video, int video_count) 
{
	Computer::changeVideo(video, video_count);
}

void  GamingConsole::changePower(int newPower) 
{
	Computer::changePower(newPower);
}

void   GamingConsole::changeRam(int newRAM) 
{
	Computer::changeRam(newRAM);
}

void GamingConsole::setPeripherals() 
{
	peripheralsCount = 2;
	initPeripherals();
	strcpy(peripherals[0], "joystick");
	strcpy(peripherals[1], "monitor");
}