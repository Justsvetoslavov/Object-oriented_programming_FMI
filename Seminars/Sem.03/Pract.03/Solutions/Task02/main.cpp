#include <iostream>
#include <fstream>

struct JobOffer {
    char companyName[25];
    int numberOfDevelopers;
    int numberOfVacationDays;
    long long priceOfProject;
};

int mystrcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return *(const unsigned char *) str1 - *(const unsigned char *) str2;
}

void readJobOffer(JobOffer &jobOffer) {
    std::cout << "Enter details for job offer:" << std::endl;
    std::cout << "Company name: ";
    std::cin.getline(jobOffer.companyName, 25);
    std::cout << "Number of developers: ";
    std::cin >> jobOffer.numberOfDevelopers;
    std::cout << "Number of vacation days: ";
    std::cin >> jobOffer.numberOfVacationDays;
    std::cout << "Price of project: ";
    std::cin >> jobOffer.priceOfProject;
    std::cin.ignore(); // ignore the newline character
}

void printJobOffer(const JobOffer &jobOffer) {
    std::cout << "Company Name: " << jobOffer.companyName << std::endl;
    std::cout << "Number of Developers: " << jobOffer.numberOfDevelopers << std::endl;
    std::cout << "Number of Vacation Days: " << jobOffer.numberOfVacationDays << std::endl;
    std::cout << "Price of Project: " << jobOffer.priceOfProject << std::endl;
}

void storeJobOffer(const JobOffer &jobOffer, const char *fileName) {
    std::ofstream file(fileName, std::ios::binary | std::ios::app);
    if (file.is_open()) {
        file.write((const char *) &jobOffer, sizeof(JobOffer));
        file.close();
    } else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

void listAllJobOffers(const char *fileName) {
    std::ifstream file(fileName, std::ios::in | std::ios::binary);
    if (file.is_open()) {
        JobOffer jobOffer;
        while (file.read((char *) &jobOffer, sizeof(JobOffer))) {
                printJobOffer(jobOffer);
                std::cout << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
}

void listJobOffersWithGreaterPriceThan(long long projectPrice, const char *fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (file.is_open()) {
        JobOffer jobOffer;
        while (file.read((char *) &jobOffer, sizeof(JobOffer))) {
            if (jobOffer.priceOfProject > projectPrice) {
                printJobOffer(jobOffer);
                std::cout << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
}

void listJobOffersFromCompany(const char *companyName, const char *fileName) {
    std::ifstream file(fileName,std::ios::binary);
    if (file.is_open()) {
        JobOffer jobOffer;
        while (file.read((char *) &jobOffer, sizeof(JobOffer))) {
            if (mystrcmp(jobOffer.companyName, companyName) == 0) {
                printJobOffer(jobOffer);
                std::cout << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
}

void displayMenu() {
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
    char companyName[25];
    long long minProjectPrice = 0;
    while (choice != 0) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1:
                std::cout << "Option 1 selected" << std::endl;
                readJobOffer(currentJobOffer);
                storeJobOffer(currentJobOffer, "jobOffers.bin");
                break;
            case 2:
                std::cout << "Option 2 selected" << std::endl;
                listAllJobOffers("jobOffers.bin");
                break;
            case 3:
                std::cout << "Company name: ";
                std::cin >> minProjectPrice;
                listJobOffersWithGreaterPriceThan(minProjectPrice, "jobOffers.bin");
                break;
            case 4:
                std::cout << "Company name: ";
                std::cin.getline(companyName, 25);
                listJobOffersFromCompany(companyName, "jobOffers.bin");
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

