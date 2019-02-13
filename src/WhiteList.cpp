#include "WhiteList.h"
#include "cqsdk\cqsdk.h"

using namespace std;

const string WhiteList::personTag = "<Persons>";
const string WhiteList::groupTag = "<Groups>";

WhiteList::WhiteList() : mode(WhiteListMode::White) {};
WhiteList::~WhiteList() {};


void WhiteList::initialize(string filePath)
{
	listFilePath = filePath;
	ifstream infile(listFilePath, ios::in);
	string buffer;
	vector<string> emptyList;
	vector<string>* currentList = &emptyList;
	while (!infile.eof())
	{
		infile >> buffer;
		if (buffer == personTag)
		{
			currentList = &personList;
			continue;
		}
		if (buffer == groupTag)
		{
			currentList = &groupList;
			continue;
		}
		currentList->push_back(buffer);
	}
}

bool WhiteList::getGroupAccess(string number)
{
	for (string group : groupList)
		if (group == number)
			return true;
	return false;
}

bool WhiteList::getPersonAccess(string number)
{
	cq::logging::debug("WhiteListGet", number);
	for (string person : personList)
		if (person == number)
			return true;
	return false;
}

bool WhiteList::getPersonAccess(int64_t number)
{
	return getPersonAccess(to_string(number));
}

bool WhiteList::getGroupAccess(int64_t number)
{
	return getGroupAccess(to_string(number));
}

void WhiteList::logAllData()
{
	cq::logging::info("WhiteList", "WhiteList: ");
	for (string person : personList)
		cq::logging::debug("WLPerson", person);
	for (string group : groupList)
		cq::logging::debug("WLGroup", group);

}
