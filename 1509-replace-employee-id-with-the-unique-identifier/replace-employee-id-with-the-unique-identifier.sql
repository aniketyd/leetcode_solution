SELECT employees.name, employeeuni.unique_id 
FROM employees 
LEFT JOIN employeeuni ON employeeuni.id = employees.id;