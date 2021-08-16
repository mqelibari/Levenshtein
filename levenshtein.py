def levenshtein_distance(word_one: str, word_two: str) -> int:
    word_one, word_two = switch_longer_word_two_one(word_one, word_two)
    word_one = word_one.replace(" ", "")
    word_two = word_two.replace(" ", "")
    if len(word_one) == 0 or len(word_two) == 0:
        return max(len(word_one), len(word_two))
    if word_one[-1] != word_two[-1]:
        distance = 1
    else:
        distance = 0

    delete = levenshtein_distance(word_one[:-1], word_two) + 1
    insert = levenshtein_distance(word_one, word_two[:-1]) + 1
    same = levenshtein_distance(word_one[:-1], word_two[:-1]) + distance

    return min(delete, insert, same)


def switch_longer_word_two_one(word_one, word_two):
    if len(word_one) < len(word_two):
        return word_two, word_one
    else:
        return word_one, word_two
