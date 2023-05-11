#pragma once
#include"Computer.h"
#include<cstring>
#pragma warning(disable:4996)

class PC :public Computer
{

public:
	PC() = default;
	PC(double CPU_power, const char* vide_card_mode, int video_count, int power_supply, int RAM_amount);

	void print()const override;
	void setPeripherals() override;

	void changeCpu(double newCPU)override;
	void changeVideo(const char* video, int video_count)override;
	void changePower(int newPower)override;
	void changeRam(int newRAM)override;

};

