#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    stack<int> stk; //declear stack
    queue<int> que; //declear que
    int data[] = {1,2,3}; // define data
    int i;
    // regist data
    for( i = 0; i < 3; i++)
    {
       stk.push(data[i]);
       que.push(data[i]);

    }
    // output data (stack)
    cout << "stack : ";
    while(!stk.empty()){
        cout << stk.top() << " "; // get element by top and delete it by pop.
        stk.pop();
    }
    cout << endl;
    // output data (queue)
    cout << "queue : ";
    while(!que.empty()){
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
    return 0;
}





