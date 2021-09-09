import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;



public class Solution {
    public static int sumOfDigits(int number) {
        return IntStream.iterate(number, n -> n > 0, n -> n / 10)
                        .map(n -> n % 10)
                        .sum();
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int number = Integer.parseInt(bufferedReader.readLine().trim());
        
        Comparator<Integer> kristenComparator = (a, b) -> {
            int sodA = sumOfDigits(a);
            int sodB = sumOfDigits(b);
            return (sodA != sodB) ? sodA - sodB : b - a;
        };
        
        System.out.println(
                Stream.iterate(1, n -> (n * n) <= number, n -> n + 1)
                      .filter(n -> number % n == 0)
                      .flatMap(n -> n == (number / n) ? Stream.of(n) : Stream.of(number / n))
                      .max(kristenComparator)
                      .orElse(0)
        );
        bufferedReader.close();
    }
}
