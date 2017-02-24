
#include <iostream>
#include <vector>

using namespace std ;

int main()
{
	int n,m,t ;
	vector<int> train,tmp ;
	while(cin >> n){
		if(!n)
			break ;	
		while(cin >> m){
			if(!m)
				break ;
			train.push_back(m) ;
			if(train.size()==n){
				t = n ;
				while(1){
					if(!tmp.empty()){
						if(tmp[tmp.size()-1]==t){
							tmp.pop_back() ;
							t-- ;
							continue ;
						}
					}
					if(!train.empty()){
						tmp.push_back(train[train.size()-1]) ;
						train.pop_back() ;
						continue ;
					}
					if(t==0){
						cout << "Yes\n" ;
						train.clear() ;
						tmp.clear() ;
						break ;
					}
					else{
						cout << "No\n" ;
						train.clear() ;
						tmp.clear() ;
						break ;
					}
				}
			}
		}
		cout << endl ;
	}
	return 0 ;
}
