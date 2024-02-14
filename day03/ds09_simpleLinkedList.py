# file : ds09_simpleLinkedList.py
# desc : 단순연결 리스트 전체 구현

# 노드 클래스
class Node():
    data = None # 실제 데이터 변수
    link = None # 다음 노드 지정 변수

    def __init__(self) -> None:
        self.data

# 노드 출력함수
def printNodes(start): # start부터 시작해서 끝까지 노드.data 출력
    curr = start
    if curr == None: return
    while True:
        if curr.link == None: # 연결할 노드가 더이상 없으면
            print(curr.data) # 자기 데이터만 출력
            break   # 반복문 탈출
        else:
            print(curr.data, end=' -> ')
            curr = curr.link # 자기 뒤의 데이터를 curr로 바꿔줌

# 노드 삽입함수
def insertNode(find, data):
    global head, prev, curr # 전역변수를 insertNode()에서 사용하겠다고 선언

    if head.data == find: # 맨 첫번째 노드
        node = Node()
        node.data = data
        node.link = head
        head = node
        return # 함수 탈출
    
    curr = head # curr가 제일 처음으로 이동
    while curr.link != None:
        prev = curr # prev와 curr가 같은 노드를 가리킴
        curr = curr.link # curr가 가리키는 다음 값을 curr로 지정(prev는 앞에 있고 curr가 뒤로 한칸 넘어가)

        if curr.data == find:
            node = Node()
            node.data = data
            node.link = curr
            prev.link = node

    node = Node() # 맨 마지막에 노드 삽입
    node.data = data
    curr.link = node
    return

# 노드 삭제함수
def deleteNode(data):
    global head, prev, curr
    
    if head.data == data: # 첫번째 노드 삭제시
        curr = head
        head = head.link
        del(curr)
        return
    
    curr = head
    while curr.link != None:
        prev = curr
        curr = curr.link

        if curr.data == data:
            prev.link = curr.link
            del(curr)
            return
        
# 노드 검색함수
def findNode(find):
    global head, curr

    curr = head # curr 사용되는 변수라서 이 작업을 항상 해줘야함
    if curr.data == find:
        return curr # 현재 노드를 리턴해주고 함수 탈출
    while curr.link != None:
        curr = curr.link # 다음 노드로 넘김
        if curr.data == find:
            return curr
    return Node() # 위 조건에 만족하지 못하면 빈노드를 호출하고 탈출

# 전역변수
head, prev, curr = None, None, None
originData = ['다현', '정연', '쯔위', '사나', '지효']

# 메인코드 영역
if __name__ == '__main__':
    node = Node()
    node.data = originData[0] # = '다현'
    head = node # head는 node를 가리킴

    for name in originData[1:]: # 1번 인덱스부터 리스트 끝까지
        prev = node
        node = Node()
        node.data = name
        prev.link = node
    
    # 연결리스트 구성완료
    print('최초 구성된 연결리스트')
    printNodes(head) # 구성된 연결리스트가 맞는지 확인

    # 노드 삽입
    print('맨앞 노드 삽입')
    insertNode('다현', '정국')
    printNodes(head)

    insertNode('사나', '미미')
    print('중간노드 삽입')
    printNodes(head)

    insertNode('재남', 'RM') # 재남이란 노드가 없으니 마지막 노드로 삽입
    print('마지막 노드 삽입')
    printNodes(head)

    # 노드 삭제
    deleteNode('정국')
    print('맨앞 노드 삭제')
    printNodes(head)

    deleteNode('쯔위')
    print('중간 노드 삭제')
    printNodes(head)

    deleteNode('재남') # 아무것도 삭제 안됨
    print('없는 노드 삭제')
    printNodes(head)

    # 노드 검색
    fNode = findNode('다현')
    printNodes(head)
    print(f'찾은 노드 : {fNode.data}')

    fNode = findNode('쯔위') # 위에서 삭제된 노드 검색
    printNodes(head)
    print(f'찾은 노드 : {fNode.data}') # None