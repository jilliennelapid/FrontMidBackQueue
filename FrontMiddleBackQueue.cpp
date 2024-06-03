// Linked list implementation of Queues
#include <iostream>
#include <cmath>

using namespace std;

class Node 
{
  public:
    int val;
    Node* next; 

    Node(int x)
    {
      val = x;
      next = NULL;
    }
};

class FrontMiddleBackQueue 
{
  public:
    Node *front, *back;
    int size;

    // Constructor that initializes nodes front and back as NULL,
    /// and the initial size of the list as 0.
    FrontMiddleBackQueue() 
    {
      front = NULL;
      back = NULL;
      size = 0;
    }

    // Pushes an element to the front of the list.
    void pushFront(int val) 
    {
      // Allocate a new node into memory.
      Node* newNode = new Node(val);

      // If list is empty, the singular element will be
      /// the front and the back node:
      if(size == 0)
      {
        back = newNode;
      }
      // else, the list has elements in it so the newNode
      /// can just point to the current front node:
      else
      {
        newNode->next = front;
      }

      // Set newNode as the front node.
      front = newNode;
      // Increase the size of the list.
      size++;
    }

    // Pushes into the middle of the current list.
    void pushMiddle(int val) 
    {
      Node* current = front;                // Give us access to the list.
      Node* temp;                           // Acts as temporary storage.
      Node * newNode = new Node(val);       // New node to be inserted.

      // If list is empty, the singular element will be
      /// the front and the back node:
      if(size == 0)
      {
        front = newNode;
        back = newNode;
      }
      // else, the list contains elements:
      else
      {
        // If there are an even number of elements in the list:
        if(size%2 == 0)
        {
          int iterate = (size/2);                // Initialize an iterating value.

          for(int i = 0; i < iterate; i++)       // for loop iterates to middle, which
          {                                      /// is between the two middle elements.
            temp = current;
            current = current->next;
          }

          temp->next = newNode;                  // Make the prior node to point to newNode,
          newNode->next = current;               // and newNode point to the following node.
        }
        // else, there is an odd number of elements in the list:
        else
        {
          int iterate = floor((size/2));         // Initialize an iterating value.

          for(int i = 0; i < iterate; i++)       // for loop iterates to middle, which
          {                                      // is to the left of the middle element.
            temp = current;
            current = current->next;
          }

          if(size == 1)                          // If there is only a single list element,
          {
            newNode->next = front;               // newNode points to the single element (front),
            front = newNode;                     // newNode becomes the new front node.
          }
          else                                   // else, there is more than one list element,
          {
            temp->next = newNode;                // so the previous node points to newNode,
            newNode->next = current;             // and newNode points to the following node.
          }
        }
      }

      // Increase the size of the list.
      size++;
    }

    // Pushes an element to the back of the list.
    void pushBack(int val) 
    {
      // Allocate a new node into memory.
      Node* newNode = new Node(val);

      // If list is empty, the singular element will be
      /// the front and the back node:
      if(size == 0)
      {
        
        front = newNode;          
      }
      // else, the list has elements in it, so the back
      /// node will point to newNode.
      else
      {
        back->next = newNode;
      }

      // newNode becomes the back node.
      back = newNode;
      // Increase the size of the list.
      size++;
    }

    // Remove the element in the front of the list.
    int popFront() 
    {
      // Gives us access to the list.
      Node* temp = front;

      // If the list is empty, returns -1.
      if(size == 0)
      {
        return -1;
      }

      // Sets front equal to the node after the front node.
      front = front->next;
      // Decreases the size of the list.
      size--;

      // Returns the value of the unlinked node.
      return temp->val;
    }

    // Removes an element from the middle of the list.
    int popMiddle() 
    {
      Node* current = front;            // Gives us access to the front of the list.
      Node* temp = current;             // Will store the node before current.
      Node* middle;                     // Acts as a temporary storage for the to-be removed node.

      // If the list is empty, returns -1. 
      if(size == 0)
      {
        return -1;
      }

      // If the list has an even number of elements:
      if(size%2 == 0)
      {
        int iterate = (size/2) - 1;              // Initializes an iterating variable.

        for(int i = 0; i < iterate; i++)         // for loop iterates to the middle of the list,
        {                                        /// which is between the two middle elements.
          temp = current;
          current = current->next;    
        }

        middle = current;                        // Stores the value of the node to be removed.

        temp->next = current->next;              // Unlinks the node between temp and current.

      }
      // else, the list has an odd amount of elements:
      else
      {
        int iterate = floor(size/2);             // Initialize an iterating variable.
  
        for(int i = 0; i < iterate; i++)         // for loop iterates to the middle of the list,
        {                                        /// which is one after the middle element.
          temp = current;
          current = current->next;
        }

        middle = current;                        // Stores the value of the node to be removed.

        temp->next = current->next;              // Unlinks the node between temp and current.
      }

      // Decreases the size of the list.
      size--;
      // Returns the value that was removed from the list.
      return middle->val;
    }

    // Removes an element from the back of the list.
    int popBack() 
    {
      Node* current = front;                // Gives us access to the list.
      Node* temp = back;                    // Temporarily stores the back node.

      // If the list is empty, returns -1.
      if(size == 0)
      {
        return -1;
      }

      // Iterates to the second to last node in the list
      for(int i = 1; i < size-1; i++)
      {
        current = current->next;
      }

      // Makes the node point to NULL rather than back.
      current->next = NULL;
      // then makes the node the new back node.
      back = current;

      // Decreases the size of the list.
      size--;

      // Returns the value that was removed from the list.
      return temp->val;
    }

    // Reverses the list calling reverse().
    void reverse() 
    {
      // If the list is empty, there is nothing to reverse.
      /// Exit the function by returning nothing.
      if(size == 0)
      {
        cout << "Empty List, cannot reverse." << endl;
        return;
      }

      Node* current = front;              // Gives us access to the list.
      Node* temp;                         // Acts as a temporary storage.

      for(int i = 0; i < size; i++)       // Iterates throught the whole list.
      {
        Node* to_delete = front;          // Stores the node that will be removed from the front.
        Node* newNode = new Node(0);      // Allocates a new node, stores a node and adds it to back.
        
        newNode->val = current->val;      // Makes the value of newNode equal to the current front node.
        back->next = newNode;             // Makes the current back node point to newNode.

        if(i == 0)                        // If the this the is the first iteration,
        {
          newNode->next = NULL;           /// make newNode point to NULL;
        }
        else                              // otherwise,
        {
          newNode->next = temp;           /// make newNode point to point to the previous "newNode"
        }
        
        temp = newNode;                   // Store newNode in temp. Each newNode will be inserted after back.
        
        current = current->next;          // Update current to the next node in the list.
        front = current;                  // Update the front node.
        current = front;

        delete to_delete;                 // Delete the node that was previously front.
      }

      // Iterates to the end of the reversed list.
      while(current->next != NULL)
      {
        current = current->next;
      }

      // Updates the last node in the list to be the new back node.
      back = current;
    }  
};


int main() 
{
  FrontMiddleBackQueue q;
  
  // Test case 1: Pushing elements to the front, middle, and back of the queue
  q.pushFront(1);     // 1
  q.pushMiddle(2);    // 2 1
  q.pushBack(3);      // 2 1 3
  q.pushMiddle(4);    // 2 4 1 3
  q.pushMiddle(5);    // 2 4 5 1 3
  q.pushFront(6);     // 6 2 4 5 1 3
  
  // Expected output: 6 2 4 5 1 3
  
  Node* temp = q.front;
  
  while(temp) 
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
  
  // Test case 2: Popping elements from the front, middle, and back of the queue
  cout << q.popFront() << endl; // Expected output: 6
  cout << q.popMiddle() << endl; // Expected output: 5
  cout << q.popBack() << endl; // Expected output: 3
  cout << q.popMiddle() << endl; // Expected output: 4
  
  // Expected output after popping: 2 1
  temp = q.front;
  
  while(temp) 
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  
  // Edge case: Popping elements from an empty queue
  FrontMiddleBackQueue q2;
  cout << q2.popFront() << endl; // Expected output: -1
  cout << q2.popMiddle() << endl; // Expected output: -1
  cout << q2.popBack() << endl; // Expected output: -1

  // Edge case: Popping elements from a queue of size 1
  FrontMiddleBackQueue q3;
  
  q3.pushFront(1);
  cout << q3.popFront() << endl; // Expected output: 1
  
  q3.pushFront(1);
  cout << q3.popMiddle() << endl; // Expected output: 1
  
  q3.pushFront(1);
  cout << q3.popBack() << endl; // Expected output: 1

  
  FrontMiddleBackQueue q4;
  
  // Test case 3: reversing the queue
  q4.pushFront(1);
  q4.pushFront(2);
  q4.pushFront(3);
  q4.pushFront(4);
  q4.reverse();
  
  temp = q4.front;
  
  while(temp) 
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  
  cout << endl;
  
  return 0;
  
}