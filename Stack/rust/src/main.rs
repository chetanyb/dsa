use std::io::{self, Write};

fn main() {
    let mut stack = Stack::new();
    loop {
        println!("1. Push");
        println!("2. Pop");
        println!("3. Peek");
        println!("4. Exit");
        print!("Enter your choice: ");
        io::stdout().flush().unwrap();

        let mut choice = String::new();
        io::stdin().read_line(&mut choice).unwrap();
        let choice: i32 = choice.trim().parse().unwrap();

        match choice {
            1 => {
                print!("Enter a number: ");
                io::stdout().flush().unwrap();
                let mut num = String::new();
                io::stdin().read_line(&mut num).unwrap();
                let num: i32 = num.trim().parse().unwrap();
                stack.push(num);
            },
            2 => {
                if let Some(val) = stack.pop() {
                    println!("Popped value: {}", val);
                }
            },
            3 => {
                if let Some(val) = stack.peek() {
                    println!("Top element is: {}", val);
                }
            },
            4 => break,
            _ => println!("Invalid choice"),
        }
    }
}

pub struct Stack {
    a: Vec<i32>,
    top: isize,
}

impl Stack {
    pub fn new() -> Self {
        Stack {
            a: Vec::new(),
            top: -1,
        }
    }

    pub fn push(&mut self, x: i32) -> bool {
        self.a.push(x);
        self.top += 1;
        println!("{} pushed into stack", x);
        true
    }

    pub fn pop(&mut self) -> Option<i32> {
        if self.top < 0 {
            println!("Stack Underflow");
            None
        } else {
            self.top -= 1;
            self.a.pop()
        }
    }

    pub fn peek(&self) -> Option<i32> {
        if self.top < 0 {
            println!("Stack is Empty");
            None
        } else {
            Some(self.a[self.top as usize])
        }
    }
}