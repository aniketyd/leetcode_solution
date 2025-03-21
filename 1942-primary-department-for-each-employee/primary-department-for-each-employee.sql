# Write your MySQL query statement below
select e1.employee_id,
 case
 when e2.department_id is NULL then e1.department_id
 else e2.department_id
 end as department_id
from (select * from employee group by employee_id) as e1 left join 
employee as e2 
on e1.employee_id=e2.employee_id and e2.primary_flag='Y';