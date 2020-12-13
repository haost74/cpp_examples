#include <string>
using std::string;
#include "Client.h"
#include "Port.cpp"
#include <iostream>


void GetAllPorts()
{
     constexpr auto arrPorts = make_inc_array<65535>();
     std::cout << arrPorts[65534] << '\n';
}

void(*getdata)(const char* dtat);

void GetData(const char* data)
{

   std::cout << data << " ---- " << '\n';
}

int main()
{
    string str = "80.87.197.181";

   getdata = GetData;     
    Client nd(str.c_str(), 33, 1024, getdata);

    string h{""};
    while (h != "h")
    {
       std::cin >> h;
    }
    
    return 0;
}