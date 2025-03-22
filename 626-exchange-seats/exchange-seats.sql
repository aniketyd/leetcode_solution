SELECT id, student
FROM (
    SELECT 
        s1.id,
        CASE
            WHEN s2.student IS NULL THEN s1.student
            ELSE s2.student
        END AS student
    FROM (SELECT * FROM seat WHERE id % 2 = 1) AS s1
    LEFT JOIN seat AS s2 ON s1.id + 1 = s2.id
    
    UNION ALL
    
    SELECT 
        s1.id,
        s2.student
    FROM (SELECT * FROM seat WHERE id % 2 = 0) AS s1
    LEFT JOIN seat AS s2 ON s1.id - 1 = s2.id
) AS swapped
ORDER BY id;
