
#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std ;

class Node
{
public :
	int num ;
	double len ;
	
	bool operator<(const Node &rhs) const
	{
		return len < rhs.len ;
	}
};

int main()
{
	for(;;)
	{
		double vt,v0 ;
		cin >> vt >> v0 ;
		
		if(vt==0 && v0 ==0)
			break ;

		multiset<Node> Con ;

		
		for(int p=1 ;  ; ++p)
		{	
			double s = vt/p-v0 ;

			if( s <= 0.00000000000001 )
				break ;

			double D ;
			D = p*0.3*sqrt(s) ;
		/*		
			cout << "p="  << p << endl ;
			cout << "D= " << D << endl ;
			cout << "s= " << s << endl ;
			cout << "Dp=" << D*p << endl << endl ;
*/
			Node node ;
			node.num = p ;
			node.len = D ;

			Con.insert(node) ;
		}

		if( Con.empty() )
		{
			cout << 0 << endl ;
			continue ;
		}

		double max_value = (*max_element( Con.begin() , Con.end() )).len ;
		int    max_num   = (*max_element( Con.begin() , Con.end() )).num ;

		Con.erase( max_element( Con.begin() , Con.end() ) ) ;

		if( Con.empty() )
		{
			cout << max_num << endl ;
			continue ;
		}

		double max_2_value = (*max_element( Con.begin() , Con.end() )).len ;

		if( fabs(max_value-max_2_value)<=0.000000001 )
			cout << 0 << endl ;
		else 
			cout << max_num << endl ;

	}
	return 0 ;
}
