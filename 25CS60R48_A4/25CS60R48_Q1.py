from ortools.linear_solver import pywraplp

def solar_investment(n, project_returns, capital, budget, years):
    solver = pywraplp.Solver.CreateSolver("SCIP")  # better for ILP
    x_vars = []

    # Create binary decision variables for each project
    for i in range(n):
        x = solver.IntVar(0, 1, f"X_{i}")
        x_vars.append(x)

    # Constraints: For each year, total capital used <= budget
    for y in range(years):
        exp = solver.Sum([capital[i][y] * x_vars[i] for i in range(n)])
        solver.Add(exp <= budget[y])

    # Objective: maximize total return
    maxfun = solver.Sum([project_returns[i] * x_vars[i] for i in range(n)])
    solver.Maximize(maxfun)

    # Solve
    status = solver.Solve()
    if status == pywraplp.Solver.OPTIMAL:
        print("Selected projects:", [i+1 for i in range(n) if x_vars[i].solution_value() == 1])
        print("Optimal return =", round(solver.Objective().Value(), 2))
    else:
        print("No optimal solution found.")

# Reading input
with open("Q1/input1.txt") as f:
    lines = [line.strip() for line in f.readlines()]

n = int(lines[0])
years = int(lines[1])
project_returns = list(map(float, lines[2].split(',')))
capital = [list(map(float, lines[3+i].split(','))) for i in range(n)]
budget = list(map(float, lines[3+n].split(',')))

solar_investment(n, project_returns, capital, budget, years)
