#include "libft.h"

void	ft_lstdel( t_list **alst, void (*del)(void *, size_t) ) {
	while ( *alst )
	{
        	t_list *tmp = *alst;
        	*alst = (*alst)->next;
        	(del != NULL) ? del( tmp->content, tmp->content_size ) : free( tmp->content );
        	free( tmp );
	}
	*alst = NULL;
}
