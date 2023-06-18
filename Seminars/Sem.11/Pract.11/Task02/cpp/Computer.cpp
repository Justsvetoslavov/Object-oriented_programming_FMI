#include "Computer.h"
#include<iostream>

Computer::Computer(double CPU_power, const char* video_card_mode, int videocard_count, int power_supply, int RAM_amount)
{
	setCpu(CPU_power);
	VIDEOCARD_mode = new char[videocard_count + 1];
	setVideo(video_card_mode,  videocard_count);
	setPower(power_supply);
	setRam(RAM_amount);

}

void  Computer::setCpu(double cpu)
{
	CPU_power = cpu;
}

void Computer::setVideo(const char* video, int videocard_count)
{
	if (videocard_count < VIDEOCARD_count) 
	{
		VIDEOCARD_count = videocard_count;
		for (int i = 0; i < VIDEOCARD_count; i++) 
		{
			VIDEOCARD_mode[i] = video[i];
		}
		VIDEOCARD_mode[VIDEOCARD_count] = '\0';
	}
}

void Computer::setPower(int power)
{
	POWER_supply = power;
}

void Computer::setRam(int ram) 
{
	RAM_amount = ram;
}

double Computer::getCPU()const 
{
	return CPU_power;
}

const char* Computer::getVideo()const
{
	return VIDEOCARD_mode;
}

int Computer::getPower()const
{
	return POWER_supply;
}

int Computer::getRam()const 
{
	return RAM_amount;
}

void  Computer::changeCpu(double newCPU)
{
	setCpu(newCPU);
}

void Computer::changeVideo(const char* video, int videocard_count)
{
	setVideo(video, videocard_count);
 }

void Computer::changePower(int newPower)
{
	setPower(newPower);
}

void Computer::changeRam(int newRAM) 
{
	setRam(newRAM);
}

Computer::~Computer() {
	delete[]VIDEOCARD_mode;

	for (size_t i = 0; i < peripheralsCount; i++) 
	{
		delete[]peripherals[i];
	}
	delete[]peripherals;
}

void Computer::initPeripherals() 
{	
	peripherals = new  char* [peripheralsCount];
	for (size_t i = 0; i < peripheralsCount; i++)
	{
		size_t length = strlen(peripherals[i] + 1);
		peripherals[i] = new char[length];
	}
}
const char** Computer::getPeripherals() const
{
	return (const char**)peripherals; 
}