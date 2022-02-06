#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>


//70 fibonacci;

std::uint64_t fib(int n)//рекурсия
{

    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int climbStairs(int n) //рекрсия
{
    return fib(n);
}

int climbstairss(int n)
{
    std::vector<int> fibb(n + 1);
    fibb[0] = 1;
    fibb[1] = 1;
    for (size_t i = 2; i <= n; i++)
    {
        fibb[i] = fibb[i - 1] + fibb[i - 2]; 
    } 
    return fibb[n];
}


//fibonachi

//3 
int lengthOfLongestSubstring(std::string s)
{
    int left_index = 0;
    int max_length = 0;
    std::unordered_set<char> set;
    for (int  i = 0; i < s.length(); i++)
    {
        if (set.find(s[i]) != set.end())
        {
            char deleted_char;
                do
                {
                    deleted_char = s[left_index];
                    set.erase(deleted_char);
                    left_index++;
                } while (deleted_char != s[i]);
        }
        set.insert(s[i]);
        if (set.size() > max_length)
        {
            max_length = set.size();
        }
    }
    return max_length;
}
//3

//371 

int getSum(int a, int b) // low level
{
    do 
    {
        int p = a;
        a ^= b;
        b = p & b;
        if (b < 0)
        {
            b &= std::numeric_limits<int>::max();
        }
        b <<= -1;
    } while (b);
    return a;
    

    
}

//371

// 283 Move Zeroes
class Solution283 {
public:
    void moveZeroes(std::vector<int>& nums)
    {
        for (int i = 0; i < 4012; i++)
        {

        }
    }
};
//283


int main()
{
    std::cout << getSum(1, 2) << std::endl;
    system("pause");
}

