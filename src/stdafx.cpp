#include <stdafx.hpp>

uint16_t AssembleInBigEndian_16(uint8_t bytes[2]) {
    uint16_t rtnval = 0;

    rtnval |= static_cast<uint16_t>(bytes[0]) << 8;
    rtnval |= static_cast<uint16_t>(bytes[1]) << 0;

    return rtnval;
}

uint32_t AssembleInBigEndian_32(uint8_t bytes[4]) {
    uint32_t rtnval = 0;
    
    rtnval |= static_cast<uint32_t>(bytes[0]) << 24;
    rtnval |= static_cast<uint32_t>(bytes[1]) << 16;
    rtnval |= static_cast<uint32_t>(bytes[2]) <<  8;
    rtnval |= static_cast<uint32_t>(bytes[3]) <<  0;

    return rtnval;
}

uint64_t AssembleInBigEndian_64(uint8_t bytes[8]) {
    uint64_t rtnval = 0;

    rtnval |= static_cast<uint64_t>(bytes[0]) << 56;
    rtnval |= static_cast<uint64_t>(bytes[1]) << 48;
    rtnval |= static_cast<uint64_t>(bytes[2]) << 40;
    rtnval |= static_cast<uint64_t>(bytes[3]) << 32;
    rtnval |= static_cast<uint64_t>(bytes[4]) << 24;
    rtnval |= static_cast<uint64_t>(bytes[5]) << 16;
    rtnval |= static_cast<uint64_t>(bytes[6]) <<  8;
    rtnval |= static_cast<uint64_t>(bytes[7]) <<  0;

    return rtnval;
}