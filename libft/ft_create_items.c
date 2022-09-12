#include "libft.h"


ITEM	**ft_create_items( t_list *lst, ITEM **(*f)(t_list *)) {
	return f( lst );
}


WINDOW	*ft_create_win( int nlines, int ncols, int begin_y, int begin_x ) {
	return ( newwin( nlines, ncols, begin_y, begin_x ) );
}
