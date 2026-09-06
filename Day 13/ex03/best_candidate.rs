pub fn winning_candidate<T: PartialOrd>(slice: &[T]) -> Option<&T> {
    if slice.is_empty() {
        return None;
    }

    let mut highest: &T = &slice[0];

    for i in slice {
        if i > highest {
            highest = i;
        }
    }

    Some(highest)
}
