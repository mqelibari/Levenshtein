import unittest
from levenshtein import levenshtein_distance


class LevenshteinDistanceTestCase(unittest.TestCase):
    def test_distanceOfTwoEmptyStringsEqualsZero(self):
        result = levenshtein_distance("", "")
        self.assertEqual(0, result)

    def test_distanceOfOneCharToEmptyStringEqualsOne(self):
        result = levenshtein_distance("a", "")
        self.assertEqual(1, result)

    def test_distanceOfSpacesToStringEqualsStringLength(self):
        result = levenshtein_distance("     ", "avs")
        self.assertEqual(3, result)

    def test_distanceTwoNonEqualCharsEqualsOne(self):
        result = levenshtein_distance("a", "b")
        self.assertEqual(1, result)

    def test_distanceOfFourNonEqualCharsEqualsTwo(self):
        result = levenshtein_distance("ab", "cd")
        self.assertEqual(2, result)

    def test_distanceOfTheeNonEqualsCharsInStringEqualsThree(self):
        result = levenshtein_distance("Hamxyzmer", "Hammer")
        self.assertEqual(3, result)

    # def test_differnetWordsDifferentLength(self):
    #     result = levenshtein_distance("Auto", "Pennymarkt")
    #     self.assertEqual(9, result)


if __name__ == '__main__':
    unittest.main()
