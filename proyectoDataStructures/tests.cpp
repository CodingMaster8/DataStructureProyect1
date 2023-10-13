#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

std::string createIP(std::string ip) {
    std::string section;
    std::vector<std::string> ipSplit;
    std::istringstream iss(ip);

    while (std::getline(iss, section, ':')) {
            if (!section.empty())
            ipSplit.push_back(section);
        }
    std::string ipp = ipSplit[0];
    return ipp;
}

long long ipNum(std::string ip) {
    std::string section;
    std::vector<std::string> ipSplit;
    std::istringstream iss(ip);

    while (std::getline(iss, section, '.')) {
            if (!section.empty())
            ipSplit.push_back(section);
        }

    int octal1 = std::stoi(ipSplit[0]);
    int octal2 = std::stoi(ipSplit[1]);
    int octal3 = std::stoi(ipSplit[2]);
    int octal4 = std::stoi(ipSplit[3]);


    int oct1 = octal1 * pow(10,4);

    long long ipNum = long(octal1 * pow(10,9)) + long(octal2*pow(10,6)) + long(octal3*pow(10,3)) + int(octal4*pow(10,1));
    cout << ipNum << endl;
    return ipNum;
    
}

int main(){
    std::string ip = "423.2.230.77:6166";
    std::string ip2 = "424.2.230.77:6166";
    std::string ip3 = "423.11.130.17:6166";
    ipNum(createIP(ip));
    ipNum(createIP(ip2));
    ipNum(createIP(ip3));
}