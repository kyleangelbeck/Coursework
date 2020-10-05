# search.py
# ---------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


"""
In search.py, you will implement generic search algorithms which are called by
Pacman agents (in searchAgents.py).
"""

import util
from game import Directions


class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
        """
        Returns the start state for the search problem.
        """
        util.raiseNotDefined()

    def isGoalState(self, state):
        """
          state: Search state

        Returns True if and only if the state is a valid goal state.
        """
        util.raiseNotDefined()

    def getSuccessors(self, state):
        """
          state: Search state

        For a given state, this should return a list of triples, (successor,
        action, stepCost), where 'successor' is a successor to the current
        state, 'action' is the action required to get there, and 'stepCost' is
        the incremental cost of expanding to that successor.
        """
        util.raiseNotDefined()

    def getCostOfActions(self, actions):
        """
         actions: A list of actions to take

        This method returns the total cost of a particular sequence of actions.
        The sequence must be composed of legal moves.
        """
        util.raiseNotDefined()

#TODO???: Make path in the format of an acceptable return
#TODO: create print function
class node:
    def __init__(self, state, path):
        self.state = state
        self.path = path

    def getState(self):
        return self.state

    def getPath(self):
        return self.path

class prioNode:
    def __init__(self, state, path, prio):
        self.state = state
        self.path = path
        self.prio = prio

    def getState(self):
        return self.state

    def getPath(self):
        return self.path
    
    def getPrio(self):
        return self.prio

def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other maze, the
    sequence of moves will be incorrect, so only use this for tinyMaze.
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s, s, w, s, w, w, s, w]

def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first.

    Your search algorithm needs to return a list of actions that reaches the
    goal. Make sure to implement a graph search algorithm.

    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:

    print("Start:", problem.getStartState())
    print("Is the start a goal?", problem.isGoalState(problem.getStartState()))
    print("Start's successors:", problem.getSuccessors(problem.getStartState()))
    """
    "*** YOUR CODE HERE ***"

    #print("Start:", problem.getStartState())

    #nodes that have been visited
    closed = set([])
    #nodes in the frontier
    fringe = util.Stack()
    fringe.push(node(problem.getStartState(), []))

    #while frontier is not empty
    while(not fringe.isEmpty()):
        currentNode = fringe.pop()
        if(problem.isGoalState(currentNode.getState())):
            return currentNode.getPath()
        #if new node, loop through children and add them to the frontier
        if(currentNode.getState() not in closed):
            #print("PARENT: ", currentNode.getState(), currentNode.getPath())
            closed.add(currentNode.getState())
            for child in problem.getSuccessors(currentNode.getState()):
                #child[0] is child state, child[1] is direction to get to child
                #print("CHILD: ", child[0], child[1])
                fringe.push(node(child[0],currentNode.getPath()+[child[1]]))
        


    util.raiseNotDefined()

def breadthFirstSearch(problem):
    """Search the shallowest nodes in the search tree first."""

    #print("Start:", problem.getStartState())

    #nodes that have been visited
    closed = []
    #nodes in the frontier
    fringe = util.Queue()
    fringe.push(node(problem.getStartState(), []))

    #while frontier is not empty
    while(not fringe.isEmpty()):
        currentNode = fringe.pop()
        if(problem.isGoalState(currentNode.getState())):
            return currentNode.getPath()
        #if new node, loop through children and add them to the frontier
        if(currentNode.getState() not in closed):
            #print("PARENT: ", currentNode.getState(), currentNode.getPath())
            #print(closed)
            closed.append(currentNode.getState())
            for child in problem.getSuccessors(currentNode.getState()):
                #child[0] is child state, child[1] is direction to get to child
                #print("CHILD: ", child[0], child[1])
                fringe.push(node(child[0],currentNode.getPath()+[child[1]]))

    
    util.raiseNotDefined()

def uniformCostSearch(problem):
    """Search the node of least total cost first."""
    
    #print("Start:", problem.getStartState())

    #nodes that have been visited
    closed = []
    #nodes in the frontier
    fringe = util.PriorityQueue()
    fringe.push(prioNode(problem.getStartState(), [], 0), 0)

    #while frontier is not empty
    while(not fringe.isEmpty()):
        currentNode = fringe.pop()
        if(problem.isGoalState(currentNode.getState())):
            return currentNode.getPath()
        #if new node, loop through children and add them to the frontier
        if(currentNode.getState() not in closed):
            closed.append(currentNode.getState())
            for child in problem.getSuccessors(currentNode.getState()):
                #child[0] is child state, child[1] is direction to get to child
                fringe.push(prioNode(child[0],currentNode.getPath()+[child[1]],child[2]+currentNode.getPrio()),child[2]+currentNode.getPrio())


    util.raiseNotDefined()

def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearch(problem, heuristic=nullHeuristic):
    """Search the node that has the lowest combined cost and heuristic first."""
    
    #print("Start:", problem.getStartState())

    #nodes that have been visited
    closed = []
    #nodes in the frontier
    fringe = util.PriorityQueue()
    fringe.push(prioNode(problem.getStartState(), [], 0), 0)

    #while frontier is not empty
    while(not fringe.isEmpty()):
        currentNode = fringe.pop()
        if(problem.isGoalState(currentNode.getState())):
            return currentNode.getPath()
        #if new node, loop through children and add them to the frontier
        if(currentNode.getState() not in closed):
            closed.append(currentNode.getState())
            for child in problem.getSuccessors(currentNode.getState()):
                #child[0] is child state, child[1] is direction to get to child
                fringe.update(prioNode(child[0],currentNode.getPath()+[child[1]],child[2]+currentNode.getPrio()),child[2]+currentNode.getPrio()+heuristic(child[0],problem))


    util.raiseNotDefined()


# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch
