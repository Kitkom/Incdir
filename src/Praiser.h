#pragma once
#include "TextPluginBase.h"

// Praiser
// A praiser machine

class Praiser : public TextPluginBase
{
public:
	Praiser(std::string dataFilePath);
	std::string getDesc();
	std::string execute(std::vector <std::string> args);
private:
};
