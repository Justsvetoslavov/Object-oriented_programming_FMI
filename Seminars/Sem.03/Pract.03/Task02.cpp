#include <iostream>
#include <fstream>

const int MAX_LENGHT = 25;

struct JobOffer {
    char companyName[MAX_LENGHT + 1];
    size_t numberOfDevelopers;
    size_t numberOfVacationDays;
    long long priceOfProject;
};

size_t Mystrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return *(const unsigned char*) str1 - *(const unsigned char*) str2;
}

void ReadJobOffer(JobOffer& jobOffer) {
    std::cout << "Enter details for job offer:" << std::endl;

    std::cout << "Company name: ";
    std::cin.getline(jobOffer.companyName, MAX_LENGHT);

    std::cout << "Number of developers: ";
    std::cin >> jobOffer.numberOfDevelopers;

    std::cout << "Number of vacation days: ";
    std::cin >> jobOffer.numberOfVacationDays;

    std::cout << "Price of project: ";
    std::cin >> jobOffer.priceOfProject;

    std::cin.ignore(); // ignore the newline character
}

void PrintJobOffer(const JobOffer& jobOffer) {
    std::cout << "Company Name: " << jobOffer.companyName << std::endl;
    std::cout << "Number of Developers: " << jobOffer.numberOfDevelopers << std::endl;
    std::cout << "Number of Vacation Days: " << jobOffer.numberOfVacationDays << std::endl;
    std::cout << "Price of Project: " << jobOffer.priceOfProject << std::endl;
}

void StoreJobOffer(const JobOffer& jobOffer, const char* fileName) {
    std::ofstream file(fileName, std::ios::binary | std::ios::app);
    if (file.is_open()) {
        file.write((const char*) &jobOffer, sizeof(JobOffer));
        file.close();
    } else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

void listAllJobOffers(const char* fileName) {
    std::ifstream file(fileName, std::ios::in | std::ios::binary);
    if (file.is_open()) {
        JobOffer jobOffer;
        while (file.read((char*) &jobOffer, sizeof(JobOffer))) {
                PrintJobOffer(jobOffer);
                std::cout << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
}

void ListJobOffersWithGreaterPriceThan(long long projectPrice, const char* fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (file.is_open()) {
        JobOffer jobOffer;
        while (file.read((char*) &jobOffer, sizeof(JobOffer))) {
            if (jobOffer.priceOfProject > projectPrice) {
                PrintJobOffer(jobOffer);
                std::cout << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
}

void ListJobOffersFromCompany(const char* companyName, const char* fileName) {
    std::ifstream file(fileName,std::ios::binary);
    if (file.is_open()) {
        JobOffer jobOffer;
        while (file.read((char*) &jobOffer, sizeof(JobOffer))) {
            if (Mystrcmp(jobOffer.companyName, companyName) == 0) {
                PrintJobOffer(jobOffer);
                std::cout << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
}

void DisplayMenu() {
    std::cout << "Job Offers Menu:" << std::endl;
    std::cout << "1. Input and store in a binary file a job offer" << std::endl;
    std::cout << "2. List all job offers" << std::endl;
    std::cout << "3. List all job offers that have priceOfProject greater than n" << std::endl;
    std::cout << "4. List all job offers from a company" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int main() {
    int choice = -1;
    JobOffer currentJobOffer;
    char companyName[MAX_LENGHT + 1];
    long long minProjectPrice = 0;
    while (choice != 0) {
        DisplayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                std::cout << "Option 1 selected" << std::endl;
                ReadJobOffer(currentJobOffer);
                StoreJobOffer(currentJobOffer, "jobOffers.bin");
                break;
            case 2:
                std::cout << "Option 2 selected" << std::endl;
                ListAllJobOffers("jobOffers.bin");
                break;
            case 3:
                std::cout << "Company name: ";
                std::cin >> minProjectPrice;
                ListJobOffersWithGreaterPriceThan(minProjectPrice, "jobOffers.bin");
                break;
            case 4:
                std::cout << "Company name: ";
                std::cin.getline(companyName, 25);
                ListJobOffersFromCompany(companyName, "jobOffers.bin");
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
    return 0;
}