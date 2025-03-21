SELECT e1.name
FROM employee AS e1
LEFT JOIN employee AS e2 ON e1.id = e2.managerId
GROUP BY e1.id
HAVING COUNT(e2.id) >= 5;
