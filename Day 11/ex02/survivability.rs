pub fn compute_survivable_days(
    water_quantity: f32,
    water_cycle: u32,
    food_quantity: f32,
    nb_crew: u32,
) -> u32 {
    if nb_crew == 0 {
        println!(
            "If the mission can embark {}L of water, {}kg of food and the water recycler can do {} water cycles... With {} crew members, there is enough water for {} day(s) and enough food for {} day(s).",
            water_quantity, food_quantity, water_cycle, nb_crew, 0 as u32, 0 as u32
        );
        return 0;
    }

    let water = (water_quantity * water_cycle as f32) / (2 as f32 * nb_crew as f32);
    let food = food_quantity * 1000.0 / (500 * nb_crew) as f32;

    println!(
        "If the mission can embark {}L of water, {}kg of food and the water recycler can do {} water cycles... With {} crew members, there is enough water for {} day(s) and enough food for {} day(s).",
        water_quantity, food_quantity, water_cycle, nb_crew, water as u32, food as u32
    );

    if water > food {
        food as u32
    } else {
        water as u32
    }
}
