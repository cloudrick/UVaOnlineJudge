
#include<iostream>

using namespace std ;

int main()
{
	int number_of_marbles[10050] ;
	int number_of_children[10050];
	int parent_of_nodes[10050] ;
	
	while(true)
	{
		int n ; 
		cin >> n ;

		if(n==0)
			break ;

		int v,m,d ;

		for( int t=0 ; t<10050 ; t++)
		{
			number_of_marbles[t] = 0 ;
			number_of_children[t] = 0 ;
			parent_of_nodes[t] = 0 ;
		}

		for( int i=1 ; i<=n ; i++)
		{
			cin >> v >> m >> d ;
			
			number_of_marbles[v] = m ;
			number_of_children[v] = d ;

			for( int j=1 ; j<=d ; j++)
			{
				int di ;
				cin >> di ;
				parent_of_nodes[di] = v ;
			}
		}

		int step = 0 ;
		int killchild = 0 ;

		while( killchild != n )
		{
			for( int k=1 ; k<=n ; k++)
			{
				if(number_of_children[k]==0)
				{
					if(number_of_marbles[k]!=1)
					{
						step += abs(number_of_marbles[k]-1) ;
						number_of_marbles[parent_of_nodes[k]] += (number_of_marbles[k]-1) ;
						number_of_marbles[k] = 1 ;	
					}
					number_of_children[parent_of_nodes[k]]-- ;
					number_of_children[k]=-1 ;
					killchild++ ;
				}
			}
		}

		cout << step << endl ;
	}

	return 0 ;
}
