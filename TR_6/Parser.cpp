#include "Parser.h"
#include "funcs.h"

void Parser::scan()
{
    std::regex variableRegex("\\b([a-zA-Z_]\\w*)\\b");
    std::regex numberRegex("\\b\\d+\\b");

    if (token != ERROR)
    {
        if (input.substr(pos, 3) == "int" && isNewInit)
        {
            pos += 3;
            token = INT;
            isNewInit = false;
        }
        else if (input.substr(pos, 4) == "bool" && isNewInit)
        {
            pos += 4;
            token = BOOL;
            isNewInit = false;
        }
        else if (input[pos] == ';')
        {
            ++pos;
            token = SEM;
            isNewInit = true;
        }
        else if (input[pos] == ',')
        {
            ++pos;
            token = COMMA;
        }
        else if (input[pos] == '=')
        {
            ++pos;
            token = EQUAL;
        }
        else if (input[pos] == '+')
        {
            ++pos;
            token = PLUS;
        }
        else if (input.substr(pos, 4) == "True") {
            pos += 4;
            token = TR;
        }
        else if (input.substr(pos, 5) == "False") {
            pos += 5;
            token = FLS;
        }
        else if (isAlpha(input[pos]))
        {
            std::sregex_iterator it(input.begin() + pos, input.end(), variableRegex);
            std::smatch match = *it;
            pos += match.length();
            tmpName = match.str();

            token = VAR;
        }
        else if (isDigit(input[pos]))
        {
            std::sregex_iterator it(input.begin() + pos, input.end(), numberRegex);
            std::smatch match = *it;
            pos += match.length();
            tmpValue = std::atoi(match.str().c_str());

            token = NUMBER;
        }
        else
        {
            token = ERROR;
        }
    }
    else
    {
        error("Unknown input");
        token = ERROR;
    }

}

void Parser::decl() {
    if (token == INT) {
        type = INT;
        scan();
        init();
    }
    else if (token == BOOL) {
        type = BOOL;
        scan();
        init();
    }
    else if (token == SEM) {
        scan();
    }
    else if (token == COMMA || token == NUMBER || token == VAR) {
        init();
    }
    else {
        error("Uknown type: use 'int' or 'bool'");
        token = ERROR;
    }
}

void Parser::assign() {

    if (token == VAR) {
        type == INT ? variables.insert(std::make_pair(tmpName, 0)) : variables.insert(std::make_pair(tmpName, false)); // нулевая инициализация
        scan();
        assign();
    }
    else if (token == EQUAL) {
        scan(); 
        value();
        variables[tmpName] = tmpValue;
        calcValue = 0;
        scan();
    }
    else if (token == COMMA) { 
        init();
    }
    else if (token == NUMBER) {
        value();
    }
    else if (token == SEM) {
        decl();
    }
    else {
        std::cout << token << std::endl;
        error("Assign error");
        token = ERROR;
    }
}

void Parser::init() {

    if (token == VAR || token == NUMBER) {
        assign();
    }
    else if (token == COMMA) {
        while (token == COMMA) {
            scan();
            assign();
        }    
    }
    else {
        error("Init error");
        token = ERROR;
    }

}

void Parser::value() {

    if (token == TR && type == BOOL) {
        tmpValue = true;
        scan();
    }
    else if (token == FLS && type == BOOL) {
        tmpValue = false;
        scan();
    }
    else if (token == NUMBER) {
        tmpValue = calc();
    }
    else {
        error("Value error");
        token = ERROR;
    }
}

int Parser::calc() {

    if (token == NUMBER) {
        try {
            calcValue += std::get<int>(tmpValue);
        }
        catch (const std::bad_variant_access&) {
            error("Calc error: you should summarize integers");
        }
        scan();
        while (token == PLUS) {
            scan();
            calc();
        }
    }
    else {
        error("Calc error");
        token = ERROR;
    }

    return calcValue;
}

void Parser::parse()
{
    // "чистка" строки
    std::getline(std::cin, input);
    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
    input.erase(std::remove_if(input.begin(), input.end(), [](char c) {
        return c == '\r' || c == '\t' || c == '\n';
        }), input.end());

    // разбор строки
    scan();
    while (token != ERROR) {
        decl();
    }

    // вывод переменных
    for (const auto& var: variables) {
        std::visit([&var](auto&& value) {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T, int>)
                std::cout << "int" << " " << var.first << " = " << value << std::endl;
            if constexpr (std::is_same_v<T, bool>)
                std::cout << "bool" << " " << var.first << " = " << std::boolalpha << value << std::endl;

            }, var.second);
    }
}
