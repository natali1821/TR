#pragma once
#include <map>
#include <string>
#include <iostream>
#include <variant>
#include <regex>
#include <vector>

using Value = std::variant<int, bool>;

// ���������
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

    std::string input;                      // ������ �������� ������
    std::string tmpName;                    // ������ ��� ��������� ����������
    int token = 0;                           
    Token type;                             // ������ ��� ����������(��) ����������� ����������
    int pos = 0;                       
    bool isNewInit = true;                  // ���� �������� ������ ����������
    int calcValue = 0;                      // �������� ������ �������� ��������� ����������
    std::variant<int, bool> tmpValue = 0;
    std::map<std::string, Value> variables; // ������ ��� ���������� - ��������

};

