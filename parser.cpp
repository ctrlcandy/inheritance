#include <iostream>
#include <cctype>

#include "parser.h"


bool IntParser::parse (std::istream &istream) {
    std::string buffer;
    istream >> buffer;

    for (char &it : buffer) {
        if (!isdigit(static_cast<unsigned char>(it)))
            return false;
    }
    return true;
}


bool IdParser::parse (std::istream &istream) {
    std::string buffer;
    istream >> buffer;

    if(!isalpha(static_cast<unsigned char>(*buffer.begin())))
        return false;

    for (std::string::iterator it=++buffer.begin(); it!=buffer.end(); it++) {
        if (!isalnum(static_cast<unsigned char>(*it)))
            return false;
    }

    return true;
}


bool StrParser::parse (std::istream &istream) {
    std::string buffer;
    istream >> buffer;

    // Не имею ни малейшего понятия,
    // какие критерии у того, является ли лексема строкой

    return true;
}


bool OpParser::parse (std::istream &istream) {
    std::string buffer;
    istream >> buffer;

    for (char & it : buffer) {
        if (it != '+' || it != '-' || it != '*' || it != '/')
            return false;
    }
    return true;
}

bool CombiParser::parse(std::istream &istream) {
    std::string buffer;
    istream >> buffer;

    /*for (std::string::iterator it=buffer.begin(); it!=buffer.end(); it++) {
        if (!it->parse(istream)) return false; */

    return true;
}


