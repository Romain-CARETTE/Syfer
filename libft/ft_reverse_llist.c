# include "libft.h"
void reverse_llist( t_list *head )
{
  t_list *left = head;
  t_list *right = head;
 
  // Traverse the list and set right pointer to
  // end of list
  while (right->next != NULL) {
    right = right->next;
  }
 
  // Swap data of left and right pointer and move
  // them towards each other until they meet or
  // cross each other
  while (left != right && left->prev != right) {
 
    // Swap data of left and right pointer
    void *temp = left->content;
    left->content = right->content;
    right->content = temp;
 
    // Advance left pointer
    left = left->next;
 
    // Advance right pointer
    right = right->prev;
  }
}
