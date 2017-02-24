
#include <set>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

void ToLower(string &str)
{
    for(int i=0;i<str.length();++i)
    {
		str[i] |= 32 ;
    }
}

int main()
{
    set<string> Dic;
    
	string temp;

    while(true)
    {
        char k = cin.get();

        if (cin.eof())
            break;

        if (!isalpha(k))                   
        {
			if( temp != "" )
			{
				ToLower(temp);
				Dic.insert(temp);
				temp = "" ;
			}
        }
        else
            temp+=k;
    }

	copy(Dic.begin(),Dic.end(), ostream_iterator<string>(cout,"\n")) ;

    return 0 ;
}
