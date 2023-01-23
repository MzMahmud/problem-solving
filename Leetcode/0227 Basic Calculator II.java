// Tutorial https://cp-algorithms.com/string/expression_parsing.html#right-associativity
// Supports expression with non-negative numbers, +, -, *, / (integer divide), (, )

public class Solution {
    public int calculate(String s) {
        Stack<Integer> params = new Stack<>();
        Stack<Character> operators = new Stack<>();
        for (int i = 0; i < s.length(); ++i) {
            char ch = s.charAt(i);
            if (DELIMITERS.contains(ch)) {
                continue;
            }
            if (ch == '(') {
                operators.push('(');
            } else if (ch == ')') {
                while (operators.peek() != '(') {
                    doOperation(operators.pop(), params);
                }
                operators.pop();
            } else if (isDigit(ch)) {
                int number = 0;
                while (i < s.length() && isDigit(s.charAt(i))) {
                    number = number * 10 + s.charAt(i) - '0';
                    ++i;
                }
                --i;
                params.push(number);
            } else if (OPERATORS.contains(ch)) {
                while (!operators.isEmpty() && priority(ch) <= priority(operators.peek())) {
                    doOperation(operators.pop(), params);
                }
                operators.push(ch);
            }
        }
        while (!operators.isEmpty()) {
            doOperation(operators.pop(), params);
        }
        return params.peek();
    }

    private static final Set<Character> DELIMITERS = Set.of(' ');
    private static final Set<Character> OPERATORS = Set.of('+', '-', '*', '/');

    private boolean isDigit(char ch) {
        return '0' <= ch && ch <= '9';
    }

    private int priority(char operator) {
        return switch (operator) {
            case '+', '-' -> 0;
            case '*', '/' -> 1;
            default -> -1;
        };
    }

    private void doOperation(char operator, Stack<Integer> params) {
        int r = params.pop();
        int l = params.pop();
        int result = switch (operator) {
            case '+' -> l + r;
            case '-' -> l - r;
            case '*' -> l * r;
            case '/' -> l / r;
            default -> throw new IllegalArgumentException("Unexpected value: " + operator);
        };
        params.add(result);
    }
}
