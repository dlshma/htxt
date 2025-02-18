#include <iostream>
#include <cstdint>

#include "shifter.h"
/* shift() takes four arguments:
1. <target byte>
2. <value against which the bit is being compared (default 0)>
3. <number of the bit being accessed>
4. <how many bits have been counted in a row>
*/

using namespace std;

int main()
{
    uint8_t test_byte{150};

    shift(test_byte, 0, 0, 0);
    return 0;
}
