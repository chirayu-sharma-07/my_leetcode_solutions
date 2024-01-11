# Write your MySQL query statement below

# pehla tarika

# SELECT id,CASE WHEN p_id IS NULL THEN 'Root' WHEN id IN(SELECT DISTINCT(p_id) FROM Tree WHERE p_id IS NOT NULL) THEN 'Inner' ELSE 'Leaf' END AS type FROM Tree;

# dusra tarika

# SELECT id,CASE WHEN p_id IS NULL THEN 'Root' WHEN id NOT IN(SELECT DISTINCT(p_id) FROM Tree WHERE p_id IS NOT NULL) THEN 'Leaf' ELSE 'Inner' END as type FROM Tree;

# Teesra tarika

SELECT id,IF(p_id IS NULL,"Root",IF(id IN(SELECT DISTINCT(p_id) FROM Tree),"Inner","Leaf")) AS type FROM Tree;