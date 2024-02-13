# file : ds04_orderedList.py
# desc : 선형리스트 프로그램

# 데이터 추가함수
def add_data(friend):
    kakaotalk.append(None) # 배열 빈 공간을 생성
    size = len(kakaotalk) # 배열 전체 크기
    kakaotalk[size-1] = friend

# 데이터 삽입함수
def insert_data(pos, friend):
    if pos < 0 or pos >= len(kakaotalk):
        print('데이터 삽입범위 초과')
        return # 함수를 빠져나감
    
    # 정상적인 처리 시작
    kakaotalk.append(None) # 배열 빈 공간을 생성
    size = len(kakaotalk) # 배열 전체 크기
    for i in range(size-1, pos, -1): #역순으로 size 맨뒤부터 pos까지 -1씩
        kakaotalk[i] = kakaotalk[i-1]
        kakaotalk[i-1] = None
    
    kakaotalk[pos] = friend

# 데이터 삭제
def delete_data(pos): # 데이터 삭제시는 위치값만 사용
    if pos < 0 or pos >= len(kakaotalk):
        print('데이터 삽입범위 초과')
        return # 함수를 빠져나감
    
    size = len(kakaotalk)
    kakaotalk[pos] = None # 데이터 삭제

    for i in range(pos+1, size):
        kakaotalk[i-1] = kakaotalk[i] # 뒤에 값을 앞으로
        kakaotalk[i] = None

    del(kakaotalk[size-1]) # 배열의 맨 마지막값 삭제

# 전역변수 선언
kakaotalk = [] # 빈 배열 생성
select = -1 # 1/추가 2/삽입 3/삭제 4/종료

if __name__ == '__main__':
    while (select != 4):
        select = int(input('메뉴 선택(1:추가, 2:삽입, 3:삭제, 4:종료) > '))
        # 데이터 입력
        if select == 1:
            data = input('추가 데이터 입력 > ')
            add_data(data)
            print(kakaotalk)
        # 데이터 삽입
        elif select == 2:
            pos = int(input('삽입 위치 입력 > '))
            data = input('추가 데이터 입력 > ')
            insert_data(pos, data)
            print(kakaotalk)
        # 데이터 삭제
        elif select == 3:
            pos = int(input('삭제 위치 입력 > '))
            delete_data(pos)
            print(kakaotalk)
        # 프로그램 종료
        elif select == 4:
            exit(0)
        #예외처리
        else:
            print('1-4의 숫자 중 하나를 입력하세요')
            continue