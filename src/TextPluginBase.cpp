#include "TextPluginBase.h"
using namespace std;

bool TextPluginBase::checkCommand(string cmd)
{
	return (cmd.find(header, 0) == 0);
}