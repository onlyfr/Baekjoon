import sys; input=sys.stdin.readline
def bellmanFord(x, edges):
    dist=[1<<30]*(N+1)
    dist[x]=0 
    for _ in range(N-1):
        for edge in edges:
            s, e, t = edge 
            dist[e] = min(dist[s]+t, dist[e])
    for edge in edges:
        s, e, t = edge 
        if dist[e] > dist[s]+t: return True
    return False
for _ in range(int(input())):
    N, M, W = map(int, input().split())
    edges = []
    for _ in range(M):
        s, e, t = map(int, input().split())
        edges.append((s,e,t))
        edges.append((e,s,t))
    for _ in range(W):
        s, e, t = map(int, input().split())
        edges.append((s,e,-t))
    print("YES" if bellmanFord(1, edges) else "NO")