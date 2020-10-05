# multiAgents.py
# --------------
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


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
    """
    A reflex agent chooses an action at each choice point by examining
    its alternatives via a state evaluation function.

    The code below is provided as a guide.  You are welcome to change
    it in any way you see fit, so long as you don't touch our method
    headers.
    """


    def getAction(self, gameState):
        """
        You do not need to change this method, but you're welcome to.

        getAction chooses among the best options according to the evaluation function.

        Just like in the previous project, getAction takes a GameState and returns
        some Directions.X for some X in the set {NORTH, SOUTH, WEST, EAST, STOP}
        """
        # Collect legal moves and successor states
        legalMoves = gameState.getLegalActions()

        # Choose one of the best actions
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Pick randomly among the best

        "Add more of your code here if you want to"
        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Design a better evaluation function here.

        The evaluation function takes in the current and proposed successor
        GameStates (pacman.py) and returns a number, where higher numbers are better.

        The code below extracts some useful information from the state, like the
        remaining food (newFood) and Pacman position after moving (newPos).
        newScaredTimes holds the number of moves that each ghost will remain
        scared because of Pacman having eaten a power pellet.

        Print out these variables to see what you're getting, then combine them
        to create a masterful evaluation function.
        """
        # Useful information you can extract from a GameState (pacman.py)
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        newPos = successorGameState.getPacmanPosition()
        newFood = successorGameState.getFood()
        newGhostStates = successorGameState.getGhostStates()
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]

        "*** YOUR CODE HERE ***"
        #if list isn't empty
        if newFood.asList():
            foodDistance = manhattanDistance(newFood[0],newPos)
            closestFood = newFood.asList()[0]
        else:
            return successorGameState.getScore() + 100

        #find distance to closest food
        for food in newFood.asList():
            temp = manhattanDistance(food,newPos)
            if temp < foodDistance:
                foodDistance = temp
                closestFood = food
                #print(temp)
                #print(food)

        #print(action)
        #print(closestFood)
        #print(newPos)
        #print(manhattanDistance(closestFood, newPos))
        #print(newFood.asList())

        return successorGameState.getScore() + (1/manhattanDistance(closestFood, newPos))

def scoreEvaluationFunction(currentGameState):
    """
    This default evaluation function just returns the score of the state.
    The score is the same one displayed in the Pacman GUI.

    This evaluation function is meant for use with adversarial search agents
    (not reflex agents).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
    This class provides some common elements to all of your
    multi-agent searchers.  Any methods defined here will be available
    to the MinimaxPacmanAgent, AlphaBetaPacmanAgent & ExpectimaxPacmanAgent.

    You *do not* need to make any changes here, but you can if you want to
    add functionality to all your adversarial search agents.  Please do not
    remove anything, however.

    Note: this is an abstract class: one that should not be instantiated.  It's
    only partially specified, and designed to be extended.  Agent (game.py)
    is another abstract class.
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Pacman is always agent index 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
    Your minimax agent (question 2)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action from the current gameState using self.depth
        and self.evaluationFunction.

        Here are some method calls that might be useful when implementing minimax.

        gameState.getLegalActions(agentIndex):
        Returns a list of legal actions for an agent
        agentIndex=0 means Pacman, ghosts are >= 1

        gameState.generateSuccessor(agentIndex, action):
        Returns the successor game state after an agent takes an action

        gameState.getNumAgents():
        Returns the total number of agents in the game

        gameState.isWin():
        Returns whether or not the game state is a winning state

        gameState.isLose():
        Returns whether or not the game state is a losing state
        """
        "*** YOUR CODE HERE ***"
        
        
        #print(self.depth)
        #print(gameState.getNumAgents())
        def recursionSux(state, i):
            #print(i)
            #If state is a winning or losing state, or if state is the final agent of the lowest depth
            #Then does not need to expand state. Just returns the evaluationfunction.
            if i == self.depth*gameState.getNumAgents() or state.isWin() or state.isLose():
                return self.evaluationFunction(state)

            #when i is divisible by numAgents, then it is pacmans turn
            if i%gameState.getNumAgents() == 0:
                bestScore = float("-inf")
                bestAction = state.getLegalActions(0)[0]
                for action in state.getLegalActions(0):
                    successorState = state.generateSuccessor(0, action)
                    successorScore = recursionSux(successorState, i+1)
                    if successorScore > bestScore:
                        bestScore = successorScore
                        bestAction = action
                #return action to take if top of tree, otherwise return the max score.
                if i == 0:
                    return bestAction
                else:
                    return bestScore
            #otherwise it is ghosts turn
            else:
                worstScore = float("inf")
                for action in state.getLegalActions(i%gameState.getNumAgents()):
                    successorState = state.generateSuccessor(i%gameState.getNumAgents(), action)
                    successorScore = recursionSux(successorState, i+1)
                    if successorScore < worstScore:
                        worstScore = successorScore
                return worstScore


        return recursionSux(gameState, 0)


class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    Your minimax agent with alpha-beta pruning (question 3)
    """

    def getAction(self, gameState):
        """
        Returns the minimax action using self.depth and self.evaluationFunction
        """
        
        #print(self.depth)
        #print(gameState.getNumAgents())
        def recursionStillSux(state, i, a, b):
            #print(i)
            #If state is a winning or losing state, or if state is the final agent of the lowest depth
            #Then does not need to expand state. Just returns the evaluationfunction.
            if i == self.depth*gameState.getNumAgents() or state.isWin() or state.isLose():
                return self.evaluationFunction(state)

            #when i is divisible by numAgents, then it is pacmans turn
            if i%gameState.getNumAgents() == 0:
                bestScore = float("-inf")
                bestAction = state.getLegalActions(0)[0]
                for action in state.getLegalActions(0):
                    successorState = state.generateSuccessor(0, action)
                    successorScore = recursionStillSux(successorState, i+1, a, b)
                    if successorScore > bestScore:
                        bestScore = successorScore
                        bestAction = action
                    if bestScore > b:
                        if i == 0:
                            return bestAction
                        else:
                            return bestScore
                    a = max(a, bestScore)
                #return action to take if top of tree, otherwise return the max score.
                if i == 0:
                    return bestAction
                else:
                    return bestScore
            #otherwise it is ghosts turn
            else:
                worstScore = float("inf")
                for action in state.getLegalActions(i%gameState.getNumAgents()):
                    successorState = state.generateSuccessor(i%gameState.getNumAgents(), action)
                    successorScore = recursionStillSux(successorState, i+1, a, b)
                    if successorScore < worstScore:
                        worstScore = successorScore
                    if worstScore < a:
                        return worstScore
                    b = min(b, worstScore)
                return worstScore


        return recursionStillSux(gameState, 0, float("-inf"), float("inf"))



        util.raiseNotDefined()

class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Your expectimax agent (question 4)
    """

    def getAction(self, gameState):
        """
        Returns the expectimax action using self.depth and self.evaluationFunction

        All ghosts should be modeled as choosing uniformly at random from their
        legal moves.
        """
        "*** YOUR CODE HERE ***"

        #print(self.depth)
        #print(gameState.getNumAgents())
        def recursionStillSTILLSux(state, i):
            #print(i)
            #If state is a winning or losing state, or if state is the final agent of the lowest depth
            #Then does not need to expand state. Just returns the evaluationfunction.
            if i == self.depth*gameState.getNumAgents() or state.isWin() or state.isLose():
                return self.evaluationFunction(state)

            #when i is divisible by numAgents, then it is pacmans turn
            if i%gameState.getNumAgents() == 0:
                bestScore = float("-inf")
                bestAction = state.getLegalActions(0)[0]
                for action in state.getLegalActions(0):
                    successorState = state.generateSuccessor(0, action)
                    successorScore = recursionStillSTILLSux(successorState, i+1)
                    if successorScore > bestScore:
                        bestScore = successorScore
                        bestAction = action
                #return action to take if top of tree, otherwise return the max score.
                if i == 0:
                    return bestAction
                else:
                    return bestScore
            #otherwise it is ghosts turn
            else:
                totalScore = 0
                for action in state.getLegalActions(i%gameState.getNumAgents()):
                    successorState = state.generateSuccessor(i%gameState.getNumAgents(), action)
                    totalScore += recursionStillSTILLSux(successorState, i+1)

                return (totalScore / len(state.getLegalActions(i%gameState.getNumAgents())))


        return recursionStillSTILLSux(gameState, 0)


        util.raiseNotDefined()

def betterEvaluationFunction(currentGameState):
    """
    Your extreme ghost-hunting, pellet-nabbing, food-gobbling, unstoppable
    evaluation function (question 5).

    DESCRIPTION: <returns score + inverse of closest position>
    """
    "*** YOUR CODE HERE ***"
    pacPosition = currentGameState.getPacmanPosition()
    foodPositions = currentGameState.getFood()

    #if list isn't empty
    if foodPositions.asList():
        foodDistance = manhattanDistance(foodPositions[0],pacPosition)
        closestFood = foodPositions.asList()[0]
    else:
        return currentGameState.getScore() + 100

    #find distance to closest food
    for food in foodPositions.asList():
        temp = manhattanDistance(food,pacPosition)
        if temp < foodDistance:
            foodDistance = temp
            closestFood = food

    return currentGameState.getScore() + (1/manhattanDistance(closestFood, pacPosition))
    util.raiseNotDefined()

# Abbreviation
better = betterEvaluationFunction
