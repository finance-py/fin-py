def main() -> None:
    x : int = 0

    # Assignment and Increment/Decrement Operators
    x = 0
    x += 1 # x = 1
    x *= 3 # x = 3
    x++    # x = 4
    x /= 2 # x = 2
    x--    # x = 1
    x -= 1 # x = 0

    # Arithmetic Operators (order matters)
    x = 2 - 1 + 4 / 2 * 3 # x = 7
    x = x % 7             # x = 0

    # Exponentiation
    x = 7
    x = x ** 2            # x = 49
    x = x ** 0.5          # x = 7
    x = x ** -2           # x = 1 / 49
    x = x ** -0.5         # x = 7
