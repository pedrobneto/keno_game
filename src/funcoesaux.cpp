#include "funcoesaux.h"
void quicksort( vector<int> & V, int left, int right ) {
	int i, j, x;
    i = left;
    j = right;
    x = V.at( ( left + right ) / 2 );

    while( i <= j ) {
        
        while( V.at( i ) < x && i < right )
            i++;
        
        while( V.at( j ) > x && j > left )
            j--;
        
        if( i <= j ) {
            
            std::swap( V.at( i ), V.at( j ) );
            i++;
            j--;
        }
    }
    
    if( j > left ) quicksort( V, left, j );
    
    if( i < right ) quicksort( V,  i, right );
}


bool No_Array( int candidato, vector<int>& Vector_atual ) {
    
	    for(auto i (0u) ; i < Vector_atual.size(); i++) {

        	    if(Vector_atual[i] == candidato)
            	    return true;
    	}
    	
    	return false;
}

int randomInt (int low, int high)
{ 
	return low + (rand() % high);
}
