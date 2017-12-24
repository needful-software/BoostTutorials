/*
    Copyright (c) 2015-2017 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include <boost/endian/conversion.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    unsigned int nativeInt = 0x12345678;
    unsigned int littleEndianInt = boost::endian::native_to_little(nativeInt);
    unsigned int bigEndianInt = boost::endian::native_to_big(nativeInt);

    std::cout << "Native endianness: 0x" << std::hex << nativeInt << std::endl;
    std::cout << "Little endian:     0x" << std::hex << littleEndianInt << std::endl;
    std::cout << "Big endian:        0x" << std::hex << bigEndianInt << std::endl;

    return 0;
}
