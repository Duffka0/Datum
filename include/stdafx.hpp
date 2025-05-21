#ifndef STDAFX_HPP
#define STDAFX_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cerrno>

#include "../build/datum/datum.hpp"

uint16_t AssembleInBigEndian_16(uint8_t bytes[2]);
uint32_t AssembleInBigEndian_32(uint8_t bytes[4]);
uint64_t AssembleInBigEndian_64(uint8_t bytes[8]);

#endif // STDAFX_HPP