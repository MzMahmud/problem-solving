import java.util.Arrays;
import java.util.Map;
import java.util.Optional;
import java.util.Stack;
import java.util.function.BiFunction;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.stream.Collectors;

public class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> values = new Stack<>();
        for (String token : tokens) {
            int a, b;
            switch (token) {
                case "+" -> {
                    b = values.pop();
                    a = values.pop();
                    values.push(a + b);
                }
                case "-" -> {
                    b = values.pop();
                    a = values.pop();
                    values.push(a - b);
                }
                case "*" -> {
                    b = values.pop();
                    a = values.pop();
                    values.push(a * b);
                }
                case "/" -> {
                    b = values.pop();
                    a = values.pop();
                    values.push(a / b);
                }
                default -> values.push(Integer.parseInt(token));
            }
        }
        return values.pop();
    }

    public int evalRPNOpenClosePrinciple(String[] tokens) {
        Stack<Integer> parameters = new Stack<>();
        Consumer<BinaryOperator> calculateAndAddResult = binaryOperator -> {
            int b = parameters.pop();
            int a = parameters.pop();
            parameters.push(binaryOperator.calculate(a, b));
        };
        for (String token : tokens) {
            Runnable addParameter = () -> parameters.push(Integer.parseInt(token));
            BinaryOperator.getBySign(token)
                          .ifPresentOrElse(calculateAndAddResult, addParameter);
        }
        return parameters.pop();
    }

    enum BinaryOperator {
        ADD("+", Integer::sum),
        SUBTRACT("-", (a, b) -> a - b),
        MULTIPLY("*", (a, b) -> a * b),
        DIVISION("/", (a, b) -> a / b);

        private final String sign;
        private final BiFunction<Integer, Integer, Integer> operate;
        private static final Map<String, BinaryOperator> mapBySign =
                Arrays.stream(values())
                      .collect(Collectors.toMap(BinaryOperator::getSign, Function.identity()));

        public String getSign() {
            return sign;
        }

        public static Optional<BinaryOperator> getBySign(String sign) {
            return Optional.ofNullable(mapBySign.get(sign));
        }

        public int calculate(int a, int b) {
            return operate.apply(a, b);
        }

        BinaryOperator(String sign, BiFunction<Integer, Integer, Integer> operate) {
            this.sign = sign;
            this.operate = operate;
        }
    }
}
