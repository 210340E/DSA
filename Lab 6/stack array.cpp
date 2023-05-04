#include <iostream>


using namespace std;

class Stack {
    private:
        int size;
        int* elements;
        int top;

    public:
        Stack(int size) {
            this->size = size;
            top = -1;
            elements = new int[size];
        }

       //check whether stack is empty.
        bool isEmpty() {
            if (top<0){
                return true;
            }
            else{
                return false;
            }
        }

        bool isFull(){
            return top == size - 1;
        }

        void push(int value) {
            if (isFull()) {
                cout << "Stack overflow" << endl;
            } else {
                top++;
                elements[top] = value;
            }
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack underflow" << endl;
                return -1;
            } else {
                int value = elements[top];
                top--;
                return value;
            }
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
            } else {
                cout << "Stack:" << endl;
                for(int i = 0; i <=top; i++) {
                    cout << elements[i] << " ";
                }
            }
        cout << endl;
    }

     
};

int main() {
    int size;
    cout << "Enter the size : "<<endl;
    cin >> size;
    Stack s(size);
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(4);
    s.push(13);
    s.push(3);
    s.push(1);
    s.display();
    
    return 0;
}
