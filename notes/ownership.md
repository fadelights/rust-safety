# Why Is Rust "Safe"?
> _The foundational goal of Rust is to ensure that your programs never have undefined behavior._
- Rust programs are **safe** because they prevent undefined behavior
    - Rust actually has a list of "behavior considered undefined": https://doc.rust-lang.org/reference/behavior-considered-undefined.html
- These undefined behaviors are prevented at compile-time, rather than run-time
    - Avoid bugs in production --- improved reliability
    - Less runtime checks --- improved performance
- An error like Python’s `NameError` comes at a cost: Each time an interpreted program reads a variable, then the interpreter must check whether that variable is defined
- RUST CAN'T PREVENT ALL BUGS
- Rust provides a particular way of thinking about your memory called "ownership"

# What Is Ownership?
(diagram)

## Rust Does Not Allow Manual Memory Management
Then how is heap managed?
- Box deallocation principle (almost correct): If a variable is bound to a box, when Rust deallocates the variable's frame, then Rust deallocates the box's heap memory
- Box deallocation principle (fully correct): If a variable **owns** a box, when Rust deallocates the variable's frame, then Rust deallocates the box's heap memory
- Variables can't be used after being moved -- only current owner can access
- Collections, like `Vec`, `HashMap`, or `String` use boxes
- Use `.clone` to create copy on heap

## Aliasing and Mutation
> Data can be aliased. Data can be mutated. But data cannot be both aliased and mutated.
- Variables have 3 kinds of permissions inside the borrow checker:
    - **Read:** can copy data
    - **Write:** can mutate data
    - **Own:** can move or drop data
- These permissions don't exist at _run-time_ -- only _compile-time_
- By default, variables have RO permissions, W if defined with `mut`
- References can temporarily remove these permissions
- Permissions are defined on _paths_
- Permissions are lost at the end of a _path_'s lifetime
- Each operation on a _path_ requires certain permissions. If they are not satisfied, the borrow checker will fail the program compilation
