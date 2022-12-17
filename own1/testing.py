
openb = ["(","[","{"]
closeb = [")","]","}"]
class Stack():
  def __init__(self,size):
    self.arr = [None for i in range(size)]
    self.head = -1
    self.tail = -1
    self.size = size
  def push(self,item):
    if self.head==-1:
      self.head = 0
      self.tail = 0
      self.arr[self.tail] = item
    elif self.tail < self.size - 1:
      self.arr[self.tail+1] = item
      self.tail += 1
      print(self.tail)
    else:
      return ("FULL LMAO")

  def pop(self):
    if self.tail != -1:
      temp = self.arr[self.tail]
      self.tail -= 1
      return temp
    else:
      return ("EMPTY")

  def display(self):
    print(self.arr[self.head:self.tail+1], self.head, self.tail)

  def sizer(self):
    print(self.tail-self.head)
    return self.tail-self.head


c = input("Input string:")
ple = Stack(int(len(c)))
isbad = False
for i in range(len(c)):
  ple.display()
  if c[i] not in openb and c[i] not in closeb:
    pass
  elif c[i] in openb:
    print('PUSHING')
    ple.push(c[i])
  elif c[i] in closeb:
    temp = ple.pop()
    print(ple.sizer())
    if ple.sizer() == 0:
      print("ERROR: CLOSING BRACKET WITH NO OPENING")
      isbad = True
    elif openb.index(temp) != closeb.index(c[i]):
      print("ERROR: INCORRECT TYPE")
      isbad = True
    # ple.push(temp)
  if i == len(c)-1 and ple.sizer()!=0:
    print("ERROR: TOO MANY OPENING SYMBOLS")
    isbad = True
if(isbad == False):
  print("GOOD STRING / BALANCED")