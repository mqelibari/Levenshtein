def levenshtein_distance(word_one: str, word_two: str) -> int:
    word_one, word_two = switch_longer_word_two_one(word_one, word_two)
    word_one = word_one.replace(" ", "")
    word_two = word_two.replace(" ", "")
    if len(word_one) == 0 or len(word_two) == 0:
        return max(len(word_one), len(word_two))
    elif len(word_one) == len(word_two) and word_two != word_one:
        distance = 0
        for i in range(len(word_one)):
            if word_two[i] != word_one[i]:
                distance += 1
        return distance
    elif len(word_one) != len(word_two):
        distance = 0
        distance += levenshtein_distance(word_one[:len(word_two)], word_two)
        return distance



def switch_longer_word_two_one(word_one, word_two):
    if len(word_one) < len(word_two):
        return word_two, word_one
    else:
        return word_one, word_two
