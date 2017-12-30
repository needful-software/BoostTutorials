/*
    Copyright (c) 2017 Xavier Leclercq

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

// No need to include these files conditionally as Boost already
// does an OS check inside them
#include <boost/system/windows_error.hpp>
#include <boost/system/linux_error.hpp>

#ifdef _WIN32
#include <windows.h>
#else
#include <fcntl.h>
#endif

#include <iostream>

int main(int argc, char* argv[])
{
    // OS-specific error code
    boost::system::error_code errorCode;

    // Open the file using the Windows or the POSIX API.
    // Note that we try to open a file in a subdirectory that doesn't exist because
    // that will cause Windows to return a different error code than when the directory
    // exists but not the file. If we didn't do that both type of calls would return 2.
#ifdef _WIN32
    HANDLE file = CreateFile(L"doesnotexist/doesnotexist", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    DWORD lastError = GetLastError();
    if (file == INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed to open file. GetLastError(): " << lastError << std::endl;
    }
    errorCode = boost::system::error_code(lastError, boost::system::system_category());
#else
    int file = open("doesnotexist/doesnotexist", O_RDONLY);
    if (file == -1)
    {
        std::cout << "Failed to open file. errno: " << errno << std::endl;
    }
    errorCode = boost::system::error_code(errno, boost::system::system_category());
#endif

    // Output the OS-specific error code
    std::cout << "error_code: " << errorCode << std::endl;

    // Convert the OS-specific error code into a generic error_condition
    // error_condition doesn't implement << the same way error_code does so we format it explicitly
    boost::system::error_condition errorCondition = errorCode.default_error_condition();
    std::cout << "error_condition: " << errorCondition.category().name() << ":" << errorCondition.value() << std::endl;

    return 0;
}
