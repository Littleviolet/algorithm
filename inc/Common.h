#ifndef COMMON_H
#define COMMON_H

namespace utils
{
    static void Swap(int& left, int& right)
    {
        int tmp = left;
        left = right;
        right = tmp;
    }
}
#endif // !COMMON_H