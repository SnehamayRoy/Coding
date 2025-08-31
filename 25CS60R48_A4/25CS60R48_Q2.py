from ortools.linear_solver import pywraplp

def chemical_production(X, Y):
    chemicals = ["A", "B", "C", "D", "E"]
    cost = [50, 70, 40, 60, 55]
    energy = [20, 25, 15, 30, 18]
    labor = [5, 6, 4, 7, 5]
    emissions = [10, 12, 8, 15, 9]
    storage = [2, 3, 1, 4, 2]

    solver = pywraplp.Solver.CreateSolver("GLOP")
    A=solver.NumVar(0, solver.infinity(), "a")
    B=solver.NumVar(0, solver.infinity(), "b")
    C=solver.NumVar(0, solver.infinity(), "c")
    D=solver.NumVar(0, solver.infinity(), "d")
    E=solver.NumVar(0, solver.infinity(), "e")
    #Write Code here
    solver.Add(20*A+25*B+15*C+30*D+18*E>=X)
    solver.Add(5*A+ 6*B +4*C +7*D+5*E>=Y)
    solver.Add(10*A+ 12*B +8*C +15*D+9*E<=500)
    solver.Add(2*A+ 3*B +1*C +4*D+2*E<=50)

    solver.Minimize(50*A+70*B+40*C+60*D+55*E)
    status = solver.Solve()
    if status == pywraplp.Solver.OPTIMAL:
        print("Minimumcost")
        print("Objective value =", round(solver.Objective().Value(),2))
        print("A =", round(A.solution_value(),2))
        print("B =", round(B.solution_value(),2))
        print("C =",round(C.solution_value(),2))
        print("D =", round(D.solution_value(),2))
        print("E =", round(E.solution_value(),2))
    else:
        print("The problem does not have an optimal solution.")    


with open('Q2/input1.txt') as f:
    lines = f.readlines()

X = int(lines[0].strip())  # Energy requirement
Y = int(lines[1].strip())  # Labor requirement

chemical_production(X, Y)