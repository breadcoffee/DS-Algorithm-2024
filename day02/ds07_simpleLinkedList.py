# file : ds07_simpleLinkedList.ipynb
# desc : 단순 연결 리스트 일반 구현

# 초기화
memory = []
head, curr, prev = None, None, None

# 연결리스트 노트 클래스
class Node():
    # data. link 두개의 멤버변수 존재
    # 생성자 추가
    def __init__(self, name) -> None:
        self.data = name
        self.link = None

# 연결 리스트 출력 방법(반복문)
def printNodes(start):
    curr = start
    if curr == None: return # 값이 없어 함수를 빠져나감
    print(curr.data, end=' -> ')
    while curr.link != None:
        curr = curr.link # 내 노드 다음의 노드가 current가 됨
        if curr.link == None:
            print(curr.data)
        else:
            print(curr.data, end=' -> ')

dataArray = ['다현', '정연', '쯔위', '사나', '지효']

# 메인시작
if __name__=='__main__':
    node = Node(dataArray[0])
    head = node # 첫번째 값을 head가 가리킴
    memory.append(node) # 메모리에 저장

    for data in dataArray[1:]: # 두번째 노드부터 끝까지
        prev = node
        node = Node(data) # 두번째 값(정연)이 들어있음
        prev.link = node
        memory.append(node)