#include <iostream>
#include <fstream>

const char OFFERS_FILE[] = "offers.dat";
const int NAME_MAX_LENGTH = 25;

struct JobOffer
{
    char companyName[NAME_MAX_LENGTH + 1];
    unsigned int programmersCount;
    unsigned int daysLeave;
    long long projectPayment;
};

struct OffersList
{
    JobOffer offers[125];
    unsigned int count = 0;
};

void printOffer(const JobOffer& offer)
{
    std::cout << "Company name: " << offer.companyName << "\n"
        << "You are going to work with " << offer.programmersCount << " programmer(s)\n"
        << "Paid leave: " << offer.daysLeave << " days\n"
        << "You are going to recieve " << offer.projectPayment << " euros for this project\n---------------------------------\n";
}

void offersToFile(const char filePath[], int countOfOffers)
{
    std::ofstream file(filePath, std::ios::binary | std::ios::app);
    if (!file.is_open())
    {
        std::cout << "Could not open file " << filePath << std::endl;
        return;
    }

    JobOffer offer;
    std::cout << "Input your " << countOfOffers << " offer(s) one property per line:\n";
    for (size_t i = 0; i < countOfOffers; i++)
    {
        std::cin.ignore();

        std::cout << "Name:\n";
        std::cin.getline(offer.companyName, NAME_MAX_LENGTH);
        size_t nameLen = strlen(offer.companyName);
        file.write((const char*)&nameLen, sizeof(size_t));
        file.write(offer.companyName, nameLen);

        std::cout << "Programmers count:\n";
        std::cin >> offer.programmersCount;
        file.write((const char*)&offer.programmersCount, sizeof(int));

        std::cout << "Days of paid leave:\n";
        std::cin >> offer.daysLeave;
        file.write((const char*)&offer.daysLeave, sizeof(int));

        std::cout << "Payment for this project:\n";
        std::cin >> offer.projectPayment;
        file.write((const char*)&offer.projectPayment, sizeof(long long));
    }

    file.close();
}

void loadOffersFromFile(const char filePath[], OffersList& offersList)
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "Could not open file " << filePath << std::endl;
        return;
    }

    if (offersList.count > 0)
    {
        offersList.count = 0;
    }

    JobOffer offer;
    int i = 1;
    while (!file.eof())
    {
        switch (i)
        {
        case 1: 
            size_t nameLen;
            file.read((char*)&nameLen, sizeof(nameLen));
            file.read(offer.companyName, nameLen);
            offer.companyName[nameLen] = '\0';
            i++;
            break;
        case 2:
            file.read((char*)&offer.programmersCount, sizeof(int));
            i++;
            break;
        case 3:
            file.read((char*)&offer.daysLeave, sizeof(int));
            i++;
            break;
        case 4:
            file.read((char*)&offer.projectPayment, sizeof(long long));
            i++;
            break;
        default:
            offersList.offers[offersList.count++] = offer;
            i = 1;
            break;
        }
    }
    file.close();
}

void filterOffers(const char* filePath, long long minSalary)
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "Could not open file " << filePath << std::endl;
        return;
    }

    OffersList list;
    loadOffersFromFile(filePath, list);

    for (size_t i = 0; i < list.count; i++)
    {
        if (list.offers[i].projectPayment >= minSalary)
        {
            printOffer(list.offers[i]);
        }
    }
    file.close();
}

bool existOffer(const char* filePath, const char* name)
{
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "Could not open file " << filePath << std::endl;
        return false;
    }

    OffersList list;
    loadOffersFromFile(filePath, list);
    
    for (size_t i = 0; i < list.count; i++)
    {
        if (strcmp(list.offers[i].companyName, name) == 0)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void removeFirstTwo(char arr[20])
{
    int j = 0;
    for (size_t i = 2; arr[i] != '\0'; i++)
    {
        arr[j++] = arr[i];
    }
    arr[j] = '\0';
}

int main()
{
    
    char action[20];
    bool quit = false;
    OffersList list;
    int minSalary = 0;
    do
    {
        std::cout << "Choose action:\na (Add offers)\ni (Show all offers)\ns <name of company> (Check if a company exists)\nf <minimum payment> (Shows all offers that have higher payment than this number)\nq (Quit)\n";
        std::cin.getline(action, 19);
        if (action[1] == ' ' || action[1] == '\0')
        {
            switch (action[0])
            {
            case 'a':
                int countOfOffers;
                std::cout << "Input count of offers you would like to add: ";
                std::cin >> countOfOffers;
                offersToFile(OFFERS_FILE, countOfOffers);
                std::cin.ignore();
                std::cout << "\n";
                break;
            case'i':
                loadOffersFromFile(OFFERS_FILE, list);
                for (size_t i = 0; i < list.count; i++)
                {
                    printOffer(list.offers[i]);
                }
                std::cout << "\n";
                break;
            case's':
                removeFirstTwo(action);
                if (existOffer(OFFERS_FILE, action))
                {
                    std::cout << "There is an offer from this company :)\n\n";
                    break;
                }
                std::cout << "There aren't any offers from this company :(\n\n";
                break;
            case'f'://debug
                removeFirstTwo(action);
                for (size_t i = 0; action[i] != '\0'; i++)
                {
                    (minSalary *= 10) += action[i] - 48;
                }
                filterOffers(OFFERS_FILE, minSalary);
                minSalary = 0;
                std::cout << "\n";
                break;
            case 'q':
                quit = true;
                break;
            default:
                std::cout << "Wrong command\n\n";
                break;
            }
        }
        else
        {
            std::cout << "Wrong command\n\n";
        }
        
    } while (!quit);
    
    return 0;
}