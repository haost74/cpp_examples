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

int main()
{
    string str = "80.87.197.181";
    Client nd(str.c_str(), 22, 1024);
    return 0;
}