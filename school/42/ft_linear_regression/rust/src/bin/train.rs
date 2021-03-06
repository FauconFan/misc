extern crate clap;

mod utils;

use clap::{App, Arg};

const DEF_LEARNING_RATE: f32 = 0.1;
const OBJECTIVE_ERROR: f32 = 0.0001;
const LIMIT_ITER: u32 = 10000;

fn main() {
    let matches = App::new("ft_linear_regression (train)")
        .version("1.0")
        .author("Joseph Priour <jpriou>")
        .about("Do some linear regression training based on csv input and save result in file")
        .arg(
            Arg::with_name("FILE")
                .short("f")
                .long("file")
                .required(true)
                .help("csv input file")
                .takes_value(true),
        )
        .arg(
            Arg::with_name("PLOT")
                .short("p")
                .long("plot")
                .help("plot the input data file"),
        )
        .arg(
            Arg::with_name("PLOT_LINE")
                .short("l")
                .long("line")
                .help("plot the input data file with line"),
        )
        .arg(
            Arg::with_name("LEARNING_RATE")
                .short("r")
                .long("learning-rate")
                .help("set the learning rate")
                .takes_value(true),
        )
        .get_matches();

    let pathfile = String::from(matches.values_of("FILE").unwrap().nth(0).unwrap());
    let do_plot = matches.is_present("PLOT");
    let do_plot_line = matches.is_present("PLOT_LINE");
    let learning_rate = match matches.value_of("LEARNING_RATE") {
        None => DEF_LEARNING_RATE,
        Some(st_f) => match st_f.parse::<f32>() {
            Ok(f) => f,
            Err(e) => {
                eprintln!("Error when parsing learning rate {}", e);
                return;
            }
        },
    };

    let cars = match utils::csv::get_records(&pathfile) {
        Some(cars) => cars,
        None => return,
    };

    let (theta0, theta1) = match train(&cars, &learning_rate) {
        None => {
            return;
        }
        Some((t0, t1)) => (t0, t1),
    };

    if do_plot {
        utils::plot::plot_records(&cars);
    }
    if do_plot_line {
        utils::plot::plot_records_with_linear_line(&cars, &theta0, &theta1);
    }

    utils::thetas::save_thetas(&theta0, &theta1);
}

fn train(cars: &Vec<(f32, f32)>, learning_rate: &f32) -> Option<(f32, f32)> {
    let (norm_car, x_min, x_max, y_min, y_max) = utils::normalization::normalize_vec(&cars);

    let mut theta0: f32 = 0.;
    let mut theta1: f32 = 0.;

    let mut actu_error: f32 = error_func(&theta0, &theta1, &norm_car);

    let mut i: u32 = 0;

    println!("Learning rate : {}", learning_rate);

    loop {
        let mut tmp0 = 0.;
        let mut tmp1 = 0.;

        for (mileage, price) in norm_car.iter() {
            tmp0 += theta0 + theta1 * mileage - price;
            tmp1 += (theta0 + theta1 * mileage - price) * mileage;
        }

        tmp0 *= learning_rate * 1. / (norm_car.len() as f32);
        tmp1 *= learning_rate * 1. / (norm_car.len() as f32);

        theta0 -= tmp0;
        theta1 -= tmp1;
        let next_error = error_func(&theta0, &theta1, &norm_car);
        if (next_error - actu_error).abs() < OBJECTIVE_ERROR || i >= LIMIT_ITER {
            actu_error = next_error;
            break;
        }
        actu_error = next_error;
        i += 1;
    }

    if i >= LIMIT_ITER {
        eprintln!("The function doesn't converge rapidly or doesn't converge at all");
        eprintln!("Consider changing the learning rate");
        return None;
    }

    theta0 = y_min + (y_max - y_min) * (theta0 - theta1 * (x_min) / (x_max - x_min));
    theta1 = theta1 * (y_max - y_min) / (x_max - x_min);

    println!("Nb tours : {}", i);
    println!("Precision : {}", actu_error);
    println!("t0 : {}", theta0);
    println!("t1 : {}", theta1);
    return Some((theta0, theta1));
}

fn error_func(t0: &f32, t1: &f32, ve: &Vec<(f32, f32)>) -> f32 {
    let mut res = 0.0;

    for (x, y) in ve {
        let tmp = y - (t0 + t1 * x);

        res += tmp * tmp;
    }
    return res;
}
