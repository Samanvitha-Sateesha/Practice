# Python Program to check if the given string 
class Stack:
    def __init__(self,limit=10):
        self.stk =[]
        self.limit=limit
    def isEmptyStack(self):
        return len(self.stk)<=0 
    def push(self,data):
        if len(self.stk)>self.limit:
            self.resize()
        self.stk.append(data)
    def pop(self):
        if len(self.stk) <= 0:
            print("Underflow! Cannot pop")
            return -1
        else:
            return self.stk.pop()
    def printStack(self):
        print("Stack:",self.stk) 
    def stackLength(self):
        return len(self.stk)           
    def peek(self):
        if len(self.stk) <= 0:
            print("Underflow!")
            return -1
        else:
            return self.stk[-1] 
    def resize(self):
        newStk=list(self.stk)
        self.limit = 2*self.limit
        self.stk = newStk
       
def checkBalancedParenthesis(input):
    input = list(input)
    symbolStack = Stack()
    balanced = False
    for symbols in input:
        if symbols in ["(","[","{"]:
            symbolStack.push(symbols)
        elif symbolStack.isEmptyStack() :
            balanced = False
        else:
            topsymbol = symbolStack.pop()
            if not matches(topsymbol,symbols):
                balanced = False
            else:
                balanced = True
    return balanced
def matches(topsymbol,symbol):
    if topsymbol == '(' and symbol == ')':
        return True     
    if topsymbol == '[' and symbol == ']':
        return True
    if topsymbol == '{' and symbol == '}':
        return True 
    return False                
inputString =input("Enter the input string to check for balanced parenthesis: ")
print(checkBalancedParenthesis(inputString))                
