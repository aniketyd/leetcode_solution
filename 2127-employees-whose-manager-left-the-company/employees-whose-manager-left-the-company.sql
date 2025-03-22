# Write your MySQL query statement below
select e.employee_id
from employees
as e left join employees as ee
on e.manager_id=ee.employee_id
where ee.employee_id is NULL and e.manager_id is not NULL and e.salary<30000
order by e.employee_id;