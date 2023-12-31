#pragma once

#include <string>

// write a function that takes a string and returns true if the string is a valid web link
// a valid link may contain:
// http:// or https:// - optional
// www - optional
// <site_name> - mandatory
// .<domain> - mandatory
// any number of sub-paths e.g. site.com/subpath1/subpath2/...
bool isValidLink(const std::string& link);


void valid_link_main();