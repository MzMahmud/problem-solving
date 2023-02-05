hex_map = [
    '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
]


class Solution:
    def toHex(self, number):
        if number == 0:
            return "0"

        unsigned = (number | (1 << 32)) & ~(1 << 32)
        hex = []
        for _ in range(8):
            if unsigned == 0:
                break

            hex_digit = unsigned & 15
            hex.append(hex_map[hex_digit])
            unsigned >>= 4

        return "".join(reversed(hex))
