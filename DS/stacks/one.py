k = int(input("Enter the maximum capacity:"))
c = int(input("Enter the count:"))
set1=set()
def put(num):
    if len(set1) < k:
        set1.add(num)
        print("Done")
    else: 
        min_val = min(set1)
        set1.remove(val)
def remove_largest():
    if len(set1)>0:
        set1.remove(max(set1))
for i in range(0,c):
    line = raw_input("Enter your operation:")
    linel = list(line)
    if linel[4].isdigit():
        name,num = line.split()
        put(num)
    else:
        remove_largest() 
new_list = sorted(list(set1))           
#print(*new_list, sep=", ")    
for x in range(len(new_list)):
    print(new_list[x]),
