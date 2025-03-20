# Write your MySQL query statement below
select s.student_id,s.student_name,s.subject_name,
 count(e.student_id) as attended_exams 
from (select * from students cross join subjects) as s left join examinations as e on e.student_id=s.student_id and s.subject_name=e.subject_name group by s.student_id,s.subject_name order by s.student_id, s.subject_name;