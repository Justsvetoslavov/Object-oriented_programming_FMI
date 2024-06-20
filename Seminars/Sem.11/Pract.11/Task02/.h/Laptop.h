#pragma once
#include "Computer.h"

class Laptop :public Computer
{
public:
	Laptop() = default;
	Laptop(double CPU_power, const char* vide_card_mode, int video_count, int power_supply, int RAM_amount);

	void changeCpu(double newCPU)override;
	void changeVideo(const char* video,int video_count)override;
	void changePower(int newPower)override;
	void changeRam(int newRAM)override;
	void setPeripherals() override;

	void print()const override;
};