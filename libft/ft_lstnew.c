#include "libft.h"

t_list	*ft_lstnew( void const *content, size_t content_size )
{
	t_list	*new;
	new = (t_list *)calloc( sizeof(char), sizeof(*new) );
	if ( new == NULL )
		return ( NULL );
	new->content = (void *)malloc(sizeof(void) * content_size );
	if (new->content == NULL)
	{
        	free( new );
		return (NULL);
    	}
	memcpy(new->content, content, content_size);
	new->content_size = content_size;
	return (new);
}
