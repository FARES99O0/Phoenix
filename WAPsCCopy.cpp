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
template <class W>
class Waifu
{
public:
    string name;
    string code;
    double height,weight,BMI;
};
vector<string> Waifus = {"zero two (002)", "sakurajima mai (005)", "nakano miku (008)"};
vector<string>::iterator it;

void searching();
void accessing();
void adding();
void deleting();
void editing();
void exiting();
void stop();
int main()
{
    DB.open("WAPdb.txt");
    if (!ID_is_given)
    {
        ID();
        ID_is_given = true;
    }
    cout << "Choose one of the following operations by letter : \n"
         << "A- Search for a Waifu\n"
         << "B- Access a Waifu Info\n"
         << "C- Adding a New Waifu\n"
         << "D- Deleting a Waifu\n"
         << "E- Editing a Waifu\n"
         << "F- Exit\n";
    cin >> op;
    transform(op.begin(), op.end(), op.begin(), ::toupper);
    if (op == "A"){searching();}
    if (op == "B"){accessing();}
    if (op == "C"){adding();}
    if (op == "D"){deleting();}
    if (op == "E"){editing();}
    if (op == "F"){exiting();}
    if (op != "A","B","C","D","E","F"){stop();}
}
    // search operation
void searching(){
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
    cout << "do you want to search again? yes/no" << endl;
    cin >> iD;
    if (iD == "yes")
    {
        searching();
    }
    else
    {
        main();
    }
}
    // accessing operation
void accessing(){
    Waifu <double> waifu1;
    waifu1.name = "Zero Two";
    waifu1.code = "002";
    waifu1.height = 1.7;
    waifu1.weight = 52.4;
    waifu1.BMI = waifu1.weight / (waifu1.height * waifu1.height);

    Waifu <double> waifu2;
    waifu2.name = "Sakurajima Mai";
    waifu2.code = "005";
    waifu2.height = 1.67;
    waifu2.weight = 49;
    waifu2.BMI = waifu2.weight / (waifu2.height * waifu2.height);

    Waifu <double> waifu3;
    waifu3.name = "Nakano Miku";
    waifu3.code = "008";
    waifu3.height = 1.59;
    waifu3.weight = 49;
    waifu3.BMI = waifu3.weight / (waifu3.height * waifu3.height);

    for (int i = 0 ; i < Waifus.size(); i++)
    {
        cout << i << ".) " << Waifus[i] << endl;
    }

    cout << "enter your waifu : ";
    cin >> iD;
    if (iD == "002")
    {
        cout << "name : " << waifu1.name << endl;
        cout << "height : " << waifu1.height << "m" << endl;
        cout << "weight : " << waifu1.weight << "kg" << endl;
        cout << "BMI : " << waifu1.BMI << endl;
    }
    if (iD == "005")
    {
        cout << "name : " << waifu2.name << endl;
        cout << "height : " << waifu2.height << "m" << endl;
        cout << "weight : " << waifu2.weight << "kg" << endl;
        cout << "BMI : " << waifu2.BMI << endl;
    }
    if (iD == "008")
    {
        cout << "name : " << waifu3.name << endl;
        cout << "height : " << waifu3.height << "m" << endl;
        cout << "weight : " << waifu3.weight << "kg" << endl;
        cout << "BMI : " << waifu3.BMI << endl;
    }
    cout << "Wanna access another waifu? yes/no" << endl;
    cin >> iD;
    if (iD == "yes")
    {
        accessing();
    }
    if (iD == "no")
    {
        main();
    }
}
    // adding operation
void adding()
{
Waifu <double> waifu;
    cout << "wonderful, please write her full name along with her code if possible" << endl;
    cout << "first name : ";
    cin >> fina;
    DB << "New waifu added :" << endl;
    DB << fina << endl;
    cout << "last name : ";
    cin >> lana;
    DB << lana << endl;
    cout << "code : ";
    cin >> waifu.code;
    DB << waifu.code << endl;
    cout << "height(in meter) : ";
    cin >> waifu.height;
    DB << waifu.height << "m" << endl;
    cout << "weight(in kilograms) : ";
    cin >> waifu.weight;
    DB << waifu.weight << "kg" << endl;
    Waifus.push_back(fina + " " + lana + " " + "(" + code + ")");
    cout << "New Archive : " << endl;
    for (string wf : Waifus)
    {
        cout << "- " << wf << endl;
    }
    cout << "archive updated, your waifu's info will be availble soon,thank you" << endl;
    cout << "do you want to add another waifu? yes/no" << endl;
    cin >> iD;
    if (iD == "yes")
    {
        adding();
    }
    else
    {
        main();
    }
}
int i;
void deleting()
{
    for (int i = 0 ; i < Waifus.size(); i++)
    {
        cout << i << ".) " << Waifus[i] << endl;
    }
    cout << "choose a waifu to delete : ";
    cin >> i;
    if(i > Waifus.size()){cout << "waifu not found\n"; goto something;}
    if (Waifus.size() <= 0) {cout << "everything is deleted\n"; goto something;}
    it = Waifus.begin() + i;
    Waifus.erase(it);
    cout << "the waifu is successfully deleted\n";
    for (int i = 0 ; i < Waifus.size(); i++)
    {
        cout << i << ".) " << Waifus[i] << endl;
    }
    something:;
    DB << i << " is deleted";
    cout << "do you want to delete another waifu? yes/no" << endl;
    cin >> iD;
    if (iD == "yes")
    {
        deleting();
    }
    else
    {
        main();
    }
}
    // editing operation
void editing()
{
    for (int i = 0 ; i < Waifus.size(); i++)
    {
        cout << i << ".) " << Waifus[i] << endl;
    }
    cout << "choose a waifu to edit : ";
    cin >> i;
    if(i > Waifus.size()){cout << "waifu not found\n"; goto somethingelse;}
    it = Waifus.begin() + i;
    cout << "to what do you want to edit it?" << endl;
    cout << "first name : ";
    cin >> fina;
    DB << i << " edited :" << endl;
    DB << fina << endl;
    cout << "last name : ";
    cin >> lana;
    DB << lana << endl;
    cout << "code : ";
    cin >> code;
    DB << code << endl;
    Waifus.at(i) = fina + " " + lana + " " + "(" + code + ")";
    cout << "archive updated, your waifu's info will be availble soon,thank you" << endl;
    for (int i = 0 ; i < Waifus.size(); i++)
    {
        cout << i << ".) " << Waifus[i] << endl;
    }
    somethingelse:;
    cout << "Wanna edit another waifu? yes/no" << endl;
    cin >> iD;
    if (iD == "yes")
    {
        editing();
    }
    else
    {
        main();
    }
}
    // exit operation
void exiting()
{
        cout << "you sure?\n";
        cin >> iD;
        if (iD == "yes")
        {
            cout << "Bye see you later\n";
            exit(1);
        }
        else if (iD == "no")
        {
            main();
        }
}
void stop()
{
        cout << "Come on dude i said choose from the following, try again\n";
        main();
    DB.close();
}