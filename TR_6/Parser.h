#pragma once
#include <map>
#include <string>
#include <iostream>
#include <variant>
#include <regex>
#include <vector>

using Value = std::variant<int, bool>;

// терминалы
enum Token
{
    INT = 0,
    BOOL,
    VAR,
    NUMBER,
    TR,  // True
    FLS, // False
    PLUS, // +
    COMMA, // ,
    EQUAL, // =
    SEM, // ;
    ERROR = -1
};

class Parser {
public:
    
    void parse();

private:

    void scan();
    void decl();
    void assign();
    void init();
    void value();
    int calc();

private:

    std::string input;                      // храним введеную строку
    std::string tmpName;                    // храним имя последней переменной
    int token = 0;                           
    Token type;                             // храним тип переменной(ых) последенего объявления
    int pos = 0;                       
    bool isNewInit = true;                  // флаг проверки нового объявления
    int calcValue = 0;                      // временно храним значение последней переменной
    std::variant<int, bool> tmpValue = 0;
    std::map<std::string, Value> variables; // храним имя переменной - значение

};

