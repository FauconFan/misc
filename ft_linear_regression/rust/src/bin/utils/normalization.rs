
pub fn normalize_vec(ve : & Vec<(f32, f32)>) -> (Vec<(f32, f32)>, f32, f32, f32, f32) {
    let mut x_min = std::f32::MAX;
    let mut x_max = std::f32::MIN;
    let mut y_min = std::f32::MAX;
    let mut y_max = std::f32::MIN;

    if ve.len() == 0 {
        return (Vec::new(), 0., 0., 0., 0.);
    }

    for (x, y) in ve {
        if x < &x_min {
            x_min = *x;
        }
        if x > &x_max {
            x_max = *x;
        }

        if y < &y_min {
            y_min = *y;
        }
        if y > &y_max {
            y_max = *y;
        }
    }
    let mut res_vec = Vec::new();

    for (x, y) in ve {
        let new_x = (x - x_min) / (x_max - x_min);
        let new_y = (y - y_min) / (y_max - y_min);
        res_vec.push((new_x, new_y));
    }
    return (res_vec, x_min, x_max, y_min, y_max);
}