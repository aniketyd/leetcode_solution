# Write your MySQL query statement below
select round(avg(case when a.player_id is not NULL then 1 else 0 end),2) as fraction
from
(select player_id as pid,min(event_date) as ed from activity group by player_id )as t1 left join
activity as a 
on DATE_ADD(ed, INTERVAL 1 DAY)=a.event_date and pid=a.player_id; 