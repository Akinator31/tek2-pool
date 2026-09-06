pub struct ShipAssessment {
    pub water_quantity: f32,
    pub water_cycles: u32,
    pub food_quantity: f32,
}

pub struct StudyResult {
    pub rock_name: String,
    pub reachable: bool,
    pub ship_index: usize,
}

pub fn compute_survivable_days(needs: &ShipAssessment, nb_crew: u32) -> u32 {
    if nb_crew == 0 {
        return 0;
    }

    let water = (needs.water_quantity * needs.water_cycles as f32) / (3 as f32 * nb_crew as f32);
    let food = needs.food_quantity * 1000.0 / (500 * nb_crew) as f32;

    if water > food {
        food as u32
    } else {
        water as u32
    }
}

pub fn study_ships(
    ships: &[ShipAssessment],
    rocks_to_visit: &[(String, u32)],
    rock: String,
    nb_crew: u32,
) -> StudyResult {
    match rocks_to_visit.iter().find(|&element| element.0 == rock) {
        Some(_) => {}
        None => {
            return StudyResult {
                rock_name: format!("Error"),
                reachable: false,
                ship_index: 0,
            };
        }
    };

    for (i, ship) in ships.iter().enumerate() {
        let days = compute_survivable_days(ship, nb_crew);

        for planet in rocks_to_visit {
            if planet.0 == rock && planet.1 <= days {
                return StudyResult {
                    rock_name: rock,
                    reachable: true,
                    ship_index: i,
                };
            }
        }
    }

    return StudyResult {
        rock_name: rock,
        reachable: false,
        ship_index: 0,
    };
}
