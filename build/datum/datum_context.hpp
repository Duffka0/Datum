#ifndef __DATUM__CONTEXT_HPP
#define __DATUM__CONTEXT_HPP

#include <string>
#include <vector>
#include <cstdint>
#include "datum_errors.hpp"

namespace Datum {

class Context {
    public: Context(std::string str, bool _fromFile = true); // 'str' can be either path/to/datum/file.extension or direct contents
    public: ~Context();

private: // Variables
    std::string filePath = "";      // Path to target datum file
    std::vector<uint8_t> content;       // Contents of file we're working with.
    bool fromFile = false;          // Are we working from a file, (true) or has the user inputed their own content? (false)
    bool success = true;           // Did we successfully read and parse?
    Errors::DatumError lastError;

    std::vector<uint8_t> elements_int8;
    std::vector<uint16_t> elements_int16;
    std::vector<uint32_t> elements_int32;
    std::vector<std::string> elements_string;

private: // Functions
    void ReadFromFile();
    void Parse();
public: // Functions
    Errors::DatumError LastError();

    // Getters
    uint8_t At_int8(unsigned long idx);
    uint16_t At_int16(unsigned long idx);
    uint32_t At_int32(unsigned long idx);
    std::string At_string(unsigned long idx);
};

}

#endif // __DATUM__CONTEXT_HPP