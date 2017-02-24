
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#include<string>

using namespace std ;

class OUTPUT
{
public :
    string key ;
    int line_num ;
    vector<string> buff ;
    bool operator<(const OUTPUT &rhs) const
    {
        return (key < rhs.key) || ( key==rhs.key && line_num<rhs.line_num) ;   
    }    
};

string ToUpper(string str)
{
    string res = str ;
    for(int i=0 ; i<res.size() ; ++i)
    {
        if( res[i] >= 'a' && res[i] <= 'z' )
            res[i] = res[i] - 'a' + 'A' ;
    }
    return res ;
}

string ToLower(string str)
{
    string res = str ;
    for(int i=0 ; i<res.size() ; ++i)
    {
        if( res[i] >= 'A' && res[i] <= 'Z' )
            res[i] = res[i] - 'A' + 'a' ;
    }
    return res ;
}

int main()
{
    set<string> igno ;

    for(;;)
    {
        string t ;
        cin >> t ;
        if( t == "::" )
            break ;
        igno.insert( ToUpper(t) ) ;   
    }
    
    multiset<OUTPUT> output ;
    
    for( int num=1 ; ; num++)
    {
        char tmp1[100],*tmp2 ;
        
        cin.getline(tmp1,99) ;
        
        if( strcmp(tmp1,"\n")==0)
            continue ;
        if( cin.eof() )
            break ;
        
        vector<string> line ;
        tmp2 = strtok( tmp1 , " \n") ;
        
        while( tmp2 != NULL )
        {
            line.push_back( ToLower(tmp2) ) ;
            tmp2 = strtok( NULL , " \n") ;   
        }
        
        for(int i=0 ; i<line.size() ; ++i)
        {
            if( igno.find( ToUpper(line[i]) ) == igno.end() )
            {
                OUTPUT tmp ;
                tmp.buff.assign( line.begin() , line.end() ) ;
                tmp.buff[i] = ToUpper( line[i] ) ;
                tmp.key = line[i] ;
                tmp.line_num = num ;
                output.insert(tmp) ;
            }      
        }
    }
    
    for( multiset<OUTPUT>::iterator i=output.begin() ; i!=output.end() ; ++i)
    {
        for( int j=0 ; j< (*i).buff.size() ; ++j)
        {
            if( j!=0)
                cout << ' ' ;
            cout << (*i).buff[j] ;  
        }   
        cout << endl ;
    }
    
    return 0 ;    
}
