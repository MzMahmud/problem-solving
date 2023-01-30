class Solution:
    def decodeString(self, encoded_string):
        decoded, encoded = [], []
        repeat, unpaired_braces = 0, 0
        encoded_string_started = False

        for ch in encoded_string:
            if encoded_string_started:
                if ch == ']' and unpaired_braces == 1:
                    decoded_inside = self.decodeString("".join(encoded))
                    decoded.append(decoded_inside * repeat)
                    encoded = []
                    repeat, unpaired_braces = 0, 0
                    encoded_string_started = False
                else:
                    encoded.append(ch)
                    if ch == '[':
                        unpaired_braces += 1
                    elif ch == ']':
                        unpaired_braces -= 1
            else:
                if Solution.is_english_letter(ch):
                    decoded.append(ch)
                elif Solution.is_digit(ch):
                    repeat = repeat * 10 + int(ch)
                elif ch == '[':
                    encoded_string_started = True
                    unpaired_braces += 1

        return "".join(decoded)

    @staticmethod
    def is_digit(char):
        return ord('0') <= ord(char) <= ord('9')

    @staticmethod
    def is_english_letter(char):
        return ord('a') <= ord(char) <= ord('z')
