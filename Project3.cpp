#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

int main()
{
    std::string country;
    std::cout << "Enter the country: ";
    std::cin >> country;
    std::ifstream myfile("countries.txt");

    
    std::string countryName;
    int zone;
    while (myfile >> countryName >> zone)
    {
        if (std::string(country) == countryName) {


            time_t rawtime;
            struct tm* ptm;
            time(&rawtime);
            ptm = gmtime(&rawtime);
            char buffer[50];
            std::cout << "Current time in  " << country << " " << " is " << (ptm->tm_hour + zone) % 24 << ":" << ptm->tm_min << ":" << ptm->tm_sec << std::endl;
            return 0;
        }
    }
    std::cout << "Error: couldnt find the country" << std::endl;
    return 0;

    return 0;
}