#pragma once
#include <string>
#include <fstream>
#include <vector>

enum WhiteListMode {White, Black};

class WhiteList
{
public:
	WhiteList();
	~WhiteList();
	void initialize(std::string filePath);
	bool getPersonAccess(std::string number);
	bool getGroupAccess(std::string number);
	bool getPersonAccess(int64_t number);
	bool getGroupAccess(int64_t number);
	void logAllData();
private:
	std::vector<std::string> personList;
	std::vector<std::string> groupList;
	WhiteListMode mode;
	std::string listFilePath;
	const static std::string personTag;
	const static std::string groupTag;
};

