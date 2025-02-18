// test program of recursive bitwise shift counter for determining number of bits in a heavenlyText 'character'
// will implement the rest tomorrow. i'm getting sleepy.

#include <iostream>
#include <cstdint>
using namespace std;

// example byte 'c' to showcase the functionality
uint8_t c{0b01100100};

// global count variable (this will break so make it not global plz)
int count{0};

// <kinda redundant- integrate this into shift()> - returns bit in counter byte
int checkBit(int x, int y)
{
    if (x & (1 << y)) { return 1; }
    else { return 0; }
}

// uUGHH
// pass in the target byte, current 'value' to reference if shift occurred, and the bit being referenced
void shift(int target, int shiftval, int spot)
{       
    if (spot < 8) {
        int x = checkBit(target, spot);
        if (shiftval ^ x) // okay IF THERE IS A CHANGE -> print how many bits were in a row and move on
        {
            shiftval = x; 
            cout << "switched after " << count << " bit(s)\n"; 
            count = 1;
            shift(target, shiftval, ++spot);
        }
        else { // IF THERE IS NO CHANGE: move it along
            count++; 
            shift(target, shiftval, ++spot);
        }
    } 
    else { // remainder is special because bytes wont start and end when htxt 'chars' do. so it's all very complicated unless the remainder value is given the special treatment.
        cout << "reached end of byte with remainder " << count; 
    }
}

// checkByte() is just to print the whole byte so you can see it OHHH THAT's WHY checkBit() IS SEPARATE
void checkByte(int z) 
{
    for (int i{}; i < 8; i++) {
        cout << checkBit(z, i);
        "/n";
    }
}

int main() 
{
    shift(c, 0, 0);
    return 0;
}
