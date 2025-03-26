select machine_id,
round(sum(case
when activity_type='end' then timestamp
else -1*timestamp end)/count(distinct process_id),3) as processing_time
from activity
group by machine_id;