use std::{
    env::args,
    fmt::{self, Display},
    num::ParseIntError,
    process::ExitCode,
};

#[derive(Debug)]
enum Materials {
    Uranium(i32),
    Plutonium(i32),
    OldBoot(i32),
    Unknown(i32),
}

#[derive(Debug)]
struct Reactor {
    energy: i32,
    temperature: i32,
}

impl Display for Materials {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Self::Uranium(weigth) => write!(f, "Uranium ({}kg)", weigth),
            Self::Plutonium(weigth) => write!(f, "Plutonium ({}kg)", weigth),
            Self::OldBoot(weigth) => write!(f, "OldBoot ({}kg)", weigth),
            Self::Unknown(weigth) => write!(f, "Unknown ({}kg)", weigth),
        }
    }
}

fn get_ship(energy: &String, temperature: &String) -> Result<Reactor, ParseIntError> {
    let energy_converted = energy.parse::<i32>()?;
    let temperature_converted = temperature.parse::<i32>()?;

    let ship = Reactor {
        energy: energy_converted,
        temperature: temperature_converted,
    };

    return Ok(ship);
}

fn get_elements(element: &[String]) -> Result<Vec<Materials>, ()> {
    let mut parsed_elements = Vec::<Materials>::new();

    if element.len() % 2 != 0 || element.is_empty() {
        return Err(());
    } else {
        for chunck in element.chunks(2) {
            let weight_parsed = match chunck[1].parse::<i32>() {
                Ok(weight) => weight,
                Err(..) => {
                    return Err(());
                }
            };

            parsed_elements.push(match chunck[0].to_lowercase().as_str() {
                "uranium" => Materials::Uranium(weight_parsed),
                "plutonium" => Materials::Plutonium(weight_parsed),
                "oldboot" => Materials::OldBoot(weight_parsed),
                "unknown" => Materials::Unknown(weight_parsed),
                _ => return Err(()),
            });
        }
    }
    Ok(parsed_elements)
}

fn process_elements(elements: &Vec<Materials>, reactor: &mut Reactor) -> () {
    if reactor.temperature > 800 {
        println!("CRITICAL MELTDOWN!");
        return;
    }

    for element in elements {
        println!("Processing: {}", element.to_string());
        match element {
            Materials::Uranium(weigth) => {
                reactor.energy += 40 * weigth;
                reactor.temperature += 10 * weigth;
            }
            Materials::Plutonium(weigth) => {
                reactor.energy += 90 * weigth;
                reactor.temperature += 60 * weigth;
            }
            Materials::OldBoot(weigth) => {
                reactor.energy += 20 * weigth;
                reactor.temperature += 5 * weigth;
            }
            Materials::Unknown(weight) => {
                if reactor.temperature % 2 == 0 {
                    reactor.energy += 400 * weight;
                    reactor.temperature += 20 * weight;
                } else {
                    reactor.energy -= 150 * weight;
                    reactor.temperature += 20 * weight;
                }
            }
        }

        println!(
            "Reactor Stats: Energy {}, Temp {}",
            reactor.energy, reactor.temperature
        );

        if reactor.temperature > 800 {
            println!("CRITICAL MELTDOWN!");
            return;
        }
        if reactor.energy >= 2000 {
            println!("Orbit achieved!");
            return;
        }
    }
    println!("Out of fuel. We drift into the void...");
    return;
}

fn print_usage(write_on_error_output: bool) {
    if write_on_error_output {
        eprintln!(
            "Usage: ./gravity_well <Start_Energy> <Start_Temp> <Elem1> <Weight1> <Elem2> <Weight2> ..."
        );
    } else {
        println!(
            "Usage: ./gravity_well <Start_Energy> <Start_Temp> <Elem1> <Weight1> <Elem2> <Weight2> ..."
        );
    }
}

fn main() -> ExitCode {
    let args: Vec<String> = args().collect();

    if args.len() > 1 && args[1] == "-h" {
        print_usage(false);
        return ExitCode::from(0);
    }

    if args.len() < 5 {
        print_usage(true);
        return ExitCode::from(84);
    }

    let mut reactor = match get_ship(&args[1], &args[2]) {
        Ok(ship) => ship,
        Err(..) => {
            return ExitCode::from(84);
        }
    };

    let elements = match get_elements(&args[3..]) {
        Ok(elements) => elements,
        Err(..) => {
            eprintln!("Error: Unknown element");
            return ExitCode::from(84);
        }
    };

    process_elements(&elements, &mut reactor);
    return ExitCode::from(0);
}
