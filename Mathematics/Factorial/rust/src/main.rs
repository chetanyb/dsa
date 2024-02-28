fn main() {
    println!("Factorial of 4 is {}", factorial(4));
    println!("Factorial of 2 is {}", factorial(2));
    println!("Factorial of 5 is {}", factorial(5));
    println!("Factorial of 1 is {}", factorial(1));
}

fn factorial(n: u32) -> u64 {
    if n == 0 {
        1
    }
    else {
        n as u64 * factorial(n - 1)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(factorial(4), 24);
    }

    #[test]
    fn test2() {
        assert_eq!(factorial(1), 1);
    }

    #[test]
    fn test3() {
        assert_eq!(factorial(0), 1);
    }

    #[test]
    fn test4() {
        assert_eq!(factorial(12), 479001600);
    }
}