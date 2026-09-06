pub struct RocketBooster {
    height: f32,
    diameter: f32,
    last_check_time: u32,
}

pub struct FuelTank {
    height: f32,
    quantity: f32,
    max_quantity: f32,
    last_check_time: u32,
}

pub struct CrewCabin {
    nb_seats: u8,
    diameter: f32,
    last_check_time: u32,
}

pub struct SciencePayload {
    quantity: f32,
    max_quantity: f32,
    science_percentage: f32,
}

pub trait RocketComponent {
    fn new() -> Self;
    fn info(&self) -> String;
}

pub trait SafetyCheck {
    fn check_component(&mut self, current_time: u32) -> bool;
    fn is_safe(&self, current_time: u32) -> bool;
}

pub trait LoadContent {
    fn load(&mut self, to_load: f32);
    fn is_full(&self) -> bool;
}

impl RocketComponent for RocketBooster {
    fn new() -> Self {
        println!("Rocket Booster created with a height of {} meters.", 32.3);
        return RocketBooster {
            height: 32.3,
            diameter: 3.0,
            last_check_time: 0,
        };
    }

    fn info(&self) -> String {
        return format!(
            "This Rocket Booster is {} meters tall and {:.0} meters wide. It was last checked on day {} of its life.",
            self.height, self.diameter, self.last_check_time
        );
    }
}

impl RocketComponent for FuelTank {
    fn new() -> Self {
        println!("Fuel Tank created with a max quantity of {} tons.", 220);
        return FuelTank {
            height: 30.0,
            quantity: 0.0,
            max_quantity: 220.0,
            last_check_time: 0,
        };
    }

    fn info(&self) -> String {
        return format!(
            "This Fuel Tank is {:.0} meters tall and can contain up to {:.0} tons of propergol, currently {:.0} tons inside. It was last checked on day {} of its life.",
            self.height, self.max_quantity, self.quantity, self.last_check_time
        );
    }
}

impl RocketComponent for CrewCabin {
    fn new() -> Self {
        println!("Cabin of {} person created.", 4);
        return CrewCabin {
            nb_seats: 4,
            diameter: 2.5,
            last_check_time: 0,
        };
    }

    fn info(&self) -> String {
        return format!(
            "This cabin has {} seats arranged in a circle {:.2} meters large. It was last checked on day {} of its life.",
            self.nb_seats, self.diameter, self.last_check_time
        );
    }
}

impl RocketComponent for SciencePayload {
    fn new() -> Self {
        println!(
            "Science Payload created with a max quantity of {} kilos.",
            1142
        );
        return SciencePayload {
            quantity: 0.0,
            max_quantity: 1142.0,
            science_percentage: 0.0,
        };
    }

    fn info(&self) -> String {
        return format!(
            "This Science Payload can carry {:.2} kilos of science material. Currently it contains {:.2} kilos which means it has a science percentage of {:.2}%.",
            self.max_quantity, self.quantity, self.science_percentage
        );
    }
}

impl SafetyCheck for RocketBooster {
    fn check_component(&mut self, current_time: u32) -> bool {
        if current_time < self.last_check_time {
            return false;
        } else {
            self.last_check_time = current_time;
            return true;
        }
    }

    fn is_safe(&self, current_time: u32) -> bool {
        if self.last_check_time == 0 {
            return false;
        }
        if current_time < self.last_check_time {
            return false;
        }
        if current_time - self.last_check_time <= 12 {
            return true;
        } else {
            return false;
        }
    }
}

impl SafetyCheck for FuelTank {
    fn check_component(&mut self, current_time: u32) -> bool {
        if current_time < self.last_check_time {
            return false;
        } else {
            self.last_check_time = current_time;
            return true;
        }
    }

    fn is_safe(&self, current_time: u32) -> bool {
        if self.last_check_time == 0 {
            return false;
        }
        if current_time < self.last_check_time {
            return false;
        }
        if current_time - self.last_check_time <= 6 {
            return true;
        } else {
            return false;
        }
    }
}

impl SafetyCheck for CrewCabin {
    fn check_component(&mut self, current_time: u32) -> bool {
        if current_time < self.last_check_time {
            return false;
        } else {
            self.last_check_time = current_time;
            return true;
        }
    }

    fn is_safe(&self, current_time: u32) -> bool {
        if self.last_check_time == 0 {
            return false;
        }
        if current_time < self.last_check_time {
            return false;
        }
        if current_time - self.last_check_time <= 16 {
            return true;
        } else {
            return false;
        }
    }
}

impl LoadContent for FuelTank {
    fn is_full(&self) -> bool {
        return self.quantity == self.max_quantity;
    }

    fn load(&mut self, to_load: f32) {
        self.quantity += to_load;
        if self.quantity > self.max_quantity {
            self.quantity = self.max_quantity;
        }
    }
}

impl LoadContent for SciencePayload {
    fn is_full(&self) -> bool {
        return self.quantity == self.max_quantity;
    }

    fn load(&mut self, to_load: f32) {
        self.quantity += to_load;
        if self.quantity > self.max_quantity {
            self.quantity = self.max_quantity;
        }
    }
}

pub const DISCOVERIES: [&str; 4] = [
    "The Union discovered that the hottest planet in our solar system is Venus (about 450°C).",
    "The Union discovered that Mercury and Venus are the only planets in our solar system with no moons.",
    "The Union discovered that one day on Venus is longer than a year on Earth.",
    "The Union discovered that on Venus it snow metal and rains sulfuric acid.",
];

impl SciencePayload {
    pub fn science(&mut self) -> f32 {
        let science_percentage = (self.quantity / self.max_quantity) * 200.0;

        if science_percentage < 50.0 {
            println!("{}", DISCOVERIES[0]);
        } else if science_percentage >= 50.0 && science_percentage < 100.0 {
            println!("{}", DISCOVERIES[1]);
        } else if science_percentage >= 100.0 && science_percentage < 150.0 {
            println!("{}", DISCOVERIES[2]);
        } else {
            println!("{}", DISCOVERIES[3]);
        }

        self.science_percentage = science_percentage;

        science_percentage
    }
}
