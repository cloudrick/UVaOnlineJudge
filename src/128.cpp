
#include<cstdio>

using namespace std ;

int main()
{
	bool done = false ;
	for(; !done ;)
	{
		char c ;
		unsigned int crc = 0 ;

		for(;;)
		{
			c = getchar() ;

			if( c == '#' )
			{
				done = true ;
				break ;
			}

			if( c == '\n' )
				break ;

			crc <<= 8 ;
			crc+=c ;
			crc %= 34943 ;
		}
		
		if( !done )
		{
			crc=(crc<<16)%34943;
      			if (crc!=0 )
				crc=34943-crc; 
			printf("%02X %02X\n", crc/256 , crc%256 ) ;
		}
	}

	return 0 ;
}
