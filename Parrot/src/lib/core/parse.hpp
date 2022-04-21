
#ifndef ParseHpp
#define ParseHpp

#include "../import.hpp"
#include "../utils/Time.hpp"

parrot__

#define function  0b0
#define variable  0b1

#define undifined 0b0000
#define null      0b0001
#define _char     0b0010
#define I8        0b0011
#define I16       0b0100
#define I32       0b0101
#define I64       0b0110
#define _float    0b0111
#define _double   0b1000

#define sign      0b000001
#define arr       0b0000001
#define complex   0b00000001
#define _const    0b000000001

class ParseTreeNode {
private:
	ParseTreeNode* parent = NULL;
	std::string name;
	uint16_t type;
	void* value;
	std::vector<ParseTreeNode*> childNodes;

public:

	ParseTreeNode(uint8_t varBit, uint8_t type, uint8_t options);
	~ParseTreeNode();

};

class ParseTree {
public:
	ParseTreeNode* root = NULL;
};

__parrot

#endif // !ParseHpp
