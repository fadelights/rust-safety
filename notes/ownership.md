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
