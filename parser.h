#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

class Parser
{
public:
    virtual bool parse(std::istream& ) = 0;
};


class IntParser : public Parser
{
public:
    bool parse(std::istream& istream) override;
};


class IdParser : public Parser {
public:
    bool parse(std::istream& istream) override;
};


class StrParser : public Parser {
public:
    bool parse(std::istream& istream) override;
};


// class OpParser - для операций типа + - * / и т.д.
class OpParser : public Parser {
public:
    bool parse(std::istream& istream) override;
};

class CombiParser : public Parser {
    struct Item
    {
        Parser* parser;
        Item* next;
    };
    Item* list{};
public:
    CombiParser(int num, ...) {};
    bool parse(std::istream& istr) override;
};

#endif //PARSER_PARSER_H
