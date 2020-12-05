#include "Timer.h"
#include <iostream>
#include <string>
using std::string;

void foo(){
   std::cout << "1" << '\n';
}

int main()
{

    Timer tm;

    tm.add(std::chrono::milliseconds(100), foo);

   string str{""};

   while (str != "h")
   {
       std::cin >> str;
   }
   


    return 0;
}