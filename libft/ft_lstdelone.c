#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    assert( *alst != NULL );
    assert( del != NULL );
    del((*alst)->content, (*alst)->content_size);
    free( *alst );
}
