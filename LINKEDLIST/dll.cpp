#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back; 

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArrToDLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp; 
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

Node* deleteHeadOfDLL(Node* head){
    
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    Node* prev = head; 
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev; 
    return head;
}

Node* deleteTailOfDLL(Node* head){

    if(head==NULL || head->next==NULL){
        return NULL;
    }

    Node* tail = head;
    
    while(tail->next != NULL){
       tail = tail->next;
    }

    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    
    delete tail;
    return head;

}

Node* deleteKelOfDLL(Node* head, int k){

    if(head==NULL){
        return NULL;
    }

    int cnt = 0;
    Node* temp = head;

    while(temp != NULL){
        cnt++;
        if(cnt == k) break;

        temp = temp->next;
    } 

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){
        // delete temp;
        return NULL;
    } 
    else if (prev == NULL)
    {
        delete deleteHeadOfDLL(head);
    }
    else if(front == NULL){
        delete deleteTailOfDLL(head);
    }
    
    prev->next = front;
    front->back = prev;
    
    temp -> next = nullptr;
    temp->back = nullptr;

    delete temp;
    return head;
}

void deleteNodeOfDLL(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back == nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->back = nullptr;
    temp->next = nullptr;

    delete temp;
    return ;
}

int main(){
   vector<int> arr = {21,11,3,12,5};
    Node* head = convertArrToDLL(arr);
    // head = deleteKelOfDLL(head , 1);
    deleteNodeOfDLL(head->next);
    print(head);
    // head = deleteHeadOfDLL(head);
    // print(head);
    // head = deleteTailOfDLL(head);
    // print(head);

    return 0;
}