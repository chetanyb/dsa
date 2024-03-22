fn main() {
    println!("Trailing zeros in 5! is {}", count_trailing_zeros(5));
    println!("Trailing zeros in 10! is {}", count_trailing_zeros(10));
    println!("Trailing zeros in 50! is {}", count_trailing_zeros(50));
}

fn count_trailing_zeros(n: u32) -> u32 {
    let mut res = 0;
    let mut i = 5;
    while n / i >= 1 {
        res += n / i;
        i *= 5;
    }
    res
}

#[cfg(test)]

mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(count_trailing_zeros(5), 1);
    }

    #[test]
    fn test2() {
        assert_eq!(count_trailing_zeros(10), 2);
    }

    #[test]
    fn test3() {
        assert_eq!(count_trailing_zeros(50), 12);
    }
}