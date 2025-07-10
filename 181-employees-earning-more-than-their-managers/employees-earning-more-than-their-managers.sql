# Write your MySQL query statement below
SELECT e.name AS Employee
FROM Employee e
LEFT JOIN Employee m
ON e.managerId = m.id 
WHERE e.managerId IS NOT NULL
AND e.salary > m.salary;