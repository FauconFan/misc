extern crate clap;

mod utils;

use clap::{App, Arg};

const LEARNING_RATE: f32 = 0.1;
const OBJECTIVE_ERROR: f32 = 0.0001;

fn main() {
    let matches = App::new("ft_linear_regression")
        .version("1.0")
        .author("Joseph Priour <jpriou>")
        .about("Do some linear regression based on csv input and save result in file")
        .arg(
            Arg::with_name("FILE")
                .short("f")
                .long("file")
                .required(true)
                .help("csv input file")
                .takes_value(true),
        )
        .get_matches();

    let pathfile = String::from(matches.values_of("FILE").unwrap().nth(0).unwrap());

    let cars = match utils::csv::get_records(&pathfile) {
        Some(cars) => cars,
        None => return,
    };

    for car in cars.iter() {
        println!("{:?}", car);
    }

    let (norm_car, x_min, x_max, y_min, y_max) = utils::normalization::normalize_vec(&cars);

    println!("x {} {}", x_min, x_max);
    println!("y {} {}", y_min, y_max);

    for car in norm_car.iter() {
        println!("{:?}", car);
    }

    let mut theta0: f32 = 0.;
    let mut theta1: f32 = 0.;

    let mut prev: f32 = error_func(&theta0, &theta1, &norm_car);

    let mut i = 0;

    loop {
        let mut tmp0 = 0.;
        let mut tmp1 = 0.;

        for (mileage, price) in norm_car.iter() {
            tmp0 += theta0 + theta1 * mileage - price;
            tmp1 += (theta0 + theta1 * mileage - price) * mileage;
        }

        tmp0 *= 1. / (norm_car.len() as f32);
        tmp1 *= 1. / (norm_car.len() as f32);

        tmp0 *= LEARNING_RATE;
        tmp1 *= LEARNING_RATE;

        theta0 -= tmp0;
        theta1 -= tmp1;
        let new_error = error_func(&theta0, &theta1, &norm_car);
        if (new_error - prev).abs() < OBJECTIVE_ERROR {
            break;
        }
        prev = new_error;
        i += 1;
    }

    theta0 = y_min + (y_max - y_min) * (theta0 - theta1 * (x_min) / (x_max - x_min));
    theta1 = theta1 * (y_max - y_min) / (x_max - x_min);

    println!("Nb tours : {}", i);
    println!("t0 {} t1 {}", theta0, theta1);

    utils::plot::plot_records_with_linear_line(&cars, Some((theta0, theta1)));
}

fn error_func(t0: &f32, t1: &f32, ve: &Vec<(f32, f32)>) -> f32 {
    let mut res = 0.0;

    for (x, y) in ve {
        let tmp = y - (t0 + t1 * x);

        res += tmp * tmp;
    }
    return res;
}
