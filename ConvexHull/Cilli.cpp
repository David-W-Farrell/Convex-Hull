// David Farrell 

#include "Cilli.h"

Cilli::Cilli(){

    handle = nullptr; //sets handle to nullptr

}

void Cilli::insertItem(int v){

    CNode* temp = nullptr;

    if(handle == nullptr){

        temp = new CNode(v);
        
        handle = temp; //sets handle to point to the address of temp

        handle->next = handle; //the following 2 lines points handle to itself
        
        handle->prev = handle;
        
        firstNode = handle; //sets the first pointer to handle

    }

    else if((handle->next == handle) && (handle->prev == handle)){

        temp = new CNode(v);
        
        handle->next = temp; // point handle->next to the memory location of temp
        
        temp->prev = handle; // points the previous pointer belonging to temp to handle
        
        temp->next = handle; // points the next pointer of temp to handle
        
        handle->prev = temp; // points previous pointer to the address of temp
        
        handle = temp; //points handle to temp, now temp is the new handle node


    }

    else{

        temp = new CNode(v);
    
        temp->prev = handle; //points the previous pointer of temp to the handle node

        handle->next->prev = temp; //points the next pointer of the handle node to temp

        temp->next = handle->next; //points the temp next pointer to the first node of the list
        
        handle->next = temp; //sets the prev pointer of the firstNode to temp
        
        handle = temp; // points handle to temp

        handle->val = handle->val;

    }

}

void Cilli::dumpForwards() const{

    CNode* temp = handle; // creates a temp node that points to handle

    temp = temp->next; //points temp to the next node of the list

//loops until temp reaches handle again and prints each nodes value 

    while(temp != handle){
        
        temp = temp->next;

    }

}

void Cilli::moveHandleForward(){

    //checks to make sure the list isnt empty, prints an error if it is and moves handle if not

    if(handle == nullptr || handle->next == nullptr || handle->prev == nullptr){

        cout << "ERROR: Empty list\n";

    }

    else{

        handle = handle->next; // moves the handle forwards a node 

    }

}

void Cilli::moveHandleBack(){

    //checks to make sure the list isnt empty, prints an error if it is and moves handle if not

    if(handle == nullptr || handle->next == nullptr || handle->prev == nullptr){

        cout << "ERROR: Empty list\n";

    }

    else{

        handle = handle->prev; //moves the handle pointer back a node 

    }

}

int Cilli::getValAtHandle() const{

    const int badReturnVal = -999;

    //prints an error if the list is empty

    if(handle == nullptr || handle->next == nullptr || handle->prev == nullptr){

        cout << "ERROR: Empty list\n";

        return badReturnVal; //error value to be returned

    }
    
    else{

        return handle->val; // returns the value at the handle node 

    }

}

void Cilli::deleteItem(){

    //prints an error if the list is empty

    if(handle == nullptr || handle->next == nullptr || handle->prev == nullptr){

        cout << "ERROR: Empty list\n";

    }

    else{

        //points the next pointer of the previous node to the next node from handle

        CNode* temp = handle; //points temp to the previous node 
       
        handle = temp->next; //points handle to temp->next which is the next node of the list 

        temp->next->prev = temp->prev; 
        temp->prev->next = temp->next;

        delete temp;

    }

}

Cilli::~Cilli(){

    CNode* temp = handle; // points temp to the memory location of handle

    CNode* delNode = nullptr;

    while (temp != nullptr){

        //if block that executes when it is not the last node of the list 

        if (temp->prev != nullptr){
        
            delNode = temp; //points delNode to the node at temp
            
            temp = temp->prev; // moves temp back a node
            
            delete delNode; //deletes the node 

            temp->next = nullptr;
            
            firstNode->prev = nullptr; // sets the back pointer of the first node in the list to nullptr

        }

        // else statement executes when it is the last node of the list
    
        else{

            delete temp; // deletes node 
            
            temp = nullptr;

        }

    }

}
