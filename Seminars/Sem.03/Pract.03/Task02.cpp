#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::ofstream;
using std::ifstream;

const int MAX_COMPANY_NAME_LENGTH = 25;
const int MAX_INPUT_LENGTH = 256;

struct jobOffer {
	char companyName[MAX_COMPANY_NAME_LENGTH]; //25
	int teamCount; //4
	int paidVacancyDays; //4
	long long salary; //8
};

void filterOffers(ifstream& file, long long minSalary);
void perfectOffer(ifstream& file, int maxCoworkers,
	int minVacancyDays, int minSalary);
void readOffersFromConsoleAndSaveInFile(const char* filePath,
	int requestsCount);


int main()
{
	readOffersFromConsoleAndSaveInFile("file.dat", 2);
	ifstream file("file.dat", ios::binary | ios::in);	
	if (!file.is_open())
	{
		cout << "Error opening " << "file.dat" << "." << endl;
		return -1;
	}


	file.close();
}

void readSingleOffer(jobOffer& offer) {
	cout << "Company name: ";
	cin >> offer.companyName;
	cout << "Team count: ";
	cin >> offer.teamCount;
	cout << "Paid vacation days count: ";
	cin >> offer.paidVacancyDays;
	cout << "Salary: ";
	cin >> offer.salary;
}



void readOffersFromConsoleAndSaveInFile(const char* filePath, int requestsCount) {
	ofstream file(filePath, ios::binary | ios::out | ios::app);
	if (!file.is_open())
	{
		cout << "Error opening " << filePath << "." << endl;
		return;
	}
	for (size_t i = 0; i < requestsCount; i++)
	{
		jobOffer offer;
		cout << "Request " << i + 1 << endl;
		readSingleOffer(offer);
		file.write((char*)&offer, sizeof(offer));
	}
	file.close();
}

size_t getFileSize(ifstream& file) {
	size_t current = file.tellg();
	file.seekg(0, ios::end);
	size_t fileSize = file.tellg();
	file.seekg(current, ios::beg);
	return fileSize;
}

void printOffer(jobOffer& jobAd) {
	cout << "Company Name: " << jobAd.companyName << endl;
	cout << "Team count: " << jobAd.teamCount << endl;
	cout << "Paid vacation days count: " << jobAd.paidVacancyDays << endl;
	cout << "Salary: " << jobAd.salary << endl;
	cout << endl;
}

jobOffer* readOffersFromFile(ifstream& file, size_t fileSize, size_t jobAdsCount) {
	jobOffer* jobOffers = new jobOffer[jobAdsCount];
	file.read((char*)jobOffers, jobAdsCount * sizeof(jobOffer));
	return jobOffers;
}

void filterOffers(ifstream& file, long long minSalary) {
	size_t fileSize = getFileSize(file);
	size_t jobOffersCount = fileSize / sizeof(jobOffer);
	jobOffer* jobOffers = readOffersFromFile(file, fileSize, jobOffersCount);

	for (size_t i = 0; i < jobOffersCount; i++)
	{
		if (jobOffers[i].salary >= minSalary)
		{
			printOffer(jobOffers[i]);
		}
	}
	delete[] jobOffers;
}

size_t min(size_t a, size_t b) {
	return a ? a < b : b;
}

size_t charArraySize(const char* arr) {
	size_t size = 0;
	while (*(arr++) != '\0') size++;
	return size;
}

bool areEqual(const char* arr1, const char* arr2) {
	size_t size1 = charArraySize(arr1);
	size_t size2 = charArraySize(arr2);
	if (size1 != size2) return false;
	for (size_t i = 0; i < size1; i++)
	{
		if (arr1[i] != arr2[i]) return false;
	}
	return true;
}

bool existOffer(ifstream& file, const char* name) {
	size_t fileSize = getFileSize(file);
	size_t jobOffersCount = fileSize / sizeof(jobOffer);
	jobOffer* jobOffers = readOffersFromFile(file, fileSize, jobOffersCount);
	for (size_t i = 0; i < jobOffersCount; i++)
	{
		if (areEqual(jobOffers[i].companyName, name))
		{
			delete[] jobOffers;
			return true;
		}
	}
}



//bonus
void perfectOffer(ifstream& file, int maxCoworkers,
	int minVacancyDays, int minSalary) {
	size_t fileSize = getFileSize(file);
	size_t jobOffersCount = fileSize / sizeof(jobOffer);
	jobOffer* jobOffers = readOffersFromFile(file, fileSize, jobOffersCount);

	for (size_t i = 0; i < jobOffersCount; i++)
	{
		if (jobOffers[i].teamCount <= maxCoworkers &&
			jobOffers[i].paidVacancyDays >= minVacancyDays &&
			jobOffers[i].salary >= minSalary)
		{
			printOffer(jobOffers[i]);
		}
	}
	delete[] jobOffers;
}



