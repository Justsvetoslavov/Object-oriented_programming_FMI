#include "PC.h"

PC::PC(double CPU_power, const char* vide_card_mode, int video_count, int power_supply, int RAM_amount) 
	:Computer(CPU_power, vide_card_mode,  video_count,power_supply, RAM_amount) {}

void  PC::print()const 
{
	std::cout << "This is PC" << std::endl;
}

void  PC::changeCpu(double newCPU) 
{
	Computer::changeCpu(newCPU);
}

void PC::changeVideo(const char* video, int video_count)
{
	Computer::changeVideo(video,  video_count);
}

void PC::changePower(int newPower) 
{
	Computer::changePower(newPower);
}

void  PC::changeRam(int newRAM) 
{
	Computer::changeRam(newRAM);
}

void PC::setPeripherals()
{
	peripheralsCount = 4;
	initPeripherals();
	strcpy(peripherals[0], "mouse ");
	strcpy(peripherals[1], "keyboard");
	strcpy(peripherals[2], "microphone");
	strcpy(peripherals[3], "headphones");
}