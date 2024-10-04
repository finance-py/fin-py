class Shape:
    area : int

    def __init__() -> None:
        pass

    def area() -> int:
        raise NotImplementedError

class Rectangle(Shape):
    length : int
    width : int

    def __init__(l : int, w : int) -> None:
        length = l
        width = w

    def area() -> int:
        return l * w
