
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

class TURTLE
{
public:
	int weight ;
	int strength ;

	bool operator<(const TURTLE &lhs) const
	{
		return (strength < lhs.strength) || (strength == lhs.strength && weight < lhs.weight);
	}
} ;

int main()
{
	vector<TURTLE> turtle_stack ;

	for(;;)
	{
		TURTLE t ;
		cin >> t.weight >> t.strength ;

		if( cin.eof() )
			break ;
		
		if( t.strength < t.weight )
			continue ;

		turtle_stack.push_back(t) ;

	}

	sort( turtle_stack.begin() , turtle_stack.end() ) ;


	vector<int> height ;
	vector<int> total_weight ;
	int globol_max_height = 1 ;

	for( int i=0 ; i<turtle_stack.size() ; ++i )
	{
		height.push_back(1) ;
		total_weight.push_back( turtle_stack[i].weight ) ;

		for( int j=0 ; j<i ; ++j )
		{
			if( height[j]+1 > height[i] && total_weight[j] < turtle_stack[i].strength - turtle_stack[i].weight)
			{
				height[i] = height[j] + 1 ;
				total_weight[i] = turtle_stack[i].weight + total_weight[j] ;
			}
		}

		if( height[i] > globol_max_height )
		{
			globol_max_height = height[i] ;
		}
	}

	cout << globol_max_height << endl ;

	return 0 ;
}
