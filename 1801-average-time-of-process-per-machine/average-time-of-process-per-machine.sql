select machine_id,
round(avg(case
when activity_type='end' then timestamp
else -1*timestamp end)*2,3) as processing_time
from activity
group by machine_id;