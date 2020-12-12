#include <string>
using std::string;
#include "Client.h"


int main()
{
    string str = "80.87.197.181";
    Client nd(str.c_str(), 22, 1024);
    return 0;
}