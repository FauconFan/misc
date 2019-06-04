use std::fs::File;
use std::io::BufReader;

extern crate csv;

pub fn get_records(path: &String) -> Option<Vec<(f32, f32)>> {
    let mut vec = Vec::new();
    let f = match File::open(path) {
        Ok(f) => f,
        Err(e) => {
            eprintln!("Fail opening csv file {}", e);
            return None;
        }
    };

    let reader = BufReader::new(f);
    let mut rdr = csv::Reader::from_reader(reader);

    for result_line in rdr.records() {
        let result = match result_line {
            Ok(result) => result,
            Err(e) => {
                eprintln!("error reading csv file from {} : {}", path, e);
                return None;
            }
        };

        let car = match get_csv_single_record(&result) {
            Some(car) => car,
            None => return None,
        };
        vec.push(car);
    }

    return Some(vec);
}

fn get_csv_single_record(result: &csv::StringRecord) -> Option<(f32, f32)> {
    if result.len() != 2 {
        eprintln!("error in csv format : expect 2 members only");
        return None;
    }

    let km = get_csv_single_record_parse(result, 0);
    let price = get_csv_single_record_parse(result, 1);

    if km.is_none() || price.is_none() {
        return None;
    }

    return Some((km.unwrap(), price.unwrap()));
}

fn get_csv_single_record_parse(result: &csv::StringRecord, index: usize) -> Option<f32> {
    match result.get(index) {
        Some(string) => match string.parse::<f32>() {
            Ok(number) => Some(number),
            Err(e) => {
                eprintln!("error in csv format : {}", e);
                return None;
            }
        },
        None => return None,
    }
}
