
#include "./parse.hpp"

Parrot::ParseTreeNode::ParseTreeNode(std::string name, uint8_t varBit, uint8_t type, uint8_t options, Parrot::ParseTreeNode* parent){
	this->childNodes = std::vector<Parrot::ParseTreeNode*>();
	this->name = name;
	this->parent = parent;
	this->type = varBit | (type << 1) | (options << 4);
	this->value = NULL;
}

Parrot::ParseTreeNode::~ParseTreeNode(){
	this->childNodes.clear();
	free(this);
}
