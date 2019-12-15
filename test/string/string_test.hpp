#include "test.hpp"
#include "string.hpp"

void z_algorithm_test()
{
    {
        string s = "abc";
        auto z = z_algorithm(s);
        eassert(z[0] == 3, "z[0] == %d", z[0]);
        eassert(z[1] == 0, "z[1] == %d", z[1]);
        eassert(z[2] == 0, "z[2] == %d", z[2]);
    }

    {
        string s = "abcabc";
        auto z = z_algorithm(s);
        eassert(z[0] == 6, "z[0] == %d", z[0]);
        eassert(z[1] == 0, "z[1] == %d", z[1]);
        eassert(z[2] == 0, "z[2] == %d", z[2]);
        eassert(z[3] == 3, "z[3] == %d", z[3]);
        eassert(z[4] == 0, "z[4] == %d", z[4]);
        eassert(z[5] == 0, "z[5] == %d", z[5]);
    }

    {
        string s = "aaabaaaab";
        auto z = z_algorithm(s);
        eassert(z[0] == 9, "z[0] == %d", z[0]);
        eassert(z[1] == 2, "z[1] == %d", z[1]);
        eassert(z[2] == 1, "z[2] == %d", z[2]);
        eassert(z[3] == 0, "z[3] == %d", z[3]);
        eassert(z[4] == 3, "z[4] == %d", z[4]);
        eassert(z[5] == 4, "z[5] == %d", z[5]);
        eassert(z[6] == 2, "z[6] == %d", z[6]);
        eassert(z[7] == 1, "z[7] == %d", z[7]);
        eassert(z[8] == 0, "z[8] == %d", z[8]);
    }
}

void string_test()
{
    z_algorithm_test();
}
