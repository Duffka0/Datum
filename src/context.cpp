#include <stdafx.hpp>

using namespace Datum::Errors;

Datum::Context::Context(std::string str, bool _fromFile) {
    lastError = SUCCESS;
    
    if(_fromFile) {
        filePath = str;
        ReadFromFile();
    }
    else {
        for(unsigned long i = 0; i < str.length(); i++) {
            content.push_back(str[i]);
        }
    }

    if(success) {
        Parse();
    }
}

Datum::Context::~Context() {
    ;
}

Datum::Errors::DatumError Datum::Context::LastError() {
    return lastError;
}

void Datum::Context::ReadFromFile() {
    FILE* file = fopen(filePath.c_str(), "r");
    if(!file) {
        switch(errno) {
            case ENOENT:
                lastError = FAILED_TO_READ_DOESNT_EXIT;
            break;

            default:
                lastError = FAILED_TO_READ;
            break;
        }
        success = false;
        return;
    }

    while(!feof(file)) {
        content.push_back(getc(file));
    }
    fclose(file);
}

uint8_t Datum::Context::At_int8(unsigned long idx) {
    return elements_int8[idx];
}

uint16_t Datum::Context::At_int16(unsigned long idx) {
    return elements_int16[idx];    
}

uint32_t Datum::Context::At_int32(unsigned long idx) {
    return elements_int32[idx];    
}

std::string Datum::Context::At_string(unsigned long idx) {
    return elements_string[idx];
}