
#include<iostream>
#include<stack>

using namespace std ;

int main()
{
    
    int n ;
    cin >> n ;
    
    for (int nn=1 ; nn<=n ; ++nn)
    {
        cout << "Case #" << nn << ": " ;
        
        int m ;
        cin >> m ;
        
        stack<int> s ;
        
        while( m!=0 )
        {
            if( m%2 == 0 )
            {
                s.push(0) ; 
                m /= (-2) ;  
            }   
            else
            {
                s.push(1) ;
                
                if( m>=0 )
                {
                    m /= (-2) ;   
                }  
                else
                {
                    m=(m-1)/ (-2) ;    
                }
            }
        }
        
        if( s.empty() )
            cout << 0 << endl ;
        else
        {
            while( !s.empty() )
            {
                int p = s.top() ;
                cout << p ;
                s.pop() ;   
            }   
            cout << endl ;
        }
        
    }
 
    return 0 ;   
}
