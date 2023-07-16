#pragma once

const size_t MAX_SIZE_DEVICE = 15;

class Computer
{
protected:
	char* typeVideoCard;
	char** peripheralDevices;
	size_t count = 0;

	int powerSupply;
	int ram;
	double processorPower;

	void initializePeripheralDevices();

public:
	virtual void setPeripheralDevices() = 0;

	void changeType(const char* newTypeVideoCard);
	void changePowerSupply(const int newPowerSupply);
    void changeRam(const int newRam);
	void changeProcessorPower(const double newProcessorPower);

	virtual void writeComputerType() const = 0;
	const char** getPeripheralDevices() const;

	virtual ~Computer() = 0;
};

