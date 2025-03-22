# Write your MySQL query statement below
(select users.name as results
from movierating inner join 
users on  users.user_id=movierating.user_id
group by users.user_id
order by count(*) desc,users.name
limit 1 )

union all

(select movies.title as results
from 
(select * from movierating
where month(created_at)=2 and year(created_at)=2020) as t inner join
movies on movies.movie_id=t.movie_id
group by movies.movie_id
order by avg(t.rating) desc, movies.title
limit 1 )