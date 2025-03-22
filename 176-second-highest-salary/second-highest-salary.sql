SELECT COALESCE((
    SELECT DISTINCT e1.salary 
    FROM Employee e1
    JOIN Employee e2 
    ON e1.salary < e2.salary
    GROUP BY e1.salary
    HAVING COUNT(DISTINCT e2.salary) = 1
    LIMIT 1  -- Ensures only one result is returned
), NULL) AS SecondHighestSalary;