mod utils;

fn main() {
    let (t0, t1) = match utils::thetas::load_thetas() {
        None => {
            return;
        }
        Some((t0, t1)) => (t0, t1),
    };

    println!("{} {}", t0, t1);
}
