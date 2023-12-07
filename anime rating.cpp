#include <iostream>
using namespace std;
int main() {
//anime rating program
    int ani;
    cout << "welcome, what would you like to watch?\n";
    cout << "1-One piece\n"
         << "2-Naruto\n"
         << "3-Black clover\n"
         << "4-Bleach\n"
         << "5-Yosuga no sora\n";
    cin >> ani;
    if (ani < 1 || ani > 5 || cin.fail())
    {
        cout << "invalid input, please in a value between 1-5\n";
    }
    else
    {
        switch (ani)
        {
        case 1:
            cout << "One piece : 4.57/5\n"
                 << endl;
            break;
        case 2:
            cout << "Naruto : 4.68/5\n"
                 << endl;
            break;
        case 3:
            cout << "Black clover : 4.65/5\n"
                 << endl;
            break;
        case 4:
            cout << "Bleach : 4.69/5\n"
                 << endl;
            break;
        case 5:
            cout << "Yosuga no sora : 3.03/5\n"
                 << endl;
        }
    }
    return 0;
}
