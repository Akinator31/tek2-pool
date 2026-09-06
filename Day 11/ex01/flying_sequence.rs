fn error() {
    println!("Wrong flying sequence, go back to the lab !");
}

pub fn flying_sequence(
    mut countdown: u32,
    ignition: u32,
    secondary_activation: u32,
    thrust_duration: u32,
) {
    if ignition > countdown || secondary_activation < 30 {
        return error();
    }
    for n in (1..countdown + 1).rev() {
        if n == ignition {
            println!("Main engine ignition");
        }
        println!("Liftoff in {}...", n);
    }
    println!("Liftoff ! We have liftoff !");

    for n in 0..secondary_activation + 1 {
        if n == secondary_activation {
            println!("T+{} : Secondary engines ignition", n);
            continue;
        }
        if n == secondary_activation - 9 {
            println!("T+{} : Main engine decoupling", n);
        }
        if n % 10 == 0 && n != 0 {
            println!("T+{} : Everything is fine", n);
        }
        if n == secondary_activation - 10 {
            println!("T+{} : Main engine cutoff", n);
            continue;
        }
    }

    for n in secondary_activation..secondary_activation + thrust_duration {
        if n % 10 == 0 && n != 0 {
            println!("T+{} : Everything is fine", n);
        }
    }
    println!(
        "T+{} : Secondary engines cutoff. We're in orbit !",
        secondary_activation + thrust_duration
    );
}
