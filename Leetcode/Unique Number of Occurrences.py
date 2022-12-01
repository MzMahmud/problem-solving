class Solution:
    def uniqueOccurrences(self, array: List[int]) -> bool:
        occurrences_of_number = {}
        for number in array:
            occurrences_of_number[number] = 1 + occurrences_of_number.get(number, 0)

        occurrences = set()
        for occurrence in occurrences_of_number.values():
            if occurrence in occurrences:
                return False
            occurrences.add(occurrence)

        return True
