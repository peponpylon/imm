/* SPDX-FileCopyrightText: Copyright (c) 2024 imm project maintainers
 * SPDX-License-Identifier: LGPL-3.0 */
/*  == imm v0 == */

#include "main.h"
#include <iostream>

int main() {

    // ARCHITECTURES
    #ifdef _M_X64
    std::cout << "  hello/0.1: _M_X64 defined\n";
    #endif

    // COMPILER VERSIONS
    #if _MSC_VER
    std::cout << "  hello/0.1: _MSC_VER" << _MSC_VER<< "\n";
    #endif

    #if _MSVC_LANG
    std::cout << "  hello/0.1: _MSVC_LANG" << _MSVC_LANG<< "\n";
    #endif


    // Let's see if we got this thing working...
    auto our_number = 1 + THE_NUMBER;
    std::cout << "Hello world!\n";
    std::cout << our_number;
}