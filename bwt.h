#ifndef BWT_H
#define BWT_H

#include <string>

namespace bwt {
    void shiftString(std::string& str);
    void encode(const std::string& s, std::string& buf, int& index);
    void decode(const std::string& s, std::string& buf, int& index);
}

#endif