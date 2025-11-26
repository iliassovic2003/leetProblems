DELETE FROM Person alias1 USING Person alias2
WHERE alias2.id < alias1.id
AND alias2.email = alias1.email