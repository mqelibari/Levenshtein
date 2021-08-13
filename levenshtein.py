def levenshtein_distance(word_one: str, word_two: str) -> int:
    if(len(word_one) == 0) or (len(word_two) == 0):
        return max(len(word_one), len(word_two))
