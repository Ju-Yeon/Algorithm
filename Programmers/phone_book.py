def solution(phone_book):
    
    phone_book.sort()
    for idx1, val1 in enumerate(phone_book):
        for val2 in phone_book[idx1+1:]:
            if val1 == val2[:len(val1)]:
                return False;
            else:
                break
    
    return True