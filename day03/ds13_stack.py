# file : ds11_stack.py
# desc : 스택 전체 구현
import webbrowser
import time

# 스택이 가득찼는지 확인하는 함수
def isStackFull():
    global SIZE, stack, top
    if top == (SIZE - 1):
        return True # 스택이 가득찼을때
    else:
        return False

# 스택 삽입 함수
def push(data):
    global SIZE, stack, top
    if isStackFull() == True: # 기능별로 함수를 분리하는 것이 좋음
        print('스택이 꽉찼습니다.')
        return
    else:
        top += 1
        stack[top] = data

# 스택이 비어있는지 확인하는 함수
def isStackEmpty():
    global SIZE, stack, top
    if top <= -1:
        return True # 스택이 비었음
    else:
        return False
    
# 스택 추출 함수
def pop():
    global SIZE, stack, top
    if isStackEmpty() == True:
        print('스택이 비었습니다')
        return None
    else:
        data = stack[top]
        stack[top] = None
        top -= 1
        return data
    
# 스택 최종 데이터 확인함수
def peek():
    global SIZE, stack, top
    if isStackEmpty() == True:
        print('스택이 비었습니다')
        return None
    else:
        return stack[top]
    
# 전역 변수 선언
SIZE = 50
stack = [None for _ in range(SIZE)]
top = -1

# 메인코드
if __name__ == '__main__':
    urls = ['naver.com', 'daum.net', 'nate.com', 'bing.com', 'github.com']

    for url in urls:
        push(url)
        webbrowser.open('https://www.{url}')
        print(url, end=' ==> ')
        time.sleep(1)

    print('방문종료')
    print(stack)
    time.sleep(5)

    while True:
        url = pop()
        if url == None: break

        webbrowser.open(f'https://www.{url}')
        print(url, end=' ==> ')
        time.sleep(1)

    print('방문종료')