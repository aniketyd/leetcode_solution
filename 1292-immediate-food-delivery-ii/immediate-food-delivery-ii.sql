SELECT 
     
    ROUND(
        AVG(
            CASE 
                WHEN min_order_date = min_pref_date THEN 1 
                ELSE 0 
            END
        ), 4) * 100 AS immediate_percentage
FROM (
 
    SELECT 
        customer_id, 
        MIN(order_date) AS min_order_date, 
        MIN(customer_pref_delivery_date) AS min_pref_date
    FROM delivery
    GROUP BY customer_id
) AS subquery;
