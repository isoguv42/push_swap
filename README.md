# 📚 Push_Swap - 42 Codam Efficient Sorting Algorithm

<div align="center">

<pre>
██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗ 
██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗
██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝
██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝ 
██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║     
╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     

┌─────────────┐  ┌─────────────┐    ┌─────────────┐  ┌─────────────┐
│   Stack A   │  │   Stack B   │    │   Stack A   │  │   Stack B   │
│    [3]      │  │             │    │    [3]      │  │    [1]      │
│    [1]      │  │             │    │    [4]      │  │             │
│    [4]      │  │             │    │    [2]      │  │             │
│    [2]      │  │             │    │             │  │             │
└─────────────┘  └─────────────┘    └─────────────┘  └─────────────┘
STEP 1: INITIAL STATE               STEP 2: PUSH TO B (pb)

┌─────────────┐  ┌─────────────┐    ┌─────────────┐  ┌─────────────┐
│   Stack A   │  │   Stack B   │    │   Stack A   │  │   Stack B   │
│    [4]      │  │     [1]     │    │    [1]      │  │             │
│             │  │     [2]     │    │    [2]      │  │             │
│             │  │     [3]     │    │    [3]      │  │             │
│             │  │             │    │    [4]      │  │             │
└─────────────┘  └─────────────┘    └─────────────┘  └─────────────┘
STEP 3: SORT & REARRANGE            STEP 4: FINAL SORTED
</pre>

**🚀 High-Performance Stack Sorting Algorithm with Limited Operations 🚀**  
_42 School Curriculum Project - Codam - Algorithm & Data Structures_

[![push_swap](https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/push_swapm.png)](https://github.com/42School)

![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/isoguv42/push_swap)
![Lines of code](https://img.shields.io/tokei/lines/github/isoguv42/push_swap)
![Language](https://img.shields.io/badge/Language-C-blue)
![Norm](https://img.shields.io/badge/42-Norm_v3-success)

[![42 School](https://img.shields.io/badge/42-School-%23000000?style=for-the-badge&logo=42&logoColor=white)](https://www.42.fr/)
[![Language](https://img.shields.io/badge/Language-C-blue.svg?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-v3-success?style=for-the-badge)](https://github.com/42School/norminette)
[![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)](LICENSE)

[![Functions](https://img.shields.io/badge/Functions-20+-brightgreen?style=for-the-badge)](src/)
[![Tests](https://img.shields.io/badge/Tests-29/29_PASS-success?style=for-the-badge)](test_push_swap.sh)
[![Memory](https://img.shields.io/badge/Memory_Leaks-0-success?style=for-the-badge)](test_push_swap.sh)
[![Build](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge)](Makefile)

[![Lines of Code](https://img.shields.io/badge/Lines_of_Code-500+-blue?style=flat-square)](src/)
[![Files](https://img.shields.io/badge/Source_Files-9-blue?style=flat-square)](src/)
[![Operations](https://img.shields.io/badge/Max_Operations-700-blue?style=flat-square)](README.md)
[![Stack Size](https://img.shields.io/badge/Max_Stack-500-orange?style=flat-square)](README.md)

</div>

---

## 📋 Table of Contents

1. [📖 About](#-about)
2. [📊 Project Statistics](#-project-statistics)
3. [🎯 Objectives](#-objectives)
4. [📁 Project Structure](#-project-structure)
5. [🔧 Functions Implemented](#-functions-implemented)
6. [🧮 Algorithm](#-algorithm)
7. [⚙️ Operations](#️-operations)
8. [🚀 Installation](#-installation)
9. [🚀 Usage](#-usage)
10. [🧪 Testing](#-testing)
11. [📋 Requirements](#-requirements)
12. [🤝 Contributing](#-contributing)
13. [📊 Performance Metrics](#-performance-metrics)
14. [🏆 Author](#-author)
15. [📜 License](#-license)

---

### 📖 About

This is a comprehensive implementation of the push_swap project from 42 School curriculum, focused on creating an efficient sorting algorithm using a limited set of stack operations.

### 📊 Project Statistics

* **Functions**: 20+ functions across 5 organized categories
* **Source Files**: 9 .c files + 1 header file (organized structure)  
* **Code Lines**: 500+ lines of C code
* **Categories**: Core, Parsing, Stack, Sorting, Utils
* **Test Coverage**: Comprehensive test suite with 30+ test cases
* **Memory Management**: Zero memory leaks (Valgrind tested)
* **42 Norm**: Fully compliant (≤5 functions per file)
* **Performance**: Optimized for minimal operations

### 🎯 Objectives

* **Algorithm Design**: Implement efficient sorting with operation constraints
* **Optimization**: Minimize the number of operations required
* **Memory Management**: Handle dynamic allocation safely
* **Error Handling**: Validate input and handle edge cases gracefully

### 📁 Project Structure

```
push_swap/
├── 📁 src/                    # Source files (organized by category)
│   ├── 📁 core/               # Core program logic
│   │   └── main.c             # Main program entry and orchestration
│   ├── 📁 parsing/            # Input parsing and validation
│   │   └── args_utils.c       # Argument parsing and normalization
│   ├── 📁 stack/              # Stack data structure and operations
│   │   ├── init_stack.c       # Stack initialization and validation
│   │   ├── operations.c       # Stack operations (sa, pb, ra, etc.)
│   │   └── stack_utils.c      # Stack utility functions (size, sorted check)
│   ├── 📁 sorting/            # Sorting algorithms and helpers
│   │   ├── indexing.c         # Value to index mapping for radix sort
│   │   ├── radix_sort.c       # Binary radix sort for large datasets
│   │   └── small_sort.c       # Optimized sorting for small stacks
│   └── 📁 utils/              # General utility functions
│       └── free_utils.c       # Memory management and cleanup
├── 📁 include/
│   └── push_swap.h            # Header file with function prototypes
├── 📁 obj/                    # Object files (created during build)
├── 📁 libft/                  # Libft library (auto-downloaded)
├── Makefile                   # Build configuration with auto-dependency
├── test_push_swap.sh          # Comprehensive test suite
├── README.md                  # This documentation
└── LICENSE                    # License information
```

### 🔧 Functions Implemented

#### Core Algorithm Functions
* `main` - Program entry point with input validation
* `init_stack` - Initialize stack from command line arguments
* `assign_indexes` - Map values to indices for radix sort optimization

#### Sorting Algorithms
* `sort_small` - Optimized sorting for 3 elements (≤ 3 operations)
* `sort_medium` - Efficient sorting for 4-6 elements (≤ 12 operations)
* `radix_sort` - Binary radix sort for large datasets

#### Stack Operations
* `sa` - Swap first two elements of stack A
* `ra` - Rotate stack A (first becomes last)
* `rra` - Reverse rotate stack A (last becomes first)
* `pa` - Push from B to A
* `pb` - Push from A to B

#### Utility Functions
* `is_sorted` - Check if stack is already sorted
* `stack_size` - Get number of elements in stack
* `find_min_position` - Locate minimum element position
* `exit_error_handler` - Centralized error handling and cleanup
* `free_stack` - Free all nodes in a stack
* `ft_free_split` - Free arrays created by ft_split (from libft)
* `ft_isnum` - Validate if string represents valid integer (from libft)

## 🧮 Algorithm

The project implements multiple sorting strategies depending on the input size:

### Small Stack Optimization (≤ 5 elements)
- **2-3 elements**: Direct sorting with minimal operations
- **4-5 elements**: Optimized manual sorting to minimize operation count

### Large Stack Strategy (> 5 elements)
- **Radix Sort**: Binary-based sorting algorithm
- **Index Mapping**: Maps values to indices for efficient bit manipulation
- **Bit-by-bit Processing**: Sorts by examining each bit position

```c
// Example: Sorting [3, 1, 4, 2]
// 1. Index mapping: 3→2, 1→0, 4→3, 2→1
// 2. Binary representation:
//    3(2) = 10₂, 1(0) = 00₂, 4(3) = 11₂, 2(1) = 01₂
// 3. Sort by LSB, then MSB
```

## ⚙️ Operations

The sorting can only be performed using these operations:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack A |
| `sb` | Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the first element of stack B to stack A |
| `pb` | Push the first element of stack A to stack B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## 🚀 Installation

### Prerequisites

- GCC or Clang compiler
- Make
- Git (for automatic libft download)
- Unix-like system (Linux, macOS)

### Compilation

```bash
# Clone and build (libft downloaded automatically)
git clone https://github.com/isoguv42/push_swap.git
cd push_swap
make

# Available targets
make clean       # Remove object files
make fclean      # Remove everything including libft
make re          # Rebuild everything
make install     # Download libft manually
make test        # Run comprehensive test suite
make help        # Show all available commands
```

### 🚀 Usage

#### Using in Your Project

```c
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_args input;
    t_node *stack_a;
    t_node *stack_b;

    // Normalize arguments (handles both "1 2 3" and 1 2 3)
    input = normalize_args(argc, argv);
    
    // Initialize and sort
    stack_a = init_stack(input.count, input.values);
    assign_indexes(stack_a);
    stack_b = NULL;
    
    // Sort based on size
    if (input.count <= 3)
        sort_small(&stack_a);
    else if (input.count <= 6)
        sort_medium(&stack_a, &stack_b);
    else
        radix_sort(&stack_a, &stack_b);
    
    // Cleanup
    clean_exit(&stack_a, &stack_b, &input);
    return (0);
}
```

#### Command Line Usage

```bash
# Basic sorting
./push_swap 3 1 4 2          # Individual arguments
./push_swap "3 1 4 2"        # String argument

# Edge cases
./push_swap 1 2 3            # Already sorted (no output)
./push_swap -1 0 1           # Negative numbers
./push_swap $(seq 1 100 | shuf)  # Large random dataset

# Error handling
./push_swap 1 2 2            # Duplicates → Error
./push_swap 1 abc 3          # Invalid input → Error
```

### 🧪 Testing

The project includes a comprehensive test suite:

```bash
# Basic test suite
make test

# Extended test options
./test_push_swap.sh --full         # Full tests with large datasets
./test_push_swap.sh --performance  # Performance benchmarks  
./test_push_swap.sh --valgrind     # Memory leak detection
./test_push_swap.sh --help         # Show all options
```

#### Test Categories

* **Basic Functionality**: Empty input, single numbers, small sets
* **Small Stack Tests**: Optimized sorting for ≤5 elements  
* **Medium Stack Tests**: Efficient sorting for 6-100 elements
* **Error Handling**: Invalid input, duplicates, overflow detection
* **Edge Cases**: Negative numbers, INT_MAX/MIN, already sorted
* **Performance Tests**: Large datasets with operation counting
* **Memory Tests**: Valgrind leak detection

### 📋 Requirements

* **Compiler**: GCC or Clang with C99 standard
* **OS**: Unix-like systems (Linux, macOS)  
* **Dependencies**: Git (for libft auto-download)
* **Memory**: Minimum 1MB for compilation
* **42 Norm**: Code must follow 42 Norm v3

### 🤝 Contributing

This is a school project, but suggestions for improvements are welcome!

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)  
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### 📊 Performance Metrics

| Stack Size | Max Operations | Strategy | Avg Time |
|------------|----------------|----------|----------|
| 3 elements | ≤ 3 ops | Manual | <1ms |
| 5 elements | ≤ 12 ops | Optimized | <1ms |
| 100 elements | ≤ 700 ops | Radix | 5-10ms |
| 500 elements | ≤ 5500 ops | Radix | 50-100ms |

*Benchmarks run on MacBook Pro M1, tested with random datasets*

---

**Made with ❤️ at 42 Codam**

_"The only way to learn a new programming language is by writing programs in it."_ - Dennis Ritchie

## 🏆 Author

**Ilyas Gyuveni** - [@isoguv42](https://github.com/isoguv42)

- 🎓 42 Codam Student  
- 📧 [igyuveni@student.42.fr](mailto:igyuveni@student.42.fr)
- 💼 [LinkedIn](https://linkedin.com/in/ilyasgyuveni)

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

<div align="center">

![42 Badge](https://img.shields.io/badge/42-School-000000?style=for-the-badge&logo=42&logoColor=white)
![Made with Love](https://img.shields.io/badge/Made%20with-❤️-red?style=for-the-badge)
![42 Codam](https://img.shields.io/badge/42-Codam-blue?style=for-the-badge)

</div> 