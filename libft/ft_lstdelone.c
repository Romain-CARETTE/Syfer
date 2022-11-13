#include "libft.h"

void	ft_lstdelone(t_list **alst, t_list *block, void (*del)(void *, size_t))
{
    assert( *alst != NULL );

    t_list	*tmp = 0X00, *prev = 0X00;
    if ( *alst == block )
    {
	    tmp = *alst;
	    if ( (*alst)->next )
		*alst = (*alst)->next;
        	(del != NULL) ? del( tmp->content, tmp->content_size ) : free( tmp->content );
        	free( tmp );
		return ;
    }
    tmp = *alst;
    while ( tmp )
    {
	    if ( tmp == block )
	    {
		if ( tmp->next )
		{
			prev->next = tmp->next;
			tmp->next->prev = prev;
		}
		else
			prev->next = 0X00;
        	(del != NULL) ? del( tmp->content, tmp->content_size ) : free( tmp->content );
        	free( tmp );
		return ;
	    }
	    prev = tmp;
	    tmp = tmp->next;
    }
}
