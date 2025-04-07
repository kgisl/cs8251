
# Python vs C Language Keyword Comparison

## Core Keywords Comparison

| Category | Python | C |
|----------|--------|---|
| **Common Keywords** | `break`, `continue`, `else`, `for`, `if`, `return`, `while` | `break`, `continue`, `else`, `for`, `if`, `return`, `while` |
| **Total Core Keywords** | 15 (excluding OOP & exceptions) | 21 |

## Unique Keywords in Each Language

### Python-Only Keywords (9)
| Keyword | Purpose |
|---------|---------|
| `class` | Object-oriented programming support |
| `def` | Function definition |
| `del` | Delete objects |
| `global` | Access global variables within functions |
| `in` | Membership testing operator |
| `is` | Identity operator (reference comparison) |
| `lambda` | Anonymous function definition |
| `nonlocal` | Access outer (non-global) scope variables |
| `pass` | Empty statement placeholder |

### C-Only Keywords (14)
| Keyword | Purpose |
|---------|---------|
| `auto` | Storage class specifier (default for local variables) |
| `const` | Declare constants |
| `do` | Alternative loop construct (do-while) |
| `enum` | Enumerated type definition |
| `extern` | External variable declaration |
| `goto` | Jump to labeled statement |
| `register` | Storage class specifier (hint for compiler) |
| `sizeof` | Determine size of a data type or variable |
| `static` | Storage class specifier (persistent local variables) |
| `struct` | Custom data structure definition |
| `typedef` | Create type aliases |
| `union` | Special data structure with overlapping fields |
| `void` | Specify no value type |
| `volatile` | Hint for compiler about variable modification |

## Key Differences

- **Object-Oriented Support**: Python supports OOP directly with `class`, while C uses `struct` and `typedef`
- **Type System**: C has explicit type handling keywords, while Python is dynamically typed
- **Memory Management**: C provides more explicit memory control through keywords like `extern`, `static`, and `register`
- **Function Definition**: Python uses `def` and `lambda`, while C uses function signatures
- **Control Flow**: C offers `goto` and `do-while` loops not available in Python

This comparison highlights Python's focus on readability and simplicity versus C's emphasis on memory management and performance optimization.
