#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int var = 5;
    static int base = 3;

    function<int()> f = [=]() mutable -> int
    {
        var++;
        base++;
        return var + base;
    };

    auto ret1 = f();
    auto ret2 = f();
    cout << "ret1 = " << ret1 << " ret2 = " << ret2 << endl
         << " var = " << var << " base = " << base << endl;

    return 0;
}
