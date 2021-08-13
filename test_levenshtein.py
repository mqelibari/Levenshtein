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


if __name__ == '__main__':
    unittest.main()