#pragma once

#include <iostream>
#include <vector>

class TextPluginBase
{
public:
	virtual std::string getDesc() = 0;
	std::string header;
	int expectedArgCount;
	virtual bool checkCommand(std::string cmd);
	virtual std::string execute(std::vector<std::string>  args) = 0;
};
