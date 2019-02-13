#pragma once

#include <string>
#include <vector>



class IncdirUtilities
{
public:
    static std::string delimiter;
    static bool charInString(char c, std::string s)
    {
        for (char sc : s)
            if (c == sc)
                return true;
        return false;
    }

    static bool checkEmptyString(std::string src)
    {
        for (char c : src)
            if (!charInString(c, delimiter))
                return false;
        return true;
    }

    static std::vector<std::string> splitCommand(std::string msg, std::string header)
    {
        std::vector<std::string> result;
        size_t pos = msg.find(header) + header.length();
        while (charInString(msg[pos], delimiter)) pos++;
        size_t tail = pos+1;
        std::string seg;
        while (tail < msg.length())
        {
            if (charInString(msg[tail], delimiter))
            {
                seg = msg.substr(pos, tail - pos);
                if (!checkEmptyString(seg))
                    result.push_back(seg);
                pos = tail + 1;
                while (charInString(msg[pos], delimiter)) pos++;
                tail = pos;
            }
            tail++;
        }
        seg = msg.substr(pos, tail - pos);
        if (!checkEmptyString(seg))
            result.push_back(seg);
        return result;
    }
};

std::string IncdirUtilities::delimiter = " \t\n\r";

