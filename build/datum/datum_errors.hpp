#ifndef __DATUM__ERRORS_HPP
#define __DATUM__ERRORS_HPP

namespace Datum::Errors {

enum DatumError {
    SUCCESS = -1,                   // -1
    UNKNOWN,                        // 0
    FAILED_TO_READ,                 // 1
    FAILED_TO_PARSE,                // 2
    ILLEGAL_SET,                    // 3
    FAILED_TO_READ_DOESNT_EXIT,     // 4
};

}

#endif // __DATUM__ERRORS_HPP