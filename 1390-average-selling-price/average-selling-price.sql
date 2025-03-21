SELECT product_id1 as product_id, 
       case
       when (sum(t1)is NULL) then 0.00
       else
       ROUND(sum(t1)/sum(t2), 2) 
       end AS average_price
FROM (
    SELECT product_id1,
          sum(total)as t1,
          sum(units)as t2
    FROM (
        SELECT p.product_id as product_id1, 
               u.product_id as product_id2,
               u.units, 
               start_date,
               (p.price * u.units) AS total
        FROM prices AS p
        LEFT JOIN unitssold AS u 
               ON p.product_id = u.product_id 
               AND u.purchase_date BETWEEN p.start_date AND p.end_date
    ) AS subquery
    GROUP BY product_id1, start_date
) AS subquery2
GROUP BY product_id1;
