#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

const int MAX_SIZE = 25;
const int MAX_JOBADS = 1024;
const char fileName[] = "file.dat";

enum Command {
    add, checkSAL, checkCOMP, quit
};

struct JobAd {
    char companyName[MAX_SIZE];
    int teamSize;
    int paidHolidayDays;
    long long projectCompletionBonus;
};

void InitJobAd(JobAd& jobAd)
{
    cin.ignore();
    cout << "Enter company name: ";
    cin.getline(jobAd.companyName, MAX_SIZE);
    cout << "Enter team size: ";
    cin >> jobAd.teamSize;
    cout << "Enter paid holiday days: ";
    cin >> jobAd.paidHolidayDays;
    cout << "Enter project completion bonus: ";
    cin >> jobAd.projectCompletionBonus;
}

void WriteJobAdToFile(const char* fileName, JobAd& jobAd, const int& N)
{
    ofstream file(fileName, std::ios::binary | std::ios::app);
    if (!file.is_open())
    {
        cout << "Error";
        return;
    }

    file.write(jobAd.companyName, sizeof(jobAd.companyName));
    file.write((const char*)&jobAd.teamSize, sizeof(int));
    file.write((const char*)&jobAd.paidHolidayDays, sizeof(int));
    file.write((const char*)&jobAd.projectCompletionBonus, sizeof(long long));
    file.close();
}

void CreateJobsOffers(const char* fileName, JobAd& jobAd, const int& n)
{
    JobAd* jobs = new JobAd[n];

    for (size_t i = 0; i < n; i++)
    {
        InitJobAd(jobAd);
        jobs[i] = jobAd;
        WriteJobAdToFile(fileName, jobs[i], n);
    }

    delete[] jobs;
}

void PrintJobOffer(JobAd& jobAd)
{
    cout << "Company name: " << jobAd.companyName << endl;
    cout << "Team size: " << jobAd.teamSize << endl;
    cout << "Paid holiday days: " << jobAd.paidHolidayDays << endl;
    cout << "Project completion bonus: " << jobAd.projectCompletionBonus << endl;
    cout << endl;
}

void FilterOffers(const char* filename, long long minSalary, JobAd& jobAd) {
    ifstream file(filename, std::ios::in | std::ios::binary);

    if (!file.is_open()) {
        cout << "Error" << endl;
        return;
    }

    while (file.read((char*)&jobAd, sizeof(JobAd))) {
        if (jobAd.projectCompletionBonus >= minSalary) {
            PrintJobOffer(jobAd);
        }
    }

    file.close();
}

bool existOffer(const char* filePath, const char* name, JobAd& jobAd)
{
    ifstream file(filePath, std::ios::in | std::ios::binary);

    if (!file.is_open())
    {
        cout << "Error";
        return false;
    }

    while (file.read(jobAd.companyName, sizeof(char) * MAX_SIZE) &&
        file.read((char*)&jobAd.teamSize, sizeof(int)) &&
        file.read((char*)&jobAd.paidHolidayDays, sizeof(int)) &&
        file.read((char*)&jobAd.projectCompletionBonus, sizeof(long long))) {
        if (strcmp(jobAd.companyName, name) == 0)
            return true;
    }
    return false;

    file.close();
}

int main()
{
    JobAd jobAd;
    bool running = true;

    while (running) {
        cout << "Enter command(0 - to add offers" << endl;
        cout << "              1 - to check offers above min salary " << endl;
        cout << "              2 - to check if a company has sent an offer)" << endl;
        cout << "              3 - to exit" << endl;

        int command;
        cin >> command;
        command = (Command)command;

        switch (command) {
        case Command::add:
            cout << "Enter the number of job ads:";
            int n;
            cin >> n;
            CreateJobsOffers(fileName, jobAd, n);
            break;

        case Command::checkSAL:
            cout << "Enter min salary: ";
            int minSalary;
            cin >> minSalary;
            FilterOffers(fileName, minSalary, jobAd);
            break;

        case Command::checkCOMP:
            cout << "Enter the company name that you want to check: ";
            char companyName[MAX_SIZE];
            cin.ignore();
            cin.getline(companyName, MAX_SIZE);
            if (existOffer(fileName, companyName, jobAd))
                cout << "The company is sent a offer.";
            else
                cout << "The company is not sent a offer.";
            break;

        case Command::quit:
            running = false;
            break;

        default:
            cout << "Invalid command!" << endl;
            break;
        }
    }

}

