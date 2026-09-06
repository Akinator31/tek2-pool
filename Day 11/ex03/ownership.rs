pub struct Chest {
    pub helmet: u32,
    pub suit: u32,
}

pub fn add_title(name: &String) -> String {
    return format!("Astronaut {}", name);
}

pub fn sign_contract(astronaut: &String) -> String {
    format!(
        "I am honored to join the space program of The Union and I am willing to risk my life to explore space. Therefore, I renounce every right I have to sue The Union in the event of my death.\nSigned: {}",
        astronaut.to_string()
    )
}

pub fn sign_press_declaration(astronaut: &String) -> String {
    format!(
        "I am thrilled that I have been chosen in the space program of The Union. I will make The Union and my family proud by being a good astronaut, dedicated to the exploration of space. Cheers and see you on Venus !\nSigned: {}",
        astronaut
    )
}

pub fn take_helmet(equipement_chest: &mut Chest, to_take: u32) {
    equipement_chest.helmet -= to_take;
}

pub fn take_suit(equipement_chest: &mut Chest, to_take: u32) {
    equipement_chest.suit -= to_take;
}
