extern crate textplots;

const WIDTH_CHART: u32 = 150;
const HEIGHT_CHART: u32 = 100;

use self::textplots::{Chart, Plot, Shape};

pub fn plot_records(ve: &Vec<(f32, f32)>) {
    hidden_plot_record(&ve, None);
}

pub fn plot_records_with_linear_line(ve: &Vec<(f32, f32)>, thetas: Option<(f32, f32)>) {
    hidden_plot_record(&ve, thetas);
}

fn hidden_plot_record(ve: &Vec<(f32, f32)>, thetas: Option<(f32, f32)>) {
    let (mi, ma) = get_min_max_of_x(&ve);

    // default chart
    Chart::new(WIDTH_CHART, HEIGHT_CHART, mi, ma)
        .lineplot(Shape::Lines(&ve[..]))
        .display();

    // chart with line
    match thetas {
        None => (),
        Some((t0, t1)) => {
            Chart::new(WIDTH_CHART, HEIGHT_CHART, mi, ma)
                .lineplot(Shape::Lines(&ve[..]))
                .lineplot(Shape::Lines(&[(mi, t0 + t1 * mi), (ma, t0 + t1 * ma)]))
                .display();
        }
    };
}

fn get_min_max_of_x(ve: &Vec<(f32, f32)>) -> (f32, f32) {
    let mut result = None;

    for (x, _) in ve {
        match result {
            None => {
                result = Some((x, x));
            }
            Some((mi, ma)) => {
                let new_mi = if x < mi { x } else { mi };
                let new_ma = if x > ma { x } else { ma };
                result = Some((new_mi, new_ma));
            }
        }
    }

    return match result {
        None => (0., 0.),
        Some((mi, ma)) => (*mi, *ma),
    };
}
