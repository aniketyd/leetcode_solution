SELECT 
    t1.machine_id, 
    ROUND(a1 - a2, 3) AS processing_time 
FROM 
    (SELECT machine_id, AVG(timestamp) AS a1 
     FROM activity 
     WHERE activity_type = 'end' 
     GROUP BY machine_id) AS t1 
INNER JOIN 
    (SELECT machine_id, AVG(timestamp) AS a2 
     FROM activity 
     WHERE activity_type = 'start' 
     GROUP BY machine_id) AS t2 
ON t1.machine_id = t2.machine_id;
