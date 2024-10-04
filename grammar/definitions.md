# Definitions

## Variable Definitions
_A variable definition requires a variable name and type; if assigning as well: a value is required_

$$\begin{align}

\text{variableName} \; &: \; \text{variableType} \\
\text{variableName} \; &: \; \text{variableType} = \text{value} \\

\end{align}$$

_Once a variable's type has been defined, it can not be redefined in any scope that the variable exists in_

## Built-in Types
$$\begin{align}

\text{bool} \; & \rarr \; \text{1 bit value (0 or 1)} \\
\text{None} \; & \rarr \; \text{...} \\
\text{int}  \; & \rarr \; \text{4 byte integer} \\
\text{float}  \; & \rarr \; \text{4 byte floating-point} \\
\text{decimal}  \; & \rarr \; \text{4 byte fixed-point} \\
\text{dict[typeA, typeB]}  \; & \rarr \; \text{variable length unordered two type key-value structure} \\
\text{list[type]}  \; & \rarr \; \text{variable length ordered values with single type} \\
\text{array[length, type]}  \; & \rarr \; \text{fixed length ordered values with single type} \\

\end{align}$$

## Function Definitions
_A function definition requires the `def` keyword, function name, parameters (and their types), and the return value_


$$\begin{align}

\text{def functionName(param1 : typeA, param2 : typeB) -> typeC:}  \\

\end{align}$$

_Functions parameters may be overloaded, return values may not_

$$\begin{align}

\text{def} \; & \text{functionName(param1 : typeA, param2 : typeB) -> typeC:}  \\
\text{def} \; & \text{functionName(param1 : typeA) -> typeC:}  \\

\end{align}$$

_By default, arguments passed to a function are by value; however, it is possible to pass by reference_

$$\begin{align}

\text{def functionName(\&param1 : typeA) -> typeB:}  \\

\end{align}$$

## Class Definitions
_A class definition requires the `class` keyword and class name; if choosing to inherit, the parent class(es) are also required_

$$\begin{align}

\text{class} \; & \text{className:} \\
\text{class} \; & \text{className(classA, classB):}  \\

\end{align}$$

_Classes may have their own methods, object properties, instance properties, and privacy levels_

$$\begin{align}

\text{self} \; & \rarr \; \text{indicator to access instance of the class} \\
\text{def functionName() -> None}  \; & \rarr \; \text{class method without access to the instance} \\
\text{def functionName(self) -> None}  \; & \rarr \; \text{class method with access to the instance} \\
\text{def \_\_functionName\_\_() -> None}  \; & \rarr \; \text{dunder method used for other operators} \\

\end{align}$$

_Dunder methods can be used to add functionality to a class, in particular allowing certain operators to work with the class_

$$\begin{align}

\text{\_\_init\_\_()} \; & \rarr \; \text{initialize instance of class} \\
\text{\_\_call\_\_()}  \; & \rarr \; \text{functionality when instance is called} \\
\text{\_\_add\_\_()}  \; & \rarr \; \text{allows support for the addition operator} \\

\end{align}$$