pub fn is_number(number: &str) -> bool {
    let mut is_floating = false;
    let mut is_number = false;

    if number.len() == 0 {
        return false;
    }

    if number.chars().nth(0).unwrap() == '.' {
        return false;
    }

    for (i, c) in number.trim().chars().enumerate() {
        match c {
            '0'..='9' => is_number = true,
            '.' => {
                if is_floating {
                    return false;
                }
                if !is_number {
                    return false;
                }
                is_number = false;
                is_floating = true;
            },
            '-' => {
                if i == 0 {
                    continue;
                } else {
                    return false;
                }
            }
            _ => return false
        }
    }
    return is_number;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn main_test() {
        assert_eq!(is_number("42.42"), true);
        assert_eq!(is_number("42.24.42"), false);
        assert_eq!(is_number("yeet"), false);
        assert_eq!(is_number("   \t123.456   "), true);
        assert_eq!(is_number("123   .456"), false);
        assert_eq!(is_number("-0.4"), true);
        assert_eq!(is_number("-.8"), false);
        assert_eq!(is_number("8.-6"), false);
        assert_eq!(is_number("-8-.6"), false);
        assert_eq!(is_number("001"), true);
    }
}
