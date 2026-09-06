pub enum Message {
    ClearString(String),
    DigitalCode(u32),
    Encrypted(String, u32),
}

pub enum SecurityClass {
    Civilian,
    Diplomatic,
    Military,
}

pub struct Transmission {
    pub message: Message,
    pub security: SecurityClass,
    pub signal_strength: u8,
}

pub fn solve_enigma(transmission: Transmission, daily_key: u32) -> Result<String, String> {
    let mut complexity_score = 0;

    match transmission.signal_strength {
        0 => return Err(format!("Signal lost")),
        0..20 => return Err(format!("Signal too weak")),
        _ => {}
    };

    match transmission.security {
        SecurityClass::Military if daily_key != 4242 => {
            return Err(format!("Security Breach: Invalid Key"));
        }
        _ => {}
    };

    let decoded_string = match transmission.message {
        Message::ClearString(encoded) if encoded == "Bomb" => {
            return Err(format!("Panic: Bomb detected"));
        }
        Message::ClearString(encoded) => encoded,
        Message::DigitalCode(404) => format!("Not Found"),
        Message::DigitalCode(200) => format!("OK"),
        Message::DigitalCode(code) => format!("Code: {}", code),
        Message::Encrypted(content, key_id) if key_id == daily_key => content,
        Message::Encrypted(_, _) => {
            return Err(format!("Encryption Error: Wrong Key"));
        }
    };

    for i in decoded_string.chars() {
        if i.is_alphabetic() {
            complexity_score += 1;
        }
        if i.is_digit(10) {
            complexity_score -= 1;
        }
    }

    match complexity_score {
        num if num < 0 => return Err(format!("Artificial Noise")),
        _ => Ok(decoded_string),
    }
}
