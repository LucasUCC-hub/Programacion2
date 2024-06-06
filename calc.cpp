#include <iostream>
#include <string>
#include <cmath>

enum class TokenType {
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    POW,
    FUNCTION,
    LPAREN,
    RPAREN,
    END,
    INVALID
};

struct Token {
    TokenType type;
    std::string value;
    
    Token(TokenType t, const std::string& v = "") : type(t), value(v) {}
};

// Divide el input en tokens y los clasifica
class Lexer {
public:
    Lexer(const std::string& input) : input(input), position(0) {}
    
    Token getNextToken() {
        while (position < input.size()) {
            char currentChar = input[position];

            if (std::isdigit(currentChar)) {
                return parseNumber();
            } else if (std::isalpha(currentChar)) {
                return parseFunction();
            } else if (isSymbol(currentChar)) {
                ++position;
                return parseSymbol(currentChar);
            } else if (std::isspace(currentChar)) {
                skipWhitespace();
            } else {
                // Error: Token no reconocido
                throw std::runtime_error("Caracter no reconocido.");
            }
        }

        return Token(TokenType::END);
    }

private:
    std::string input;
    size_t position;
    
    bool isSymbol(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')';
    }

    Token parseSymbol(char symbol) {
        TokenType type;
        switch(symbol) {
            case '+': type = TokenType::PLUS; break;
            case '-': type = TokenType::MINUS; break;
            case '*': type = TokenType::MULTIPLY; break;
            case '/': type = TokenType::DIVIDE; break;
            case '^': type = TokenType::POW; break;
            case '(': type = TokenType::LPAREN; break;
            case ')': type = TokenType::RPAREN; break;
            default: type = TokenType::INVALID; break;
        }
        return Token(type);
    }
    
    void skipWhitespace() {
        while (position < input.size() && std::isspace(input[position])) {
            ++position;
        }
    }

    Token parseNumber() {
        std::string value;
        while (position < input.size() && (std::isdigit(input[position]) || input[position] == '.')) {
            value += input[position];
            ++position;
        }
        return Token(TokenType::NUMBER, value);
    }

    Token parseFunction() {
        std::string value;
        while (position < input.size() && std::isalpha(input[position])) {
            value += input[position];
            ++position;
        }
        return Token(TokenType::FUNCTION, value);
    }
};

// Toma un lexer, lo recorre linealmente y sigue las reglas jerarquicas de las matematicas

class Parser {
public:
    Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.getNextToken()) {}

    double parseExpression() {
        double result = parseTerm();
        
        while (currentToken.type == TokenType::PLUS || currentToken.type == TokenType::MINUS) {
            Token op = currentToken;
            if (op.type == TokenType::PLUS) {
                eat(TokenType::PLUS);
                result += parseTerm();
            } else if (op.type == TokenType::MINUS) {
                eat(TokenType::MINUS);
                result -= parseTerm();
            }
        }

        return result;
    }

private:
    Lexer& lexer;
    Token currentToken;

    double parseTerm() {
        double result = parseFactor();
        
        // Jerarquia secundaria 2
        while (currentToken.type == TokenType::MULTIPLY || currentToken.type == TokenType::DIVIDE ||
               currentToken.type == TokenType::POW) {
            Token op = currentToken;
            if (op.type == TokenType::MULTIPLY) {
                eat(TokenType::MULTIPLY);
                result *= parseFactor();
            } else if (op.type == TokenType::DIVIDE) {
                eat(TokenType::DIVIDE);
                result /= parseFactor();
            } else if (op.type == TokenType::POW) {
                eat(TokenType::POW);
                result = std::pow(result, parseFactor());
            }
        }

        return result;
    }

    double parseFactor() {
        Token token = currentToken;
        double result;
        
        // Jerarquia primaria 1
        if (token.type == TokenType::NUMBER) {
            eat(TokenType::NUMBER);
            result = std::stod(token.value);
        } else if (token.type == TokenType::FUNCTION) {
            eat(TokenType::FUNCTION);
            eat(TokenType::LPAREN);
            if (token.value == "sin") result = std::sin(parseExpression());
            else if (token.value == "cos") result = std::cos(parseExpression());
            else if (token.value == "tan") result = std::tan(parseExpression());
            else if (token.value == "sqrt") result = std::sqrt(parseExpression());
            eat(TokenType::RPAREN);
        } else if (token.type == TokenType::LPAREN) {
            eat(TokenType::LPAREN);
            result = parseExpression();
            eat(TokenType::RPAREN);
        } else if (token.type == TokenType::MINUS) {
            eat(TokenType::MINUS);
            result = -parseFactor();
        } else if (token.type == TokenType::PLUS) {
            eat(TokenType::PLUS);
            result = parseFactor();
        } else {
            // Error: Token no esperado
            throw std::runtime_error("Token no esperado.");
        }

        return result;
    }

    void eat(TokenType expectedToken) {
        if (currentToken.type == expectedToken) {
            currentToken = lexer.getNextToken();
        } else {
            // Error: Token inesperado
            throw std::runtime_error("Token inesperado.");
        }
    }
};


int main() {
    std::cout << "CALCULADORA MATEMATICA PRO" << std::endl;
    
    while (true) {
        std::string input;
        std::cout << "Expresion: ";
        std::getline(std::cin, input);
        
        try {
            Lexer lexer(input);
            Parser parser(lexer);
            double result = parser.parseExpression();
            std::cout  << " = " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    

    return 0;
}
