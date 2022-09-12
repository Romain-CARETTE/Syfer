#include "libft.h"


uint8_t         detach_block( t_list **alst, t_list *block ) {

    uint8_t     res = 0X00;

    if ( memcmp( (*alst)->content, block->content, block->content_size ) == 0 )
    {
            if ( (*alst)->next != NULL ) {
                *alst = (*alst)->next;
                (*alst)->prev = NULL;
            }
            else
                *alst = 0x00;
            res |= 0X01;
            block->next = NULL;
            block->prev = NULL;
            return ( res );
    }
    t_list  *tmp = *alst;
    while( tmp )
    {
        if ( memcmp( tmp->content, block->content, block->content_size ) == 0 ) {
            if ( tmp->next != NULL ) {
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;
            }
            else
                tmp->prev->next = NULL;
            res |= 0X01;
            block->next = NULL;
            block->prev = NULL;
            return ( res );
        }
        tmp = tmp->next;
    }
    return ( res );
}



// []  [] [*]
