pub enum ItemType {
    Tool,
    Weapon(u32),
}

pub struct Item {
    pub name: String,
    pub item_type: ItemType,
    pub price: f32,
    pub usage: u32,
}

pub fn get_damage(weapon: &Item) -> u32 {
    return match weapon.item_type {
        ItemType::Weapon(value) => value,
        _ => 0,
    };
}

pub fn is_used(tool: &Item) -> bool {
    if tool.usage < 25 {
        return true;
    }
    return false;
}

pub fn use_item(tool: &mut Item, usage: u8) {
    tool.usage -= usage as u32;
    if tool.usage <= 25 {
        tool.price *= 0.25;
    }
}

pub fn harmonize_price(weapon1: &mut Item, weapon2: &mut Item) {
    if weapon2.price > weapon1.price {
        weapon1.price = weapon2.price;
        return;
    }
    weapon2.price = weapon1.price;
}
