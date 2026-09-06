use std::collections::HashMap;

pub struct Stock {
    pub quantity: u32,
    pub total_value: u32,
}

pub fn consolidate_inventory(orders: &[(&str, u32, u32)]) -> HashMap<String, Stock> {
    let mut map = HashMap::<String, Stock>::new();

    orders
        .iter()
        .filter_map(|o| if o.1 == 0 { None } else { Some(o) })
        .for_each(|order| {
            if !map.contains_key(order.0) {
                map.insert(
                    order.0.to_string(),
                    Stock {
                        quantity: order.1,
                        total_value: order.1 * order.2,
                    },
                );
            } else {
                map.get_mut(order.0).map(|stock| {
                    stock.quantity += order.1;
                    stock.total_value += order.1 * order.2;
                });
            }
        });

    map
}
