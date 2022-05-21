from collections import defaultdict
class DGRAPH:

	def __init__(self):
		self.DGRAPH = defaultdict(list)

	def Edge(self,a,b):
		self.DGRAPH[a].append(b)

	def bFS(self, x):

		Visit = [False] * (max(self.DGRAPH) + 1)
		queue = []

		queue.append(x)
		Visit[x] = True

		while queue:
			x = queue.pop(0)
			print (x, end = " ")

			for n in self.DGRAPH[x]:
				if Visit[n] == False:
					queue.append(n)
					Visit[n] = True
G = DGRAPH()
G.Edge(0, 1)
G.Edge(0, 2)
G.Edge(1, 2)
G.Edge(1, 3)
G.Edge(2, 3)
G.Edge(3, 4)
G.Edge(4, 4)

print("Breadth_First_Search (starting from vertex 0)")
G.bFS(0)

