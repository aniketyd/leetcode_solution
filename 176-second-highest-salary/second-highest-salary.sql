# Write your MySQL query statement below
select distinct  COALESCE(max(salary), NULL) 
as SecondHighestSalary 
from Employee 
where salary < (select max(salary) from Employee)
