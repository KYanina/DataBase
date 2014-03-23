#include <iostream>
#include <cstring>
#include <fstream>
#include "funs.h"
#include <iomanip>
using namespace std;
const int n = 21;


using namespace std;;
void vvod (storage*a)
{
    ifstream fin ("Database.txt");

    for (int i=0; i<n-1; i++)
    {
        fin >> a[i].goods;
        fin >> a[i].num;
        fin >> a[i].us;
        fin >> a[i].dat;
    }
}
void output (storage*a)
{
    cout << left << setw (12) << "Goods" << setw(9) << "Number" << setw(18) << "Used per mounth" << setw(7) <<
         "Date of coming" << endl;
    cout<<endl;
    for (int i=0; i<n-1; i++)
    {
        cout << left << setw (14) << a[i].goods;
        cout << setw (15) << a[i].num;
        cout << setw (8) << a[i].us;
        cout << setw (7) << a[i].dat;
        cout << endl;
    }
    cout << endl;

}
void vivod (storage*a, int i)
{
    cout << left << setw (12) << a[i].goods;
    cout << setw (9) << a[i].num;
    cout << setw (16) << a[i].us;
    cout << setw (7) << a[i].dat;
    cout << endl;
}
void swaping (storage*a, int b, int c)
{
    a[20]=a[b];
    a[b]=a[c];
    a[c]=a[20];
}
int cmpdate(char *x, char *y)
{
    for(int i=6; i<10; i++)
        if (x[i]!=y[i])
        {
            if(x[i]<y[i]) return 1;
            if(x[i]>y[i]) return 2;
        }
    for(int i=3; i<5; i++)
        if (x[i]!=y[i])
        {
            if(x[i]<y[i]) return 1;
            if(x[i]>y[i]) return 2;
        }
    for(int i=0; i<2; i++)
        if (x[i]!=y[i])
        {
            if(x[i]<y[i]) return 1;
            if(x[i]>y[i]) return 2;
        }
}
void sorting (storage*a, int b, int c, int x) //Сортировка для структуры, где значения не Int
{
    int s, r, l;
    s=b;
    r=c;
    if(x==2)
    {
        l=a[(b+c)/2].num;

        do
        {
            while (a[s].num<l)
                s++;
            while (a[r].num>l)
                r--;
            if(s<= r)
            {
                swaping(a,s,r);
                s++;
                r--;
            }

        }
        while (s<=r);
        if (s<c)
            sorting(a,s,c,2);
        if (b<r)
            sorting(a,b,r,2);
    }

    else
    {
        l=a[(b+c)/2].us;

        do
        {
            while (a[s].us<l)
                s++;
            while (a[r].us>l)
                r--;
            if(s<= r)
            {
                swaping(a,s,r);
                s++;
                r--;
            }

        }
        while (s<=r);
        if (s<c)
            sorting(a,s,c,3);
        if (b<r)
            sorting(a,b,r,3);
    }
}
void sortingchar(storage*a, int b, int c, int x)
{
    int s, r;
    char l[20]= {0};
    s=b;
    r=c;
    if(x==1)
    {
        strcpy(l,a[(b+c)/2].goods);
        do
        {
            while (strcmp(a[s].goods,l)<0) //(a[s].goods<l)
                s++;
            while (strcmp(a[r].goods,l)>0) //(a[r].num>l)
                r--;
            if(s<= r)
            {
                swaping(a,s,r);
                s++;
                r--;
            }

        }
        while (s<=r);
        if (s<c)
            sortingchar(a,s,c,1);
        if (b<r)
            sortingchar(a,b,r,1);
    }



    else
    {
        int s, r;
        char l[20]= {0};
        s=b;
        r=c;
        strcpy(l,a[(b+c)/2].dat);
        do
        {
            while (cmpdate(a[s].dat,l)==1)
                s++;
            while (cmpdate(a[r].dat,l)==2)
                r--;
            if(s<=r)
            {
                swaping(a,s,r);
                s++;
                r--;
            }

        }
        while (s<=r);
        if (s<c)
            sortingchar(a,s,c,4);
        if (b<r)
            sortingchar(a,b,r,4);
    }
}
void sortnum(storage*a)
{
    cout << "Sort by number of goods" << endl;
    cout << left << setw (12) << "Goods" << setw(9) << "Number" << setw(16) << "Used" << setw(7) <<
         "Date" << setw(5) << endl;
    sorting(a,0,n,2);
    cout<< endl;
}
void sortus(storage*a)
{
    cout << "Sort by using per week" << endl;
    cout << left << setw (12) << "Goods" << setw(9) << "Number" << setw(16) << "Used" << setw(7) <<
         "Date" << setw(5) << endl;
    sorting(a,0,n,3);
    cout<< endl;
}
void sortgoods(storage*a)
{
    cout << "Sort by goods' names" << endl;
    cout << left << setw (12) << "Goods" << setw(9) << "Number" << setw(16) << "Used" << setw(7) <<
         "Date" << setw(5) << endl;
    sortingchar(a,0,n,1);
    cout<< endl;
}
void sortdat(storage*a)
{
    cout << "Sort by Date" << endl;
    cout << left << setw (12) << "Goods" << setw(9) << "Number" << setw(16) << "Used" << setw(7) <<"Date" << setw(5) << endl;
    sortingchar(a,0,n,4);
    cout<< endl;
}


