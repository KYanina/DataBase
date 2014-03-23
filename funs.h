#ifndef FUNS_H_INCLUDED
#define FUNS_H_INCLUDED

struct storage
{
    char goods[20];
    int num;
    int us;
    char dat[11];
};

struct storage;
void vvod (storage*a);
void output (storage*a);
void vivod (storage*a, int i);
void swaping (storage*a, int b, int c);
int cmpdate(char *x, char *y);
void sorting (storage*a, int b, int c, int x);
void sortingchar(storage*a, int b, int c, int x);
void sortnum(storage*a);
void sortus(storage*a);
void sortgoods(storage*a);
void sortdat(storage*a);




#endif // FUNS_H_INCLUDED
