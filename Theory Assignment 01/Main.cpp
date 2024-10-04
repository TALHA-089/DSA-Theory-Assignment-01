#include "Stack.cpp"

void Menu(){

    cout << "\n----------- Main Menu -----------\n";
    cout << "\n1.Get the Smallest Value in Stack";
    cout << "\n2.Get Stack Size";
    cout << "\n3.Push to Stack";
    cout << "\n4.Pop from Stack";
    cout << "\n5.Next Greater Element Problem";
    cout << "\n6.Exit";
    cout << "\n\nEnter your Choice: ";
}

void GreaterNextElement(int array[], int size){

    Stack stack1 = Stack(size);
    int result[size];

    for (int i = size - 1; i >= 0; i--) {
        while (!stack1.isEmpty() && stack1.getMin() <= array[i]) {
            int temp;
            stack1.Pop(temp);
        }

        if (stack1.isEmpty()) {
            result[i] = -1;
        } else {
            result[i] = stack1.getMin();
        }

        stack1.Push(array[i]);
    }

    for (int i = 0; i < size; i++) {
        array[i] = result[i];
    }
}


int main(){
    int maxSize;
    cout << "\nEnter the Max Size for the Stack: ";
    cin >> maxSize;
    
    Stack stack = Stack(maxSize);
    
    while(true){
        int choice;
        Menu();
        cin >> choice;
        if(choice == 6){
            break;
        }else if(choice == 1){
            if(stack.isEmpty()){
                cout << "\nStack is Empty right now.\nPlease Push Something first\n";
            }else{
            cout << "\nMinimum value in the Current Stack is " << stack.getMin();
            }

        }else if(choice == 2){
        cout << "\nSize of the Current Stack is " << stack.Size();

        }else if(choice == 3){

            if(stack.isFull()){
                cout << "\nStack Overflow!\n";
                continue;
            }

            cout << "\n1.Push Multiple Numbers";
            cout << "\n2.Push One Number";
            cout << "\nEnter your Choice: ";
            cin >> choice;

            if(choice == 1){
            do{
                cout << "\nHow many Numbers do you want to Push?: ";
                cin >> maxSize;

                if( stack.getMaxSize() >= maxSize){
                    int *array = new int[maxSize];
                    for(int i = 0; i < maxSize; i++){
                    cout << "\nEnter Number " << i + 1 <<": ";
                    cin >> array[i];
                    stack.Push(array[i]);
                    cout << "\nNumber " << array[i] << " was Pushed Successfully!\n";
                    }   
                }else{
                    cout << "\nStack Overflow!\n";
                    cout << "\nTry Again";
                }
            }while(stack.getMaxSize() < maxSize);
            
            }else if(choice == 2){
            int x;
            cout << "\nEnter a Number: ";
            cin >> x;
            stack.Push(x);
            cout << "\nNumber Pushed Successfully\n";
            }else{
            cout << "\nInvalid Input\n";
            }
        }else if(choice == 4){
             if(stack.isEmpty()){
                cout << "\nStack Underflow!\n";
                continue;
            }
            int PoppedValue;
            stack.Pop(PoppedValue);
            cout << "\nSuccessfully Popped a Value from the Stack\n";
            cout << "\nPopped Value: " << PoppedValue;
        }else if(choice == 5){
            int n;
            cout << "\nEnter the number of Elements: ";
            cin >> n;
            int *array = new int[n];

            for(int i = 0; i < n; i++){
                cout << "\nEnter Number " << i + 1 <<": ";
                cin >> array[i];
            }

            GreaterNextElement(array, n);

            for(int i = 0; i < n; i++){
                if(i == 0){
                    cout << "\nOutput[ " << array[i];
                }else if(i == n -1){
                    cout << ", "<< array[i] <<" ]";
                }else{
                    cout << ", " << array[i];
                }
            }
            delete [] array;
            cout << endl << endl;

        }else{
            cout << "\nInvalid Input\n";
            cout << "\nTry Again";
        }
    }
    

    cout << "\nGoodBye!\n";
    cout << endl << endl;
    return 0;
}
