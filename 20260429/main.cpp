#include <iostream>
#include <string>
#include <vector>

void binary_operation()
{
    int result = 0b1001101 | 0b1001110110;
    std::cout << "换算后: " << result << std::endl;
}

void while_loop()
{
    int current_tick = 0;
    int last_checked_tick = 0;

    std::string temp;

    while (current_tick < 100)
    {
        if (current_tick - last_checked_tick >= 10)
        {
            // 将当前tick保存到最后检查点tick
            last_checked_tick = current_tick;
            std::cout << "[第 " << (current_tick + 1) << " 次循环] last tick checked: " << last_checked_tick << std::endl;
        }
        else
        {
            std::cout << "[第 " << (current_tick + 1) << " 次循环] current tick: " << current_tick << std::endl;
            getline(std::cin, temp);
        }
        current_tick++;
    }
}

void bubbleSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {                         // 外层循环控制遍历次数
        bool swapped = false; // 优化：记录是否发生交换
        for (int j = 0; j < n - i - 1; ++j)
        { // 内层循环进行相邻比较
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]); // 交换元素
                swapped = true;
            }
        }
        // 如果没有发生交换，说明序列已排序完成，跳出循环
        if (!swapped)
            break;
    }
}

void call_bubble_sort()
{
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(data);
    std::cout << "Sorted array: ";
    for (int x : data)
        std::cout << x << " ";
}
// -----------------------------------------



// int currentSecond: 传值调用 (call by value): 参数赋值仅在函数内部作用域中生效，
//                    不会影响调用函数时传递进来的变量的值。
// int &totalQuantity: 引用调用 (call by reference): 外部传递到函数的变量，
//                     在函数内部修改的结果，会影响到这个变量本身
void sellApple(int currentSecond, int &totalQuantity)
{
    int lastSecond = 0;
    if (currentSecond - lastSecond >= 1000)
    {
        lastSecond = currentSecond;
        for (; totalQuantity > 0; totalQuantity--)
        {
            std::cout << "当前苹果剩余: " << totalQuantity << std::endl;
        }
    }
}

bool isAppleSoldOut(int currentQuantity)
{
    if (currentQuantity <= 0)
    {
        std::cout << "当前苹果已全部卖完~" << std::endl;
        return true;
    }
    return false;
}

int main()
{
    int tick = 0;
    int totalApple = 100;

    while (true)
    {
        sellApple(tick, totalApple);

        // call function [isAppleSoldOut] with parameter "totalApple"
        if (isAppleSoldOut(totalApple))
        {
            break;
        }

        tick++;
    }

    return 0;
}