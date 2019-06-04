extern crate clap;

mod utils;

use clap::{App, Arg};

fn main() {
    let matches = App::new("ft_linear_regression (predict)")
        .version("1.0")
        .author("Joseph Priour <jpriou>")
        .about("Do some linear regression prediction based on saved file and print result")
        .arg(
            Arg::with_name("THETAS")
                .short("t")
                .long("thetas")
                .help("thetas file")
                .takes_value(true),
        )
        .get_matches();

    let thetas_file = matches.value_of("THETAS");

    let (t0, t1) = match utils::thetas::load_thetas(thetas_file) {
        None => {
            return;
        }
        Some((t0, t1)) => (t0, t1),
    };

    println!("t0 : {}", t0);
    println!("t1 : {}", t1);

    println!("What is your mileage (input) ?");

    let mut buffer = String::new();
    match std::io::stdin().read_line(&mut buffer) {
        Ok(_) => (),
        Err(e) => {
            eprintln!("reading error : {}", e);
            return;
        }
    }
    buffer = buffer.trim().to_string();

    let mileage = match buffer.parse::<f32>() {
        Ok(f) => f,
        Err(e) => {
            eprintln!("parsing error : {}", e);
            return;
        }
    };

    if mileage < 0. {
        eprintln!("The mileage can't be negative..., but i let it go...");
    }

    let price = t0 + t1 * mileage;

    if price > 0. {
        println!("The price (output) must be around {}", price);
    } else {
        println!("The car must be free !!! (or the output is just {})", price);
    }
}
