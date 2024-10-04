def add(a : int, b : int) -> int:
    return a + b

def add(addends : list[int]) -> int:
    sum : int
    for (int a in addends):
        sum += a

def sayHello(s : str) -> None:
    print(s)

def addInplace(&a : int, b : int) -> None:
    a += b
