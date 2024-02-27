fn main() {
    println!("Is 1331 a palindrome: {}", is_palindrome(1331));
    println!("Is 1313 a palindrome: {}", is_palindrome(1313));
    println!("Is 7 a palindrome: {}", is_palindrome(7));
}

fn is_palindrome(mut n: u32) -> bool {
    let mut reversed = 0;
    let initial = n;
    while n > 0 {
        reversed = (reversed * 10) + (n % 10);
        n /= 10;
    }
    initial == reversed
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let solution:bool = is_palindrome(3773);
        assert!(solution, "3773 is a palindrome.")
    }

    #[test]
    fn test2() {
        let solution:bool = is_palindrome(1313);
        assert!(!solution, "1313 is not a palindrome.")
    }

    #[test]
    fn test3() {
        let solution:bool = is_palindrome(7);
        assert!(solution, "Single digit numbers are always palindrome.")
    }
}