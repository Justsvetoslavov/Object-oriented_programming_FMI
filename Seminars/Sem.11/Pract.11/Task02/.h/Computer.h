#pragma once
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)

class Computer
{
	double CPU_power;
	int POWER_supply;
	int RAM_amount;
	int VIDEOCARD_count;
	char *VIDEOCARD_mode;

protected:

	char** peripherals;
	size_t peripheralsCount;

public:

	Computer()=default;
	Computer(double CPU_power, const char* vide_card_mode, int videocard_count,int power_supply, int RAM_amount);
	virtual ~Computer();

	void setCpu(double cpu);
	void setVideo(const char* video,int videocard_count);
	void setPower(int power);
	void setRam(int ram);
	virtual void setPeripherals()=0;
	void initPeripherals();


	double getCPU()const;
	const char* getVideo()const;
	int getPower()const;
	int getRam()const;
	const char** getPeripherals()const;
   
	virtual  void changeCpu(double newCPU);
	virtual  void changePower(int newP);
	virtual  void changeRam(int newRAM);
	virtual  void changeVideo(const char*newVIDEO, int videocard_count);

	virtual void print()const = 0;

};