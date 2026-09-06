use std::{env::args, fs::read_to_string, io::Error, process::ExitCode};

fn verify_documents(document: &String) -> Result<String, ()> {
    let mut first_line_find = false;
    let mut second_line_find = false;

    let mut first = 0;
    let mut last = 0;

    for (line, content) in document.lines().enumerate() {
        if content.is_empty() {
            continue;
        }

        if content.chars().all(|c| c == '=') && !first_line_find {
            first = line;
            first_line_find = true;
            continue;
        }
        if content.trim().chars().all(|c| c == '=') && first_line_find && !second_line_find {
            last = line;
            second_line_find = true;
            break;
        }
    }

    if first_line_find && second_line_find {
        let mut slice = document.lines().collect::<Vec<&str>>();
        slice.truncate(last + 1);

        let mut text = slice.join("\n").to_string();

        text = text.lines().skip(first).collect::<Vec<&str>>().join("\n");

        return Ok(text);
    }
    return Err(());
}

fn open_document(document1: &String, document2: &String) -> Result<(String, String), Error> {
    let file1 = read_to_string(document1)?;
    let file2 = read_to_string(document2)?;

    return Ok((file1, file2));
}

fn print_error() -> ExitCode {
    eprintln!("The document is probably not arrived yet...");
    return ExitCode::from(84);
}

fn analyze_document(file1: &String, file2: &String, department: &String) -> Result<(), ()> {
    let mut department_doc1 = "";
    let mut department_doc2 = "";

    for line in file1.lines() {
        if line.contains(department) {
            department_doc1 = line;
        }
    }

    for line in file2.lines() {
        if line.contains(department) {
            department_doc2 = line;
        }
    }

    if !department_doc1.is_empty() && department_doc2.is_empty() {
        println!("Department deleted this year, no comparisons possible !");
        return Ok(());
    }

    if department_doc1.is_empty() && !department_doc2.is_empty() {
        println!("Department created this year, no comparisons possible !");
        return Ok(());
    }

    let (_, doc_stat1) = department_doc1.split_once(":").unwrap_or(("", ""));
    let (_, doc_stat2) = department_doc2.split_once(":").unwrap_or(("", ""));

    if doc_stat1.is_empty() || doc_stat2.is_empty() {
        return Err(());
    }

    let data1 = doc_stat1.trim().split_once(" ").unwrap_or(("", "")).0;
    let data2 = doc_stat2.trim().split_once(" ").unwrap_or(("", "")).0;

    let percent1 = match data1.parse::<f32>() {
        Ok(value) => value,
        Err(e) => {
            print!("[{} : {}]\n", doc_stat1, e.to_string());
            return Err(());
        }
    };

    let percent2 = match data2.parse::<f32>() {
        Ok(value) => value,
        Err(_) => {
            print!("HELLO\n");
            return Err(());
        }
    };

    if percent2 == 0.0 {
        println!(
            "This year the budget of the department of {} has been lowered by -100.00%",
            department
        );
        return Ok(());
    }

    let result = ((percent2 - percent1) / percent1) * 100.00;

    if result < 0.0 {
        println!(
            "This year the budget of the department of {} has been lowered by {:.2}%",
            department, result
        );
        return Ok(());
    } else {
        println!(
            "This year the budget of the department of {} has been raised by {:.2}%",
            department, result
        );
        return Ok(());
    }
}

fn main() -> ExitCode {
    let args: Vec<String> = args().collect();

    if args.len() != 4 {
        return print_error();
    }

    let (file1, file2) = match open_document(&args[1], &args[2]) {
        Ok(documents) => {
            match verify_documents(&documents.0) {
                Ok(..) => {}
                Err(..) => {
                    return print_error();
                }
            }
            match verify_documents(&documents.1) {
                Ok(..) => documents,
                Err(..) => {
                    return print_error();
                }
            }
        }
        Err(..) => return print_error(),
    };

    match analyze_document(&file1, &file2, &args[3].to_string()) {
        Ok(_) => return ExitCode::from(0),
        Err(_) => return print_error(),
    }
}
