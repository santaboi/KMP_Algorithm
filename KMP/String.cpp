#include "String.h"
#include<iostream>


//**************************by KMP algorithm**********************
void String::fail() //failure function
{   
    unsigned lengthP=len();
    f=new int[lengthP];//dont forget to save some storage space!!!!!!!
    *f=(-1);    //f[0]=-1;
    for(unsigned j=1;j<lengthP;j++)
    {
        int i=*(f+j-1);    //int i=f[j-1];
        while((*(data+j)!=*(data+i+1))&&(i>=0)) {i=*(f+i);}   //i=f[i];
        if(*(data+j)==*(data+i+1))  *(f+j)=i+1;//f[j]=i+1;
        else *(f+j)=-1;   //f[j]=-1;
    }

}

int String::fastfind(String pat)  
{
    pat.fail();

    int posP=0,posS=0;
    unsigned lengthP=pat.len(),lengthS=len();
    /********************************************
    ********lengthP,lengthS,data,pat.data,f值正常************************/
    while((posP<lengthP)&&(posS<lengthS))
    {
        if(pat.data[posP]==data[posS])
        {posP++,posS++;}
        else if(posP==0)posS++;
        else posP=pat.f[posP-1]+1;  
    }
    if(posP<lengthP)return-1;
    else return posS-lengthP; 
}

void String::print_fail()
{   
    for (int i = 0; i <len(); i++)
    {
        std::cout<<*(f+i);
    }
}

int String::get_f(int i)
{
    if (i<length)
    {
        return *(f+i);
    }
    else
    {   std::cout<<"out of bounds!*******error********";
        return -1;}
}
//****************************************************************


String::String () 
{
    length = 0;
    data   = new char[0];
}

String::String (char c) 
{
    length = 1;
    data   = new char(c);
}

String::String (const char* c) 
{
    if (c) 
    {
        unsigned n = 0;
        while (c[n] != '\0') n++;
        length = n;
        data   = new char[n];
        for (unsigned j=0; j < n; j++)
            data[j] = c[j];
    } else 
    {
        length = 0;
        data   = new char[0];
    }
}

String::String (const String& s) 
{
    length = s.len();
    data   = new char[length];
    for (unsigned j=0; j < length; j++)
        data[j] = s[j];
}



String::~String ( ) 
{
    delete[] data;
}

unsigned String::len ( ) const 
{
    return length;
}

int String::index (char c) const 
{
    for (unsigned j=0; j < length; j++)
        if (data[j] == c) return (int)j;
    return -1;
}



void String::upcase (unsigned first, unsigned last) 
{
    if ((first >= last) || (last > length)) throw 1;

    for (unsigned j=first; j < last; j++)
        if ('a' <= data[j] && data[j] <= 'z')
            data[j] -= ('a' - 'A');
}

void String::downcase (unsigned first, unsigned last) 
{
    if ((first >= last) || (last > length)) throw 1;

    for (unsigned j=first; j < last; j++)
        if ('A' <= data[j] && data[j] <= 'Z')
            data[j] += ('a' - 'A');
}

void String::togglecase (unsigned first, unsigned last) 
{
    if ((first >= last) || (last > length)) throw 1;

    for (unsigned j=first; j < last; j++)
        if ('A' <= data[j] && data[j] <= 'Z')
            data[j] += ('a' - 'A');
        else if ('a' <= data[j] && data[j] <= 'z')
            data[j] -= ('a' - 'A');
}



std::ostream& operator<< (std::ostream& os, const String& s) 
{
    if (s.len() > 0) 
    {
        for (unsigned j=0; j < s.len(); j++)
            os << s[j];
    } else os << "";

    return os;
}

std::istream& operator>> (std::istream& is, String& s) 
{
    char* c = new char[1000];
    is >> c;
    s = String(c);
    delete[] c;
    
    return is;
}



char String::operator[] (unsigned j) const 
{
    if (j >= length) throw 1;
    return data[j];
}

char& String::operator[] (unsigned j) 
{
    if (j >= length) throw 1;
    return data[j];
}



String& String::operator= (const String& s) 
{
    if(this == &s) return *this;

    delete data;
    length = s.len();
    data   = new char[length];
    for (unsigned j=0; j < length; j++)
        data[j] = s[j];
    return *this;
}



String& String::operator+= (const String& s) 
{
    unsigned len = length + s.len();
    char*    str = new char[len];

    for (unsigned j=0; j < length; j++)
        str[j] = data[j];

    for (unsigned i=0; i < s.len(); i++)
        str[length+i] = s[i];

    delete data;
    length = len;
    data   = str;
    return *this;    
}



String operator+ (const String& lhs, const String& rhs) 
{
    return String(lhs) += rhs;
}

String operator+ (const String& lhs, char rhs) 
{
    return String(lhs) += String(rhs);
}

String operator+ (const String& lhs, const char* rhs) 
{
    return String(lhs) += String(rhs);
}

String operator+ (char lhs, const String& rhs) 
{
    return String(lhs) += rhs;
}
String operator+ (const char* lhs, const String& rhs) 
{
    return String(lhs) += rhs;
}



bool operator== (const String& lhs, const String& rhs) 
{
    if (lhs.len() != rhs.len()) return false;

    unsigned cap = lhs.len();
    unsigned   n = 0;
    while ((n < cap) && (lhs[n] == rhs[n])) n++;
    return (n == cap);
}

bool operator== (const String& lhs, char rhs) 
{
    return (lhs == String(rhs));
}

bool operator== (const String& lhs, const char* rhs) 
{
    return (lhs == String(rhs));
}

bool operator== (char lhs, const String& rhs) 
{
    return (String(lhs) == rhs);
}

bool operator== (const char* lhs, const String& rhs) 
{
    return (String(lhs) == rhs);
}



bool operator> (const String& lhs, const String& rhs) 
{
    unsigned cap = (lhs.len() < rhs.len()) ? lhs.len() : rhs.len();
    unsigned n = 0;
    while ((n < cap) && (lhs[n] == rhs[n])) n++;
    if (n == cap) return (lhs.len() > rhs.len());

    if ( (('A'<=lhs[n]&&lhs[n]<='Z') || ('a'<=lhs[n]&&lhs[n]<='z')) &&
         (('A'<=rhs[n]&&rhs[n]<='Z') || ('a'<=rhs[n]&&rhs[n]<='z')) )
    {
        char A = (lhs[n] & ~32);
        char B = (rhs[n] & ~32);
        if (A != B) return (A > B);
    }
    return lhs[n] > rhs[n];
}

bool operator> (const String& lhs, char rhs) 
{
    return (lhs > String(rhs));
}

bool operator> (const String& lhs, const char* rhs) 
{
    return (lhs > String(rhs));
}

bool operator> (char lhs, const String& rhs) 
{
    return (String(lhs) > rhs);
}

bool operator> (const char* lhs, const String& rhs) 
{
    return (String(lhs) > rhs);
}



bool operator!= (const String& lhs, const String& rhs) 
{
    return !(lhs == rhs);
}

bool operator!= (const String& lhs, char rhs) 
{
    return !(lhs == rhs);
}

bool operator!= (const String& lhs, const char* rhs) 
{
    return !(lhs == rhs);
}

bool operator!= (char lhs, const String& rhs) 
{
    return !(lhs == rhs);
}

bool operator!= (const char* lhs, const String& rhs) 
{
    return !(lhs == rhs);
}



bool operator< (const String& lhs, const String& rhs) 
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const String& lhs, char rhs) 
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const String& lhs, const char* rhs) 
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (char lhs, const String& rhs) 
{
    return !(lhs == rhs) && !(lhs > rhs);
}

bool operator< (const char* lhs, const String& rhs) 
{
    return !(lhs == rhs) && !(lhs > rhs);
}



bool operator<= (const String& lhs, const String& rhs) 
{
    return !(lhs > rhs);
}

bool operator<= (const String& lhs, char rhs) 
{
    return !(lhs > rhs);
}

bool operator<= (const String& lhs, const char* rhs) 
{
    return !(lhs > rhs);
}

bool operator<= (char lhs, const String& rhs) 
{
    return !(lhs > rhs);
}

bool operator<= (const char* lhs, const String& rhs) 
{
    return !(lhs > rhs);
}



bool operator>= (const String& lhs, const String& rhs) 
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const String& lhs, char rhs) 
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const String& lhs, const char* rhs) 
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (char lhs, const String& rhs) 
{
    return (lhs == rhs) || (lhs > rhs);
}

bool operator>= (const char* lhs, const String& rhs) 
{
    return (lhs == rhs) || (lhs > rhs);
}




