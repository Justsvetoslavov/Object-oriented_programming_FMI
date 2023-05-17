#include "PC.h"


PC::PC(double CPU_power, const MyString& videoCardModel, int powerSupply, int RAM,
	const MyString& mouse, const MyString& keyboard, const MyString& microphone, const MyString& headphones)
	: Computer(CPU_power, videoCardModel, powerSupply, RAM) {
	_mouse = mouse;
	_keyboard = keyboard;
	_microphone = microphone;
	_headphones = headphones;
}

void PC::printComputerType() const {
	std::cout << "Computer type: PC" << std::endl;
}

const MyString& PC::getPeripheralDevices() const {
	return _mouse + " " + _keyboard + " " + _microphone + " " + _headphones;
}