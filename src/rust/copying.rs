/* This code will NOT compile! */
fn main() {
    let a = [0; 10];
    let b = a; // creates a new copy of `a`'s data in `b`
    println!("a: {:?}\nb: {:?}", a, b);

    let a = Box::new([0; 1_000_000]); // `a` is now a pointer
    let b = a; // `a` is "moved"
    println!("{:?} has been moved to {:?}", a, b); // errors out
}
