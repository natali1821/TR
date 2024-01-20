// main.cpp
#include "src/gramLexer.h"
#include "src/gramParser.h"
#include "src/gramBaseVisitor.h"
#include "src/gramBaseListener.h"
#include "antlr4-runtime.h"

#include <iostream>
#include <variant>
#include <string>
#include <unordered_map>

std::map<std::string, std::variant<int, bool>> variables;

using namespace antlr4;

class MyListener : public gramBaseListener {
public:

    enum TYPE {
        INT,
        BOOL
    };

    TYPE type;
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
            type = INT;
        }
        else if (ctx->BOOL() != nullptr) {
            type = BOOL;
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
            if (type == INT) {
                variables[tmpName] = 0;
            }
            else if (type == BOOL) {
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
            calcValue += countValue;
            tmpValue = calcValue;
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
    
    // Пример использования Listener
    tree::ParseTreeWalker::DEFAULT.walk((antlr4::tree::ParseTreeListener*)&listener, tree);

    for (const auto& var: variables) {
        std::visit([&var](auto&& value) {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T, int>)
                std::cout << "int" << " " << var.first << " = " << value << std::endl;
            if constexpr (std::is_same_v<T, bool>)
                std::cout << "bool" << " " << var.first << " = " << std::boolalpha << value << std::endl;

            }, var.second);
    }

    return 0;
}