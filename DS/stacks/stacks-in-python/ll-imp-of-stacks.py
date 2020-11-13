# Linked List implementation of stacks
class Node():
    def __init__(self):
        self.data = None
        self.next = None
    def setData(self,data):
        self.data = data
    def getData(self):
        return self.data
    def setNext(self,next):
        self.next = next
    def getNext(self):
        return self.next
    def hasNext(self):
        return self.next != None
class Stack():
    def __init__(self,data=None):
        self.head = None
        if data:
            for data in data:
                self.push(data)
    def push(self,data):
        temp = Node()
        temp.setData(data)
        temp.setNext(self.head)
        self.head = temp
    def pop(self):
        if self.head == None:
            raise IndexError
        temp = self.head.getData()
        self.head = self.head.getNext()
        return temp
    def peek(self):
        if self.head == None:
            raise IndexError
        return self.head.getData()
my_list = [10,20,30,40]
my_stack=Stack(my_list)
print("Popped ",my_stack.pop())
my_list.append(100)
my_stack=Stack(my_list)
my_stack.push(50)
print("Popped ",my_stack.pop())
print("Top of the stack is ",my_stack.peek())