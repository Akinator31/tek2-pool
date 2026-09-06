use std::fmt::Display;

pub use crate::life_struct::{Board, GameOfLife};

impl GameOfLife for Board {
    fn new(size_x: i64, size_y: i64) -> Self {
        let u_x = size_x as usize;
        let u_y = size_y as usize;

        return Board {
            size_x: size_x,
            size_y: size_y,
            board: vec!['.'; u_x * u_y],
        };
    }

    fn next(&mut self) {
        let u_x = self.size_x as usize;
        let u_y = self.size_y as usize;
        let width = self.size_x as usize;

        // for i in 0..self.size_y as usize {
        //     for e in 0..self.size_x as usize {
        //         if self.board[(u_y * width) + u_x] ==
        //     }
        // }
    }

    fn add_life(&mut self, x: i64, y: i64) -> Result<(), (String)> {
        let u_x = x as usize;
        let u_y = y as usize;
        let width = self.size_x as usize;

        let index = (u_y * width) + u_x;

        if (y * self.size_x) + x > self.board.len() as i64 {
            return Err(format!("Wrong index"));
        } else {
            self.board[index] = 'o';
        }
        Ok(())
    }
}

impl Display for Board {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        for i in 0..self.size_y as usize {
            for e in 0..self.size_x as usize {
                write!(f, "{}", self.board[i + e])?;
            }
            write!(f, "\n")?;
        }
        write!(f, "")
    }
}
