#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

char ifpath[] = "C:\\Users\\boris\\OneDrive\\Desktop\\inFile.txt";
char ofpath[] = "C:\\Users\\boris\\OneDrive\\Desktop\\outFile.data";

const int MAX_SIZE = 100;

struct JobOffer
{
    char name[26];
    unsigned int coworkers;
    unsigned int paidOfftime;
    unsigned long long payment;
};

JobOffer allOffers[MAX_SIZE];
int offers;

void saveInfo()
{
    ofstream streamWriter(ofpath, ios::binary | ios::app);

    if (streamWriter.is_open())
        streamWriter.write((char*)&allOffers, offers * sizeof(JobOffer));

    streamWriter.close();
}

void readOffersConsole()
{
    int N;
    do {
        cout << "Enter the amount of offers you're getting: ";
        cin >> N;
    } while (N < 0);
    cin.ignore();

    int i;
    for (i = 0; i < N; ++i)
    {
        cin.getline(allOffers[i].name, 26);
        cin >> allOffers[i].coworkers
            >> allOffers[i].paidOfftime
            >> allOffers[i].payment;
        cin.ignore();
    }
    offers = N;
}

void filterOffers(const char* filePath, long long minSalary)
{
    ifstream streamReader(filePath);
    JobOffer tempoffer;

    while (!streamReader.eof())
    {
        streamReader.read((char*)&tempoffer.name       , sizeof(tempoffer.name));
        streamReader.read((char*)&tempoffer.coworkers  , sizeof(tempoffer.coworkers));
        streamReader.read((char*)&tempoffer.paidOfftime, sizeof(tempoffer.paidOfftime));
        streamReader.read((char*)&tempoffer.payment    , sizeof(tempoffer.payment));

        if (tempoffer.payment >= minSalary)
        {
            cout << tempoffer.name        << ' '
                 << tempoffer.coworkers   << ' '
                 << tempoffer.paidOfftime << ' '
                 << tempoffer.payment     << '\n';
        }
    }

    streamReader.close();
}

bool existOffer(const char* filePath, const char* name)
{
    ifstream streamReader(filePath);
    char tempname[sizeof(allOffers[0].name)];
    char tempdump[sizeof(JobOffer) - sizeof(allOffers[0].name)];
    
    while (!streamReader.eof())
    {
        streamReader.read((char*)&tempname, sizeof(allOffers[0].name));
        streamReader.read((char*)&tempdump, sizeof(tempdump));

        if (tempname == name)
            return true;
    }

    streamReader.close();
    return false;
}

void perfectOffer(const char* filePath, int maxCoworkers, int minVacantions, int minSalary, int entries)
{
    ofstream streamWriter(filePath, ios::binary | ios::app);
    ifstream streamReader(ifpath, ios::binary);

    streamReader.read((char*)&allOffers, entries * sizeof(JobOffer));
    
    for (int i = 0; i < entries; ++i)
    {
        if (allOffers[i].coworkers <= maxCoworkers && allOffers[i].paidOfftime >= minVacantions && allOffers[i].payment >= minSalary)
            streamWriter.write((char*)&allOffers[i], sizeof(JobOffer));
    }

    streamReader.close();
    streamWriter.close();
}

int main()
{
    readOffersConsole();
    saveInfo();

    return 0;
}