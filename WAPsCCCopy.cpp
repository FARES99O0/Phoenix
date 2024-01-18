// Waifus Archive Program
#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
string iD,fina,lana,code,op;
ofstream DB;
int i;
bool rain_has_run = false;
bool ID_is_given = false;
bool isFound = false;
// Title function
void rain()
{
    cout << "\t\t\t\t==================================================================\n"
         << "\t\t\t\t||                                                              ||\n"
         << "\t\t\t\t||                    WAIFUS ARCHIVE PROGRAM                    ||\n"
         << "\t\t\t\t||                                                              ||\n"
         << "\t\t\t\t==================================================================\n";
}
// Password fuction
void ID()
{
    if (!rain_has_run)
    {
        rain();
        rain_has_run = false;
    }
    cout << "Enter your ID : " << endl;
    cin >> iD;
    if (iD == "0000")
    {
        cout << "Yeah Boy!" << endl;
        Sleep(700);
        system("cls");
    }
    else
    {
        cout << "Wrong! try again" << endl;
        Sleep(1000);
        system("cls");
        ID();
    }
}

class Waifu
{
public:
    string name,code;
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
    system("cls");
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
    if (op != "A","B","C","D","E","F" || cin.fail()){stop();}
}
    // search operation
void searching(){
    system("cls");
    cout << "Enter something to search : ";
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
    else if(iD =="no")
    {
        
        main();
    }
}
    // accessing operation
void accessing(){
    system("cls");
    Waifu waifu1;
    waifu1.name = "Zero Two";
    waifu1.code = "002";
    waifu1.height = 1.70;
    waifu1.weight = 52.4;
    waifu1.BMI = waifu1.weight / (waifu1.height * waifu1.height);

    Waifu waifu2;
    waifu2.name = "Sakurajima Mai";
    waifu2.code = "005";
    waifu2.height = 1.67;
    waifu2.weight = 49;
    waifu2.BMI = waifu2.weight / (waifu2.height * waifu2.height);

    Waifu waifu3;
    waifu3.name = "Nakano Miku";
    waifu3.code = "008";
    waifu3.height = 1.59;
    waifu3.weight = 49;
    waifu3.BMI = waifu3.weight / (waifu3.height * waifu3.height);

    for (int i = 0 ; i < Waifus.size(); i++)
    {
        cout << i << ".) " << Waifus[i] << endl;
    }
    cout << "choose a waifu to access by list number : ";
    cin >> i;
    if(i >= Waifus.size()){cout << "waifu not found\n"; goto somethingnew;}
    if (i == 0)
    {
        cout << "name : " << waifu1.name << endl;
        cout << "height : " << waifu1.height << "m" << endl;
        cout << "weight : " << waifu1.weight << "kg" << endl;
        cout << "BMI : " << waifu1.BMI << endl;
    }
    if (i == 1)
    {
        cout << "name : " << waifu2.name << endl;
        cout << "height : " << waifu2.height << "m" << endl;
        cout << "weight : " << waifu2.weight << "kg" << endl;
        cout << "BMI : " << waifu2.BMI << endl;
    }
    if (i == 2)
    {
        cout << "name : " << waifu3.name << endl;
        cout << "height : " << waifu3.height << "m" << endl;
        cout << "weight : " << waifu3.weight << "kg" << endl;
        cout << "BMI : " << waifu3.BMI << endl;
    }
    somethingnew:;
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
void adding(){
    system("cls");
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
    for (int i = 0 ; i < Waifus.size(); i++)
    {
        cout << i << ".) " << Waifus[i] << endl;
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
    //deleting operation
void deleting(){
    system("cls");
    for (int i = 0 ; i < Waifus.size(); i++)
    {
        cout << i << ".) " << Waifus[i] << endl;
    }
    cout << "choose a waifu to delete by list number: ";
    cin >> i;
    if(i >= Waifus.size()){cout << "waifu not found\n"; goto something;}
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
void editing(){
    system("cls");
    for (int i = 0 ; i < Waifus.size(); i++)
    {
        cout << i << ".) " << Waifus[i] << endl;
    }
    cout << "choose a waifu to edit by list number: ";
    cin >> i;
    if(i >= Waifus.size()){cout << "waifu not found\n"; goto somethingelse;}
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
    system("cls");
    cout << "Bye see you later\n";
}
void stop()
{
    system("cls");
    cout << "Come on dude, enter the correct input, try again\n";
    Sleep(2500);
    main();
    DB.close();
}