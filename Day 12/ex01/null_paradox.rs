pub struct Coordinates {
    pub x: i32,
    pub y: i32,
    pub z: i32,
}

pub fn get_place(name: &str) -> Option<Coordinates> {
    match name {
        "Earth" => return Some(Coordinates { x: 0, y: 0, z: 0 }),
        "Mars" => {
            return Some(Coordinates {
                x: 15,
                y: 22,
                z: 110,
            });
        }
        "Jupiter" => {
            return Some(Coordinates {
                x: 88,
                y: 12,
                z: -4,
            });
        }
        _ => return None,
    }
}

pub fn analyze_transport_method(options: Option<Coordinates>) -> String {
    match options {
        Some(coords) => return format!("Teleporting to {},{},{}", coords.x, coords.y, coords.z),
        None => return format!("No destination available"),
    }
}

pub fn risky_teleport(options: Option<Coordinates>) -> String {
    let options_unwrap = options.unwrap();
    return format!(
        "Teleporting to {},{},{}",
        options_unwrap.x, options_unwrap.y, options_unwrap.z
    );
}
