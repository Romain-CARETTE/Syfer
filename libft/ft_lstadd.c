
#include "libft.h"

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

void	ft_push_back( t_list **alst, t_list *new ) {
	if ( *alst == NULL )
	{
		*alst = new;
		return ;
	}
	t_list *tmp = *alst;
	while ( tmp->next )
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}
