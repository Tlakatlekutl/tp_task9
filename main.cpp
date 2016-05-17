#include <iostream>

#include "TpSet.h"
#include <string>
using namespace std;

int main()
{
    try
    {
        TpSet<string> ts;
        ts.PushBack("aaa");
        ts.PushBack("bbb");
        ts.PushBack("bbb");
        ts.PushBack("ccc");

        TpSet<string> ots;
        ots.PushBack("dddd");
        ots.PushBack("eee");
        ots.PushBack("bbb");
        ots.PushBack("bbb");

        TpSet<string> result = ts + ots;
        cout << result;

        result = ts * ots;
        cout << result;
        result = ts - ots;
        cout << result;

        result = ts^ots;
        cout << result;
        result[3] = "runner";
        cout<<result;
        string a = result[1];
        cout<<a;

    }
    catch(...)
    {
        cout<<"Somthing was wrong!!!" << endl;
    }


    return 0;
}
