class Solution:
    def fractionToDecimal(self, a: int, b: int) -> str:
        if b < 0:
            a = -a
            b = -b

        dec = ''
        if a < 0:
            dec = '-'
            a = -a

        dec += str(a//b)

        if a % b != 0:
            dec += ('.' + Solution.recurring_decimal(a % b, b, '', []))

        return dec

    @staticmethod
    def recurring_decimal(a, b, c, prev_a):
        if a == 0:
            return c

        if a in prev_a:
            out = ''
            rec = prev_a.index(a)
            for i in range(len(prev_a)):
                out += (('(' if i == rec else '') + c[i])

            return out + ')'

        prev_a.append(a)

        a = (10 * a) if b > a else a
        c += str(a//b)
        a = a % b

        return Solution.recurring_decimal(a, b, c, prev_a)


s = Solution()

print(s.fractionToDecimal(1, 13))
