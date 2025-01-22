// INSERTION IN LINKED LIST
// DELETION IN LINKED LIST 
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* ConvertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* insertNewHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertNewTail(Node* head, int val){
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* insertNewK(Node* head, int val, int k){
    if(head == NULL){
        if(k==1){
            return new Node(val);
        }
        else{
            return head;
        }
    }

    if(k == 1){
        Node* newNode = new Node(val, head);
        return newNode; 
    }

    int cnt = 0;
    Node* temp = head;

    while(temp != NULL){
        cnt++;
        if(cnt == (k-1)){
            Node* x = new Node(val);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next; 
    }
    return head;
}

Node* insertBeforeValue(Node* head, int val, int el){
    if(head == NULL){
       return NULL;
    }
    

    if(head->data == el){
        Node* newNode = new Node(val, head);
        return newNode; 
    }

    
    Node* temp = head;

    while(temp->next != NULL){
        
        if(temp->next->data == el){
            Node* x = new Node(val);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next; 
    }
    return head;
}
int main() {
    vector<int> arr = {32,5,8,7,9};
    Node* head = ConvertArr2LL(arr);

    // head = insertNewHead(head, 100);
    // cout<<endl;
    // head = insertNewTail(head, 100);
    // cout<<endl;
    // head = insertNewK(head, 100, 2);
    head = insertBeforeValue(head, 100, 8);
    print(head);    

    return 0;
} 