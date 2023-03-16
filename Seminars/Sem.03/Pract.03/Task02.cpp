#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl, std::ofstream, std::ifstream;

const char *FILE_NAME = "jobOffers.dat";
const int max_length = 25;

struct jobOffer {
    char companyName[max_length + 1];
    size_t teamSize;
    size_t vacationDays;
    long long salary;
};

void printJobOffer(const jobOffer &job) {
    cout << "Company name: " << job.companyName << endl;
    cout << "Team size: " << job.teamSize << endl;
    cout << "Vacation days: " << job.vacationDays << endl;
    cout << "Salary: " << job.salary << endl;
    cout << "-----------------------------------" << endl;
}

bool writeJobOffersToFile(const char *&filename, const jobOffer *const &jobs, const int &N) {
    ofstream file(filename, std::ios::binary | std::ios::app);
    if (!file.is_open()) {
        cout << "File could not be opened!" << endl;
        return false;
    }
    for (int i = 0; i < N; ++i) {
        file << jobs[i].companyName << " " << jobs[i].teamSize << " " << jobs[i].vacationDays << " " << jobs[i].salary
             << endl;
    }

    cout << "Job offers successfully written to file!" << endl;

    file.close();
    return true;
}


void readJobsFromTerminal(bool multiple = false) {
    int N = 1;
    if (multiple) {
        cout << "Enter number of jobs: ";
        cin >> N;
    }
    jobOffer *jobs = new jobOffer[N];
    for (int i = 0; i < N; ++i) {
        cout << "Enter company name: ";
        cin >> jobs[i].companyName;
        cout << "Enter team size: ";
        cin >> jobs[i].teamSize;
        cout << "Enter vacation days: ";
        cin >> jobs[i].vacationDays;
        cout << "Enter salary: ";
        cin >> jobs[i].salary;
        cout << endl;
    }

    writeJobOffersToFile(FILE_NAME, jobs, N);
    delete[] jobs;
}

void filterOffers(const char *filename, long long minSalary) {
    ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        cout << "File could not be opened!" << endl;
        return;
    }
    jobOffer job{};
    while (file >> job.companyName >> job.teamSize >> job.vacationDays >> job.salary) {
        if (job.salary >= minSalary) {
            printJobOffer(job);
        }
    }

    file.close();
}

bool existsOffer(const char *filename, const char *companyName) {
    ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        cout << "File could not be opened!" << endl;
        return false;
    }
    jobOffer job{};
    int counter = 0;
    while (file >> job.companyName >> job.teamSize >> job.vacationDays >> job.salary) {
        if (strcmp(job.companyName, companyName) == 0) {
            counter++;
            printJobOffer(job);
        }
    }

    file.close();
    return counter;
}

void printAllOffers(const char *filename) {
    ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        cout << "File could not be opened!" << endl;
        return;
    }
    jobOffer job{};
    while (file >> job.companyName >> job.teamSize >> job.vacationDays >> job.salary) {
        printJobOffer(job);
    }

    file.close();
}

void perfectOffer(const char *filename, int maxCoworkers, int minVacancyDays, int minSalary) {
    ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        cout << "File could not be opened!" << endl;
        return;
    }
    jobOffer job{};
    int counter = 0;
    while (file >> job.companyName >> job.teamSize >> job.vacationDays >> job.salary) {
        if (job.teamSize <= maxCoworkers && job.vacationDays >= minVacancyDays && job.salary >= minSalary) {
            counter++;
            printJobOffer(job);
        }
    }

    if (counter == 0) {
        cout << "No matching offers!" << endl;
    }

    file.close();
}

int main() {
    cout << "Welcome to the job offers database!" << endl;
    cout << "Supported commands:" << endl;
    cout << "   a - add job offer" << endl;
    cout << "   i - print all job offers" << endl;
    cout << "   s <company_name> - search for job offer" << endl;
    cout << "   f <salary> - filter job offers" << endl;
    cout << "   q - quit" << endl;
    char c = ' ';
    while (c != 'q') {
        cout << endl << "Enter command: ";
        cin >> c;
        cout << endl;
        switch (c) {
            case 'a':
                readJobsFromTerminal();
                break;
            case 'i':
                printAllOffers(FILE_NAME);
                break;
            case 's':
                cin.ignore(1, ' ');
                char companyName[max_length + 1];
                cin.getline(companyName, max_length + 1);
                if (!existsOffer(FILE_NAME, companyName)) {
                    cout << "Company doesn't exists!" << endl;
                }
                break;
            case 'f':
                cin.ignore(1, ' ');
                long long minSalary;
                cin >> minSalary;
                filterOffers(FILE_NAME, minSalary);
                break;
            case 'q':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid command!" << endl;
                break;
        }
    }
    return 0;
}
