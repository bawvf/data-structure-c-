#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 10

typedef char E;

typedef struct Node {
    int nextVertex;
    struct Node * next;
} * Node;

struct HeadNode {
    E element;
    struct Node * next;
};

typedef struct AdjacecyGraph {
    int vertexCount;  //������
    int edgeCount;  //����
    struct HeadNode vertex[MaxVertex];
} * Graph;

Graph create() {
    Graph graph = malloc(sizeof (struct AdjacecyGraph));
    graph->vertexCount = graph->edgeCount = 0;
    return graph;
}

//���붥��
void addVertex(Graph graph, E element) {
    graph->vertex[graph->vertexCount].element = element;
    graph->vertex[graph->vertexCount].next = NULL;
    graph->vertexCount++;
}

//�����
void addEdge(Graph graph, int a, int b) {
    Node node = graph->vertex[a].next;
    Node newNode = malloc(sizeof (struct Node));
    newNode->next = NULL;
    newNode->nextVertex = b;
    if (!node) {
        graph->vertex[a].next = newNode;
    } else {
        do {
            if (node->nextVertex == b)
                return;
            if (node->next)
                node = node->next;
            else break;
        } while (1);
        node->next = newNode;
    }
    graph->edgeCount++;
}

//��ӡ
void printGraph(Graph graph) {
    for (int i = 0; i < graph->vertexCount; ++i) {
        printf("%d | %c", i, graph->vertex[i].element);
        Node node = graph->vertex[i].next;
        while (node) {
            printf(" -> %d", node->nextVertex);
            node = node->next;
        }
        putchar('\n');
    }
}

typedef int T;   //���ｫ�����±���ΪԪ��

struct QueueNode {
    T element;
    struct QueueNode * next;
};

typedef struct QueueNode * QNode;

struct Queue{
    QNode front, rear;
};

typedef struct Queue * LinkedQueue;

_Bool initQueue(LinkedQueue queue){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    queue->front = queue->rear = node;
    return 1;
}

_Bool offerQueue(LinkedQueue queue, T element){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

_Bool isEmpty(LinkedQueue queue){
    return queue->front == queue->rear;
}

T pollQueue(LinkedQueue queue){
    T e = queue->front->next->element;
    QNode node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if(queue->rear == node) queue->rear = queue->front;
    free(node);
    return e;
}


/**
 * ������������㷨
 * @param graph ͼ
 * @param startVertex ��㶥���±�
 * @param targetVertex Ŀ�궥���±�
 * @param visited �ѵ�����Ķ�������
 */
_Bool dfs(Graph graph, int startVertex, int targetVertex, int * visited){
    printf("%c -> ", graph->vertex[startVertex].element);
    visited[startVertex] = 1;
    if (startVertex == targetVertex)
        return 1;
    Node node = graph->vertex[startVertex].next;
    while (node) {
        if (!visited[node->nextVertex])
            if (dfs(graph, node->nextVertex, targetVertex, visited))
                return 1;
        node = node->next;
    }
    return 0;
}

/**
 * ������ȱ���
 * @param graph ͼ
 * @param startVertex ��㶥���±�
 * @param targetVertex Ŀ�궥���±�
 * @param visited �ѵ�����Ķ�������
 * @param queue ��������
 */
_Bool bfs(Graph graph, int startVertex, int targetVertex, int * visited, LinkedQueue queue) {
    offerQueue(queue, startVertex);  //���Ȱ���ʼλ�ö��㶪��ȥ
    visited[startVertex] = 1;
    while (!isEmpty(queue)) {
        int next = pollQueue(queue);
        printf("%c -> ", graph->vertex[next].element);
        Node node = graph->vertex[next].next;
        while (node) {
            if (node->nextVertex == targetVertex)
                return 1;
            if (!visited[node->nextVertex]) {
                offerQueue(queue, node->nextVertex);
                visited[node->nextVertex] = 1;
            }
            node = node->next;
        }
    }
    return 0;
}


int main(){
    Graph graph = create();
    for (int c = 'A'; c <= 'F' ; ++c)
        addVertex(graph, (char) c);
    addEdge(graph, 0, 1);   //A -> B
    addEdge(graph, 1, 2);   //B -> C
    addEdge(graph, 1, 3);   //B -> D
    addEdge(graph, 1, 4);   //D -> E
    addEdge(graph, 4, 5);   //E -> F
    addEdge(graph, 3, 6);
    
    int arr[graph->vertexCount];
    for (int i = 0; i < graph->vertexCount; ++i)
        arr[i] = 0;
    struct Queue queue;
    initQueue(&queue);
    printf("\n%d", bfs(graph, 0, 5, arr, &queue));
}


