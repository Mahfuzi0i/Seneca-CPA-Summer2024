/*------------------------------------------------- Views ---------------------------------------------------------------*/

/*  View 1
    This view provides detailed information about each candidate's applications, including job titles, application dates, and statuses.
    It helps HR and recruitment teams track application progress and analyze candidate interest in various job roles.
    This report is valuable for evaluating recruitment efforts and understanding candidate engagement.
*/
CREATE VIEW candidate_application_details AS
SELECT c.candidate_id, c.firstname, c.lastname, a.application_date, a.status, j.job_title, e.company_name
FROM candidates c
JOIN applications a ON c.candidate_id = a.candidate_id
JOIN job j ON a.job_id = j.job_id
JOIN employer e ON j.employer_id = e.employer_id;

SELECT * FROM candidate_application_details;

/*  View 2
    This view lists all job openings posted by employers, including job titles, descriptions, and application deadlines.
    It assists employers in managing their job listings and helps them track the status of open positions.
    This report is beneficial for ensuring timely recruitment and evaluating job market demand.
*/
CREATE VIEW employer_job_listings AS
SELECT e.employer_id, e.company_name, j.job_id, j.job_title, j.job_desc, j.application_deadline
FROM employer e
JOIN job j ON e.employer_id = j.employer_id
ORDER BY e.employer_id;

SELECT * FROM employer_job_listings;


/*  View 3
    This view provides a schedule of interviews for each candidate, including interview dates, times, and locations.
    It helps HR and recruitment teams efficiently organize and manage interview processes.
    This report ensures proper coordination and preparation for interviews, enhancing candidate experience.
*/
CREATE VIEW interview_schedules AS
SELECT i.interview_id, c.firstname, c.lastname, j.job_title, i.interview_date, i.interview_time, i.location
FROM interviews i
JOIN candidates c ON i.candidate_id = c.candidate_id
JOIN job j ON i.job_id = j.job_id;

SELECT * FROM interview_schedules;

/*  View 4
    This view shows the offers made to candidates, including position titles, employment types, and staff contacts.
    It helps HR and management monitor offer acceptance rates and analyze the effectiveness of job offers.
    This report is crucial for understanding recruitment success and adjusting offer strategies as needed.
*/
CREATE VIEW candidate_offers AS
SELECT o.offer_id, c.firstname, c.lastname, o.postition_title, e.company_name, o.employment_type, s.first_name AS staff_first_name, s.last_name AS staff_last_name
FROM offer o
JOIN candidates c ON o.candidate_id = c.candidate_id
JOIN staff s ON o.staff_id = s.staff_id
JOIN employer e ON s.reportsto = e.employer_id;

SELECT * FROM candidate_offers;


/*  View 5
    This view summarizes feedback notes from interviews for each candidate, providing insights into candidate strengths and weaknesses.
    It helps recruitment teams assess candidate performance and identify areas for improvement.
    This report is valuable for refining candidate selection and providing constructive feedback to candidates.
*/
CREATE VIEW candidate_feedback_summary AS
SELECT c.candidate_id, c.firstname, c.lastname, j.job_title, i.interview_date, i.location, i.status AS interview_status, a.notes AS remarks
FROM candidates c
JOIN applications a ON c.candidate_id = a.candidate_id
JOIN interviews i ON a.candidate_id = i.candidate_id AND a.job_id = i.job_id
JOIN job j ON a.job_id = j.job_id
ORDER BY c.candidate_id, i.interview_date DESC;

SELECT * FROM candidate_feedback_summary;

/*  View 6
    This view shows staff members and their corresponding employers, helping understand staff distribution and management structure.
    It is useful for organizational clarity and for addressing staffing needs.
*/
CREATE VIEW staff_working_for_employer AS
SELECT s.staff_id, s.first_name, s.last_name, e.company_name
FROM staff s
JOIN employer e ON s.reportsto = e.employer_id
ORDER BY s.staff_id;

SELECT * FROM staff_working_for_employer;


DROP VIEW candidate_application_details;
DROP VIEW employer_job_listings;
DROP VIEW interview_schedules;
DROP VIEW candidate_offers;
DROP VIEW candidate_feedback_summary;
DROP VIEW staff_working_for_employer;