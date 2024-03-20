#ifndef HANGMAN_STATESQUEUE_H
#define HANGMAN_STATESQUEUE_H

#include <iostream>
#include <memory>

template <class Type>
struct Node{
    Node(Type v):value(v),next(nullptr){} //constructor
    Type value;
    Node<Type>* next;
};


using namespace std;

template <class Type>
class StateQueue {
private:
    Node<Type> *tail;
    Node<Type> *head;
    Node<Type> *next;
    int cnt;

public:
    //Constructor
    StateQueue() {
        tail = nullptr;
        head = nullptr;
        cnt = 0;
    }

    ~StateQueue() {
        clear();
    };

    void enqueue(Type item)
    {
        auto p = new Node<Type>(item);
        if( this->is_empty() )
        {
            tail = p;
            head = p;
        }
        else
        {
            tail->next =p;
            tail =p;
        }
        cnt++;
    }

    void dequeue()
    {
        if( this->is_empty() )
        {
            //throw runtime_error("Empty Queue. Can not remove elements.\n");
            printf("Empty Queue. Can not remove elements.\n");
        }
        else
        {
            auto temp = head;
            head = head->next;
            delete temp;
            cnt--;
            if(head == nullptr)
                tail = nullptr;
        }
    }

    bool is_empty(){
        return (head == nullptr and tail == nullptr);
    }

    void clear()
    {
        cnt =0;
        auto temp=head;
        while(head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    friend ostream &operator<<(ostream &out, const StateQueue<Type> &q)
    {
        auto temp = q.head;
        out << temp->value;
        if (temp->next) {
            out << " ";
            temp = temp->next;
        }
        return out;
    }
};
#endif //HANGMAN_STATESQUEUE_H
