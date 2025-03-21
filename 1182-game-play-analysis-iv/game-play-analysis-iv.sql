select round(count(*)/(select count(distinct player_id) from activity),2) as fraction
from activity
where (player_id,event_date) in 
(select player_id,DATE_ADD(MIN(event_date),INTERVAL 1 DAY)
from activity 
group by player_id
)