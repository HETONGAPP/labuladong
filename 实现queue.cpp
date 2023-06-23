#include <stack>
#include <iostream>
#include <queue>
using namespace  std;


template<typename T>
class MyQueue
{
public:
    MyQueue() {};
    ~MyQueue() {};

    void push(T val) { _input.push(val); };

    T pop()
    {
        if (_output.empty())
        {
            while (!_input.empty())
            {
                _output.push(_input.top());
                _input.pop();
            }
        }
        T temp = _output.top();
        _output.pop();
        return temp;
    }

    T peak()
    {
        if (_output.empty())
        {
            while (!_input.empty())
            {
                _output.push(_input.top);
                _input.pop();
            }
        }
        return _output.top;
    }
    bool empty() { return _input.empty() && _output.empty(); };

private:
    stack<T> _input;
    stack<T> _output;

};


int main()
{
    MyQueue<int>* obj = new MyQueue<int>();
    obj->push(3);
    int param_2 = obj->pop();
    cout << param_2;
    //int param_3 = obj->peek();
    //bool param_4 = obj->empty();

}