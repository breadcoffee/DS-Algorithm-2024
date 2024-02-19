# file : ds22_rc.py
# desc : 재귀호출
import time

# 재귀 호출은 무한반복처럼 보이지만 무한반복이 아님
# 자신이 호출한 것을 다시 돌아가야하기때문에 맥시멈이 정해져있음
def open_box():
    global count
    print(f'{count}번째 상자를 엽니다')
    count -= 1
    if count == 0: # count가 0이 되었을때 반환함
        print('반지를 넣고 반환합니다')
        return

    time.sleep(0.1)
    open_box()
    print('상자를 닫습니다')

# 전역변수
count = 10

if __name__ == '__main__':
    open_box()