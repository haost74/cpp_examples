#include <iostream>
#include "src/task/task_system.hpp"

int main(int argc, char* argv[])
{

    // if(__cplusplus == 202002L) std::cout << "C++20\n";
    //     else if(__cplusplus == 201703L) std::cout << "C++17\n";
    //     else if (__cplusplus == 201402L) std::cout << "C++14\n";
    //     else if (__cplusplus == 201103L) std::cout << "C++11\n";
    //     else if (__cplusplus == 199711L) std::cout << "C++98\n";
    //     else std::cout << "pre-standard C++\n";

    pool::task_system ts;
    ts.async_([]{std::cout << "hi" << '\n';});


    return 0;
}