#[derive(Debug, PartialEq)]
pub enum FlightStatus {
    OnTime,
    Delayed(u32),
    Cancelled(String),
}

#[derive(Debug)]
pub struct Flight {
    pub id: String,
    pub destination: String,
    pub time: u32,
    pub status: FlightStatus,
}

pub fn parse_flight(line: &str) -> Result<Flight, String> {
    let elements = line.split(',').collect::<Vec<&str>>();

    if elements.len() != 4 {
        return Err(format!("Bad format"));
    }

    let time = match elements[2].parse::<u32>() {
        Ok(t) => t,
        Err(..) => return Err(format!("Bad time")),
    };

    let status: FlightStatus = match elements[3] {
        "ONTIME" => FlightStatus::OnTime,
        s if s.starts_with("DELAYED") => {
            let time = &s["DELAYED".len()..];

            match time.trim().parse::<u32>() {
                Ok(t) => FlightStatus::Delayed(t),
                Err(..) => return Err(format!("Bad delay")),
            }
        }
        s if s.starts_with("CANCELLED") => {
            let reason = &s["CANCELLED".len()..];

            FlightStatus::Cancelled(reason.trim().to_string())
        }
        _ => return Err(format!("Unknown status")),
    };

    Ok(Flight {
        id: elements[0].to_string(),
        destination: elements[1].to_string(),
        time: time,
        status: status,
    })
}

pub fn build_schedule(raw_logs: Vec<&str>) -> Vec<Flight> {
    let mut result = Vec::<Flight>::new();

    for logs in raw_logs {
        match parse_flight(logs) {
            Ok(flight) => result.push(flight),
            Err(..) => {}
        }
    }

    result.sort_by(|a, b| a.time.cmp(&b.time));

    result
}
