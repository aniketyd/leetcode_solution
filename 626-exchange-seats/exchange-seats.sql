# Write your MySQL query statement below

select id,student from
(select s1.id ,
case
when s2.student is NULL then s1.student
else s2.student
end as student
from (select * from seat where id%2=1) as s1 left join seat
as s2 on s1.id+1=s2.id
union all
select s1.id ,
s2.student as student
from (select * from seat where id%2=0) as s1 left join seat
as s2 on s1.id-1=s2.id) as t
order by id
;