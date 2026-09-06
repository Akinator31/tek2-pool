use std::fmt::Display;

#[derive(Debug, PartialEq, PartialOrd, Eq, Ord)]
pub enum MissionState {
    Completed,
    Planned,
    InProgress,
    Failed,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Rover {
    pub name: String,
    pub fuel_level: u8,
    pub map_sectors: Vec<u32>,
}

#[derive(Debug)]
pub struct Mission {
    pub mission_name: String,
    pub rover: Rover,
    pub state: MissionState,
}

impl Display for MissionState {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::Planned => write!(f, "PLANNED"),
            Self::InProgress => write!(f, "IN PROGRESS"),
            Self::Failed => write!(f, "FAILED"),
            Self::Completed => write!(f, "COMPLETED"),
        }
    }
}

impl Display for Mission {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "[{}] {}\n  > Assigned Rover: {} (Fuel: {}%)\n  > Map Coverage: {} sectors",
            self.state,
            self.mission_name,
            self.rover.name,
            self.rover.fuel_level,
            self.rover.map_sectors.iter().count()
        )
    }
}

impl PartialEq for Mission {
    fn eq(&self, other: &Self) -> bool {
        return self.mission_name == other.mission_name;
    }
}
