#include <iostream>
#include <cctype>

using namespace std;


class Parser
{
	public:
		virtual bool parse( istream& ) = 0;
};


class IntNumParser : public Parser
{
	public:
		bool parse( istream& istr)
		{
			char buffer[30]; istr >> buffer;

			for(const char* it = buffer; *it; ++it)
				if(!isdigit(*it)) return false;

			return true;
		}
};


class IdParser : public Parser
{
	public:
	bool parse(istream& istr)
	{
			char buffer[30]; istr >> buffer;
			const char * it = buffer;

			if(!isalpha(*it++)) return false;

			for(;*it;++it)
				if(!isalnum(*it)) return false;

			return true;
	}
};


//class StrParser....
// class OpParser - для операций типа + - * / и т.д.
class CombiParser : public Parser
{
	struct Item
	{
		Parser* parser;
		Item* next;
	};
	Item* list;
	public:
		CombiParser(int num, ...);
		bool parse( istream& istr)
		{
			for(Item* it = list; *it; it = it->next)
				if(!it->parse(istr)) return false;

			return true;
		}
};


int main()
{
	NumParser num1;
	NumParser num2;
	StrParser name;
	OpParser  op1;
	OpParser  op2;
	// Шаблон: name num op num op 
	CombiParser combi1(5, &name, &num1, &op1, &num2, &op2); 

	cout (combi1.parse(cin) ? "Template match" : "Template not match") << endl;

	return 0;
}




