extern crate regex;

use self::regex::Regex;

use std::fs::File;
use std::io::prelude::*;

const FILE_SAVE: &str = ".save_thetas.txt";
const DEF_THETA0: f32 = 0.;
const DEF_THETA1: f32 = 0.;

pub fn save_thetas(theta0: &f32, theta1: &f32) {
    let mut file = match File::create(FILE_SAVE) {
        Ok(f) => f,
        Err(e) => {
            eprintln!("Unable to create file {}", e);
            return;
        }
    };
    match file.write_fmt(format_args!("{}\n{}\n", theta0, theta1)) {
        Ok(()) => (),
        Err(e) => {
            eprintln!("Unable to write in file {}", e);
            return;
        }
    }
    println!("Save thetas in the file {}", FILE_SAVE);
}

pub fn load_thetas() -> Option<(f32, f32)> {
    let mut file = match File::open(FILE_SAVE) {
        Ok(f) => f,
        Err(_) => {
            eprintln!("The file may not exist. Consider training before.");
            return None;
        }
    };
    let mut contents = String::new();
    match file.read_to_string(&mut contents) {
        Err(e) => {
            eprintln!("Unable to read in file {}", e);
            return None;
        }
        _ => (),
    }
    let mut vec = Vec::new();
    for f in Regex::new(r"[+-]?([0-9]+[.])?[0-9]+")
        .unwrap()
        .find_iter(&contents)
    {
        match f.as_str().parse::<f32>() {
            Ok(fl) => {
                vec.push(fl);
            }
            Err(e) => {
                eprintln!("Unable to parse float {}", e);
                return None;
            }
        }
    }

    if vec.len() != 2 {
        eprintln!("Too many values");
        return None;
    }

    return Some((vec[0], vec[1]));
}
