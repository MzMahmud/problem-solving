class Solution:
    ROMAN_MAPPINGS = [
        ('M', 1000, True), ('CM', 900, False), ('D', 500, True), ('CD', 400, False),
        ('C', 100, True), ('XC', 90, False), ('L', 50, True), ('XL', 40, False),
        ('X', 10, True), ('IX', 9, False), ('V', 5, True), ('IV', 4, False),
        ('I', 1, True)
    ]

    def intToRoman(self, number):
        roman = []
        for roman_char, value, is_repeatable in Solution.ROMAN_MAPPINGS:
            if number < 1:
                break

            if number < value:
                continue

            repeat = number // value if is_repeatable else 1
            roman.append(roman_char * repeat)
            number -= repeat * value

        return "".join(roman)
