#include <iostream>
#include <string>
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
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                std::swap(nums[j], nums[i]);
                j++;
                
            }
        }
    }
};
//283 
// Четные слева а нечетные справа
class Solution283_chet {
public:
    void moveZeroes(std::vector<int>& nums)
    {
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            if (nums[i] & 0) // Если двочиное представление числа заканчивается на  1, оно не четное, на 0, четное
            {
                std::swap(nums[j], nums[i]);
                j++;

            }
        }
    }
};

//108. Convert Sorted Array to Binary Search Tree
class Solution108 {
public:
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    TreeNode* sortedArrayToBST(std::vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int current_index = (left + right) / 2;
        TreeNode* current_item = new TreeNode(nums[current_index]);
        current_item->left = sortedArrayToBST(nums, left, current_index - 1);
        current_item->right = sortedArrayToBST(nums, current_index + 1, right);
        return current_item;
    }


    TreeNode* sortedArrayToBST(std::vector<int>& nums)
    {
        if (nums.empty())
        {
            return nullptr;
        }
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};

//108. Convert Sorted Array to Binary Search Tree

//94. Binary Tree Inorder Traversal

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution94 {
public:
    
    std::vector<int> buffer;

    void inorderTraversalBuff(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorderTraversal(root->left);
        buffer.push_back(root->val);
        inorderTraversal(root->right);
    }

    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        inorderTraversalBuff(root);
        return buffer;
    }
};

//94. Binary Tree Inorder Traversal

//9. Palindrome Number

class Solution9 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long y = 0, t = x;
        while (t != 0) {
            y = y * 10 + t % 10;
            t /= 10;
        }
        return x == y;
    }
};
int main()
{

    Solution9 kek;
    int x = 0;
    std::cin >> x;
    kek.isPalindrome(x);
    system("PAUSE");
}

//9. Palindrome Number


/*int main()
{
    Solution283_chet chok;
    std::vector<int> vec = { 1,2,3,4,5,6 };
    chok.moveZeroes(vec);
    system("pause");

}*/

//int main()
//{
//    // Поддержка кириллицы в консоли Windows
//    setlocale(LC_ALL, "");
//
//    // Создание вектора из строк
//    std::vector<std::string> students;
//
//    // Буфер для ввода фамилии студента
//    std::string buffer = "";
//
//    std::cout << "Вводите фамилии студентов. "
//        << "По окончание ввода введите пустую строку" << std::endl;
//
//    do {
//        std::getline(std::cin, buffer);
//        if (buffer.size() > 0) {
//            // Добавление элемента в конец вектора
//            students.push_back(buffer);
//        }
//    } while (buffer != "");
//
//
//    // Сохраняем количество элементов вектора 
//    unsigned int vector_size = students.size();
//
//    // Вывод заполненного вектора на экран
//    std::cout << "Ваш вектор." << std::endl;
//    for (int i = 0; i < vector_size; i++) {
//        std::cout << students[i] << std::endl;
//    }
//
//    return 0;
//}