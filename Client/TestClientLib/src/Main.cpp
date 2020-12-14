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

void(*getdata)(const char* dtat, string str);

int _count;

void GetData(const char* data, string str)
{

   std::cout << data << " ---- " <<  str << '\n';
}

int main()
{
    string str = "80.87.197.181";
    str = "176.99.162.211";

    constexpr auto allPorts = make_inc_array<65535>();
   getdata = GetData;     

    for(int i = 0; i < 65535; ++i)
    {

      _count = i;
      //std::cout << i << '\n';
        Client nd(str.c_str(), allPorts[i], 1024, getdata);
    }


    string h{""};
    while (h != "h")
    {
       std::cin >> h;
    }
    
    return 0;
}