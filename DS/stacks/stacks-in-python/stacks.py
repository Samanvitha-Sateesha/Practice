# Single array implementation of stacks
class Stack:
    def __init__(self,limit=10):
        self.stk =[]
        self.limit=limit
    def isEmptyStack(self):
        return len(self.stk)<=0 
    def push(self,data):
        if len(self.stk)>self.limit:
            print("Overflow")
        else:
            self.stk.append(data)
            print("Appended",self.stk)
    def pop(self):
        if len(self.stk) <= 0:
            print("Underflow! Cannot pop")
        else:
            print("Popped!")
            return self.stk.pop()
    def printStack(self):
        print("Stack:",self.stk) 
    def stackLength(self):
        return len(self.stk)           
    def peek(self):
        if len(self.stk) <= 0:
            print("Underflow!")
        else:
            return self.stk[-1]    
our_stack = Stack()
our_stack.push(5)   
our_stack.push(8)   
num = our_stack.pop()
print(num)
our_stack.printStack()
print(our_stack.pop())
our_stack.push(6)
our_stack.push(10)
our_stack.push(20)
print("Top element of the stack is",our_stack.peek())