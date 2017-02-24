
#include<iostream>

using namespace std ;

class BinaryTree
{
private :
	struct btnode 
	{
		int key ;
		btnode *left ;
		btnode *right ;
	};	
	
	void DeleteSubTree(btnode *r)
	{
		if( r != NULL )
		{
			if( r->left != NULL )
			{
				DeleteSubTree(r->left) ;
				delete r->left ;
			}
			if( r->right != NULL)
			{
				DeleteSubTree(r->right) ;
				delete r->right ;
			}
		}
	}

	btnode *root ;

public :
	BinaryTree()
	{
		root = NULL ;
	}

	int Insert(int k)
	{
		if( root == NULL )
		{
			root = new btnode ;
			root->key = k ;
			root->left = NULL ;
			root->right = NULL ;
			return 0 ;
		}
		else
		{
			btnode *p = root ;
			bool done = false ;
			int time=0 ;

			while(!done)
			{
				if( k>= p->key)
				{
					if( p->right == NULL )
					{
						btnode *new_node = new btnode ;
						new_node->left = NULL ;
						new_node->right = NULL ;
						new_node->key = k ;
						p->right = new_node ;
						done = true ;
					}
					else
					{
						p = p->right ;
					}
				}
				else
				{
					if( p->left == NULL )
					{
						btnode *new_node = new btnode ;
						new_node->left = NULL ;
						new_node->right = NULL ;
						new_node->key = k ;
						p->left = new_node ;
						done = true ;
					}
					else
					{
						p = p->left ;
						
					}
					time++ ;
				}
			}
			return time ;
		}
	}



	~BinaryTree()
	{
		DeleteSubTree(root) ;
	}
};

int main()
{
	for(;;)
	{
		int n ;
		cin >> n ;

		if( n==0 )
			break ;

//		int a[500010] ;
//		int size = 0 ;
		int time = 0 ;

		BinaryTree bt ;
		
		for( int i=0 ; i<n ; ++i)
		{
			int key ;
			cin >> key ;

			time += bt.Insert(key) ;

		}

		cout << time << endl ;

	}

	return 0 ;
}