from ortools.linear_solver import pywraplp

def fractional_knapsack(w, n, values, weights):
    print()
    #Write code from here
    list=[]
    solver = pywraplp.Solver.CreateSolver("GLOP")
    for i in range(n):
        x=solver.NumVar(0, 1,f"X_{i}") 
        list.append(x)  
    cts=0
    for i in range(n):
        cts+=weights[i]*list[i]
    solver.Add(cts<=w) 

    maxfun=0;   
    for i in range(n):
        maxfun+=values[i]*list[i]
      
    solver.Maximize(maxfun)

    status = solver.Solve()
    if status == pywraplp.Solver.OPTIMAL:
        for i in range(n):
            print(round(list[i].solution_value(),2))

        print("Objective value =", round(solver.Objective().Value(),2))
    # else:
    #     print("The problem does not have an optimal solution.")    


if __name__ == "__main__":
    with open("Q3/input1.txt") as f:
        lines = [line.strip() for line in f.readlines() if line.strip()]

    w = int(lines[0])
    n = int(lines[1])
    values = list(map(float, lines[2].split(',')))
    weights = list(map(float, lines[3].split(',')))

    fractional_knapsack(w, n, values, weights)
