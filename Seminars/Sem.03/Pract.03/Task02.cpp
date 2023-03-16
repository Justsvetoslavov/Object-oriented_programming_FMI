#include <iostream>
#include <fstream>

const int GROUP_NAME_SIZE = 25;
const char FILE_PATH[] = "jobOfferFile3.txt";
#pragma warning(disable : 4996)

struct JobOffer {
	char groupName[GROUP_NAME_SIZE + 1];
	int colleaguesCount;
	int paidLeaveDays;
	long long salary;
};

JobOffer InitJobOffer(const char* groupName, int colleaguesCount, int paidLeaveDays, long long salary) {
	JobOffer jobOffer;
	strcpy(jobOffer.groupName, groupName);
	jobOffer.colleaguesCount = colleaguesCount;
	jobOffer.paidLeaveDays = paidLeaveDays;
	jobOffer.salary = salary;
	return jobOffer;
}

size_t GetFileSize(std::ifstream& file) {
	size_t size;
	int currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	size = file.tellg();
	file.seekg(currentPos);
	return size;
}


void WriteJobOffer(std::ofstream& writeFile, const JobOffer& jobOffer) {
	if (!writeFile.is_open()) {
		std::cout << "Error opening file!";
		return;
	}

	writeFile.write((const char*)&jobOffer, sizeof(JobOffer));
}

int GetJobOffersCountFromFile(std::ifstream& readFile) {
	int currentCountOfJobOffers;
	currentCountOfJobOffers = GetFileSize(readFile) / sizeof(JobOffer);
	return currentCountOfJobOffers;
}

JobOffer* GetJobOffersFromFile(std::ifstream& readFile) {
	int jobOffersCount = GetJobOffersCountFromFile(readFile);
	JobOffer* jobOffers = new JobOffer[jobOffersCount];

	readFile.read((char*)jobOffers, jobOffersCount * sizeof(JobOffer));

	return jobOffers;
}

void PrintJobOffer(const JobOffer& jobOffer) {
	std::cout << "Group name: " << jobOffer.groupName << std::endl;
	std::cout << "Colleagues count: " << jobOffer.colleaguesCount << std::endl;
	std::cout << "Count of paid leave days: " << jobOffer.paidLeaveDays << std::endl;
	std::cout << "Salary for project: " << jobOffer.salary << std::endl;
}

void FilterOffers(const char* filePath, long long minSalary) {
	std::ifstream readFile(filePath, std::ios::binary);
	if (!readFile.is_open()) {
		std::cout << "Error opening file!";
		return;
	}

	JobOffer* jobOffers = GetJobOffersFromFile(readFile);
	int countOfJobOffers = GetJobOffersCountFromFile(readFile);

	for (size_t i = 0; i < countOfJobOffers; i++)
	{
		if (jobOffers[i].salary > minSalary) {
			PrintJobOffer(jobOffers[i]);
		}
	}
	readFile.close();
	delete[] jobOffers;
}

bool ExistOffer(const char* filePath, const char* name) {
	std::ifstream readFile(filePath, std::ios::binary);
	if (!readFile.is_open()) {
		std::cout << "Error opening file!";
		return 0;
	}

	JobOffer* jobOffers = GetJobOffersFromFile(readFile);
	int countOfJobOffers = GetJobOffersCountFromFile(readFile);

	for (size_t i = 0; i < countOfJobOffers; i++)
	{
		if (!strcmp(jobOffers[i].groupName, name)) {
			return true;
		}
	}
	readFile.close();
	delete[] jobOffers;
}

void PerfectOffer(const char* filePath, int maxCoworkers, int minVacancyDays, int minSalary) {
	std::ifstream readFile(filePath, std::ios::binary);
	if (!readFile.is_open()) {
		std::cout << "Error opening file!";
		return;
	}

	JobOffer* jobOffers = GetJobOffersFromFile(readFile);
	int countOfJobOffers = GetJobOffersCountFromFile(readFile);

	for (size_t i = 0; i < countOfJobOffers; i++)
	{
		if (jobOffers[i].colleaguesCount == maxCoworkers
			&& jobOffers[i].paidLeaveDays == minVacancyDays
			&& jobOffers[i].salary == minSalary) {
			PrintJobOffer(jobOffers[i]);
		}
	}
	readFile.close();
	delete[] jobOffers;
}

void AddJobOffer() {
	int n;
	std::cin >> n;

	std::ofstream writeFile(FILE_PATH, std::ios::binary | std::ios::app);

	if (!writeFile.is_open()) {
		std::cout << "Error opening file!";
		return;
	}

	JobOffer* jobOffers = new JobOffer[n];

	for (size_t i = 0; i < n; i++)
	{
		char groupName[GROUP_NAME_SIZE + 1];
		int colleaguesCount;
		int paidLeaveDays;
		long long salary;

		std::cout << "Enter group name: ";
		std::cin >> groupName;
		std::cout << "Enter colleagues count: ";
		std::cin >> colleaguesCount;
		std::cout << "Enter count of paid leave days: ";
		std::cin >> paidLeaveDays;
		std::cout << "Enter salary for project: ";
		std::cin >> salary;

		jobOffers[i] = InitJobOffer(groupName, colleaguesCount, paidLeaveDays, salary);
		WriteJobOffer(writeFile, jobOffers[i]);
	}
	writeFile.close();

	delete[] jobOffers;
}

void PrintAllOffers() {
	std::ifstream readFile(FILE_PATH, std::ios::binary);
	if (!readFile.is_open()) {
		std::cout << "Error opening file!";
		return;
	}

	JobOffer* jobOffers = GetJobOffersFromFile(readFile);
	int countOfJobOffers = GetJobOffersCountFromFile(readFile);

	for (size_t i = 0; i < countOfJobOffers; i++)
	{
		std::cout << "Group " << i + 1 << std::endl;
		PrintJobOffer(jobOffers[i]);
	}
	delete[] jobOffers;
}

int main()
{
	char command;
	while (true) {
		std::cin >> command;
		switch (command) {
		case 'a': AddJobOffer();
			break;
		case 'i': PrintAllOffers();
			break;
		case 's':
			char offerName[GROUP_NAME_SIZE + 1];
			std::cin >> offerName;
			std::cout << ExistOffer(FILE_PATH, offerName);
			break;
		case 'f':
			int minSalary;
			std::cin >> minSalary;
			FilterOffers(FILE_PATH, minSalary);
			break;
		case 'q' : return 0;
		}
	}
}
