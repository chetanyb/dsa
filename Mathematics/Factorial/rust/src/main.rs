fn main() {
    println!("factorial_recursive of 4 is {}", factorial_recursive(4));
    println!("factorial_recursive of 2 is {}", factorial_recursive(2));
    println!("factorial_recursive of 5 is {}", factorial_recursive(5));
    println!("factorial_recursive of 1 is {}", factorial_recursive(1));
    println!("factorial_iterative of 4 is {}", factorial_iterative(4));
    println!("factorial_iterative of 2 is {}", factorial_iterative(2));
    println!("factorial_iterative of 5 is {}", factorial_iterative(5));
    println!("factorial_iterative of 1 is {}", factorial_iterative(1));
}

fn factorial_recursive(n: u32) -> u64 {
    if n == 0 {
        1
    }
    else {
        n as u64 * factorial_recursive(n - 1)
    }
}

fn factorial_iterative(mut n: u32) -> u64 {
    let mut factorial: u64 = 1;
    while n > 0 {
        factorial *= n as u64;
        n -= 1;
    }
    factorial
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(factorial_recursive(4), 24);
        assert_eq!(factorial_iterative(4), 24);
    }

    #[test]
    fn test2() {
        assert_eq!(factorial_recursive(1), 1);
        assert_eq!(factorial_iterative(1), 1);
    }

    #[test]
    fn test3() {
        assert_eq!(factorial_recursive(0), 1);
        assert_eq!(factorial_iterative(0), 1);
    }

    #[test]
    fn test4() {
        assert_eq!(factorial_recursive(12), 479001600);
        assert_eq!(factorial_iterative(12), 479001600);
    }
}