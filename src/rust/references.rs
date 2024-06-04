fn hello(name: String) {
    println!("What's poppin' {}?!", name);
}

fn main() {
    let firstname = String::from("Velstadt");
    let title = String::from("Royal Aegis");

    hello(firstname);

    let fullname = format!("{}, the {}", firstname, title);
    println!("{}", fullname);
}
