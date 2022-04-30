
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
#define array     0b0000001
#define complex   0b00000001
#define _const    0b000000001
#define global    0b0000000001
#define block     0b00000000001
#define argument  0b000000000001

const char *keyWords[] = {"import", 
						"const", "static", "unsigned", 
						"int8", "int16", "int32", "int64", 
						"char", 
						"float", 
						"double",
						"undifined", "NULL"};

class ParseTreeNode {
private:

	ParseTreeNode* parent = NULL;
	std::string name;
	uint16_t type;
	void* value;
	std::vector<ParseTreeNode*> childNodes;

public:

	ParseTreeNode(std::string name, uint8_t varBit, uint8_t type, uint8_t options, ParseTreeNode* parent = NULL);
	~ParseTreeNode();

};

class ParseTree {
private:

	ParseTreeNode* root = NULL;

public:

	ParseTree();
	~ParseTree();

};

__parrot

#endif // !ParseHpp
