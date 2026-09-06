pub fn calculate_average_temperature(readings: &[f64]) -> Option<f64> {
    if readings.is_empty() {
        return None;
    }

    let it = readings.iter().filter(|r| **r >= -273.15);

    let len = it.clone().collect::<Vec<&f64>>().len();

    if len == 0 {
        return None;
    }
    Some(it.map(|r| *r + 2.0).fold(0.0, |acc, el| acc + el) / len as f64)
}
