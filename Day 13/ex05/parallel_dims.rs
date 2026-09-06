pub struct Report {
    pub sample_count: usize,
    pub total_energy: f64,
}

pub fn fusion_processing(temp_log: &[&str], rpm_logs: &[u32]) -> Report {
    let purated_temp_log = temp_log
        .iter()
        .filter(|val| val.parse::<f64>().is_ok())
        .map(|val| val.parse::<f64>().unwrap())
        .collect::<Vec<f64>>();

    let purated_rpm_log = rpm_logs
        .iter()
        .filter(|val| **val > 2500)
        .collect::<Vec<&u32>>();

    purated_temp_log.iter().zip(purated_rpm_log).fold(
        Report {
            sample_count: 0,
            total_energy: 0.0,
        },
        |mut acc, val| {
            if *val.1 == 0 {
                acc.sample_count += 1;
                acc.total_energy += 100.0;
                return acc;
            }
            match *val.0 / *val.1 as f64 {
                val if val > 100.0 => {
                    acc.sample_count += 1;
                    acc.total_energy += 100.0;
                    return acc;
                }
                val => {
                    acc.sample_count += 1;
                    acc.total_energy += val;
                    return acc;
                }
            }
        },
    )
}
