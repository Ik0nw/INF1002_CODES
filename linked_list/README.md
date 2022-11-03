
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
