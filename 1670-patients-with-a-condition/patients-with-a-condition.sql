# Write your MySQL query statement below
select patient_id,patient_name,conditions
from patients
where Locate(' DIAB1',conditions)>0 or left(conditions,5)='DIAB1';