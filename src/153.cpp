

#include<iostream>
#include<string>
#include<set>
#include<cstdio>
#include<vector>

using namespace std ;

class DATA
{
public:
	char alpha;
	int time ;	
	DATA(int a,int t):alpha(a),time(t){}
	
	bool operator<(const DATA &rhs) const
	{
		return alpha < rhs.alpha ;	
	}
};

set<DATA> myset ;
set<char> used1 ;

int gcd(int a,int b)
{
	while(b)
		b^=a^=b^=a%=b ;
	return a ;
}

int cal_tmp(int n,vector<int> d)
{
	int res=1 ;
	
	vector<int> dd,nn ;
	for(int i=0 ; i<d.size() ; ++i)
	{
		for(int j=2 ; j<=d[i] ; ++j)
		{
			dd.push_back(j)	;
		}
	}
	for(int i=2;i<=n;++i)
	{
		int ii=i ;
		for( int j=0 ; j<dd.size() && ii!=1 ;++j)	
		{
			int g=gcd(ii,dd[j]) ;
			if( g!=1 )
			{
				ii/=g ;
				dd[j]/=g ;	
			}
		}
		res*=ii ;
	}
	
	return res ;
}

void pre_cal(string &str)
{
	myset.clear() ;
	
	for(int i=0 ; i<str.length() ; ++i)	
	{
		if( str[i] >= 'a' && str[i] <= 'z' )
			str[i] = str[i] - 'a' + 'A' ;
		
		set<DATA>::iterator itor = myset.find( DATA(str[i],0) ) ;
		
		
		if( itor != myset.end() )
		{
			DATA tmp((*itor).alpha,(*itor).time+1) ;
			myset.erase(itor) ;
			myset.insert(tmp) ;
		}
		else
		{
			myset.insert( DATA(str[i],1) )	;
		}
	}
}

int cal_perm(string str)
{
	if( str == "" )
		return 0 ;

	int res = 0 ;
	
	pre_cal(str) ;

	used1.clear() ;
	for(int i=1 ; i<str.length() ; ++i)	
	{
		if( str[i] < str[0] && used1.find(str[i])==used1.end() )	
		{
			used1.insert(str[i]) ;
			
			vector<int> d ;
			
			for( set<DATA>::iterator itor=myset.begin() ;
			     itor!=myset.end() ; ++itor)
			{
				if( (*itor).alpha == str[i] )
				{
					d.push_back(  (*itor).time-1  ) ;
				}
				else
				{
					d.push_back( (*itor).time ) ;
				}
			}
			
			res += cal_tmp(str.length()-1,d) ;
		}
	}
	
	if( str.begin()+1 != str.end() )
	{
		res += cal_perm( string(str.begin()+1,str.end()) ) ;
	}
	
	return res ;
}

int main()
{
	for(;;)
	{
		string str  ;		
		cin >> str ;
		
		if( str == "#" )
			break ;
		
		printf("%10d\n", cal_perm(str)+1 ) ;
	}
	
	return 0 ;	
}
