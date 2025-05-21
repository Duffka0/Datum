#include <stdafx.hpp>

using namespace Datum::Errors;

void Datum::Context::Parse() {
    for(unsigned long i = 0; i < content.size() - 1; i++) {
        //std::cout << (int)content[i] << "\t" << i << "\n";
        switch(content[i]) {
            case 0x01: {     // String (read till 0x00)
                std::string str = "";
                i++;
                while(content[i] != 0x00) {
                    str += content[i];
                    i++;
                }
                elements_string.push_back(str);
            } break;
            case 0x02: {     // String (read specified number of bytes)
                std::string str = "";
                uint8_t args[4];
                i++; args[0] = content[i];
                i++; args[1] = content[i];
                i++; args[2] = content[i];
                i++; args[3] = content[i];
                uint32_t target = AssembleInBigEndian_32(args);

                for(unsigned long j = 0; j < target; j++) {
                    i++;
                    str += content[i];
                }
                elements_string.push_back(str);
            } break;
            case 0x03: {     // Integer
                i++;
                uint8_t mode = 0;
                mode = content[i];
                if(mode == 1) { // 8-bit
                    i++;
                    elements_int8.push_back(content[i]);
                }
                else if(mode == 2) { // 16-bit
                    uint8_t args[2];
                    i++; args[0] = content[i];
                    i++; args[1] = content[i];
                    uint16_t num = AssembleInBigEndian_16(args);
                    elements_int16.push_back(num);
                }
                else if(mode == 3) { // 32-bit
                    uint8_t args[4];
                    i++; args[0] = content[i];
                    i++; args[1] = content[i];
                    i++; args[2] = content[i];
                    i++; args[3] = content[i];
                    uint32_t num = AssembleInBigEndian_32(args);
                    elements_int32.push_back(num);
                }
            } break;
        }
    }
}