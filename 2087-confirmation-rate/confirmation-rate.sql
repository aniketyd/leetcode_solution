SELECT s.user_id,
       ROUND(
           CASE 
               WHEN COUNT(c.user_id) = 0 THEN 0.00
               ELSE SUM(c.action = 'confirmed') / COUNT(c.user_id)
           END, 2
       ) AS confirmation_rate
FROM signups AS s
LEFT JOIN confirmations AS c ON s.user_id = c.user_id
GROUP BY s.user_id;
