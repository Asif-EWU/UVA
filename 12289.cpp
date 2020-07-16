#include<iostream>
using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

/*-------------------------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------*/


int main()
{
    int test, one, two;
    string str;

    fs(test);

    while(test--)
    {
        one=0, two=0;

        cin >> str;

        if(str.size()==5)
            printf("3\n");
        else
        {
            if(str[0]=='o')
                one++;
            if(str[0]=='t')
                two++;

            if(str[1]=='n')
                one++;
            if(str[1]=='w')
                two++;

            if(str[2]=='e')
                one++;
            if(str[2]=='o')
                two++;

            if(one>=two)
                printf("1\n");
            else
                printf("2\n");
        }
    }

    return 0;
}
