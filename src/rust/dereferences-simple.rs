fn main() {
    let director = String::from("Hayao Miyazaki");
    let author = &director;
    let animator = &author;
    let legend  = &animator;

    println!("Director: {}", director);
    println!("Author: {}", author);
    println!("Animator: {}", animator);
    println!("Legend: {}", legend);
}
