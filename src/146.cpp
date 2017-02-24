
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

int main()
{
	ostream_iterator<char> out_stream(cout) ;
	vector<char> ch(60) ;
	char tmp[60] ;
	int i ;

	while(1){
		cin >> tmp ;
		if(tmp[0]=='#')
			break ;
		ch.clear() ;
		for(i=0;tmp[i];i++)
			ch.push_back(tmp[i]) ;
		if(next_permutation(ch.begin(),ch.end()))
			copy(ch.begin(),ch.end(),out_stream) ;
		else
			cout << "No Successor" ;
		cout << endl ;
	}
	return 0 ;
}