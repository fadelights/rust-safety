fn main() {
    let meaning: Box<i32> = Box::new(42);
    let meaningless: i32 = *meaning - 1;

    let universe: &Box<i32> = &meaning;
    let sense: i32 = **universe;

    let everything: &i32 = &*meaning;
    let nothing: i32 = *everything;
}
