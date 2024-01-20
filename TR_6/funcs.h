#pragma once
#include <string>
#include <iostream>

static void error(std::string msg)
{
    std::cerr << msg ;
    exit(1);
}

static bool isAlpha(char symbol)
{
    return (symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z');
}

static bool isDigit(char symbol) {
    return symbol >= '0' && symbol <= '9';
}


