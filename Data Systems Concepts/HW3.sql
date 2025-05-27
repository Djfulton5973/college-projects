-- Question 1)
SELECT distinct course_id, title
    FROM course_view
    WHERE grade is null
    AND crse_dept = 'Math'
;

-- Question 2)
SELECT distinct course_id, title, crse_dept
    FROM course_view as crse_one
    WHERE NOT EXISTS (SELECT *
                        FROM course_view as crse_two
                      WHERE crse_one.year = 2010
                        AND crse_one.course_id = crse_two.course_id)
    AND crse_one.year = 2009
;

-- Question 3)
SELECT count(stu_name), year, crse_dept
    FROM course_view
    GROUP BY year, crse_dept
;

-- Question 4)
SELECT course_id, title, stu_name, grade, inst_name as advisor
    FROM course_view
        LEFT OUTER JOIN advisor
            ON course_view.stu_id = advisor.s_ID
                LEFT JOIN instructor
                    ON advisor.i_ID = instructor.ID
    WHERE stu_dept = 'Biology'
    AND (grade = 'C-'
        OR grade = 'C '
        OR grade = 'C+')
;

-- Question 5)
SELECT distinct section.course_id, title
    FROM section
        LEFT OUTER JOIN takes
            ON (section.course_id = takes.course_id)
        INNER JOIN student
            ON (takes.ID = student.ID)
        LEFT OUTER JOIN teaches
            ON (section.course_id = teaches.course_id)
        INNER JOIN course
            ON (section.course_id = course.course_id)
    WHERE grade is null
    AND course.dept_name = 'Math'
    ORDER BY section.year
;