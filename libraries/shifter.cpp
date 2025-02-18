// test program of recursive bitwise shift counter for determining number of bits in a heavenlyText 'character'
// will implement the rest tomorrow. i'm getting sleepy.

#include <iostream>
#include <cstdint>
using namespace std;

// global count variables (this will break so make it not global plz)
int global_count{};
int globalx{0};

// returns bit in counter byte
int checkBit(int x, int y)
{
    if (x & (1 << y)) { return 1; }
    else { return 0; }
}

// uUGHH
// pass in the target byte, current 'value' to reference if shift occurred, and the bit being referenced
void shift(int target, int shiftval, int spot, int count)
{ 
    if (spot < 8) 
    {
        int x = checkBit(target, spot);
        if (shiftval ^ x) // okay IF THERE IS A CHANGE -> print how many bits were in a row and move on
        {
            shiftval = x; 
            cout << "switched after " << count << " bit(s)\n"; 
            count = 1;
            shift(target, shiftval, ++spot, count);
        }
        else { // IF THERE IS NO CHANGE: move it along
            count++; 
            shift(target, shiftval, ++spot, count);
        }
    } else {
        globalx = shiftval;
        global_count = count;
        cout << "reached end of byte with " << global_count << " remaining bit(s) (value " << globalx << ")\n";
    }
}

// checkByte() is just to print the whole byte so you can see it OHHH THAT's WHY checkBit() IS SEPARATE
void checkByte(int z)
{
    for (int i{}; i < 8; i++) {
        cout << checkBit(z, i) << "/n";
    }
}
