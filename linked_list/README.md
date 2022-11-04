
# Insert element into linked list


Adding elements to the linked list can be divided into the following three situations according to the location of the addition:

- Insert into the head of the linked list as the first node;
- Insert somewhere in the middle of the linked list
- Inserted at the end of the linked list as the last node of the linked list;

Steps:

1. Insert the next pointer of the new node into the position after the node
2. Point the next pointer of the node before the insertion position to the inserted node

![image](https://user-images.githubusercontent.com/48197340/199792774-e1638107-b839-4917-afc7-a14f3c599271.png)

No matter you are inserting at the head nodes or middle or tail nodes.


As can be seen from the figure, although **the insertion position of the new element is different**

The method of implementing the **insertion operation is the same**, that is, **step 1 is performed first, and then step 2 is performed.** 

The implementation code is as follows:

```c
void insertElem(Link*p, int element, int add)
{
  int i;
  Link* c = Null;
  Link* temp = p; // create temport node
  
  //First we have to find the node just before the node we going to insert @@
  for ( i = 0; i < add; i++)
  {
      temp = temp->next;
      if(temp == Null) {
      printf("Invalid inserting position");
      return;
      }
  }
  
  // Create a insert node C
  c = (Link*)malloc(sizeof(Link));
  c->element = element;
  // Step 1 Get the inserted node Next pointer point to the Next node (Look at graph if unsure)
  c->next = temp->next
  // Step 2, change the previous node next pointer, points to the new node.
  temp->next = c;
}

```

If let say there's no head node in the linked list.

![image](https://user-images.githubusercontent.com/48197340/199877700-5bd4a142-169d-41c1-a142-25d9101ffa1b.png)

1)set the inserted node point to the head node

2) Head pointer points to the current node

Important to take node that, since we are changing the value of head pointer struct, we have to return it for new value.

```c
Link* insertElemenet(Link*p, int element, int add)
{
  if(add = 1)
  { 
    Link*c = (Link*)malloc(sizeof(struct Link));
    c->element = element;
    c->next = p;
    // head pointer now point at our newly inserted head node.
    p = c;
    return p;
  }
  else
  {
    int i =;
    Link* temp = p;
    // as we do not have head node, therefore we have to - 1
    for (i=0; i < add - 1; i++)
    {
      temp = temp->next;
      if (temp == NULL)
        printf("invalid insertion");
    }
   Link*c = (Link*)malloc(sizeof(struct Link));
   c->element = element;
   c->next = temp->next;
   temp->next = c;
   return p;
  {
}
```

# Delete element in linked list

When deleting a specified data element from the linked list, it is actually removing the node containing the data element from the linked list.

  1. Find the previous node that we wanted to delete.
  
  2. Remove the node from the linked list
  
  3. Manually release the memory space occupied by the node
  
  ![image](https://user-images.githubusercontent.com/48197340/199889112-af0613d4-47b0-4898-9603-f449733e3f09.png)
  
`temp->next = temp->next->next;`

Actually code will be :

```c
int delElem(Link* p, int element)
{
  Link*del = NULL;
  *temp = p;
  int find = 0;
  // find the node before the deleted node.
  while(temp->){
    if (temp->next->element == element)
    {
      find = 1;
      break;
    }
    temp = temp->next;
    }
    if (find == 0）
      return -1; //delete failed
    else
    {
      del = temp->next;
      temp->next = temp->next->next;
      free(del);
      return 1;
    }
}
```
