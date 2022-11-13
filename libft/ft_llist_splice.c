#include "libft.h"

void ft_llist_splice( t_list **alst, t_list *llist_s1, t_list *llist_s2 ) {

	t_list	*last = llist_s2;
	while ( last->next )
		last = last->next;
	if ( llist_s1 == *alst )
	{
		last->next = *alst;
		(*alst)->prev = last;
		*alst = llist_s2;
		return ;
	}

	if ( llist_s1->next )
	{
		last->next = llist_s1->next;
		llist_s1->next->prev = last;
	}
	llist_s1->next = llist_s2;
	llist_s2->prev = llist_s1;

}
