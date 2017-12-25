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

#include <boost/random/random_device.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <iostream>
#include <vector>
#include <ctime>

int main(int argc, char* argv[])
{
    // Create a random number generator using the platform default
    boost::random_device rng;
    
    std::cout << "Random number generator:" << std::endl;
    std::cout << "\tMin generated number: " << rng.min() << std::endl;
    std::cout << "\tMax generated number: " << rng.max() << std::endl;
    std::cout << std::endl;

    // Create a Mersenne Twister pseudo-random number generator
    boost::random::mt19937 prng;

    std::cout << "Pseudo-random number generator:" << std::endl;
    std::cout << "\tMin generated number: " << prng.min() << std::endl;
    std::cout << "\tMax generated number: " << prng.max() << std::endl;
    std::cout << std::endl;

    // Generate a random number to be used as the seed
    unsigned int seed = rng();
    std::cout << "The seed is: " << seed << std::endl;
    std::cout << std::endl;

    prng.seed(seed);

    // Generate a few pseudo-random numbers one by one
    std::cout << "Pseudo-random number 1: " << prng() << std::endl;
    std::cout << "Pseudo-random number 2: " << prng() << std::endl;
    std::cout << "Pseudo-random number 3: " << prng() << std::endl;
    std::cout << std::endl;

    // Fill a vector with pseudo-random numbers
    std::vector<unsigned int> v;
    v.resize(5);
    prng.generate(v.begin(), v.end());

    std::cout << "Pseudo-random numbers vector: ";
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
