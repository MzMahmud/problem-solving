class Solution:
    def decodeString(self, encoded_string):
        decoded, _ = self.get_decoded_next_index(encoded_string)
        return decoded

    def get_decoded_next_index(self, encoded_string, start=0):
        decoded = []
        repeat, i = 0, start
        while i < len(encoded_string):
            ch = encoded_string[i]
            if ch == ']':
                break
            if ch == '[':
                decoded_inside, next_index = self.get_decoded_next_index(encoded_string, i + 1)
                decoded.append(decoded_inside * repeat)
                repeat, i = 0, next_index
            elif Solution.is_english_letter(ch):
                decoded.append(ch)
            elif Solution.is_digit(ch):
                repeat = repeat * 10 + int(ch)
            i += 1

        return "".join(decoded), i

    @staticmethod
    def is_digit(char):
        return ord('0') <= ord(char) <= ord('9')

    @staticmethod
    def is_english_letter(char):
        return ord('a') <= ord(char) <= ord('z')
