select product_id,
10 as price
from products
group by product_id
having min(change_date)>'2019-08-16'
UNION ALL
select t.product_id,p.new_price as price
from (select product_id, max(change_date) as reqdate from products
where change_date<='2019-08-16'
group by product_id
) as t inner join products as p
on t.product_id=p.product_id and t.reqdate=p.change_date;
