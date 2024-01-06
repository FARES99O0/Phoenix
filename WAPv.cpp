// Waifus Archive Program
#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
string iD;
string fina;
string lana;
string code;
string op;
ofstream DB;
bool rain_has_run = false;
bool ID_is_given = false;
bool isFound = false;
// Title function
void rain()
{
    cout << "==================================================================\n"
         << "||                                                              ||\n"
         << "||                    WAIFUS ARCHIVE PROGRAM                    ||\n"
         << "||                                                              ||\n"
         << "==================================================================\n";
}
// Password fuction
void ID()
{
    if (!rain_has_run)
    {
        rain();
        rain_has_run = true;
    }
    cout << "Enter your ID : " << endl;
    cin >> iD;
    if (iD == "0000")
    {
        cout << "Yeah Boy!" << endl;
    }
    else
    {
        cout << "Wrong! try again" << endl;
        ID();
    }
}

class Waifu
{
public:
    string name;
    double height;
    double weight;
};
int main()
{
    DB.open("WAPdb.txt");
    if (!ID_is_given)
    {
        ID();
        ID_is_given = true;
    }
    Waifu waifu1;
    waifu1.name = "Zero Two";
    waifu1.height = 1.70;
    waifu1.weight = 52.4;

    Waifu waifu2;
    waifu2.name = "Sakurajima Mai";
    waifu2.height = 1.67;
    waifu2.weight = 49;

    Waifu waifu3;
    waifu3.name = "Nakano Miku";
    waifu3.height = 1.59;
    waifu3.weight = 49;

    vector<string> Waifus = {"sakurajima mai (005)", "nakano miku (008)", "zero two (002)"};
    vector<string>::iterator it;
    cout << "Choose one of the following operations by letter : \n"
         << "A- Search for a Waifu\n"
         << "B- Access a Waifu Info\n"
         << "C- Adding a New Waifu\n"
         << "D- Deleting a Waifu\n"
         << "E- Editing a Waifu\n"
         << "F- BMI count\n"
         << "G- Exit\n";
    cin >> op;
    transform(op.begin(), op.end(), op.begin(), ::toupper);
    // search operation
    if (op == "A")
    {
        cout << "enter something to search : ";
        cin >> iD;
        for (string wf : Waifus)
        {
            if (wf.find(iD) != wf.npos)
            {
                cout << wf << endl;
                isFound = true;
            }
        }
        if (!isFound)
        {
            cout << "nothing was found!" << endl;
        }
        cout << "do you want to check available waifus? yes/no" << endl;
        cin >> iD;
        if (iD == "yes")
        {
            main();
        }
        if (iD == "no")
        {
            cout << "OK, bey.\n";
            return 0;
        }
    }
    // accessing operation
    if (op == "B")
    {
        cout << "enter waifu code" << endl;
        cin >> iD;
        if (iD == "002")
        {
            cout << "name : " << waifu1.name << endl;
            cout << "height : " << waifu1.height << "m" << endl;
            cout << "weight : " << waifu1.weight << "kg" << endl;
        }
        if (iD == "005")
        {
            cout << "name : " << waifu2.name << endl;
            cout << "height : " << waifu2.height << "m" << endl;
            cout << "weight : " << waifu2.weight << "kg" << endl;
        }
        if (iD == "008")
        {
            cout << "name : " << waifu3.name << endl;
            cout << "height : " << waifu3.height << "m" << endl;
            cout << "weight : " << waifu3.weight << "kg" << endl; 
        }
            cout << "Wanna do something else? yes/no" << endl;
            cin >> iD;
            if (iD == "yes")
            {
                main();
            }
            if (iD == "no")
            {
                cout << "OK, bey.\n";
                return 0;
            }
    }
    // adding operation
    if (op == "C")
    {
        cout << "====================(!)Warning(!)====================\n"
             << "enter your id to move on " << endl;
        ID();
        cout << "wonderful, please write her full name along with her code if possible" << endl;
        cout << "first name : ";
        cin >> fina;
        DB << "New waifu added :" << endl;
        DB << fina << endl;
        cout << "last name : ";
        cin >> lana;
        DB << lana << endl;
        cout << "code : ";
        cin >> code;
        DB << code << endl;
        Waifus.push_back(fina + " " + lana + " " + "(" + code + ")");
        cout << "New Archive : " << endl;
        for (string wf : Waifus)
        {
            cout << "- " << wf << endl;
        }
        cout << "archive updated, your waifu's info will be availble soon,thank you" << endl;
        cout << "do you want to check available waifus? yes/no" << endl;
        cin >> iD;
        if (iD == "yes")
        {
            main();
        }
        else
        {
            cout << "oh, maybe next time, bey!\n";
            return 0;
        }
    }
    // deleting operation
    if (op == "D")
    {
        cout << "====================(!)Warning(!)====================\n"
             << "enter your id to move on " << endl;
        ID();
        cout << "choose a waifu to delete by her code" << endl;
        for (string wf : Waifus)
        {
            cout << "- " << wf << endl;
        }
        cin >> iD;
        if (iD == "002")
        {
            cout << "(!)Operetion Impossible(!)\n";
            main();
        }
        if (iD == "005")
        {
            it = Waifus.begin();
            Waifus.erase(it);
            for (auto it = Waifus.begin(); it != Waifus.end(); ++it)
            {
                cout << "- " << *it << endl;
            }
        }
        DB << "005 is deleted";
        if (iD == "008")
        {
            it = Waifus.begin() + 1;
            Waifus.erase(it);
            for (auto it = Waifus.begin(); it != Waifus.end(); ++it)
            {
                cout << "- " << *it << endl;
            }
        }
        DB << "008 is deleted";
        cout << "do you want to check available waifus? yes/no" << endl;
        cin >> iD;
        if (iD == "yes")
        {
            main();
        }
        else
        {
            cout << "oh, maybe next time, bey!\n";
            return 0;
        }
    }
    // editing operation
    if (op == "E")
    {
        cout << "====================(!)Warning(!)====================\n"
             << "enter your id to move on " << endl;
        ID();
        cout << "choose a waifu to edit by her code" << endl;
        for (string wf : Waifus)
        {
            cout << "- " << wf << endl;
        }
        cin >> iD;
        if (iD == "002")
        {
            cout << "(!)Operetion Impossible(!)\n";
            main();
        }
        if (iD == "005")
        {
            cout << "to what do you want to edit it?" << endl;
            cout << "first name : ";
            cin >> fina;
            DB << "005 edited :" << endl;
            DB << fina << endl;
            cout << "last name : ";
            cin >> lana;
            DB << lana << endl;
            cout << "code : ";
            cin >> code;
            DB << code << endl;
            Waifus.at(1) = fina + " " + lana + " " + "(" + code + ")";
            for (const string &wf : Waifus)
            {
                cout << "- " << wf << endl;
            }
            cout << "archive updated, your waifu's info will be availble soon,thank you" << endl;
        }
        if (iD == "008")
        {
            cout << "to what do you want to edit it?" << endl;
            cout << "first name : ";
            cin >> fina;
            DB << "008 edited :" << endl;
            DB << fina << endl;
            cout << "last name : ";
            cin >> lana;
            DB << lana << endl;
            cout << "code : ";
            cin >> code;
            DB << code << endl;
            Waifus.at(2) = fina + " " + lana + " " + "(" + code + ")";
            for (const string &wf : Waifus)
            {
                cout << "- " << wf << endl;
            }
            cout << "archive updated, your waifu's info will be availble soon,thank you" << endl;
        }
            cout << "do you want to check available waifus? yes/no" << endl;
            cin >> iD;
            if (iD == "yes")
            {
                main();
            }
            else
            {
                cout << "oh, maybe next time, bey!\n";
                return 0;
            }
    }
    // BMI operation
    double H;
    double W;
    if (op == "F")
    {
        cout << "enter the height and the weight of the waifu?\n";
        cout << "Height (in meters) : ";
        cin >> H;
        cout << "Weight (in kilograms) : ";
        cin >> W;
        cout << W / (H * H) << " : ";
        if (W / (H * H) < 18.5)
        {
            cout << "your waifu is underweight!\n";
        }
        if (W / (H * H) >= 18.5, W / (H * H) <= 24.9)
        {
            cout << "your waifu has a healthy weight!\n";
        }
        if (W / (H * H) > 24.9)
        {
            cout << "your waifu is overweight!\n";
        }
            cout << "Wanna do something else? yes/no" << endl;
            cin >> iD;
            if (iD == "yes")
            {
                main();
            }
            if (iD == "no")
            {
                cout << "OK, bey.\n";
                return 0;
            }
    }
    // exit operation
    if (op == "G")
    {
        cout << "Bey see you later\n";
        return 0;
    }
    if (op != "A", "B", "C", "D", "E", "F", "G")
    {
        cout << "Come on dude i said choose from the following, try again\n";
        main();
    }
    DB.close();
}