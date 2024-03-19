#include<data_structure/NestedList.h>

NestedInteger::NestedInteger(int number) :m_isInteger(true), m_integer(number)
{
}

NestedInteger::NestedInteger(const std::vector<NestedInteger>& list) :m_isInteger(false), m_list(list)
{
}
