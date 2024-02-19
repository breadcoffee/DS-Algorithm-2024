# file : ds24_forFactorial.py
# desc : 반복문으로 팩토리얼 구하기

factValue = 1 # 곱셉이기때문에 1부터 시작

for i in range(10, 0, -1): # 10부터 1까지 역순으로
    factValue *= i

print(f'10x9x8x...x2x1 = {factValue}')

# 재귀호출 factorial
def factorial(num):
    if num <= 1: return 1
    
    return num * factorial(num-1)

print(f'10! = {factorial(10)}')
# 재귀호출 1000이 넘으면 RecursionError: maximum recursion depth exceeded로 재귀호출 최고 깊이를 초과한다.