#include <iostream>
#include <fstream>

const char file_Name[14] = "jobOffers.dat";
const int name_max_size = 25;

struct JobOffer {
	char companyName[name_max_size + 1];
	int countOfProgrammers;
	int countOfPaidLeaveDays;
	long long salary;
};

bool IsFileOpened(std::ofstream& file) {
	if (!file.is_open()) {
		std::cout << "File couldn't open!";
		return 0;
	}
	return 1;
}

bool IsFileOpened(std::ifstream& file) {
	if (!file.is_open()) {
		std::cout << "File couldn't open!";
		return 0;
	}
	return 1;
}

void SaveJobOfferToFile(const JobOffer& offer) {
	std::ofstream file(file_Name, std::ios::binary | std::ios::app);
	if (!IsFileOpened(file))
		return;

	file.write((const char*)&offer, sizeof(JobOffer));

	file.close();
}

JobOffer ReadJobOffer() {
	JobOffer offer;

	std::cout << "Enter the company name: ";
	std::cin.ignore();
	std::cin.getline(offer.companyName, name_max_size + 1, '\n');
	std::cout << "Enter count of programmers on the team: ";
	std::cin >> offer.countOfProgrammers;
	std::cout << "Enter count of paid leave days: ";
	std::cin >> offer.countOfPaidLeaveDays;
	std::cout << "Enter the payment for completing the project: ";
	std::cin >> offer.salary;

	return offer;
}

int getFileSize(std::ifstream& file)
{
	int currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	int fileSize = file.tellg();
	file.seekg(currentPos);
	return fileSize;
}

JobOffer* ReadOffersFromFile(std::ifstream& file) {
	int sizeOfFile = getFileSize(file);
	int arraySize = sizeOfFile / sizeof(JobOffer);
	JobOffer* offers = new JobOffer[arraySize];
	file.read((char*)offers, sizeOfFile);
	return offers;
}

void PrintJobOffer(const JobOffer& offer) {
	std::cout << "Company name: " << offer.companyName << std::endl;
	std::cout << "Count of programmers: " << offer.countOfProgrammers << std::endl;
	std::cout << "Count of paid leave days: " << offer.countOfPaidLeaveDays << std::endl;
	std::cout << "Salary: " << offer.salary << std::endl;
}

void FilterOffers(const char* filePath, long long minSalary) {
	if (filePath == nullptr)
		return;
	std::ifstream file(file_Name);
	if (!IsFileOpened(file))
		return;

	JobOffer* offers = ReadOffersFromFile(file);
	int countOfOffers = getFileSize(file) / sizeof(offers[0]);
	for (int i = 0; i < countOfOffers; i++) {
		if (offers[i].salary >= minSalary)
			PrintJobOffer(offers[i]);
	}
	delete[] offers;
	file.close();
}

bool ExistOffer(const char* filePath, const char* name) {
	if (filePath == nullptr || name == nullptr)
		return false;

	std::ifstream file(filePath);
	if (!IsFileOpened(file))
		return false;

	JobOffer* offers = ReadOffersFromFile(file);
	int countOfOffers = getFileSize(file) / sizeof(offers[0]);
	for (int i = 0; i < countOfOffers; i++) {
		if (!strcmp(offers[i].companyName, name))
			return true;
	}

	delete[] offers;
	file.close();
	return false;
}

void PerfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary) {
	if (filePath == nullptr)
		return;

	std::ifstream readFile(file_Name);
	if (!IsFileOpened(readFile))
		return;

	std::ofstream writeFile("IdealOffers.dat", std::ios::binary);
	if (!IsFileOpened(writeFile))
		return;
	JobOffer* offers = ReadOffersFromFile(readFile);
	int countOfOffers = getFileSize(readFile) / sizeof(offers[0]);
	for (int i = 0; i < countOfOffers; i++) {
		if (offers[i].countOfProgrammers < maxCoworkers && offers[i].countOfPaidLeaveDays < minVacancyDays && offers[i].salary < minSalary)
		{
			writeFile.write((const char*)&offers[i], sizeof(JobOffer));
		}
	}

	delete[] offers;
	readFile.close();
	writeFile.close();
}

void PrintAllJobOffers() {
	std::ifstream file(file_Name);
	if (!IsFileOpened(file))
		return;

	JobOffer* offers = ReadOffersFromFile(file);
	int countOfOffers = getFileSize(file) / sizeof(offers[0]);
	for (int i = 0; i < countOfOffers; i++) {
		PrintJobOffer(offers[i]);
	}
	file.close();
	delete[] offers;
}

void HasReceivedInvitation() {
	char companyName[name_max_size + 1];
	std::cout << "Enter company name: ";
	std::cin.ignore();
	std::cin.getline(companyName, name_max_size + 1, '\n');
	if (ExistOffer(file_Name, companyName))
		std::cout << "You have received an invitation for job!\n";
	else
		std::cout << "You haven't received an invitation for job!\n";
}

void PrintOffersWithHigherSalary() {
	int salary;
	std::cout << "Enter wanted salary: ";
	std::cin >> salary;
	std::cout << "\nPrinting offers with salary higher than " << salary << std::endl;
	FilterOffers(file_Name, salary);
}

int main()
{
	std::cout << "Menu:\n";
	std::cout << "a - adds job offer\n";
	std::cout << "i - shows all offers\n";
	std::cout << "s - reads company name and shows whether the job offer exists\n";
	std::cout << "f - reads a number for minimal salary and shows all the companies which fulfill it\n";
	std::cout << "q - exit\n";

	bool isExited = false;

	while (!isExited)
	{
		std::cout << "Enter command: ";
		char operation;
		std::cin >> operation;
		switch (operation) {
			case 'a':
				JobOffer offer = ReadJobOffer();
				SaveJobOfferToFile(offer);
				break;
			case 'i':
				PrintAllJobOffers();
				break;
			case 's':
				HasReceivedInvitation();
				break;
			case 'f':
				PrintOffersWithHigherSalary();
				break;
			case 'q':
				std::cout << "Goodbye!";
				isExited = true;
				break;
			default:
				std::cout << "Wrong command!\n";
				break;
		}
	}
}