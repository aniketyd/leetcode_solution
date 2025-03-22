select round(sum(t2.tiv_2016),2) as tiv_2016
from
(select tiv_2015 from
insurance 
group by tiv_2015
having count(*)>1) as t1
inner join

(select * from
insurance 
group by lat,lon
having count(*)=1)  as t2 
on t1.tiv_2015=t2.tiv_2015
;