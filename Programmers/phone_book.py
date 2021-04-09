def solution(phone_book):
    h = set()
    for i in phone_book:
        for l in range(1, len(i)):
            h.add(i[:l])
    for i in phone_book:
        if i in h:
            return False
    return True