
#include<iostream>
#include<vector>
#include<set>

using namespace std ;

class Remainer
{
    public  :
        int index ;
        int cycle ;
        bool operator<(const Remainer &rhs) const
        {
            return cycle < rhs.cycle ;   
        }  
        Remainer(int n): cycle(n) {}
} ;

int main()
{
    for(;;)
    {
        int n,d ;
        cin >> n >> d ;
        
        if( cin.eof() )
            break ;
        
        vector<int> q ;
        vector<int> cycle ;
        
        set<Remainer> remain ;
        
        cout << n << '/' << d << " = " << n/d << '.' ;
        n%=d ;
        
        for( ;; )
        {
            set<Remainer>::iterator itor = remain.find( Remainer(n) ) ;
            if( itor != remain.end() )
            {
                Remainer r = (*itor) ;
                
                for(int i=0 ; i<r.index ; ++i)
                {
                    cout << q[i] ;   
                }
                cout << '(' ;
                
                for(int i=r.index ; i<cycle.size() ; ++i)
                {
                    if( i-r.index+1 > 50 )
                    {
                        cout << "..." ;
                        break ;
                    }
                    cout << q[i] ;   
                }
                cout << ')' << endl ;
                cout << "   " ;
                cout << cycle.size()-r.index << " = number of digits in repeating cycle" << endl ;
                cout << endl ;
                break ;
            }
            
            Remainer r( n ) ;
            r.index = cycle.size() ;
            remain.insert(r) ;
            
            cycle.push_back(n) ;            
            n*=10 ;
            q.push_back( n/d ) ;
            n%=d ;
        }
    }
 
    return 0 ;   
}
