# Write your MySQL query statement below
select t1.visited_on,sum(t2.amount)
as amount,round(sum(t2.amount)/7,2) as average_amount
from 
(SELECT distinct visited_on 
FROM customer 
WHERE visited_on >= (
    SELECT MIN(visited_on) FROM customer
) + INTERVAL 6 DAY )as t1 inner join customer as t2
on DATEDIFF(t1.visited_on, t2.visited_on) BETWEEN 0 AND 6

group by t1.visited_on
order by t1.visited_on
