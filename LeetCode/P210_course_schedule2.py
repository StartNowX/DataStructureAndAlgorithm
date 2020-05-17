from typing import List
import collections

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        self.__edges = collections.defaultdict(list)
        self.__visited = [0] * numCourses
        self.__invalid = False
        self.__result = []

        for item in prerequisites:
            self.__edges[item[1]].append(item[0])
        
        for i in range(numCourses):
            if not self.__invalid and not self.__visited[i]:
                self.__dfs(i)

        if self.__invalid:
            return []

        return self.__result[::-1]
        
    def __dfs(self, u: int):
        self.__visited[u] = 1

        for item in self.__edges[u]:
            if self.__visited[item] == 0:
                self.__dfs(item)

                if self.__invalid:
                    return
            elif self.__visited[item] == 1:
                self.__invalid = True
                return

        self.__visited[u] = 2
        self.__result.append(u)

        return