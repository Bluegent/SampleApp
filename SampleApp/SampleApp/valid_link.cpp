#include "valid_link.h"
#include <iostream>
#include <vector>



//write a function that splits a string into multiple strings based on a list of possible delimiters
std::vector<std::string> split(const std::string& str, char delimiter)
{
    std::vector<std::string> result;

    std::vector<size_t> delimPositions;
    size_t pos = 0;

    //first we find all the positions of the delimiters inside the string
    while (true)
    {
        pos = str.find(delimiter, pos + 1);
        //if find returns npos, then the string no longer contains any delimiters and we can stop
        if (pos == std::string::npos)
        {
            break;
        }
        delimPositions.push_back(pos);
    }

    //if there are no delimiter positions, that means there are no delimiters
    //therfore the "split" string is just the original string
    if (delimPositions.size() == 0)
    {
        result.push_back(str);
        return result;
    }

    // "test.123.321.tst"
    // delimPosition = {4,8,12}
    // test = str.substr(0,4)
    // 123  = str.substr(4+1,8-4-1)
    // 321  = str.substr(8+1,12-8-1)
    // tst  = str.substr(12+1)

    //we push what is between position 0 and the position of the first delimiter
    result.push_back(str.substr(0, delimPositions[0]));
    for (size_t i = 0; i < delimPositions.size() - 1; ++i)
    {
        //then we push what is between each consecutive pair of delimiters
        result.push_back(str.substr(delimPositions[i] + 1, delimPositions[i + 1] - delimPositions[i] - 1));
    }
    //and finally we push the last portion of the string
    result.push_back(str.substr(delimPositions[delimPositions.size() - 1] + 1));

    return result;
}

bool trimPrefix(std::string& str, const std::string& prefix)
{
    if (str.find(prefix) == 0)
    {
        str = str.substr(prefix.size());
        return true;
    }
    return false;
}

// write a function that takes a string and returns true if the string is a valid web link
// a valid link may contain:
// http:// or https:// - optional
// www - optional
// <site_name> - mandatory
// .<domain> - mandatory
// any number of sub-paths e.g. site.com/subpath1/subpath2/...
bool isValidLink(const std::string& link)
{
    std::string copy{ link };


    if (link.find(' ') != std::string::npos)
    {
        return false;
    }
    //first, we try to remove the optional prefixes at the start of the link
    if (!trimPrefix(copy, "http://"))
    {
        trimPrefix(copy, "https://");
    }
    trimPrefix(copy, "www.");

    auto substrings = split(copy, '.');

    if (substrings.size() <= 1)
    {
        return false;
    }
    for (const auto& str : substrings)
    {
        if (str.size() == 0)
        {
            return false;
        }
    }

    substrings = split(copy, '/');
    for (const auto& str : substrings)
    {
        if (str.size() == 0)
        {
            return false;
        }
    }


    return true;
}


void testLink(const std::string& link)
{
    bool valid = isValidLink(link);
    std::cout << "Link = \"" << link << "\" is" << (valid ? "" : " NOT") << " valid\n";
}

void valid_link_main()
{
    std::vector<std::string> links = {
        "https://google.com/search?=yes"
        ,"http://no"
        ,"asite.com"
        ,"www.asite.com/home"
        ,"totally_a_link_bro_trust_me/yes"
        ,"...","cloud.google..com"
        ,"http://https://www.google.com"
        ,"www.cloud.google.com//search" };
    for (const auto& link : links)
    {
        testLink(link);
    }


    //std::vector<std::string> words = split("test.123.321.tst",'.');
    //std::vector<std::string> words = split("cloud.google..com", '.');
}