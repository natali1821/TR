// main.cpp
#include "src/gramLexer.h"
#include "src/gramParser.h"
#include "src/gramBaseVisitor.h"
#include "src/gramBaseListener.h"
#include "antlr4-runtime.h"

#include <iostream>
#include <variant>
#include <string>
#include <map>

using namespace antlr4;

class MyListener : public gramBaseListener {
public:

    std::map<std::string, std::variant<int, bool>> variables;

    int type;
    int calcValue;
    int countValue;
    std::variant<int, bool> tmpValue;
    std::string tmpName;

    void enterValue(gramParser::ValueContext *ctx)  {
        calcValue = 0;
        countValue = 0;
    }

    void enterType(gramParser::TypeContext *ctx) {
        if (ctx->INT() != nullptr) {
            type = gramParser::INT;
        }
        else if (ctx->BOOL() != nullptr) {
            type = gramParser::BOOL;
        }
    }

    void enterCalc(gramParser::CalcContext *ctx) {
        countValue = std::stoi(ctx->NUMBER()->getText());
        if (ctx->PLUS() != nullptr) {
            calcValue += countValue;
        }
    }

    void enterAssign(gramParser::AssignContext *ctx) {

        if (ctx->VAR() != nullptr) {
            tmpName = ctx->VAR()->getText();
            if (type == gramParser::INT) {
                variables[tmpName] = 0;
            }
            else if (type == gramParser::BOOL) {
                variables[tmpName] = false;
            }
            
        }
    }

    void exitAssign(gramParser::AssignContext *ctx) {
        if (ctx->value() != nullptr) {
            variables[tmpName] = tmpValue;
        }
    }

    void exitValue(gramParser::ValueContext *ctx) {
        
        if (ctx->calc() != nullptr) {
            if (type == gramParser::INT) {
                calcValue += countValue;
                tmpValue = calcValue;
            }
            else {
                throw std::string{"Boolean variables must be initialized with a boolean value"};
            }     
        } else if (type == gramParser::INT) {
            throw std::string{"Integer variables must be initialized with a number"}; 
        }
        
         if (ctx->TRUE() != nullptr) {
            tmpValue = true;
        } 

        if (ctx->FALSE() != nullptr) {
            tmpValue = false;
        }
       
    }
};


int main() {

    std::string in;
    std::getline(std::cin, in);
    ANTLRInputStream input(in);
    gramLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    gramParser parser(&tokens);

    tree::ParseTree* tree = parser.decl();

    MyListener listener;

    try {
    
    // Пример использования Listener
        tree::ParseTreeWalker::DEFAULT.walk((antlr4::tree::ParseTreeListener*)&listener, tree);

        for (const auto& var: listener.variables) {
            std::visit([&var](auto&& value) {
                using T = std::decay_t<decltype(value)>;
                if constexpr (std::is_same_v<T, int>)
                    std::cout << "int" << " " << var.first << " = " << value << std::endl;
                if constexpr (std::is_same_v<T, bool>)
                    std::cout << "bool" << " " << var.first << " = " << std::boolalpha << value << std::endl;
                }, var.second);
        }
    }
    catch (std::string error_message)
    {
        std::cout << error_message << std::endl;
        return -1;
    }

    return 0;
}