#include <iostream>
int main()
{
    int max = 3;
    int val[max];
    char codigo;
    for (int i = 0; i < max; i++)
    {
        std::cin >> val[i];
    }
    std::cin >> codigo;
    if (codigo == 'P')
    {
        for (int i = 0; i < max; i++)
        {
            std::cout << val[i] << std::endl;
        }
    }

    std::cout << "asdasd";
    return 0;
}
