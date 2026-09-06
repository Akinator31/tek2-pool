pub fn create_crew(size: i32) -> Vec<String> {
    if size <= 0 {
        return Vec::<String>::new();
    } else {
        return Vec::<String>::with_capacity(size as usize);
    }
}

pub fn join_crew(crew: &mut Vec<String>, name: String) {
    crew.push(name);
}

pub fn leave_crew(crew: &mut Vec<String>, name: &str) {
    for (index, value) in crew.clone().iter().enumerate() {
        if value == name {
            crew.remove(index);
        }
    }
}

pub fn survey_crew(crew: &Vec<String>) -> usize {
    return crew.len();
}
