#include "libft.h"

t_list	*ft_lstiter(t_list *lst, uint8_t (*f)(t_list *elem)) {
	while (lst) {
		if ( f(lst) == 1 )
            return ( lst );
		lst = lst->next;
	}
    return ( NULL );
}
