#include <Lydian.h>
#include <cqsdk\cqsdk.h>
#include <stdexcept>
#include <sstream>

using namespace std;

Praiser::Praiser(string dataFilePath)
{
  
}

string Praiser::getDesc()
{
  string desc = "    praise <style> <name> \n" 
    + "        <style>=[" + allKey;
  for (string key : sentencesMap)
  {
    desc += key + " ";
  }
  return desc + ']';
}

string Praiser::execute(vector<string> args)
{
  srand(time(0));

  if (args.size() < 2)
    return getDesc();
  if (args[0] not in sentencesMap.keys())
    return "Exception: style not found \n" + getDesc();

  string style = args[0];
  string name = "";
  for (int i = 1; i < args.size(); ++i)
    name += args[i];

  
}

