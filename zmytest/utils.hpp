#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

void print_section(const std::string& msg)
{
    std::cout << " --- " << msg << " --- \n";
}

void print_subsection(const std::string& msg)
{
    std::cout << " # " << msg << " # \n";
}

#endif
