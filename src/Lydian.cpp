#include <Lydian.h>
#include <cqsdk\cqsdk.h>
#include <stdexcept>
#include <sstream>

using namespace std;

Lydian::Lydian()
{
	expectedArgCount = 2;
	header = "motif";
};

string Lydian::getDesc()
{
	return ((string)"    motif <style> <length> <repeat=1> (create several certain size motives)\n" 
		+ "        <style>=[c, u] (c=classic, u=unrestricted)\n"
		+ "        <length>=[1..20] (0 for random in [3..8])");
}

string Lydian::execute(vector<string> args)
{
	srand(time(0));

	// input check here
	int size = 0;
	int repeat = 1;
	try {
		size = stoi(args[1]);
		if (args.size() == 3)
		{
			repeat = stoi(args[2]);
		}
		if (size < 0 || size > 20)
			throw (string)"size out of range";
		if (repeat < 0)
			throw (string)"invalid repeat time";
	}
	catch (string err)
	{
		return (string)"Exception: " + err + "\n" + getDesc();
	}
    catch (invalid_argument err)
    {
		return (string)"Exception: invalid number\n" + getDesc();
    }

	int ssize = size;
	ostringstream result;
	for (int repeatee = 0; repeatee < repeat; ++repeatee)
	{
		if (ssize == 0)
			size = rand() % 6 + 3;

		if (args[0] == "c")
		{
			int base = rand() % 6 + 1;
			result << base;
			int dir = 1;
			bool leap = false;
			int step = -1;
			for (int i = 1; i < size; ++i)
			{
				if (leap)
				{
					dir = -dir;
					step = rand() % 2 + 1;
					leap = false;
				}
				else
				{
					dir = rand() % 2 == 0 ? -1 : 1;
					step = rand() % 9;
					step = step % 6;
					if (step > 2)
						leap = true;
				}
				cout << step << ' ' << dir << endl;
				base += step * dir;
				int temp = base;
				result << " ";
				while (temp <= 0)
				{
					result << "-";
					temp += 7;
				}
				while (temp > 7)
				{
					result << "+";
					temp -= 7;
				}
				result << temp;
			}
		}
		else if (args[0] == "u")
		{
			string note[] = { "C", "#C", "D", "#D", "E", "F", "#F", "G", "#G", "A", "#A", "B" };
			for (int i = 0; i < size; ++i)
			{
				result << note[rand() % 12] << " ";
			}
		}
		else
		{
			result << getDesc();
		}
		result << "\n";
	}
	return result.str();
}
