import java.io.*;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {
    public static int compareBigInteger(String a, String b) {
        if (a.length() != b.length()) return a.length() - b.length();
        for (int i = 0; i < a.length(); ++i) {
            char digitOfA = a.charAt(i);
            char digitOfB = b.charAt(i);
            if (digitOfA != digitOfB)
                return digitOfA - digitOfB;
        }
        return 0;
    }

    public static List<String> bigSorting(List<String> unsorted) {
        return unsorted.stream()
                       .sorted(Result::compareBigInteger)
                       .collect(Collectors.toList());
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> unsorted = IntStream.range(0, n).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
                                         .collect(toList());

        List<String> result = Result.bigSorting(unsorted);

        bufferedWriter.write(
                result.stream()
                      .collect(joining("\n"))
                        + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
