
#include<iostream>
#include<string>

using namespace std ;

class tree
{
public :
	tree *left ;
	tree *right ;
	char root ;
public :
	tree():left(NULL),right(NULL),root(0) {}
	~tree() ;
	void transf(string&,string) ;
	void post_walk() ;
} ;

tree::~tree()
{
	delete left ;
	delete right ;
}

void tree::post_walk()
{
	if(left!=NULL)
		left->post_walk() ;
	if(right!=NULL)
		right->post_walk() ;
	cout << root ;
}

int find_char_in_infix(string s,char c)
{
	int i ;
	for( i=0 ; i<s.length() ; i++)
	{
		if( s[i] == c )
			return i ;
	}
	return -1 ;
}

void tree::transf(string &pre,string in)
{
	if(in=="")
	{
		return ;
	}

	root = pre[0] ;

	pre = string( pre.begin()+1 , pre.end() ) ;

	int i = find_char_in_infix(in,root) ;

	if( string(in.begin(),in.begin()+i) != "" )
	{
		left = new tree() ;
		left->transf( pre , 
		              string(in.begin(),in.begin()+i) ) ;
	}

	if( string(in.begin()+i+1,in.end()) != "" )
	{
		right = new tree() ;
		right->transf( pre ,
		               string(in.begin()+i+1,in.end()) ) ;
	}

}


int main()
{
	int C ;
	cin >> C ;

	while(C--)
	{
		string pre,in ;
		int n ;
		cin >> n >> pre >> in ;

		tree t ;

		t.transf(pre,in) ;

		t.post_walk() ;

		cout << endl ;

	}
	return 0 ;
}