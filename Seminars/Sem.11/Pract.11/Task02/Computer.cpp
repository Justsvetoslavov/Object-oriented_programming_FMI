#include "Computer.h"

Computer::Computer(double CPU_power, const MyString& videoCardModel, int powerSupply, int RAM) {
	setCPU_power(CPU_power);
	setVideoCardModel(videoCardModel);
	setPowerSupply(powerSupply);
	setRAM(RAM);
}

void Computer::setCPU_power(double CPU_power) {
	if (CPU_power <= 0) {
		return;
	}
	_CPU_power = CPU_power;
}

void Computer::setVideoCardModel(const MyString& videoCardModel) {
	_videoCardModel = videoCardModel;
}

void Computer::setPowerSupply(int powerSupply) {
	if (powerSupply <= 0) {
		return;
	}
	_powerSupply = powerSupply;
}

void Computer::setRAM(int RAM) {
	if (RAM <= 0) {
		return;
	}
	_RAM = RAM;
}

