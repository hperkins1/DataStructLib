#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "CDA.cpp"

using namespace std;

/*
** There should be 3 print statements:
** Two that print length and capacity; the correct output is labeled by the lines that print them
**
** One that prints "It worked." or "It did not work."
** This statement tests the majority of the functions.
** For best results, comment out individual blocks of code to see which blocks are causing a failure
** Please note any errors.
**
** This test case uses strings. To convert to integers, change all the appropriate data types to integers,
** remove all quotes, and change the exclamation marks to negative signs. It will then function in the same way.
**
**                            ** Ensure that you have "infile.txt" in folder **
*/

int main()
{
    ifstream fil;

    fil.open("infile.txt");

    string v[20005];
    CDA<string> t;
    bool yes =  true;
    if(t.Length() != 0 || t.Capacity() != 1)
    {
        yes = false;
    }
    int count = 0;
    while(count < 20000)
    {
        string k;
        fil >> k;

        v[count] = k;
        t.AddFront(k);
        count++;
    }

    t.Reverse();
    t.AddFront("69");
    t.DelFront();
    t.AddEnd("69");
    t.DelEnd();
    t.Reverse();
    t.AddFront("7");
    v[20000] = "7";
    t.AddFront("-9");
    v[20001] = "-9";
    t.Reverse();
    t.AddEnd("384");
    v[20002] = "384";
    t.AddEnd("10000");
    v[20003] = "10000";
    t.AddEnd("!2934");
    v[20004] = "!2934";

    // Tests that the capacity and length changed appropriately
    cout << t.Capacity() << " " << t.Length() << endl;
    // 32768 20005

    for(int i = 0; i < 12005; i++)
    {
        t.DelEnd();
    }

    // Tests that the capacity and length changed appropriately
    cout << t.Capacity() << " " << t.Length() << endl;
    // 16384 8000

    for(int i = 0; i < 20005; i++)
    {
        t.AddEnd(v[i]);
    }


    t[-33] = "44444";
    t[103032] = "3532123";

    // Tests that the additions and deletions worked as predicted
    for(int i = 0; i < t.Length(); i++)
    {
        if(i > 7999)
        {
            if(t[i] != v[i - 8000])
            {
                yes = false;
            }
        }
        else
        {
            if(t[i] != v[i])
            {
                yes = false;
            }
        }
    }
    
    CDA<string> g(t);
    CDA<string> f(7);

    // Tests copy constructor
    for(int i = 0; i < t.Length(); i++)
    {
        if(i > 7999)
        {
            if(g[i] != v[i - 8000])
            {
                yes = false;
            }
        }
        else
        {
            if(g[i] != v[i])
            {
                yes = false;
            }
        }
    }
    
    // Tests constructor with size parameter
    if(f.Length() != 7 || f.Capacity() != 7)
    {
        yes = false;
    }
    
    f = t;

    t[15] = "1929482";

    // Tests copy constructor 
    for(int i = 0; i < t.Length(); i++)
    {
        if(i > 7999)
        {
            if(g[i] != v[i - 8000])
            {
                yes = false;
            }
        }
        else
        {
            if(g[i] != v[i])
            {
                yes = false;
            }
        }
    }
    
    // Tests copy assignment constructor
    for(int i = 0; i < t.Length(); i++)
    {
        if(i > 7999)
        {
            if(f[i] != v[i - 8000])
            {
                yes = false;
            }
        }
        else
        {
            if(f[i] != v[i])
            {
                yes = false;
            }
        }
    }
    
    // Tests search
    if(f.Search(v[15]) != 15)
    {
        yes = false;
    }
    
    // Tests search
    if(g.Search(v[15]) != 15)
    {
        yes = false;
    }
    
    // Tests select
    if(g.Select(1) != "!2934")
    {
        yes = false;
    }
    
    string selected = g.Select(4855);

    g.Sort();

    // Tests select and sort
    if(g[4854] != selected)
    {
        yes = false;
    }
    
    // Tests binary search, select, and sort
    int bsIndex = g.BinSearch(selected);
    if(g[bsIndex] != selected)
    {
        yes = false;
    }
    
    // Tests sort
    for(int i = 1; i < g.Length(); i++)
    {
        if(g[i] < g[i - 1])
        {
            yes = false;
            break;
        }
    }
    
    g.Clear();

    // Tests clear
    if(g.Capacity() != 4 || g.Length() != 0)
    {
        yes = false;
    }
    
    // Tests copy constructor
   for(int i = 0; i < t.Length(); i++)
    {
        if(i > 7999)
        {
            if(f[i] != v[i - 8000])
            {
                yes = false;
            }
        }
        else
        {
            if(f[i] != v[i])
            {
                yes = false;
            }
        }
    }
    
    CDA<int> *y = new CDA<int>(15);

    // Tests constructor with size parameter using pointers
    if((*y).Capacity() != 15 || (*y).Length() != 15)
    {
        yes = false;
    }

    // If no statement prints, this could be the issue: tests the destructor (hopefully)
    delete(y);
    
    if(yes)
    {
        cout << "It worked." << endl;
    }
    else
    {
        cout << "It did not work." << endl;
    }

    return 0;
}