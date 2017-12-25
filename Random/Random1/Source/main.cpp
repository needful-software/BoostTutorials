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

#include <boost/random/mersenne_twister.hpp>
#include <iostream>
#include <vector>
#include <ctime>

int main(int argc, char* argv[])
{
    // Create a Mersenne Twister pseudo-random number generator
    boost::random::mt19937 prng;

    // Seed it with the current time
    prng.seed((uint32_t)std::time(0));
    
    std::cout << "The random number generator will generate numbers between "
        << prng.min() << " and " << prng.max() << std::endl << std::endl;

    // Generate a few random numbers one by one
    std::cout << "Random number 1: " << prng() << std::endl;
    std::cout << "Random number 2: " << prng() << std::endl;
    std::cout << "Random number 3: " << prng() << std::endl;
    std::cout << std::endl;

    // Fill a vector with random numbers
    std::vector<unsigned int> v;
    v.resize(5);
    prng.generate(v.begin(), v.end());

    std::cout << "Random numbers vector: ";
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
