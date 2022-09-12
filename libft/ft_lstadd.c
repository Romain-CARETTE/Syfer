
#include "libft.h"

//  -
//
void	ft_lstadd( t_list **alst, t_list *new )
{
	assert( new != NULL );
	if ( *alst == NULL )
	{
		*alst = new;
		return ;
	}
	new->next = *alst;
	(*alst)->prev = new;
	*alst = new;
}
