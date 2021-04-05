def solution(participant, completion):
    participant.sort();
    completion.sort();
    
    for i in range(len(completion)):
        if completion[i] != participant[i]:
            break;
    
    if completion[i] == participant[i]:
        return participant[i+1]
    else:
        return participant[i]

