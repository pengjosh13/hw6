#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        unsigned long long leeng[5] = {0,0,0,0,0};
        std::string stuf = k;
        for (int i = 4; i >= 0; i--){
            unsigned intt stufSiz = stuf.size();
            for (int j = stuf.size(); j >= 0; j--){
                if (j < 6 && j < stuf.size()){
                    stuf[i] += pow(36, j) * letterDigitToNumber(get[abs(i - stuf.size() + 1)]);
                }

            }
            for (int k = 0; k < 6; k++){
                if (stuf.size() !=  0){
                    stuf.pop_back();
                }
            }
        }
        HASH_INDEX_T extraFunx = 0;
        for (int l = 0; l < 5; l++){
            extraFunx += stuf[i] * rValues[i];
        }
        return extraFunx;
        // Add your code here


    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        if (letter >= 'A' && letter <= 'Z'){
            letter = tolower(letter);
        }
        if (letter >= '0' && letter <= '9'){
            letter -= 22;
            return letter;
        }
        if (letter >= 'a' && letter <= 'z'){
            letter -= 97;
            return letter;
        }
        return -1;

        // Add code here or delete this helper function if you do not want it

    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
