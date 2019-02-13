#pragma once
#include "TextPluginBase.h"

// Lydian
// A music helper

class Lydian : public TextPluginBase
{
public:
	Lydian();
	std::string getDesc();
	std::string execute(std::vector <std::string> args);
};
