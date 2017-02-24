
#include<iostream>
#include<string>
#include<set>
#include<map>

using namespace std ;

class expression
{
public :
	string p1 ;
	char op ;
	string p2 ;
} ;

inline bool isNumber(string &str)
{
	for( int i=0 ; i<str.size() ; ++i)
	{
		if( str[i]<'0' || str[i] >'9')
			return false ;
	}
	return true ;
}

void PrintExpression(map<string,expression> &var,
					 string                  key,
					 bool                    brackets )
{

	if(brackets)
		cout << '(' ;

	map<string,expression>::iterator pos ;
	map<string,expression>::iterator pos_left ;
	map<string,expression>::iterator pos_right ;

	pos = var.find(key) ;
	pos_left  = var.end() ;
	pos_right = var.end() ;

	if( isNumber( pos->second.p1 ) )
	{
		cout << pos->second.p1 ;
	}
	else
	{
		pos_left = var.find( pos->second.p1 ) ;
		if( pos_left->second.op == '+' && pos->second.op == '*' )
		{
			PrintExpression(var,pos->second.p1,true) ;
		}
		else
		{
			PrintExpression(var,pos->second.p1,false) ;
		}
	}

	cout << pos->second.op ;

	if( isNumber( pos->second.p2 ) )
	{
		cout << pos->second.p2 ;
	}
	else
	{
		pos_right = var.find( pos->second.p2 ) ;
		if( pos_right->second.op == '*' && pos->second.op == '+' )
		{
			PrintExpression(var,pos->second.p2,false) ;
		}
		else
		{
			PrintExpression(var,pos->second.p2,true) ;
		}
	}

	if(brackets)
		cout << ')' ;

}

int main()
{
	int T ;
	cin >> T ;

	for( int t=1 ; t<=T ; ++t)
	{
		int N ;
		cin >> N ;

		map<string,expression> var ;
		set<string> notRoot ;

		for( int n=1 ; n<=N ; ++n)
		{
			string v ;
			string assign ;
			expression exp ;
			cin >> v >> assign >> exp.p1 >> exp.op >> exp.p2 ;

			pair<string,expression> p ;
			p.first = v ;
			p.second = exp ;

			if( !isNumber(exp.p1) )
				notRoot.insert(exp.p1) ;

			if( !isNumber(exp.p2) )
				notRoot.insert(exp.p2) ;

			var.insert(p) ;
		}

		string root ;

		for( map<string,expression>::iterator i=var.begin() ;
		     i!=var.end() ; ++i)
		{
			if( notRoot.find( i->first ) == notRoot.end() )
			{
				root = i->first ;
				break ;
			}
		}

		cout << "Expression #" << t << ": " ;
		PrintExpression(var,root,false) ;
		cout << endl ;
		
	}

	return 0 ;
}
